<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function tema_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tema';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'tema' => 'tema',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-Tema-block_1' => array(
          'module' => 'views',
          'delta' => 'Tema-block_1',
          'region' => 'under_content',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  $export['tema'] = $context;
  return $export;
}
