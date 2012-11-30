(function ($) {
var current;
var previous;

function kr2012_set_body_class(new_class){
	
	if(current == undefined){
		$('body').addClass(new_class);
		current = new_class;
		$("body").trigger("layoutset", [new_class]);
	}
	else if(current != new_class){
		previous = current;
		$('body').addClass(new_class).removeClass(previous);
		current = new_class;
		$("body").trigger("layoutset", [new_class]);
	}
	
}
function kr2012_current_body(width){
	if(width >= 800){
		return "layout-desktop";
	}
	else if(width>739 && width < 800){
		return "layout-tablet";
	}
	else{
		return "layout-mobile";
	}
}
function kr_20212_ad_right(){
	margins = $(window).width() - $('.container-16').width();
	new_left = $(window).width() - (margins/2) + 15;
	$('#ad-right').css('left', new_left);
}
$(document).ready(function() {
	current_width = $(window).width();
	current_class = kr2012_current_body(current_width);
	kr2012_set_body_class(current_class);
	kr_20212_ad_right();
	$(window).resize(function(){
		current_width = $(window).width();
		current_class = kr2012_current_body(current_width);
		kr_20212_ad_right();
		kr2012_set_body_class(current_class);
	});
});

}(jQuery));


