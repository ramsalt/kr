(function ($) {
	function equal_height(selector){
		var eq = false;
		if($('body').hasClass('layout-tablet ')){
			eq = true;
			height = 0;
			$(selector).each(function(index) {
				if($(this).height() > height){
					height = $(this).height();
				}			 
			});
			$(selector).height(height);
		}else{
			$(selector).height('auto');
		}
	}
	$(document).ready(function() {
		$('body').bind('layoutset', function(event, layout) {
			equal_height('.newslist.sak-4 li.views-row');
		});
		equal_height('.newslist.sak-4 li.views-row');
		
	});
}(jQuery));
