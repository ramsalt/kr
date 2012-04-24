<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function bildegalleri_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bildegalleri';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'bildegalleri' => 'bildegalleri',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-Bildegalleri-block_2' => array(
          'module' => 'views',
          'delta' => 'Bildegalleri-block_2',
          'region' => 'left',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  $export['bildegalleri'] = $context;
  return $export;
}
