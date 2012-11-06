(function ($) {
	$(document).ready(function() {
		$('.fakta-mobil .faktatittel a').bind('click', function(){
			$(this).closest('.fakta-mobil').toggleClass('open');
			return false;
		});
	});
}(jQuery));