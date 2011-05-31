/**
 * @author Ole Mahtte Scheie Anti
 */
(function ($) {

Drupal.behaviors.run_after_page_loads = function (context) {
    // Some jQuery that runs once the page loads.
			var center_height = $('#center').height();
			var sidebar_left_height = $('#sidebar-left').height();
			
			if(sidebar_left_height<center_height){
				$('#sidebar-left').height(center_height);
			}
}
})(jQuery);
