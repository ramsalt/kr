_.extend(DV.Schema.helpers, { 
  resetNavigationState: function(){
    var elements                      = this.elements;
    if (elements.chaptersContainer.length) elements.chaptersContainer[0].id  = '';
    if (elements.navigation.length)        elements.navigation[0].id         = '';
  },
  setActiveChapter: function(chapterId){
    this.elements.chaptersContainer.attr('id','DV-selectedChapter-'+chapterId);
  },
  setActiveAnnotationInNav: function(annotationId){
    if(annotationId){
      this.elements.navigation.attr('id','DV-selectedAnnotation-'+annotationId);
    }else{
      this.elements.navigation.attr('id','');
    }
  }
});
