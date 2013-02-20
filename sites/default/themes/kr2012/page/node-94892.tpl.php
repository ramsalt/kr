<h1 property="dc:title"><?php print $title; ?></h1>
  <div id="search_wrapper">
    <div class="left">
      <div id="currentsearch">
       <div id="currentsearch"> </div>
        <h2>Dine valg</h2>
      </div>
      <p><div id="level">
        <h2>Nivå</h2>
      </div></p>
      <div id="sublevel">
        <h2>Nivå</h2>
      </div>
      <div id="fagomrade"></div>
      <p><div id="adminarea">
        <h2>Fylke</h2>
      </div> </p>   
    </div>
    <div class="main_content">
      <div class="main_content_inner">
        <div id="logo"></div>
        <p><div id="search"></div></p>
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
        filter : {fq : '(collection:utdanning AND (termEvu:ja OR labelGeouavhengig:Ja OR termGeouavhengig:ja)) OR collection:course'},
        per_page : 25,
        collection : 'dismax',
        use_lightbox : false,
        show_facet_numbers : true,
        fields : [
                 {label : 'Nivå', field : 'niva'},
                 {label : 'Fylke', field : 'fylke'},
                 {label : 'Undervisningssted', field : 'undervisningssted', href :'linkRelHttp_x003A__x002F__x002F_utdanning.no_x002F_org_x0023_teachingOrg' },
               ]
      });
      // Current search
      $('#currentsearch').currentSearch();
      // Facets
      $('#level').facet('niva');
      $('#sublevel').facet('underniva');
      $('#fagomrade').facet('fagomrade');
      $('#undervisningsform').facet('undervisningsform');
      $('#pace').facet('pace');
      // $('#adminarea').facet('fylke');
      $('#org').facet('undervisningssted');
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