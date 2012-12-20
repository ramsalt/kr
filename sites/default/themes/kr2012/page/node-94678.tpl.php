<?php print $page_header; ?>
<?php
print "Dummy text for testing.(node-nid)";
?>
<section>
<html>
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <title>Søk i utdanninger - utdanning.no</title>
  <link rel="stylesheet" href="http://service.utdanning.no/finn/fancybox/jquery.fancybox-1.3.4.css">
  <link rel="stylesheet" href="http://service.utdanning.no/finn/theme.css">
  <link rel="stylesheet" href="http://service.utdanning.no/finn/ajax-solr.css">
</head>

<body>
  <h1>Søk i utdanninger - utdanning.no</h1>
  <div id="search_wrapper">
    <div class="left">
      <div id="currentsearch">
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
        <form onSubmit="alert('BØ!!')">
          <div id="search"></div>
        </form>
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
  <script src="http://service.utdanning.no/finn/scripts/jquery.js"></script>
    <script src="http://service.utdanning.no/finn/scripts/ajax-solr-complete.min.js"></script>
  <script>
  (function($) {
    $(function() {
      $.search({
        filter : {fq : '(collection:utdanning AND (termEvu:ja OR labelGeouavhengig:Ja OR termGeouavhengig:ja)) OR collection:course'},
        per_page : 25,
        collection : 'dismax',
        show_facet_numbers : true,
        show_selected_facets : true,
        fields : [
          {label : 'Nivå', field : 'niva'},
          {label : 'Fylke', field : 'fylke'},
          {label : 'Undervisningssted', field : 'undervisningssted'}
        ]
      });

      // Current search
      $('#currentsearch').currentSearch();

      // Facets
      $('#level').facet('niva');
      $('#sublevel').facet('underniva');
      $('#fagomrade').facet('fagomrade');
      $('#undervisningsform').facet('undervisningsform');
      <?php // $('#pace').facet('pace'); //heltid-deltid kan være interesant for EVU?>
      $('#adminarea').facet('fylke');
      <?php // $('#org').facet('undervisningssted'); ?>

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
  })(jQuery);
  </script>
</body>
</html>
</section>
<?php print $page_footer;