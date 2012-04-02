<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function bildegalleri_ctools_plugin_api() {
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
function bildegalleri_imagecache_default_presets() {
  $items = array(
    'slider_stort' => array(
      'presetname' => 'slider_stort',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '1200',
            'height' => '1200',
            'upscale' => 0,
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
function bildegalleri_node_info() {
  $items = array(
    'bildegalleri' => array(
      'name' => t('Bildegalleri'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Tittel'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function bildegalleri_views_api() {
  return array(
    'api' => '2',
  );
}
