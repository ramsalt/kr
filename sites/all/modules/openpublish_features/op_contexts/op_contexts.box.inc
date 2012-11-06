<?php

/**
 * Implementation of hook_default_box().
 */
function op_contexts_default_box() {
  $export = array();

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-3709d30d';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Økonomibloggen';
  $box->options = array(
    'body' => '<a href="http://www.kommunal-rapport.no/kategori/okonomi/okonomibloggen"><img src=" http://www.kommunal-rapport.no/sites/default/files/okonomibloggen.jpg"width="100%"></a>',
    'format' => '2',
  );
  $export['box-3709d30d'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-4bb00d6c';
  $box->plugin_key = 'simple';
  $box->title = 'Kjøp papirutgaven';
  $box->description = 'Kjøp papirutgaven';
  $box->options = array(
    'body' => '<a href="https://kommunalrapport.buyandread.com"><img width="99%" src="http://static.buyandread.com/thumbnail/kommunalrapport/kommunalrapport.jpg"></a>',
    'format' => '2',
  );
  $export['box-4bb00d6c'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-5c93aa7';
  $box->plugin_key = 'simple';
  $box->title = 'Kjøp ordførerkartet her';
  $box->description = 'Ordførerkart';
  $box->options = array(
    'body' => '<a href="http://www.kommunal-rapport.no/innhold/her_kan_du_kjope_ordforerkartet"><img src="http://www.kommunal-rapport.no/sites/default/files/plakatbilde.jpg" width="100%"></a>',
    'format' => '2',
  );
  $export['box-5c93aa7'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-61c5e380';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'skolebarometeret';
  $box->options = array(
    'body' => '<a href="http://www.kommunal-rapport.no/topics/Skolebarometeret"><img src="http://www.kommunal-rapport.no/sites/default/files/skolebarometeret.jpg" width="100%"></a>',
    'format' => '2',
  );
  $export['box-61c5e380'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-645d1de3';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Egenannonse-dråpe';
  $box->options = array(
    'body' => '<iframe src="http://player.vimeo.com/video/34122700?title=0&amp;byline=0&amp;portrait=0&amp;color=ffffff&amp;autoplay=1&amp;loop=1" width="190" height="127" frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe>',
    'format' => '2',
  );
  $export['box-645d1de3'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-756aa15a';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Norske rådmenn';
  $box->options = array(
    'body' => '<a href="http://www.kommunal-rapport.no/artikkel/R_dmenn_i_norske_kommuner"><img src="http://www.kommunal-rapport.no/sites/default/files/raadmenn.jpg" width="100%"></a>',
    'format' => '2',
  );
  $export['box-756aa15a'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-7b6d4ea9';
  $box->plugin_key = 'simple';
  $box->title = 'Åpenhet i Kommune-Norge';
  $box->description = 'Åpenhet';
  $box->options = array(
    'body' => '<a href="artikkel/sjekk_hvor_apen_din_kommune_er"><img src="http://a.tiles.mapbox.com/kommunalrapport/1.0.0/kommunalrapport.openhetny_90b287/6/32/43.png " width="100%"></a>
<a href="http://www.kommunal-rapport.no/artikkel/apenhetsindeksen_2011">Les alle sakene her</a>',
    'format' => '2',
  );
  $export['box-7b6d4ea9'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-86cdd488';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Lederloggen';
  $box->options = array(
    'body' => '<a href="http://www.kommunal-rapport.no/kategori/arbeidsliv_og_ledelse/lederloggen"><img src=" http://www.kommunal-rapport.no/sites/default/files/lederloggen_0.jpg"width="100%"></a>',
    'format' => '2',
  );
  $export['box-86cdd488'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-ad57121c';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Norske byer';
  $box->options = array(
    'body' => '<a href="artikkel/byer_i_norge"><img src=" http://www.kommunal-rapport.no/sites/default/files/byer_ny.jpg" width="100%"></a>',
    'format' => '2',
  );
  $export['box-ad57121c'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-c7e511c';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Quiz';
  $box->options = array(
    'body' => '<a href="http://www.kommunal-rapport.no/artikkel/hva_husker_du_fra_denne_uka_7"><img src=" http://www.kommunal-rapport.no/sites/default/files/quiz_ny.jpg"width="100%"></a>

',
    'format' => '2',
  );
  $export['box-c7e511c'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-e57de1f';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Ordførerleksikon';
  $box->options = array(
    'body' => '<a href=" http://www.kommunal-rapport.no/ordf%C3%B8rere"><img src="http://www.kommunal-rapport.no/sites/default/files/ordforerleksikon_ny.jpg"width="100%"></a>',
    'format' => '2',
  );
  $export['box-e57de1f'] = $box;

  return $export;
}
