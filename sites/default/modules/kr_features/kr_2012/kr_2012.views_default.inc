<?php

/**
 * Implementation of hook_views_default_views().
 */
function kr_2012_views_default_views() {
  $views = array();

  // Exported view: siste_saker
  $view = new view;
  $view->name = 'siste_saker';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->core = 6;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Standardverdier', 'default');
  $handler->override_option('fields', array(
    'field_main_image_fid' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 1,
      'empty_zero' => 0,
      'hide_alter_empty' => 1,
      'link_to_node' => 0,
      'label_type' => 'none',
      'format' => 'siste_saker_linked',
      'multiple' => array(
        'group' => 1,
        'multiple_number' => '1',
        'multiple_from' => '0',
        'multiple_reversed' => 0,
      ),
      'exclude' => 0,
      'id' => 'field_main_image_fid',
      'table' => 'node_data_field_main_image',
      'field' => 'field_main_image_fid',
      'relationship' => 'none',
    ),
    'title' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'hide_alter_empty' => 1,
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'created' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'created',
      'table' => 'node',
      'field' => 'created',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'article' => 'article',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'views_content_cache',
    'keys' => array(
      'comment' => array(
        'changed' => 0,
      ),
      'node' => array(
        'article' => 'article',
        'poll' => 0,
        'barometer' => 0,
        'op_image' => 0,
        'bildegalleri' => 0,
        'blog' => 0,
        'book' => 0,
        'chart' => 0,
        'ekstern_blogg' => 0,
        'eksternt_blogginnlegg' => 0,
        'multichoice' => 0,
        'author' => 0,
        'kalkulator' => 0,
        'kommune' => 0,
        'simplenews' => 0,
        'ordforer' => 0,
        'page' => 0,
        'panel' => 0,
        'quiz' => 0,
        'resource' => 0,
        'job' => 0,
        'table' => 0,
        'tema' => 0,
        'topichub' => 0,
        'webform' => 0,
      ),
    ),
    'results_min_lifespan' => '-1',
    'results_max_lifespan' => '-1',
    'output_min_lifespan' => '21600',
    'output_max_lifespan' => '21600',
  ));
  $handler->override_option('title', 'Siste saker');
  $handler->override_option('css_class', 'siste-saker');
  $handler->override_option('items_per_page', 5);
  $handler->override_option('style_plugin', 'list');
  $handler->override_option('row_options', array(
    'inline' => array(
      'field_main_image_fid' => 'field_main_image_fid',
    ),
    'separator' => '',
    'hide_empty' => 0,
  ));
  $handler = $view->new_display('block', 'Siste saker block', 'block_1');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);

  $views[$view->name] = $view;

  return $views;
}
