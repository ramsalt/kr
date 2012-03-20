<?php

/**
 * Implementation of hook_strongarm().
 */
function kr_openx_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openx_delivery_url';
  $strongarm->value = 'openx.dev.ramsalt.com/delivery';

  $export['openx_delivery_url'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openx_delivery_url_https';
  $strongarm->value = 'openx.dev.ramsalt.com/delivery';

  $export['openx_delivery_url_https'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openx_site_vars';
  $strongarm->value = array();

  $export['openx_site_vars'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openx_zones';
  $strongarm->value = array(
    0 => array(
      'id' => '3',
      'name' => '150px*X',
      'delete' => 'slett',
    ),
    1 => array(
      'id' => '1',
      'name' => '580px*X',
      'delete' => 'slett',
    ),
  );

  $export['openx_zones'] = $strongarm;
  return $export;
}
