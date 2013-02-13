

Drupal.behaviors.kalkulatorNode = function (context) {
  var elements = ['.node-type-kalkulator .node .node-content', '.embedded-node-type-kalkulator .embedded-node .content'];
  
  var values = Drupal.settings.kalkulator.values;
  var headers = values.shift();
  
  $.each(elements, function(index, item) {
    var regex = /\[search:(\w+)\]/g;
    var element = $(item);
    var input = element.html(); 
    if(regex.test(input)) {
      element.html(input.replace(regex, '<input type="text" id="kalk-search-$1" class="calc-search" search-col="$1" />'));
    }
    
    var regex = /\[out:(\w+):([a-z|A-Z|(0-9)|\xE5|\xF8|\xE6|\xC5|\xC6|\xD8]*)\]/g; 
    var input = element.html(); 
    if(regex.test(input)) {
      element.html(input.replace(regex, '<span class="replace-text" replace-col="$1" id="replace-text-$1">$2</span>'));
    }
    
    element.find('.calc-search').keyup(function () {
      var row = kalkulator_search_values($(this).attr('search-col'), $(this).val(), values);
      if(row > -1) {
        for(var id in headers) {
        	$('.replace-text[replace-col="'+headers[id]+'"]').text(values[row][id]);
        } 
      }
    });
    
    function kalkulator_search_values(col, find, values) {
      for (var i = 0; i < values.length; i++) {
        if (values[i][jQuery.inArray(col, headers)].toLowerCase() == find.toLowerCase()) return i;
      }
      return -1;
    }  
  
  });
  

  
};