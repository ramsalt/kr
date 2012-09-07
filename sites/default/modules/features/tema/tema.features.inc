<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function tema_ctools_plugin_api() {
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
function tema_imagecache_default_presets() {
  $items = array(
    'tema_1_3_stor' => array(
      'presetname' => 'tema_1_3_stor',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '580',
            'height' => '',
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
function tema_node_info() {
  $items = array(
    'tema' => array(
      'name' => t('Tema'),
      'module' => 'features',
      'description' => t('Tema inneholder en samling artikler innenfor det samme temaet. Tema kan legges inn på forsiden.'),
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
function tema_views_api() {
  return array(
    'api' => '2',
  );
}
