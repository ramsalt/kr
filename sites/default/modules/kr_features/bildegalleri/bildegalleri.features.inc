<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function bildegalleri_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function bildegalleri_node_info() {
  $items = array(
    'bildegalleri' => array(
      'name' => t('Bildegalleri'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Tittel'),
      'has_body' => '1',
      'body_label' => t('Beskrivelse'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
