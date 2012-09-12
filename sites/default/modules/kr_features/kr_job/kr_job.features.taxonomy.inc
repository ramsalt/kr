<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function kr_job_taxonomy_default_vocabularies() {
  return array(
    'stillingskategorier' => array(
      'name' => 'Stillingskategorier',
      'description' => '',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '1',
      'multiple' => '0',
      'required' => '0',
      'tags' => '0',
      'module' => 'features_stillingskategorier',
      'weight' => '0',
      'nodes' => array(
        'job' => 'job',
      ),
    ),
  );
}
