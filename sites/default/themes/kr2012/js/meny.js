(function ($) {
	$(document).ready(function() {
		$('body').bind('layoutset', function(event, layout) {
			$('#nav-button').removeClass('open');
			$('#nav').removeClass('open');
		});
		$('body.layout-mobile #nav-button a, body.layout-tablet #nav-button a').bind('click', function(){
			$(this).parent().toggleClass('open');
			$("#nav").toggleClass('open');
			return false;
		});
		$('body.layout-mobile #nav .multilevel a.first-level, body.layout-tablet #nav .multilevel a.first-level').bind('click', function(){
			$(this).parent().toggleClass('open');
			return false;
		});
	});
}(jQuery));
