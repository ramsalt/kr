(function ($) {
	$(document).ready(function() {
		$('body').bind('layoutset', function(event, layout) {
			$('#nav-button').removeClass('open');
			$('#nav').removeClass('open');
			$('#search-content').removeClass('open');
			$("#search-mob").removeClass('open');
			$("#user-login-mob").removeClass('open');
			$("#login-content").removeClass('open');
		});
		$('body.layout-mobile #nav-button a').bind('click', function(){
			$("#user-login-mob").removeClass('open');
			$("#login-content").removeClass('open');
			$('#search-content').removeClass('open');
			$("#search-mob").removeClass('open');
			
			$(this).parent().toggleClass('open');
			$("#nav").toggleClass('open');
			return false;
		});
		$('body.layout-mobile #search-content a').bind('click', function(){
			$('#nav-button').removeClass('open');
			$('#nav').removeClass('open');
			$("#user-login-mob").removeClass('open');
			$("#login-content").removeClass('open');
			
			$(this).parent().toggleClass('open');
			$("#search-mob").toggleClass('open');
			return false;
		});
		$('body.layout-mobile #login-content a').bind('click', function(){
			$('#nav-button').removeClass('open');
			$('#nav').removeClass('open');
			$('#search-content').removeClass('open');
			$("#search-mob").removeClass('open');
			
			$(this).parent().toggleClass('open');
			$("#user-login-mob").toggleClass('open');
			return false;
		});
		$('body.layout-mobile #nav .multilevel a.first-level').bind('click', function(){
			$(this).parent().toggleClass('open');
			return false;
		});
	});
}(jQuery));
