(function ($) {

Drupal.behaviors.utgivelser_article = function (context) {
	selector_kanal_ukeavis = '#edit-field-kanal-value-Ukeavis';
	selector_utgave_wrapper = "#edit-taxonomy-47-wrapper";
	
	if($(selector_kanal_ukeavis).attr('checked') == false){
		$(selector_utgave_wrapper).css('display', 'none');
	}
	$(selector_kanal_ukeavis).click( function(){
		   if( $(this).is(':checked')){
			   $(selector_utgave_wrapper).css('display', 'block');
		   }else{
			   $(selector_utgave_wrapper).css('display', 'none');
		   }
	});
};

}(jQuery));