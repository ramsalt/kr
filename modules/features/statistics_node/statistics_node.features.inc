<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function statistics_node_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function statistics_node_node_info() {
  $items = array(
    'chart' => array(
      'name' => t('Chart'),
      'module' => 'features',
      'description' => t('Add a chart with values and specify how you wish to present it.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
