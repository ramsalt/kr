(function ($) {
	// eqheight tre saker på brett, sakene 4-6
	function equal_height(selector){
		var eq = false;
		if($('body').hasClass('layout-tablet')){
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
	function eq_desk(){
		if($('body').hasClass('layout-desktop')){
			$('.container-16 .grid.full.nomargin .one').height('auto');
			$('.container-16 .grid.full.nomargin .one').height($('.container-16 .grid.full.nomargin').height());
			$('.newslist.sak-7 li.views-row').height('auto');
			console.log($('.newslist.sak-7 .item-list ul').height());
			$('.newslist.sak-7 .item-list li.views-row').height($('.newslist.sak-7 .item-list ul').height());
		}else{
			$('.newslist.sak-7 .item-list li.views-row').height('auto');
			$('.container-16 .grid.full.nomargin .one').height('auto');
		}
	}
	$(document).ready(function() {
		$('body').bind('layoutset', function(event, layout) {
			equal_height('.newslist.sak-4 li.views-row');
			
		});
		$(window).resize(function(){
			eq_desk();
		});
		equal_height('.newslist.sak-4 li.views-row');

	});
	$(window).load(function() {
		eq_desk();
	});
}(jQuery));
