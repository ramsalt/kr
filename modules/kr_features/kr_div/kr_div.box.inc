<?php

/**
 * Implementation of hook_default_box().
 */
function kr_div_default_box() {
  $export = array();
  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'endre_rekkefolgen_pa_forsiden';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'endre rekkefølgen på forsiden';
  $box->options = array(
    'body' => '<a href="/forsiderediger" class="edit-forsiderekkefolge">Endre forsiden</a>',
    'format' => '2',
  );

  $export['endre_rekkefolgen_pa_forsiden'] = $box;
  return $export;
}
