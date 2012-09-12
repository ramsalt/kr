<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function kr_job_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'kr-listing_pages-job';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'job' => 'job',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-jobs-block_1' => array(
          'module' => 'views',
          'delta' => 'jobs-block_1',
          'region' => 'right',
          'weight' => 2,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  $export['kr-listing_pages-job'] = $context;
  return $export;
}
