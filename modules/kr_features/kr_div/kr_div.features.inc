<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function kr_div_imagecache_default_presets() {
  $items = array(
    'article_liten_slideshow' => array(
      'presetname' => 'article_liten_slideshow',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '40',
            'height' => '40',
          ),
        ),
      ),
    ),
    'article_stor_slideshow' => array(
      'presetname' => 'article_stor_slideshow',
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
    'forside_forstebilde' => array(
      'presetname' => 'forside_forstebilde',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '250',
            'height' => '',
            'upscale' => 1,
          ),
        ),
      ),
    ),
    'forside_totilfire' => array(
      'presetname' => 'forside_totilfire',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '166px',
            'height' => '',
            'upscale' => 1,
          ),
        ),
      ),
    ),
    'w280px' => array(
      'presetname' => 'w280px',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '280px',
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
 * Implementation of hook_views_api().
 */
function kr_div_views_api() {
  return array(
    'api' => '2',
  );
}
