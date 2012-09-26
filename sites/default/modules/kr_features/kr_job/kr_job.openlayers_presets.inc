<?php

/**
 * Implementation of hook_openlayers_presets().
 */
function kr_job_openlayers_presets() {
  $export = array();
  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'stillingskartpreset';
  $openlayers_presets->title = 'Stillingskart preset';
  $openlayers_presets->description = 'Stillingskart preser';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => '',
    'css_path' => '',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '16.347656249346, 65.730626491676',
        'zoom' => '4',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'stillinger_kartlayer_openlayers_1' => 'stillinger_kartlayer_openlayers_1',
        ),
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
      ),
      'openlayers_behavior_panzoombar' => array(),
    ),
    'default_layer' => 'google_normal',
    'layers' => array(
      'google_normal' => 'google_normal',
      'stillinger_kartlayer_openlayers_1' => 'stillinger_kartlayer_openlayers_1',
    ),
    'layer_styles' => array(
      'stillinger_kartlayer_openlayers_1' => array(
        'default' => 'default',
        'select' => 'default',
        'temporary' => 'default',
      ),
    ),
    'layer_activated' => array(
      'stillinger_kartlayer_openlayers_1' => 'stillinger_kartlayer_openlayers_1',
    ),
    'layer_switcher' => array(
      'stillinger_kartlayer_openlayers_1' => 'stillinger_kartlayer_openlayers_1',
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'arbeidsicon',
      'select' => 'arbeidsicon',
      'temporary' => 'arbeidsicon',
    ),
  );

  $export['stillingskartpreset'] = $openlayers_presets;
  return $export;
}
