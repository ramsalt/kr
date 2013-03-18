<h1 property="dc:title"><?php print $title; ?></h1>
  
      <meta charset="utf-8" />
    
      
      <!-- jQuery (1.8+, possibly lower too) -->
      <script src="http://utdanning.no/solrservice/contrib/jQuery/jquery.js"></script>
      
      <!-- utdanning.no search framework (use remote version for automatic updates) -->
      <script src="http://utdanning.no/solrservice/js-min/solr-search-full-min.js?ver=11"></script>
      
  	<!-- Your init-script, normally in external JS, but inline for demo-purpose -->
  	<script type="text/javascript">
  	    
  		var Manager; // Search manager object
  		(function ($) { // jQuery => $
  		  $(function () { // On page load
  
                      jQuery.ajax({
                        dataType: "jsonp",
                        cache: true,
                        jsonpCallback: 'ajaxSolrConfigCallback',
                        url: "http://utdanning.no/solrservice/utdanning.no/config/searchpage.php?callback=?",
                        success: function (uno_config) {
                          
  			  uno_config['server']['proxy_filter'] = 'bm_field_evu:true&fq=sm_vid_Ansvarlig:Offentlig';
                            
                            fylker = uno_config['facets']['fylke_vgs'];
                            fylker['target'] = '#facet_fylker';
                            
                            content_types = new Array();
                            content_types['widget'] = 'plain';
                            content_types['facet'] = 'bundle_name';
                            content_types['target'] = '#content_types';
                            content_types['max_facets'] = 10;
  
  
                            uno_config['facets'] = [];
  			  uno_config['facets']['level'] = content_types;
                            uno_config['facets']['fylke_vgs'] = fylker;
  			  uno_config['search']['menu_dependencies']['always'].push(content_types);
  			  uno_config['search']['menu_dependencies']['always'].push(fylker);
  
  			  // Loading the search manager
  			  Manager = AjaxSolr.auxiliary('manager', uno_config);
  
  			  // Connecting search box - uses default HTML-id from uno_config['plain-searchbox']['target'] = "#query"
  			  Manager.addPlainSearch(uno_config);
  
  			  // Adding hitcounter - uses default HTML-id from uno_config['result-count']['target'] = "#result_count"
  			  Manager.addResultCount(uno_config); 
  
  			  // Adding rows per page selector - uses default HTML-id from uno_config['rows-per-page']['target'] = '#resultsperpage';
  			  Manager.addRowsPerPage(uno_config);
  
  			  // Adding pager - uses default HTML-id from uno_config['pager']['target'] = '#navigator';
  			  Manager.addPager(uno_config);
  
  			  // Adding result list - uses default HTML-id from uno_config['search']['target'] = '#hits';
  			  Manager.addResults(uno_config);
  			  
  			  // Adding "You are searching for" area - uses default HTML-id from uno_config['current-search']['target'] = '#selection';
  			  Manager.addCurrentSearch(uno_config);
  
  			  // Adding facets - adds all facets configured in uno_config['facets'], we simplified it in this example
  			  Manager.addFacets(uno_config);
  			  
  			  // Finalize config
  			  Manager.finalizeConfig(uno_config);
  
  			  // Optional, but recommended; loads the results for an empty search
  			  Manager.doRequest();
  
                        } // End loading config
                      });
  		  });
  		})(jQuery);
  	</script>	
  	
  	
  	
  	
  
  	
  	
   
    
  	<!-- 
  	  Searchbox - must have name="query"
  	-->
  	<div class="videreutdanning">
          <form>
           <!-- Logo - must be presented with the search results -->
           <a href="#" class="logoSenter visible-desktop"><img style="height: 35px; margin-bottom: -10px;" id="utdanningno_logo" src="http://utdanning.no/solrservice/design/img/logo-utdanning.png" alt="utdanning.no" title="Søket er levert av utdanning.no" /></a>
  	 <input id="query" name="query" type="search" autocomplete="off" placeholder="Finn utdanning, yrke eller skole" />
  	 <input type="submit" value="Søk" />
          </form>
  	        
  	<!-- Hitcount - displays a hitcount in a <h1> element plus additional info within a <span> -->
          <div id="result_count"></div>
      
  	<!-- Your choices - displays selected facets and text searches in a list -->
  	<div class="yourChoices">
  	  <h2>Dine valg</h2>
  	  <ul id="selection"></ul>
  	</div>
  	<div class="facet_content">
          <!-- Facets -->
          <h2 class="expanded">Nivå</h2>
          <ul class="filterList" id="content_types"></ul>
  
          <h2 class="expanded">Fylke</h2>
          <ul class="filterList" id="facet_fylker"></ul>
      </div>    
          
  	<!-- Results -->
  	<div class="search-result">
  	<ul class="hits" id="hits"></ul>
  	
  	</div>
              
  	<!-- Pager -->
  	<div>
  	  <div id="resultsperpage"></div>
  	  <div id="navigator">
  		<ul class="navigator"></ul>
  	  </div>
  	</div>
   </div>
  
  