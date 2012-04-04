jQuery164(document).ready(function() {

jQuery164(".flexslider").flexslider({
  slideshow: "false"
});
  
  if(!jQuery164.browser.msie){
    jQuery164(".colorboks1").colorbox({
      rel: "colorboks1",
      transition:"fade",
      inline:true,
      scalePhotos: "true",
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
      
      max_width = jQuery164("#cboxLoadedContent").width();
      max_height = jQuery164("#cboxLoadedContent").height();
      max_height = max_height - jQuery164("#cboxLoadedContent .cimage .caption").height() - 20;
      console.log("width: "+max_width+" height: "+max_height);

      
      if(jQuery164("#cboxLoadedContent").height() > (jQuery164(window).height()-120)){
        console.log("height is larger "+jQuery164(window).height());
        new_height = jQuery164(window).height() - jQuery164("#cboxLoadedContent .cimage .caption").height() - 120;
        console.log("new height: "+new_height);
        jQuery164("#cboxLoadedContent .cimage img").width("");
        jQuery164("#cboxLoadedContent .cimage img").attr("width", "");
        jQuery164("#cboxLoadedContent .cimage img").height(new_height);
        jQuery164("#cboxLoadedContent .cimage img").attr("height",new_height);
      }
      else if (jQuery164("#cboxLoadedContent").width() > (jQuery164(window).width()-70)){
        console.log("width is larger "+jQuery164(window).width());
        new_width = jQuery164(window).width() - 60;
        console.log("new width: "+new_width);
        jQuery164("#cboxLoadedContent .cimage img").width(new_width);
        jQuery164("#cboxLoadedContent .cimage img").attr("width", new_width);
        jQuery164("#cboxLoadedContent .cimage img").height("");
        jQuery164("#cboxLoadedContent .cimage img").attr("height", "");
  
      }
      wrap_width=jQuery164("#cboxLoadedContent .cimage img").width()+28;
      console.log("ww: "+ wrap_width);
      jQuery164.colorbox.resize({width: wrap_width});
      jQuery164("#colorbox").css("overflow","visible");
    });
  }

});