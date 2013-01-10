<?php print $page_header; ?>
  <div id="search_wrapper">
    <div class="left">
      <div id="currentsearch">
       <div id="currentsearch"> </div>
        <h2>Dine valg</h2>
      </div>
      <div id="level">
        <h2>Nivå</h2>
      </div>
      <div id="sublevel">
        <h2>Nivå</h2>
      </div>
      <div id="fagomrade"></div>
      <div id="adminarea">
        <h2>Fylke</h2>
      </div>    
    </div>
    <div class="main_content">
      <div class="main_content_inner">
        <div id="logo"></div>
        <div id="search"></div>
        <div id="pager-header"></div>
        <div id="result"></div>
        <div id="pager"></div>
        <div>
          <span id="per_page"></span>
          <span id="sorting"></span>
        </div>
      </div>
    </div>
  </div>
  <script src="http://service.utdanning.no/finn/scripts/ajax-solr-complete.min.js"></script>
  
  <script>
  (function($) {
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
console.log('doh');
    });
  })(jQuery);
  </script>