
(function ($) {

Drupal.behaviors.run_after_page_loads = function (context) {

  set_sidebar_heights();
		
}
function set_sidebar_heights(){
  var center_height = $('#center').height();
  var sidebar_left_height = $('#sidebar-left').height();
  var sidebar_right_height = $('#sidebar-right').height();
  
  var sidebars = false;
  var max = center_height;
  
  if(sidebar_right_height > center_height || sidebar_left_height > center_height){
    sidebars = true;
    if(sidebar_right_height > sidebar_left_height){
      max = sidebar_right_height;
    }else{
      max = sidebar_left_height;
    }
  }
  
  $('#sidebar-left').height(max);
  $('#sidebar-right').height(max);
}
})(jQuery);
