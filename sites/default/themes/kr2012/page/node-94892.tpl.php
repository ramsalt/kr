<?php print $page_header; ?>
<?php
print "Dummy text for testing.(node-nid)";
?>
<section>
<h1 property="dc:title"><?php print $title; ?></h1>
<div class="node-content">
  <?php print $content ?>
</div>
<html>
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <title>Søk i utdanninger - utdanning.no</title>
  <link rel="stylesheet" href="http://service.utdanning.no/finn/fancybox/jquery.fancybox-1.3.4.css">
  <link rel="stylesheet" href="http://service.utdanning.no/finn/theme.css">
  <link rel="stylesheet" href="http://service.utdanning.no/finn/ajax-solr.css">
   <link type="text/css" rel="stylesheet" media="all" href="http://www.kommunal-rapport.no/sites/default/files/css/css_31965bcaf0982507861587fc96e10d6b.css" />
<link type="text/css" rel="stylesheet" media="screen" href="http://www.kommunal-rapport.no/sites/default/files/css/css_7fd0a90a0227366f56bd90f64ee9dfdb.css" />
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
         <div id="pace"></div>
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
         filter : {fq : '(collection:utdanning AND (termEvu:ja OR labelEvu:Ja OR labelGeouavhengig:Nettbasert OR termGeouavhengig:ja)) OR collection:course'},
         per_page : 25,
        show_facet_numbers : true,
        show_selected_facets : true,
        style : 'table',
        fields : [
            {label : 'Tittel', field : 'title'},
            {label : 'Nivå', field : 'niva'},
            {label : 'Fylke', field : 'fylke'},
            {label : 'Undervisningssted', field : 'undervisningssted', href :'linkRelHttp_x003A__x002F__x002F_utdanning.no_x002F_org_x0023_teachingOrg' }
           // {label : tableLabels.studiested, field : 'labelOrgName', href : 'linkRelHttp_x003A__x002F__x002F_utdanning.no_x002F_org_x0023_teachingOrg'},

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
      $('#adminarea').facet('fylke');
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
    });
  })(jQuery);
  </script>
</body>
</html>
</section>
<?php print $page_footer;