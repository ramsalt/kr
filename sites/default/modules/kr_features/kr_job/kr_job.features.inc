<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function kr_job_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "openlayers" && $api == "openlayers_presets") {
    return array("version" => 1);
  }
  elseif ($module == "openlayers" && $api == "openlayers_styles") {
    return array("version" => 1);
  }
  elseif ($module == "page_manager" && $api == "pages_default") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function kr_job_imagecache_default_presets() {
  $items = array(
    'kr_jobs_block' => array(
      'presetname' => 'kr_jobs_block',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '45',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'premium_stilling_liste' => array(
      'presetname' => 'premium_stilling_liste',
      'actions' => array(
        '0' => array(
          'weight' => '-10',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '129',
            'height' => '',
            'upscale' => 0,
          ),
        ),
        '1' => array(
          'weight' => '-9',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '',
            'height' => '56',
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
function kr_job_node_info() {
  $items = array(
    'job' => array(
      'name' => t('Stilling'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Tittel'),
      'has_body' => '1',
      'body_label' => t('Brødtekst'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function kr_job_views_api() {
  return array(
    'api' => '2',
  );
}
