<?php

/**
 * Implementation of hook_views_default_views().
 */
function utgivelser_views_default_views() {
  $views = array();

  // Exported view: XML_export_av_node
  $view = new view;
  $view->name = 'XML_export_av_node';
  $view->description = 'XML export av node til indesign';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = 'xml_export_av_node';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Standardverdier */
  $handler = $view->new_display('default', 'Standardverdier', 'default');
  $handler->display->display_options['use_more_text'] = 'mer';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Søk';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Nullstill';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér på';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Felt: Node: Tittel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'tittel';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Felt: Innhold: Info om utlyseren (field_teaser) */
  $handler->display->display_options['fields']['field_teaser_value']['id'] = 'field_teaser_value';
  $handler->display->display_options['fields']['field_teaser_value']['table'] = 'node_data_field_teaser';
  $handler->display->display_options['fields']['field_teaser_value']['field'] = 'field_teaser_value';
  $handler->display->display_options['fields']['field_teaser_value']['label'] = 'teaser';
  $handler->display->display_options['fields']['field_teaser_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_teaser_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_teaser_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_teaser_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['label_type'] = 'custom';
  $handler->display->display_options['fields']['field_teaser_value']['format'] = 'plain';
  /* Felt: Innhold: Byline ukeavis (field_byline_ukeavis) */
  $handler->display->display_options['fields']['field_byline_ukeavis_value']['id'] = 'field_byline_ukeavis_value';
  $handler->display->display_options['fields']['field_byline_ukeavis_value']['table'] = 'node_data_field_byline_ukeavis';
  $handler->display->display_options['fields']['field_byline_ukeavis_value']['field'] = 'field_byline_ukeavis_value';
  $handler->display->display_options['fields']['field_byline_ukeavis_value']['label'] = 'byline';
  $handler->display->display_options['fields']['field_byline_ukeavis_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_byline_ukeavis_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_byline_ukeavis_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_byline_ukeavis_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_byline_ukeavis_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_byline_ukeavis_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_byline_ukeavis_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_byline_ukeavis_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_byline_ukeavis_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_byline_ukeavis_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_byline_ukeavis_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_byline_ukeavis_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_byline_ukeavis_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_byline_ukeavis_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_byline_ukeavis_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_byline_ukeavis_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_byline_ukeavis_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_byline_ukeavis_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_byline_ukeavis_value']['label_type'] = 'custom';
  /* Felt: Node: Brødtekst */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'node_revisions';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'innhold';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  /* Argument: Node: NID */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['wildcard_substitution'] = 'Siste nytt';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;

  /* Display: Strøm */
  $handler = $view->new_display('feed', 'Strøm', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_xml';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'node/%/export.xml';
  $translatables['XML_export_av_node'] = array(
    t('Standardverdier'),
    t('mer'),
    t('Søk'),
    t('Nullstill'),
    t('Sortér på'),
    t('Asc'),
    t('Desc'),
    t('tittel'),
    t('teaser'),
    t('byline'),
    t('innhold'),
    t('Siste nytt'),
    t('Strøm'),
  );

  $views[$view->name] = $view;

  return $views;
}
