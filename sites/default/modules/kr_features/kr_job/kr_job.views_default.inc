<?php

/**
 * Implementation of hook_views_default_views().
 */
function kr_job_views_default_views() {
  $views = array();

  // Exported view: alle_stillingskategorier
  $view = new view;
  $view->name = 'alle_stillingskategorier';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'term_data';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Standardverdier */
  $handler = $view->new_display('default', 'Standardverdier', 'default');
  $handler->display->display_options['title'] = 'Stillingskategorier';
  $handler->display->display_options['use_more_text'] = 'mer';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Søk';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Nullstill';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér på';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Felt: Taksonomi: Term */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  /* Sorteringskriterium: Taksonomi: Term */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filtrer: Taksonomi: Vokabular */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    46 => '46',
  );
  $handler->display->display_options['filters']['vid']['expose']['operator'] = FALSE;

  /* Display: Alle stillingskategorier */
  $handler = $view->new_display('block', 'Alle stillingskategorier', 'block_1');
  $translatables['alle_stillingskategorier'] = array(
    t('Standardverdier'),
    t('Stillingskategorier'),
    t('mer'),
    t('Søk'),
    t('Nullstill'),
    t('Sortér på'),
    t('Asc'),
    t('Desc'),
    t('Alle stillingskategorier'),
  );

  $views[$view->name] = $view;

  // Exported view: jobbmarkede
  $view = new view;
  $view->name = 'jobbmarkede';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Standardverdier */
  $handler = $view->new_display('default', 'Standardverdier', 'default');
  $handler->display->display_options['css_class'] = 'jobbliste';
  $handler->display->display_options['use_more_text'] = 'mer';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Søk';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Nullstill';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér på';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementer per side';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Felt: Innhold: Main Image (field_main_image) */
  $handler->display->display_options['fields']['field_main_image_fid']['id'] = 'field_main_image_fid';
  $handler->display->display_options['fields']['field_main_image_fid']['table'] = 'node_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image_fid']['field'] = 'field_main_image_fid';
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_main_image_fid']['format'] = 'v2_forside_h60_linked';
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['group'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['multiple_reversed'] = 0;
  /* Felt: Node: Tittel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
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
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Felt: Innhold: Utlyser (field_job_utlyser) */
  $handler->display->display_options['fields']['field_job_utlyser_value']['id'] = 'field_job_utlyser_value';
  $handler->display->display_options['fields']['field_job_utlyser_value']['table'] = 'node_data_field_job_utlyser';
  $handler->display->display_options['fields']['field_job_utlyser_value']['field'] = 'field_job_utlyser_value';
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_job_utlyser_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_job_utlyser_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_job_utlyser_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['label_type'] = 'none';
  /* Felt: Innhold: Søknadsfrist (field_job_date) */
  $handler->display->display_options['fields']['field_job_date_value']['id'] = 'field_job_date_value';
  $handler->display->display_options['fields']['field_job_date_value']['table'] = 'node_data_field_job_date';
  $handler->display->display_options['fields']['field_job_date_value']['field'] = 'field_job_date_value';
  $handler->display->display_options['fields']['field_job_date_value']['label'] = 'Søknadsfrist';
  $handler->display->display_options['fields']['field_job_date_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_job_date_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_job_date_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_job_date_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['label_type'] = 'custom';
  /* Filtrer: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'job' => 'job',
  );
  /* Filtrer: Innhold: Søknadsfrist (field_job_date) */
  $handler->display->display_options['filters']['field_job_date_value']['id'] = 'field_job_date_value';
  $handler->display->display_options['filters']['field_job_date_value']['table'] = 'node_data_field_job_date';
  $handler->display->display_options['filters']['field_job_date_value']['field'] = 'field_job_date_value';
  $handler->display->display_options['filters']['field_job_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_job_date_value']['allow_null'] = 1;
  $handler->display->display_options['filters']['field_job_date_value']['date_fields'] = array(
    'node_data_field_job_date.field_job_date_value' => 'node_data_field_job_date.field_job_date_value',
  );
  $handler->display->display_options['filters']['field_job_date_value']['default_date'] = 'now';

  /* Display: Premium jobber i en slider */
  $handler = $view->new_display('block', 'Premium jobber i en slider', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Jobbmarkedet';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'jcar jobber';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jcarousel';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtrer: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'job' => 'job',
  );
  /* Filtrer: Innhold: Er en premium utlysning (field_stilling_premium) */
  $handler->display->display_options['filters']['field_stilling_premium_value']['id'] = 'field_stilling_premium_value';
  $handler->display->display_options['filters']['field_stilling_premium_value']['table'] = 'node_data_field_stilling_premium';
  $handler->display->display_options['filters']['field_stilling_premium_value']['field'] = 'field_stilling_premium_value';
  $handler->display->display_options['filters']['field_stilling_premium_value']['value']['value'] = '1';
  $handler->display->display_options['filters']['field_stilling_premium_value']['allow_null'] = 1;
  /* Filtrer: Innhold: Søknadsfrist (field_job_date) */
  $handler->display->display_options['filters']['field_job_date_value']['id'] = 'field_job_date_value';
  $handler->display->display_options['filters']['field_job_date_value']['table'] = 'node_data_field_job_date';
  $handler->display->display_options['filters']['field_job_date_value']['field'] = 'field_job_date_value';
  $handler->display->display_options['filters']['field_job_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_job_date_value']['value']['min'] = '2012-01-01 00:00:00';
  $handler->display->display_options['filters']['field_job_date_value']['value']['max'] = '2012-01-01 00:00:00';
  $handler->display->display_options['filters']['field_job_date_value']['value']['value'] = '2012-01-01 00:00:00';
  $handler->display->display_options['filters']['field_job_date_value']['allow_null'] = 1;
  $handler->display->display_options['filters']['field_job_date_value']['date_fields'] = array(
    'node_data_field_job_date.field_job_date_value' => 'node_data_field_job_date.field_job_date_value',
  );
  $handler->display->display_options['filters']['field_job_date_value']['default_date'] = 'now';

  /* Display: Alle */
  $handler = $view->new_display('block', 'Alle', 'block_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Innhold: Main Image (field_main_image) */
  $handler->display->display_options['fields']['field_main_image_fid']['id'] = 'field_main_image_fid';
  $handler->display->display_options['fields']['field_main_image_fid']['table'] = 'node_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image_fid']['field'] = 'field_main_image_fid';
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_main_image_fid']['format'] = 'v2_stilling_thumb_linked';
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['group'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['multiple_reversed'] = 0;
  /* Felt: Node: Tittel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
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
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Felt: Innhold: Utlyser (field_job_utlyser) */
  $handler->display->display_options['fields']['field_job_utlyser_value']['id'] = 'field_job_utlyser_value';
  $handler->display->display_options['fields']['field_job_utlyser_value']['table'] = 'node_data_field_job_utlyser';
  $handler->display->display_options['fields']['field_job_utlyser_value']['field'] = 'field_job_utlyser_value';
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_job_utlyser_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_job_utlyser_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_job_utlyser_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['label_type'] = 'none';
  /* Felt: Innhold: Søknadsfrist (field_job_date) */
  $handler->display->display_options['fields']['field_job_date_value']['id'] = 'field_job_date_value';
  $handler->display->display_options['fields']['field_job_date_value']['table'] = 'node_data_field_job_date';
  $handler->display->display_options['fields']['field_job_date_value']['field'] = 'field_job_date_value';
  $handler->display->display_options['fields']['field_job_date_value']['label'] = 'Søknadsfrist';
  $handler->display->display_options['fields']['field_job_date_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_job_date_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_job_date_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_job_date_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['label_type'] = 'custom';
  $translatables['jobbmarkede'] = array(
    t('Standardverdier'),
    t('mer'),
    t('Søk'),
    t('Nullstill'),
    t('Sortér på'),
    t('Asc'),
    t('Desc'),
    t('Elementer per side'),
    t('- Alle -'),
    t('Offset'),
    t('Søknadsfrist'),
    t('Premium jobber i en slider'),
    t('Jobbmarkedet'),
    t('Alle'),
  );

  $views[$view->name] = $view;

  // Exported view: jobs
  $view = new view;
  $view->name = 'jobs';
  $view->description = 'Stillingslister';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 0;
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
  /* Felt: Innhold: Main Image (field_main_image) */
  $handler->display->display_options['fields']['field_main_image_fid']['id'] = 'field_main_image_fid';
  $handler->display->display_options['fields']['field_main_image_fid']['table'] = 'node_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image_fid']['field'] = 'field_main_image_fid';
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_main_image_fid']['format'] = 'kr_jobs_block_linked';
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['group'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['multiple_number'] = '1';
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['multiple_from'] = '0';
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['multiple_reversed'] = 0;
  /* Felt: Customfield: PHP-kode */
  $handler->display->display_options['fields']['phpcode']['id'] = 'phpcode';
  $handler->display->display_options['fields']['phpcode']['table'] = 'customfield';
  $handler->display->display_options['fields']['phpcode']['field'] = 'phpcode';
  $handler->display->display_options['fields']['phpcode']['label'] = '';
  $handler->display->display_options['fields']['phpcode']['exclude'] = TRUE;
  $handler->display->display_options['fields']['phpcode']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['phpcode']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['phpcode']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['phpcode']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['phpcode']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['phpcode']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['phpcode']['alter']['html'] = 0;
  $handler->display->display_options['fields']['phpcode']['hide_empty'] = 0;
  $handler->display->display_options['fields']['phpcode']['empty_zero'] = 0;
  $handler->display->display_options['fields']['phpcode']['value'] = '<?php

$words = explode(\' \', $data->node_title);

foreach($words as $word){
    $new_word=str_replace(\'_\',\'\', $word);
    $new_title .= $new_word;

$new_title.=\' \';
}
print trim($new_title);

?>';
  /* Felt: Node: Tittel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[phpcode]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Felt: Innhold: Utlyser (field_job_utlyser) */
  $handler->display->display_options['fields']['field_job_utlyser_value']['id'] = 'field_job_utlyser_value';
  $handler->display->display_options['fields']['field_job_utlyser_value']['table'] = 'node_data_field_job_utlyser';
  $handler->display->display_options['fields']['field_job_utlyser_value']['field'] = 'field_job_utlyser_value';
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['label_type'] = 'none';
  /* Felt: Innhold: Søknadsfrist (field_job_date) */
  $handler->display->display_options['fields']['field_job_date_value']['id'] = 'field_job_date_value';
  $handler->display->display_options['fields']['field_job_date_value']['table'] = 'node_data_field_job_date';
  $handler->display->display_options['fields']['field_job_date_value']['field'] = 'field_job_date_value';
  $handler->display->display_options['fields']['field_job_date_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['label_type'] = 'none';
  /* Sorteringskriterium: Innhold: Søknadsfrist (field_job_date) */
  $handler->display->display_options['sorts']['field_job_date_value']['id'] = 'field_job_date_value';
  $handler->display->display_options['sorts']['field_job_date_value']['table'] = 'node_data_field_job_date';
  $handler->display->display_options['sorts']['field_job_date_value']['field'] = 'field_job_date_value';
  /* Filtrer: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'job' => 'job',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filtrer: Node: Publisert */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtrer: Innhold: Søknadsfrist (field_job_date) */
  $handler->display->display_options['filters']['field_job_date_value']['id'] = 'field_job_date_value';
  $handler->display->display_options['filters']['field_job_date_value']['table'] = 'node_data_field_job_date';
  $handler->display->display_options['filters']['field_job_date_value']['field'] = 'field_job_date_value';
  $handler->display->display_options['filters']['field_job_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_job_date_value']['expose']['operator'] = FALSE;
  $handler->display->display_options['filters']['field_job_date_value']['date_fields'] = array(
    'node_data_field_job_date.field_job_date_value' => 'node_data_field_job_date.field_job_date_value',
  );
  $handler->display->display_options['filters']['field_job_date_value']['default_date'] = 'now';

  /* Display: Blokk */
  $handler = $view->new_display('block', 'Blokk', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Ledige stillinger';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_job_utlyser_value' => 'field_job_utlyser_value',
    'field_job_date_value' => 'field_job_date_value',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Innhold: Main Image (field_main_image) */
  $handler->display->display_options['fields']['field_main_image_fid']['id'] = 'field_main_image_fid';
  $handler->display->display_options['fields']['field_main_image_fid']['table'] = 'node_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image_fid']['field'] = 'field_main_image_fid';
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['link_to_node'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_main_image_fid']['format'] = 'kr_jobs_block_linked';
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['group'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['multiple_number'] = '1';
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['multiple_from'] = '0';
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['multiple_reversed'] = 0;
  /* Felt: Customfield: PHP-kode */
  $handler->display->display_options['fields']['phpcode']['id'] = 'phpcode';
  $handler->display->display_options['fields']['phpcode']['table'] = 'customfield';
  $handler->display->display_options['fields']['phpcode']['field'] = 'phpcode';
  $handler->display->display_options['fields']['phpcode']['label'] = '';
  $handler->display->display_options['fields']['phpcode']['exclude'] = TRUE;
  $handler->display->display_options['fields']['phpcode']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['phpcode']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['phpcode']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['phpcode']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['phpcode']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['phpcode']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['phpcode']['alter']['html'] = 0;
  $handler->display->display_options['fields']['phpcode']['hide_empty'] = 0;
  $handler->display->display_options['fields']['phpcode']['empty_zero'] = 0;
  $handler->display->display_options['fields']['phpcode']['value'] = '<?php

$words = explode(\' \', $data->node_title);

foreach($words as $word){
  if(strlen($word)>13){
    $new_word=str_replace(\'_\',\'- \', $word);
    $new_title .= $new_word;
  }else{
    $new_word=str_replace(\'_\',\'\', $word);
    $new_title .= $new_word;
}
$new_title.=\' \';
}
print trim($new_title);

?>';
  /* Felt: Node: Tittel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[phpcode]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Felt: Innhold: Utlyser (field_job_utlyser) */
  $handler->display->display_options['fields']['field_job_utlyser_value']['id'] = 'field_job_utlyser_value';
  $handler->display->display_options['fields']['field_job_utlyser_value']['table'] = 'node_data_field_job_utlyser';
  $handler->display->display_options['fields']['field_job_utlyser_value']['field'] = 'field_job_utlyser_value';
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['label_type'] = 'none';
  /* Felt: Innhold: Søknadsfrist (field_job_date) */
  $handler->display->display_options['fields']['field_job_date_value']['id'] = 'field_job_date_value';
  $handler->display->display_options['fields']['field_job_date_value']['table'] = 'node_data_field_job_date';
  $handler->display->display_options['fields']['field_job_date_value']['field'] = 'field_job_date_value';
  $handler->display->display_options['fields']['field_job_date_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_job_date_value']['format'] = 'short';

  /* Display: Nyhetsbrev Blokk */
  $handler = $view->new_display('block', 'Nyhetsbrev Blokk', 'block_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Customfield: PHP-kode */
  $handler->display->display_options['fields']['phpcode']['id'] = 'phpcode';
  $handler->display->display_options['fields']['phpcode']['table'] = 'customfield';
  $handler->display->display_options['fields']['phpcode']['field'] = 'phpcode';
  $handler->display->display_options['fields']['phpcode']['label'] = '';
  $handler->display->display_options['fields']['phpcode']['exclude'] = TRUE;
  $handler->display->display_options['fields']['phpcode']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['phpcode']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['phpcode']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['phpcode']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['phpcode']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['phpcode']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['phpcode']['alter']['html'] = 0;
  $handler->display->display_options['fields']['phpcode']['hide_empty'] = 0;
  $handler->display->display_options['fields']['phpcode']['empty_zero'] = 0;
  $handler->display->display_options['fields']['phpcode']['value'] = '<?php

$words = explode(\' \', $data->node_title);

foreach($words as $word){
  if(strlen($word)>13){
    $new_word=str_replace(\'_\',\'- \', $word);
    $new_title .= $new_word;
  }else{
    $new_word=str_replace(\'_\',\'\', $word);
    $new_title .= $new_word;
}
$new_title.=\' \';
}
print trim($new_title);

?>';
  /* Felt: Node: Tittel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[phpcode]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Felt: Innhold: Utlyser (field_job_utlyser) */
  $handler->display->display_options['fields']['field_job_utlyser_value']['id'] = 'field_job_utlyser_value';
  $handler->display->display_options['fields']['field_job_utlyser_value']['table'] = 'node_data_field_job_utlyser';
  $handler->display->display_options['fields']['field_job_utlyser_value']['field'] = 'field_job_utlyser_value';
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['label_type'] = 'none';
  /* Felt: Innhold: Søknadsfrist (field_job_date) */
  $handler->display->display_options['fields']['field_job_date_value']['id'] = 'field_job_date_value';
  $handler->display->display_options['fields']['field_job_date_value']['table'] = 'node_data_field_job_date';
  $handler->display->display_options['fields']['field_job_date_value']['field'] = 'field_job_date_value';
  $handler->display->display_options['fields']['field_job_date_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['label_type'] = 'none';

  /* Display: Nettside */
  $handler = $view->new_display('page', 'Nettside', 'page_1');
  $handler->display->display_options['path'] = 'stilling';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Nye jobber';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['menu']['name'] = 'primary-links';
  $translatables['jobs'] = array(
    t('Standardverdier'),
    t('mer'),
    t('Søk'),
    t('Nullstill'),
    t('Sortér på'),
    t('Asc'),
    t('Desc'),
    t('[phpcode]'),
    t('Blokk'),
    t('Ledige stillinger'),
    t('Nyhetsbrev Blokk'),
    t('Nettside'),
  );

  $views[$view->name] = $view;

  // Exported view: ledige_stillinger
  $view = new view;
  $view->name = 'ledige_stillinger';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Standardverdier */
  $handler = $view->new_display('default', 'Standardverdier', 'default');
  $handler->display->display_options['title'] = 'Ledige stillinger';
  $handler->display->display_options['css_class'] = 'stillinger';
  $handler->display->display_options['use_more_text'] = 'mer';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Søk';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Nullstill';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér på';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 20;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementer per side';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Felt: Innhold: Main Image (field_main_image) */
  $handler->display->display_options['fields']['field_main_image_fid']['id'] = 'field_main_image_fid';
  $handler->display->display_options['fields']['field_main_image_fid']['table'] = 'node_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image_fid']['field'] = 'field_main_image_fid';
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
  $handler->display->display_options['fields']['field_main_image_fid']['format'] = 'kr_jobs_block_linked';
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['group'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['multiple_number'] = '1';
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['multiple_from'] = '0';
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['multiple_reversed'] = 0;
  /* Felt: Node: Tittel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
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
  /* Felt: Innhold: Utlyser (field_job_utlyser) */
  $handler->display->display_options['fields']['field_job_utlyser_value']['id'] = 'field_job_utlyser_value';
  $handler->display->display_options['fields']['field_job_utlyser_value']['table'] = 'node_data_field_job_utlyser';
  $handler->display->display_options['fields']['field_job_utlyser_value']['field'] = 'field_job_utlyser_value';
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_job_utlyser_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['label_type'] = 'none';
  /* Felt: Innhold: Søknadsfrist (field_job_date) */
  $handler->display->display_options['fields']['field_job_date_value']['id'] = 'field_job_date_value';
  $handler->display->display_options['fields']['field_job_date_value']['table'] = 'node_data_field_job_date';
  $handler->display->display_options['fields']['field_job_date_value']['field'] = 'field_job_date_value';
  $handler->display->display_options['fields']['field_job_date_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_job_date_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_job_date_value']['label_type'] = 'none';
  /* Felt: Innhold: Er en premium utlysning (field_stilling_premium) */
  $handler->display->display_options['fields']['field_stilling_premium_value']['id'] = 'field_stilling_premium_value';
  $handler->display->display_options['fields']['field_stilling_premium_value']['table'] = 'node_data_field_stilling_premium';
  $handler->display->display_options['fields']['field_stilling_premium_value']['field'] = 'field_stilling_premium_value';
  $handler->display->display_options['fields']['field_stilling_premium_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stilling_premium_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stilling_premium_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stilling_premium_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stilling_premium_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stilling_premium_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stilling_premium_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stilling_premium_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stilling_premium_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stilling_premium_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stilling_premium_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stilling_premium_value']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_stilling_premium_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_stilling_premium_value']['label_type'] = 'none';
  /* Sorteringskriterium: Innhold: Er en premium utlysning (field_stilling_premium) */
  $handler->display->display_options['sorts']['field_stilling_premium_value']['id'] = 'field_stilling_premium_value';
  $handler->display->display_options['sorts']['field_stilling_premium_value']['table'] = 'node_data_field_stilling_premium';
  $handler->display->display_options['sorts']['field_stilling_premium_value']['field'] = 'field_stilling_premium_value';
  $handler->display->display_options['sorts']['field_stilling_premium_value']['order'] = 'DESC';
  /* Sorteringskriterium: Innhold: Søknadsfrist (field_job_date) */
  $handler->display->display_options['sorts']['field_job_date_value']['id'] = 'field_job_date_value';
  $handler->display->display_options['sorts']['field_job_date_value']['table'] = 'node_data_field_job_date';
  $handler->display->display_options['sorts']['field_job_date_value']['field'] = 'field_job_date_value';
  /* Argument: Taksonomi: Term */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['wildcard_substitution'] = 'Siste nytt';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['validate_type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['name']['validate_options']['vids'] = array(
    46 => 46,
    43 => 0,
    44 => 0,
    45 => 0,
  );
  $handler->display->display_options['arguments']['name']['validate_options']['type'] = 'name';
  $handler->display->display_options['arguments']['name']['validate_options']['transform'] = 0;
  $handler->display->display_options['arguments']['name']['glossary'] = 0;
  $handler->display->display_options['arguments']['name']['ignorecase'] = 0;
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  $handler->display->display_options['arguments']['name']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['name']['add_table'] = 0;
  $handler->display->display_options['arguments']['name']['require_value'] = 0;
  /* Filtrer: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'job' => 'job',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filtrer: Innhold: Søknadsfrist (field_job_date) */
  $handler->display->display_options['filters']['field_job_date_value']['id'] = 'field_job_date_value';
  $handler->display->display_options['filters']['field_job_date_value']['table'] = 'node_data_field_job_date';
  $handler->display->display_options['filters']['field_job_date_value']['field'] = 'field_job_date_value';
  $handler->display->display_options['filters']['field_job_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_job_date_value']['expose']['operator'] = FALSE;
  $handler->display->display_options['filters']['field_job_date_value']['date_fields'] = array(
    'node_data_field_job_date.field_job_date_value' => 'node_data_field_job_date.field_job_date_value',
  );
  $handler->display->display_options['filters']['field_job_date_value']['default_date'] = 'now';

  /* Display: Ledige stillinger */
  $handler = $view->new_display('panel_pane', 'Ledige stillinger', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'name' => array(
      'type' => 'context',
      'context' => 'term.name',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Stillingsterm',
    ),
  );
  $translatables['ledige_stillinger'] = array(
    t('Standardverdier'),
    t('Ledige stillinger'),
    t('mer'),
    t('Søk'),
    t('Nullstill'),
    t('Sortér på'),
    t('Asc'),
    t('Desc'),
    t('Elementer per side'),
    t('- Alle -'),
    t('Offset'),
    t('Siste nytt'),
    t('View panes'),
  );

  $views[$view->name] = $view;

  // Exported view: premium_stillinger
  $view = new view;
  $view->name = 'premium_stillinger';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Standardverdier */
  $handler = $view->new_display('default', 'Standardverdier', 'default');
  $handler->display->display_options['title'] = 'Utlyste stillinger';
  $handler->display->display_options['css_class'] = 'premiumstillingsblock';
  $handler->display->display_options['use_more_text'] = 'mer';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Søk';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Nullstill';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér på';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = 4;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Felt: Innhold: Main Image (field_main_image) */
  $handler->display->display_options['fields']['field_main_image_fid']['id'] = 'field_main_image_fid';
  $handler->display->display_options['fields']['field_main_image_fid']['table'] = 'node_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image_fid']['field'] = 'field_main_image_fid';
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
  $handler->display->display_options['fields']['field_main_image_fid']['format'] = 'premium_stilling_liste_linked';
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['group'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['multiple_number'] = '1';
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['multiple_from'] = '0';
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['multiple_reversed'] = 0;
  /* Felt: Node: Tittel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
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
  /* Felt: Innhold: Utlyser (field_job_utlyser) */
  $handler->display->display_options['fields']['field_job_utlyser_value']['id'] = 'field_job_utlyser_value';
  $handler->display->display_options['fields']['field_job_utlyser_value']['table'] = 'node_data_field_job_utlyser';
  $handler->display->display_options['fields']['field_job_utlyser_value']['field'] = 'field_job_utlyser_value';
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_job_utlyser_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_job_utlyser_value']['label_type'] = 'none';
  /* Sorteringskriterium: Innhold: Søknadsfrist (field_job_date) */
  $handler->display->display_options['sorts']['field_job_date_value']['id'] = 'field_job_date_value';
  $handler->display->display_options['sorts']['field_job_date_value']['table'] = 'node_data_field_job_date';
  $handler->display->display_options['sorts']['field_job_date_value']['field'] = 'field_job_date_value';
  $handler->display->display_options['sorts']['field_job_date_value']['order'] = 'DESC';
  /* Filtrer: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'job' => 'job',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filtrer: Innhold: Søknadsfrist (field_job_date) */
  $handler->display->display_options['filters']['field_job_date_value']['id'] = 'field_job_date_value';
  $handler->display->display_options['filters']['field_job_date_value']['table'] = 'node_data_field_job_date';
  $handler->display->display_options['filters']['field_job_date_value']['field'] = 'field_job_date_value';
  $handler->display->display_options['filters']['field_job_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_job_date_value']['expose']['operator'] = FALSE;
  $handler->display->display_options['filters']['field_job_date_value']['date_fields'] = array(
    'node_data_field_job_date.field_job_date_value' => 'node_data_field_job_date.field_job_date_value',
  );
  $handler->display->display_options['filters']['field_job_date_value']['default_date'] = 'now';

  /* Display: Utlyste stillinger */
  $handler = $view->new_display('block', 'Utlyste stillinger', 'block_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'premiumstillingsblock stillinger';
  $translatables['premium_stillinger'] = array(
    t('Standardverdier'),
    t('Utlyste stillinger'),
    t('mer'),
    t('Søk'),
    t('Nullstill'),
    t('Sortér på'),
    t('Asc'),
    t('Desc'),
  );

  $views[$view->name] = $view;

  // Exported view: stillinger_kartlayer
  $view = new view;
  $view->name = 'stillinger_kartlayer';
  $view->description = '';
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
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'openlayers_wkt',
    'other_lat' => 'field_stilling_geopos_openlayers_wkt',
    'other_lon' => 'field_stilling_geopos_openlayers_wkt',
    'openlayers_wkt' => 'field_stilling_geopos_openlayers_wkt',
    'other_top' => 'field_stilling_geopos_openlayers_wkt',
    'other_right' => 'field_stilling_geopos_openlayers_wkt',
    'other_bottom' => 'field_stilling_geopos_openlayers_wkt',
    'other_left' => 'field_stilling_geopos_openlayers_wkt',
    'name_field' => 'title',
    'keep_orig_name_field' => 1,
    'description_field' => 'field_rel_kommune_nid',
    'keep_orig_desc_field' => 1,
  );
  /* Felt: Innhold: Hvor er dette (field_stilling_geopos) */
  $handler->display->display_options['fields']['field_stilling_geopos_openlayers_wkt']['id'] = 'field_stilling_geopos_openlayers_wkt';
  $handler->display->display_options['fields']['field_stilling_geopos_openlayers_wkt']['table'] = 'node_data_field_stilling_geopos';
  $handler->display->display_options['fields']['field_stilling_geopos_openlayers_wkt']['field'] = 'field_stilling_geopos_openlayers_wkt';
  $handler->display->display_options['fields']['field_stilling_geopos_openlayers_wkt']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stilling_geopos_openlayers_wkt']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stilling_geopos_openlayers_wkt']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stilling_geopos_openlayers_wkt']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stilling_geopos_openlayers_wkt']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stilling_geopos_openlayers_wkt']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stilling_geopos_openlayers_wkt']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stilling_geopos_openlayers_wkt']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stilling_geopos_openlayers_wkt']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stilling_geopos_openlayers_wkt']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stilling_geopos_openlayers_wkt']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stilling_geopos_openlayers_wkt']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_stilling_geopos_openlayers_wkt']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_stilling_geopos_openlayers_wkt']['format'] = 'openlayers_wkt';
  /* Felt: Node: Tittel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
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
  /* Felt: Innhold: Kommune (field_rel_kommune) */
  $handler->display->display_options['fields']['field_rel_kommune_nid']['id'] = 'field_rel_kommune_nid';
  $handler->display->display_options['fields']['field_rel_kommune_nid']['table'] = 'node_data_field_rel_kommune';
  $handler->display->display_options['fields']['field_rel_kommune_nid']['field'] = 'field_rel_kommune_nid';
  $handler->display->display_options['fields']['field_rel_kommune_nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_rel_kommune_nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_rel_kommune_nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_rel_kommune_nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_rel_kommune_nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_rel_kommune_nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_rel_kommune_nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_rel_kommune_nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_rel_kommune_nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_rel_kommune_nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_rel_kommune_nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_rel_kommune_nid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_rel_kommune_nid']['label_type'] = 'none';
  /* Argument: Taksonomi: Term */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['wildcard_substitution'] = 'Siste nytt';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['name']['default_argument_options']['term_page'] = 0;
  $handler->display->display_options['arguments']['name']['default_argument_options']['node'] = 0;
  $handler->display->display_options['arguments']['name']['default_argument_options']['limit'] = 0;
  $handler->display->display_options['arguments']['name']['default_argument_options']['vids'] = array(
    43 => 0,
    44 => 0,
    45 => 0,
    46 => 0,
  );
  $handler->display->display_options['arguments']['name']['validate_type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['name']['validate_options']['vids'] = array(
    46 => 46,
    43 => 0,
    44 => 0,
    45 => 0,
  );
  $handler->display->display_options['arguments']['name']['validate_options']['type'] = 'name';
  $handler->display->display_options['arguments']['name']['validate_options']['transform'] = 0;
  $handler->display->display_options['arguments']['name']['glossary'] = 0;
  $handler->display->display_options['arguments']['name']['ignorecase'] = 0;
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  $handler->display->display_options['arguments']['name']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['name']['add_table'] = 0;
  $handler->display->display_options['arguments']['name']['require_value'] = 0;
  /* Filtrer: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'job' => 'job',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filtrer: Innhold: Hvor er dette (field_stilling_geopos) */
  $handler->display->display_options['filters']['field_stilling_geopos_openlayers_wkt']['id'] = 'field_stilling_geopos_openlayers_wkt';
  $handler->display->display_options['filters']['field_stilling_geopos_openlayers_wkt']['table'] = 'node_data_field_stilling_geopos';
  $handler->display->display_options['filters']['field_stilling_geopos_openlayers_wkt']['field'] = 'field_stilling_geopos_openlayers_wkt';
  $handler->display->display_options['filters']['field_stilling_geopos_openlayers_wkt']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_stilling_geopos_openlayers_wkt']['expose']['operator'] = FALSE;
  $handler->display->display_options['filters']['field_stilling_geopos_openlayers_wkt']['case'] = 0;
  /* Filtrer: Innhold: Søknadsfrist (field_job_date) */
  $handler->display->display_options['filters']['field_job_date_value']['id'] = 'field_job_date_value';
  $handler->display->display_options['filters']['field_job_date_value']['table'] = 'node_data_field_job_date';
  $handler->display->display_options['filters']['field_job_date_value']['field'] = 'field_job_date_value';
  $handler->display->display_options['filters']['field_job_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_job_date_value']['allow_null'] = 1;
  $handler->display->display_options['filters']['field_job_date_value']['date_fields'] = array(
    'node_data_field_job_date.field_job_date_value' => 'node_data_field_job_date.field_job_date_value',
  );
  $handler->display->display_options['filters']['field_job_date_value']['default_date'] = 'now';

  /* Display: OpenLayers Data */
  $handler = $view->new_display('openlayers', 'OpenLayers Data', 'openlayers_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'openlayers_wkt',
    'other_lat' => 'field_stilling_geopos_openlayers_wkt',
    'other_lon' => 'field_stilling_geopos_openlayers_wkt',
    'openlayers_wkt' => 'field_stilling_geopos_openlayers_wkt',
    'other_top' => 'field_stilling_geopos_openlayers_wkt',
    'other_right' => 'field_stilling_geopos_openlayers_wkt',
    'other_bottom' => 'field_stilling_geopos_openlayers_wkt',
    'other_left' => 'field_stilling_geopos_openlayers_wkt',
    'name_field' => 'title',
    'keep_orig_name_field' => 1,
    'description_field' => 'field_rel_kommune_nid',
    'keep_orig_desc_field' => 1,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Blokk */
  $handler = $view->new_display('block', 'Blokk', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['preset'] = 'stillingskartpreset';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['stillinger_kartlayer'] = array(
    t('Standardverdier'),
    t('mer'),
    t('Søk'),
    t('Nullstill'),
    t('Sortér på'),
    t('Asc'),
    t('Desc'),
    t('Siste nytt'),
    t('OpenLayers Data'),
    t('Blokk'),
  );

  $views[$view->name] = $view;

  // Exported view: stillingskategorier_med_teller
  $view = new view;
  $view->name = 'stillingskategorier_med_teller';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Standardverdier */
  $handler = $view->new_display('default', 'Standardverdier', 'default');
  $handler->display->display_options['title'] = 'Stillingskategorier';
  $handler->display->display_options['use_more_text'] = 'mer';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Søk';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Nullstill';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér på';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name' => 'name',
    'nid' => 'nid',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  /* Felt: Taksonomi: Term */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['name']['alter']['text'] = '<a href="/stillinger/[name]">[name]</a>';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 0;
  /* Felt: Node: NID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['text'] = ' ([nid])';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Filtrer: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'job' => 'job',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filtrer: Innhold: Søknadsfrist (field_job_date) */
  $handler->display->display_options['filters']['field_job_date_value']['id'] = 'field_job_date_value';
  $handler->display->display_options['filters']['field_job_date_value']['table'] = 'node_data_field_job_date';
  $handler->display->display_options['filters']['field_job_date_value']['field'] = 'field_job_date_value';
  $handler->display->display_options['filters']['field_job_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_job_date_value']['expose']['operator'] = FALSE;
  $handler->display->display_options['filters']['field_job_date_value']['date_fields'] = array(
    'node_data_field_job_date.field_job_date_value' => 'node_data_field_job_date.field_job_date_value',
  );
  $handler->display->display_options['filters']['field_job_date_value']['default_date'] = 'now';
  /* Filtrer: Taksonomi: Vokabular */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    46 => '46',
  );

  /* Display: Blokk */
  $handler = $view->new_display('block', 'Blokk', 'block_1');
  $translatables['stillingskategorier_med_teller'] = array(
    t('Standardverdier'),
    t('Stillingskategorier'),
    t('mer'),
    t('Søk'),
    t('Nullstill'),
    t('Sortér på'),
    t('Asc'),
    t('Desc'),
    t('<a href="/stillinger/[name]">[name]</a>'),
    t(' ([nid])'),
    t('Blokk'),
  );

  $views[$view->name] = $view;

  return $views;
}
