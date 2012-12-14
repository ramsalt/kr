(function ($) {
	$(document).ready(function() {
		$('.form-label-alter .form-item input').bind('focus.forms', function(){
			form_item = $(this).parent();
			$('label',form_item).hide();
		});
		$('.form-label-alter .form-item input').bind('focusout.forms', function(){
			console.log($(this).val().length + ' ole');
			if($(this).val().length == 0){
				form_item = $(this).parent();
				$('label',form_item).show();
			}
		});

	});

}(jQuery));
