jQuery164(document).ready(function() {

jQuery164(".flexslider").flexslider({
  slideshow: "false"
});
  
 /* if(!jQuery164.browser.msie){ */
    jQuery164(".colorboks1").colorbox({
      rel: "colorboks1",
      transition:"fade",
      inline:true,

      scrolling: "false",
      maxheight: "88%",
      fixed: "true",
      top: "2%"
    });
    
    jQuery164(document).bind("cbox_complete", function(){
      jQuery164("#header").css("width","0px");
      jQuery164("#header").css("height","0px");
      jQuery164("#header").css("display","none");
      jQuery164("#colorbox").css("overflow","visible");
      
      
      if(jQuery164("#cboxLoadedContent").height() > (jQuery164(window).height()-120)){

        old_height = jQuery164("#cboxLoadedContent .cimage img").height();
        old_width = jQuery164("#cboxLoadedContent .cimage img").width();
        new_height = jQuery164(window).height() - jQuery164("#cboxLoadedContent .cimage .caption").height() - 120;
        diff = old_height-new_height;
        multiplier = diff/old_height;
        new_width = old_width - (old_width*multiplier);
        

        
        jQuery164("#cboxLoadedContent .cimage img").width(new_width);
        jQuery164("#cboxLoadedContent .cimage img").attr("width", new_width);
        jQuery164("#cboxLoadedContent .cimage img").height(new_height);
        jQuery164("#cboxLoadedContent .cimage img").attr("height",new_height);
      }
      if (jQuery164("#cboxLoadedContent").width() > (jQuery164(window).width()-70)){

        old_height = jQuery164("#cboxLoadedContent .cimage img").height();
        old_width = jQuery164("#cboxLoadedContent .cimage img").width();
        new_width = jQuery164("#cboxLoadedContent .cimage img").width() - 60;
        diff = old_width-new_width;
        multiplier = diff/old_width;
        new_height = old_height - (old_height*multiplier);
        

        
        jQuery164("#cboxLoadedContent .cimage img").width(new_width);
        jQuery164("#cboxLoadedContent .cimage img").attr("width", new_width);
        jQuery164("#cboxLoadedContent .cimage img").height(new_height);
        jQuery164("#cboxLoadedContent .cimage img").attr("height",new_height);
  
      }
      wrap_width=jQuery164("#cboxLoadedContent .cimage img").width()+28;
      jQuery164.colorbox.resize({width: wrap_width});
      jQuery164("#colorbox").css("overflow","visible");
      
      jQuery164("#colorbox").css("margin","0px auto");
      jQuery164("#colorbox").css("position","absolute");
      jQuery164("#cboxOverlay").css("display", "block");
      jQuery164("#cboxOverlay").css("position", "absolute");
    });
/*  } */

});