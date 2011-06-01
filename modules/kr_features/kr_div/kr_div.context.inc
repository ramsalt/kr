<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function kr_div_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'kr_innlogget_forside';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
        'editor' => 'editor',
        'web editor' => 'web editor',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-endre_rekkefolgen_pa_forsiden' => array(
          'module' => 'boxes',
          'delta' => 'endre_rekkefolgen_pa_forsiden',
          'region' => 'left',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  $export['kr_innlogget_forside'] = $context;
  return $export;
}
