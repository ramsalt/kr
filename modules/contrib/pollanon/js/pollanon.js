Drupal.behaviors.pollanonHandleVoteView = function (context) {
  //Does this page contain poll form or poll results?
  if (typeof PollAnon == 'undefined' || !PollAnon.nid) {
    return;
  }

  cookieName = 'pa-' + PollAnon.nid;
  cookieNameOld = 'pollanon-' + PollAnon.nid; //Legacy cookies some users may have from older version of pollanon

  //Form element is hidden by CSS to prevent flashing on switching to result display
  $('form.pollanon').fadeIn('fast');
  
  if ($.cookie(cookieName) || $.cookie(cookieNameOld)) {
    //Cookie exists: This anonymous user has already submitted the given poll
    $hiddenResults = $('.pollanon-poll-results.hidden');
    if ($hiddenResults.length > 0) {
      //Hide poll form options and button
      $poll_form = $('form.pollanon .vote-form');
      $('.form-radios, .form-submit', $poll_form).hide();
      //Display results
      $hiddenResults.hide(); //Needs to be hidden by jQuery for the fadeIn() to work
      $hiddenResults.removeClass('hidden'); //Remove CSS hiding
      $hiddenResults.fadeIn('fast'); //Show element with an animation
    }
  }
  else {
    //User might be submitting the poll form
    ua = navigator.userAgent;
    uaI = Math.floor(ua.length/2);
    pollanonKey = ua? ua.substring(uaI, uaI+2) + ua.length : '';
    pollanonKey += '-' + new Date().getTime();
    $.cookie('pa-submit', pollanonKey, {path: '/'});
    $('form.pollanon input[name="pollanonkey"]', context).attr('value', pollanonKey);
  }

  msg = $.cookie('pa-messages');
  if (msg) {
    msg = unescape(msg.replace(/\+/g, " "));
    $('form.pollanon').before('<div class="messages status">'+msg+'</div>');
    $.cookie('pa-messages', null, { path: '/' }); //Remove message cookie
  }

};
