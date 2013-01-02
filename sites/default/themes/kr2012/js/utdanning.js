(function ($) {
	$(document).ready(function() {
        $.search({
          filter : {collection : 'utdanning'},
          per_page : 25,
          collection : 'dismax',
          use_lightbox : false,
          show_facet_numbers : true,
        });
        // Current search
        $('#currentsearch').currentSearch();
        // Facets
        $('#level').facet('niva');
        $('#sublevel').facet('underniva');
        $('#fagomrade').facet('fagomrade');
        $('#undervisningsform').facet('undervisningsform');
        $('#adminarea').facet('fylke');
        // Search box
        $('#search').searchBox();
        // Search results
        $('#pager-header').searchRows();
        $('#result').searchResult();
        // Pager
        $('#pager').searchPager();
        $('#per_page').searchPerPage();
        $('#sorting').searchSort();
        $.doRequest();
      });
}(jQuery));