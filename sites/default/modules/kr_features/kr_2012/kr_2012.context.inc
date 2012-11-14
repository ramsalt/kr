<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function kr_2012_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ny_forside';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'context_condition_theme' => array(
      'values' => array(
        'kr2012' => 'kr2012',
      ),
    ),
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-forside-block_1' => array(
          'module' => 'views',
          'delta' => 'forside-block_1',
          'region' => 'one_one',
          'weight' => 0,
        ),
        'views-forside-block_2' => array(
          'module' => 'views',
          'delta' => 'forside-block_2',
          'region' => 'one_one',
          'weight' => 1,
        ),
        'boxes-box-61c5e380' => array(
          'module' => 'boxes',
          'delta' => 'box-61c5e380',
          'region' => 'one_two',
          'weight' => 0,
        ),
        'block-10' => array(
          'module' => 'block',
          'delta' => 10,
          'region' => 'one_two',
          'weight' => 1,
        ),
        'views-Kommentarutdrag-block_1' => array(
          'module' => 'views',
          'delta' => 'Kommentarutdrag-block_1',
          'region' => 'one_three',
          'weight' => 0,
        ),
      ),
      'layout' => 'columns',
    ),
  );
  $context->condition_mode = 1;
  $export['ny_forside'] = $context;

  return $export;
}
