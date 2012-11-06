<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function kr2012_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openpublish-node_detail-article';
  $context->description = '';
  $context->tag = 'OpenPublish Detail Page';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'article' => 'article',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-siste_saker-block_1' => array(
          'module' => 'views',
          'delta' => 'siste_saker-block_1',
          'region' => 'right',
          'weight' => 0,
        ),
        'views-bilde_slider_node-block_1' => array(
          'module' => 'views',
          'delta' => 'bilde_slider_node-block_1',
          'region' => 'over_content',
          'weight' => 0,
        ),
        'kr_diverse-1' => array(
          'module' => 'kr_diverse',
          'delta' => 1,
          'region' => 'over_content',
          'weight' => 1,
        ),
        'disqus-disqus_comments' => array(
          'module' => 'disqus',
          'delta' => 'disqus_comments',
          'region' => 'under_content',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('OpenPublish Detail Page');

  $export['openpublish-node_detail-article'] = $context;
  return $export;
}
