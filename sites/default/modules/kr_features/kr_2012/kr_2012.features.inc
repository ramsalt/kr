<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function kr_2012_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "boxes" && $api == "box") {
    return array("version" => 1);
  }
  elseif ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function kr_2012_imagecache_default_presets() {
  $items = array(
    'siste_saker' => array(
      'presetname' => 'siste_saker',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '78',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'v2_forside_b170' => array(
      'presetname' => 'v2_forside_b170',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '170',
            'height' => '115',
          ),
        ),
      ),
    ),
    'v2_forside_stor' => array(
      'presetname' => 'v2_forside_stor',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '500',
            'height' => '',
            'upscale' => 0,
          ),
        ),
        '1' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_crop',
          'data' => array(
            'width' => '468',
            'height' => '310',
            'xoffset' => 'center',
            'yoffset' => 'center',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function kr_2012_views_api() {
  return array(
    'api' => '2',
  );
}
