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
	if(width>1003){
		return "layout-desktop";
	}
	else if(width>739){
		return "layout-tablet";
	}
	else{
		return "layout-mobile";
	}
}
$(document).ready(function() {
	current_width = $(window).width();
	current_class = kr2012_current_body(current_width);
	kr2012_set_body_class(current_class);
	
	$(window).resize(function(){
		current_width = $(window).width();
		current_class = kr2012_current_body(current_width);
		kr2012_set_body_class(current_class);
	});
});

}(jQuery));


