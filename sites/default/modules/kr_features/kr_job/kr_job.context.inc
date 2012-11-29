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
    'context_condition_theme' => array(
      'values' => array(
        'kr2011' => 'kr2011',
      ),
    ),
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
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['kr-listing_pages-job'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'kr2012-stilling';
  $context->description = '';
  $context->tag = 'node';
  $context->conditions = array(
    'context_condition_theme' => array(
      'values' => array(
        'kr2012' => 'kr2012',
      ),
    ),
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
        'cck_blocks-field_stilling_geopos' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_stilling_geopos',
          'region' => 'right',
          'weight' => 0,
        ),
      ),
      'layout' => 'default',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('node');
  $export['kr2012-stilling'] = $context;

  return $export;
}
