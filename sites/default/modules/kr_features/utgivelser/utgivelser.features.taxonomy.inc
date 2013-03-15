<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function utgivelser_taxonomy_default_vocabularies() {
  return array(
    'utgave' => array(
      'name' => 'Utgave',
      'description' => '',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '0',
      'multiple' => '0',
      'required' => '0',
      'tags' => '0',
      'module' => 'features_utgave',
      'weight' => '0',
      'type' => NULL,
      'nodes' => array(),
    ),
  );
}
