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
			$('.newslist.fire').each(function(index) {
				$('li.views-row', this).height('auto');
				$('.item-list li.views-row', this).height($('.item-list ul', this).height());
			});
			$('.newslist.fem').each(function(index) {
				$('li.views-row', this).height('auto');
				$('.item-list li.views-row', this).height($('.item-list ul', this).height());
			});
		}else{
			$('.newslist.fire .item-list li.views-row').height('auto');
			$('.newslist.fem .item-list li.views-row').height('auto');
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
