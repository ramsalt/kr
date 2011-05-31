<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function kr_stilling_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'kr_stilling_detail';
  $context->description = '';
  $context->tag = 'kr';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'stillingsannonse' => 'stillingsannonse',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'breadcrumb' => 'stillinger',
    'menu' => 'stillinger',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('kr');

  $export['kr_stilling_detail'] = $context;
  return $export;
}
