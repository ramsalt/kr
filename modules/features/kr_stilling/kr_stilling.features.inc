<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function kr_stilling_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function kr_stilling_imagecache_default_presets() {
  $items = array(
    'stilling_thumb' => array(
      'presetname' => 'stilling_thumb',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '50',
            'height' => '',
            'upscale' => 1,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function kr_stilling_node_info() {
  $items = array(
    'stillingsannonse' => array(
      'name' => t('Stillingsannonse'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Stillingstittel'),
      'has_body' => '1',
      'body_label' => t('Utlysningstekst'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function kr_stilling_views_api() {
  return array(
    'api' => '2',
  );
}
