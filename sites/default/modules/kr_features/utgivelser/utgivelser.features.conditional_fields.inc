<?php

/**
 * Implementation of hook_conditional_fields_default_fields().
 */
function utgivelser_conditional_fields_default_fields() {
$items = array();
$items[] = array (
  'control_field_name' => 'field_kanal',
  'field_name' => 'field_byline_ukeavis',
  'type' => 'article',
  'trigger_values' => 
  array (
    'Ukeavis' => 'Ukeavis',
  ),
);
$items[] = array (
  'control_field_name' => 'field_kanal',
  'field_name' => 'field_sidetall',
  'type' => 'article',
  'trigger_values' => 
  array (
    'Ukeavis' => 'Ukeavis',
  ),
);
return $items;
}
