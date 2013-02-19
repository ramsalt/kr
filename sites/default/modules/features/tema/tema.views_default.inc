<?php

/**
 * Implementation of hook_views_default_views().
 */
function tema_views_default_views() {
  $views = array();

  // Exported view: Tema
  $view = new view;
  $view->name = 'Tema';
  $view->description = 'Viser alle saker under ett tema';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = '';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  /* Relasjon: Innhold: Artikler (field_tema_saker) */
  $handler->display->display_options['relationships']['field_tema_saker_nid']['id'] = 'field_tema_saker_nid';
  $handler->display->display_options['relationships']['field_tema_saker_nid']['table'] = 'node_data_field_tema_saker';
  $handler->display->display_options['relationships']['field_tema_saker_nid']['field'] = 'field_tema_saker_nid';
  $handler->display->display_options['relationships']['field_tema_saker_nid']['required'] = 1;
  $handler->display->display_options['relationships']['field_tema_saker_nid']['delta'] = '-1';
  /* Felt: Node: Tittel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_tema_saker_nid';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Felt: Innhold: Main Image (field_main_image) */
  $handler->display->display_options['fields']['field_main_image_fid']['id'] = 'field_main_image_fid';
  $handler->display->display_options['fields']['field_main_image_fid']['table'] = 'node_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image_fid']['field'] = 'field_main_image_fid';
  $handler->display->display_options['fields']['field_main_image_fid']['relationship'] = 'field_tema_saker_nid';
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_main_image_fid']['format'] = 'forside_galleri_liten_linked';
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['group'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['multiple_number'] = '1';
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['multiple_from'] = '0';
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['multiple_reversed'] = 0;
  /* Felt: Innhold: Info om utlyseren (field_teaser) */
  $handler->display->display_options['fields']['field_teaser_value']['id'] = 'field_teaser_value';
  $handler->display->display_options['fields']['field_teaser_value']['table'] = 'node_data_field_teaser';
  $handler->display->display_options['fields']['field_teaser_value']['field'] = 'field_teaser_value';
  $handler->display->display_options['fields']['field_teaser_value']['relationship'] = 'field_tema_saker_nid';
  $handler->display->display_options['fields']['field_teaser_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_teaser_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['label_type'] = 'none';
  /* Felt: Node: Lenke */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['relationship'] = 'field_tema_saker_nid';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view_node']['text'] = 'Les hele saken';
  /* Argument: Node: NID */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['wildcard_substitution'] = 'Siste nytt';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'blog' => 0,
    'poll' => 0,
    'article' => 0,
    'author' => 0,
    'op_image' => 0,
    'resource' => 0,
    'barometer' => 0,
    'simplenews' => 0,
    'chart' => 0,
    'table' => 0,
    'bildegalleri' => 0,
    'job' => 0,
    'multichoice' => 0,
    'quiz' => 0,
    'panel' => 0,
    'book' => 0,
    'eksternt_blogginnlegg' => 0,
    'ekstern_blogg' => 0,
    'kommune' => 0,
    'ordforer' => 0,
    'page' => 0,
    'tema' => 0,
    'topichub' => 0,
    'webform' => 0,
  );
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;

  /* Display: Ingress av saker */
  $handler = $view->new_display('block', 'Ingress av saker', 'block_1');
  $translatables['Tema'] = array(
    t('Standardverdier'),
    t('mer'),
    t('Søk'),
    t('Nullstill'),
    t('Sortér på'),
    t('Asc'),
    t('Desc'),
    t('Artikler'),
    t('Les hele saken'),
    t('Siste nytt'),
    t('Ingress av saker'),
  );

  $views[$view->name] = $view;

  return $views;
}
