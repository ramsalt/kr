(function ($) {
	function meny_mob_menu_fix(){
		$('#nav-button').removeClass('open');
		$('#nav').removeClass('open');
		$('#search-content').removeClass('open');
		$("#search-mob").removeClass('open');
		$("#user-login-mob").removeClass('open');
		$("#login-content").removeClass('open');
		
		$("#nav-button a").unbind('click.mob');
		$("#search-content a").unbind('click.mob');
		$("#login-content a").unbind('click.mob');
		
		$('body.layout-mobile #nav-button a').bind('click.mob', function(){
			$("#user-login-mob").removeClass('open');
			$("#login-content").removeClass('open');
			$('#search-content').removeClass('open');
			$("#search-mob").removeClass('open');
			
			$(this).parent().toggleClass('open');
			$("#nav").toggleClass('open');
			return false;
		});
		$('body.layout-mobile #search-content a').bind('click.mob', function(){
			$('#nav-button').removeClass('open');
			$('#nav').removeClass('open');
			$("#user-login-mob").removeClass('open');
			$("#login-content").removeClass('open');
			
			$(this).parent().toggleClass('open');
			$("#search-mob").toggleClass('open');
			return false;
		});
		$('body.layout-mobile #login-content a').bind('click.mob', function(){
			$('#nav-button').removeClass('open');
			$('#nav').removeClass('open');
			$('#search-content').removeClass('open');
			$("#search-mob").removeClass('open');
			
			$(this).parent().toggleClass('open');
			$("#user-login-mob").toggleClass('open');
			return false;
		});

		// fix width of mobile menu
		max_width = $("#login-area .container .grid").width();
		$(".navbuttun").width((max_width - 4)/3);
	}
	$(document).ready(function() {
		$('body').bind('layoutset', function(event, layout) {
			meny_mob_menu_fix();
		});
		meny_mob_menu_fix();
		$('#nav .multilevel a.first-level').bind('click.multilevel', function(){
			$(this).parent().toggleClass('open');
			return false;
		});

	});
}(jQuery));
