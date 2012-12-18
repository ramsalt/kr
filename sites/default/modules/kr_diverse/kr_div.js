(function ($) {
	function ticker_news_width(){
		content_width = $('#block-kr_diverse-2 .content').width();
		ticker_label_width = parseInt($('#block-kr_diverse-2 .ticker-label').width()) + parseInt($('#block-kr_diverse-2 .ticker-label').css('margin-left').replace('px', '')) + parseInt($('#block-kr_diverse-2 .ticker-label').css('margin-right').replace('px', ''));
		ticker_next_width = parseInt($('#block-kr_diverse-2 .ticker-next').width()) + parseInt($('#block-kr_diverse-2 .ticker-next').css('right').replace('px', ''));
		total_width = content_width - ticker_label_width - ticker_next_width;
		$('#block-kr_diverse-2 .ticker-news').width(total_width-10);
	}
	$(document).ready(function() {
		$('body').bind('layoutset', function(event, layout) {
			ticker_news_width();
		});
		ticker_news_width();
		
		$('.ticker div.ticker-prev').bind('click.ticker', function(){
			$('#block-kr_diverse-2 .ticker-news ul').animate({'margin-left': "+=100px"}, 50);
			
		});
		$('.ticker div.ticker-next').bind('click.ticker', function(){
			$('#block-kr_diverse-2 .ticker-news ul').animate({'margin-left': "-=100px"}, 50);
		});
	});
}(jQuery));
