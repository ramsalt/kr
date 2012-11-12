<?php

/**
 * Implementation of hook_default_box().
 */
function kr_2012_default_box() {
  $export = array();

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

  return $export;
}
