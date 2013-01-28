Drupal.behaviors.kalkulatorNode = function (context) {
  var regex = /\[search:(\w+)\]/g; 
  var input = $('.node-type-kalkulator .node .node-content').html(); 
  if(regex.test(input)) {
    $('.node-type-kalkulator .node .node-content').html(input.replace(regex, '<input type="text" id="kalk-search-$1" class="calc-search" search-col="$1" />'));
  }
  
  var regex = /\[out:(\w+):([a-z|A-Z|(0-9)|\xE5|\xF8|\xE6|\xC5|\xC6|\xD8]*)\]/g; 
  var input = $('.node-type-kalkulator .node .node-content').html(); 
  if(regex.test(input)) {
    $('.node-type-kalkulator .node .node-content').html(input.replace(regex, '<span class="replace-text" replace-col="$1" id="replace-text-$1">$2</span>'));
  }
  
  var values = Drupal.settings.kalkulator.values;
  var headers = values.shift();

  $('.calc-search').keyup(function () {
    var row = kalkulator_search_values($(this).attr('search-col'), $(this).val(), values);
    if(row > -1) {
      for(var id in headers) {
      	$('.replace-text[replace-col="'+headers[id]+'"]').text(values[row][id]);
      } 
    }
  });
  
  function kalkulator_search_values(col, find, values) {
    for (var i = 0; i < values.length; i++) {
      if (values[i][jQuery.inArray(col, headers)].toLowerCase() == find.toLowerCase()) return i;
    }
    return -1;
  }
  
};