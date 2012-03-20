<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function kr_newsletter_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation:admin/content/scs_node_selection
  $menu_links['navigation:admin/content/scs_node_selection'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'admin/content/scs_node_selection',
    'router_path' => 'admin/content/scs_node_selection',
    'link_title' => 'Create newsletter issue',
    'options' => array(
      'query' => 'sort=desc&order=Skrevet',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'node/add',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Create newsletter issue');


  return $menu_links;
}
