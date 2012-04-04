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
      

      console.log("width: "+jQuery164("#cboxLoadedContent .cimage img").width()+" height: "+jQuery164("#cboxLoadedContent .cimage img").height());

      
      if(jQuery164("#cboxLoadedContent").height() > (jQuery164(window).height()-120)){
        console.log("height is larger. current height: "+jQuery164("#cboxLoadedContent").height()+" window height: "+jQuery164(window).height());
        old_height = jQuery164("#cboxLoadedContent .cimage img").height();
        old_width = jQuery164("#cboxLoadedContent .cimage img").width();
        new_height = jQuery164(window).height() - jQuery164("#cboxLoadedContent .cimage .caption").height() - 120;
        diff = old_height-new_height;
        multiplier = diff/old_height;
        new_width = old_width - (old_width*multiplier);
        
        console.log("old width: "+old_width+" new width: "+new_width );
        console.log("old height: "+old_height+" new height: "+new_height + " window height: "+jQuery164(window).height());
        
        jQuery164("#cboxLoadedContent .cimage img").width(new_width);
        jQuery164("#cboxLoadedContent .cimage img").attr("width", new_width);
        jQuery164("#cboxLoadedContent .cimage img").height(new_height);
        jQuery164("#cboxLoadedContent .cimage img").attr("height",new_height);
      }
      else if (jQuery164("#cboxLoadedContent").width() > (jQuery164(window).width()-70)){
        console.log("width is larger. current:"+jQuery164("#cboxLoadedContent").width()+" window width:"+jQuery164(window).width());
        new_width = jQuery164(window).width() - 60;
        console.log("new width: "+new_width+ "ww: " +jQuery164(window).width());
        jQuery164("#cboxLoadedContent .cimage img").width(new_width);
        jQuery164("#cboxLoadedContent .cimage img").attr("width", new_width);
        jQuery164("#cboxLoadedContent .cimage img").height("");
        jQuery164("#cboxLoadedContent .cimage img").attr("height", "");
  
      }
      wrap_width=jQuery164("#cboxLoadedContent .cimage img").width()+28;
      console.log("wrapwidth: "+ wrap_width);
      jQuery164.colorbox.resize({width: wrap_width});
      jQuery164("#colorbox").css("overflow","visible");
    });
/*  } */

});