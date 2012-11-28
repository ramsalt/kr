<?php

/**
 * Implementation of hook_views_default_views().
 */
function kr_2012_views_default_views() {
  $views = array();

  // Exported view: economic_blogg
  $view = new view;
  $view->name = 'economic_blogg';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Standardverdier */
  $handler = $view->new_display('default', 'Standardverdier', 'default');
  $handler->display->display_options['title'] = 'Økonomibloggen';
  $handler->display->display_options['use_more_text'] = 'mer';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'views_content_cache';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Søk';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Nullstill';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér på';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = 1;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Topptekst: Global: Text area */
  $handler->display->display_options['header']['text']['id'] = 'area';
  $handler->display->display_options['header']['text']['table'] = 'views';
  $handler->display->display_options['header']['text']['field'] = 'area';
  $handler->display->display_options['header']['text']['label'] = '';
  $handler->display->display_options['header']['text']['empty'] = FALSE;
  $handler->display->display_options['header']['text']['content'] = 'Økonomiredaktør Ole Petter Pedersen skriver hver tirsdag og fredag Økonomibloggen';
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
  /* Felt: Innhold: Info om utlyseren (field_teaser) */
  $handler->display->display_options['fields']['field_teaser_value']['id'] = 'field_teaser_value';
  $handler->display->display_options['fields']['field_teaser_value']['table'] = 'node_data_field_teaser';
  $handler->display->display_options['fields']['field_teaser_value']['field'] = 'field_teaser_value';
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
  $handler->display->display_options['fields']['view_node']['text'] = 'Les Økonomibloggen';
  /* Sorteringskriterium: Node: Klistret */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sorteringskriterium: Node: Innleggsdato */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filtrer: Node: Publisert */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtrer: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
    'blog' => 'blog',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filtrer: Taksonomi: Term ID (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = array(
    0 => '1694',
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = FALSE;
  $handler->display->display_options['filters']['term_node_tid_depth']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['term_node_tid_depth']['vid'] = '43';
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '0';

  /* Display: Siste i økonomibloggen */
  $handler = $view->new_display('block', 'Siste i økonomibloggen', 'block_1');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Topptekst: Global: Text area */
  $handler->display->display_options['header']['text']['id'] = 'area';
  $handler->display->display_options['header']['text']['table'] = 'views';
  $handler->display->display_options['header']['text']['field'] = 'area';
  $handler->display->display_options['header']['text']['label'] = '';
  $handler->display->display_options['header']['text']['empty'] = FALSE;
  $handler->display->display_options['header']['text']['content'] = 'Økonomiredaktør Ole Petter Pedersen skriver hver tirsdag og fredag Økonomibloggen';
  $translatables['economic_blogg'] = array(
    t('Standardverdier'),
    t('Økonomibloggen'),
    t('mer'),
    t('Søk'),
    t('Nullstill'),
    t('Sortér på'),
    t('Asc'),
    t('Desc'),
    t('Økonomiredaktør Ole Petter Pedersen skriver hver tirsdag og fredag Økonomibloggen'),
    t('Les Økonomibloggen'),
    t('Siste i økonomibloggen'),
  );

  $views[$view->name] = $view;

  // Exported view: forside
  $view = new view;
  $view->name = 'forside';
  $view->description = 'Viser saker på forsiden v2.0';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Forside */
  $handler = $view->new_display('default', 'Forside', 'default');
  $handler->display->display_options['css_class'] = 'newslist';
  $handler->display->display_options['use_more_text'] = 'mer';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Søk';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Nullstill';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér på';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Felt: Node: Tittel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]';
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
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['group'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['multiple_number'] = '1';
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['multiple_from'] = '0';
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['multiple_reversed'] = 0;
  /* Felt: Innhold: Info om utlyseren (field_teaser) */
  $handler->display->display_options['fields']['field_teaser_value']['id'] = 'field_teaser_value';
  $handler->display->display_options['fields']['field_teaser_value']['table'] = 'node_data_field_teaser';
  $handler->display->display_options['fields']['field_teaser_value']['field'] = 'field_teaser_value';
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
  /* Felt: DraggableViews: Rekkefølge */
  $handler->display->display_options['fields']['value0']['id'] = 'value0';
  $handler->display->display_options['fields']['value0']['table'] = 'draggableviews_structure_node0';
  $handler->display->display_options['fields']['value0']['field'] = 'value0';
  /* Sorteringskriterium: DraggableViews: Rekkefølge */
  $handler->display->display_options['sorts']['value0']['id'] = 'value0';
  $handler->display->display_options['sorts']['value0']['table'] = 'draggableviews_structure_node0';
  $handler->display->display_options['sorts']['value0']['field'] = 'value0';
  /* Sorteringskriterium: Node: Klistret */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sorteringskriterium: Node: Oppdatert dato */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Sorteringskriterium: Node: Innleggsdato */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sorteringskriterium: Node: Tittel */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Argument: Taksonomi: Term */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['wildcard_substitution'] = 'Siste nytt';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
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
    'article' => 'article',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filtrer: Node: Publisert */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtrer: Node: Oppdatert dato */
  $handler->display->display_options['filters']['changed']['id'] = 'changed';
  $handler->display->display_options['filters']['changed']['table'] = 'node';
  $handler->display->display_options['filters']['changed']['field'] = 'changed';
  $handler->display->display_options['filters']['changed']['operator'] = '>';
  $handler->display->display_options['filters']['changed']['value']['value'] = '-60 days';
  $handler->display->display_options['filters']['changed']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['changed']['expose']['operator'] = FALSE;

  /* Display: Sak 1 */
  $handler = $view->new_display('block', 'Sak 1', 'block_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'newslist sak-1';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_main_image_fid']['format'] = 'v2_forside_stor_linked';
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
  /* Felt: Innhold: Info om utlyseren (field_teaser) */
  $handler->display->display_options['fields']['field_teaser_value']['id'] = 'field_teaser_value';
  $handler->display->display_options['fields']['field_teaser_value']['table'] = 'node_data_field_teaser';
  $handler->display->display_options['fields']['field_teaser_value']['field'] = 'field_teaser_value';
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

  /* Display: Sak 2-3 */
  $handler = $view->new_display('block', 'Sak 2-3', 'block_2');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'newslist sak-2';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_main_image_fid']['format'] = 'v2_forside_b170_linked';
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
  /* Felt: Innhold: Info om utlyseren (field_teaser) */
  $handler->display->display_options['fields']['field_teaser_value']['id'] = 'field_teaser_value';
  $handler->display->display_options['fields']['field_teaser_value']['table'] = 'node_data_field_teaser';
  $handler->display->display_options['fields']['field_teaser_value']['field'] = 'field_teaser_value';
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

  /* Display: Sak 4-6 */
  $handler = $view->new_display('block', 'Sak 4-6', 'block_3');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'newslist sak-4';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '3';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_main_image_fid']['format'] = 'v2_forside_b86_linked';
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
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Felt: Innhold: Info om utlyseren (field_teaser) */
  $handler->display->display_options['fields']['field_teaser_value']['id'] = 'field_teaser_value';
  $handler->display->display_options['fields']['field_teaser_value']['table'] = 'node_data_field_teaser';
  $handler->display->display_options['fields']['field_teaser_value']['field'] = 'field_teaser_value';
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

  /* Display: Rediger forside */
  $handler = $view->new_display('page', 'Rediger forside', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'draggabletable';
  $handler->display->display_options['style_options']['columns'] = array(
    'value0' => 'value0',
    'title' => 'title',
    'value0_1' => 'value0_1',
  );
  $handler->display->display_options['style_options']['default'] = -1;
  $handler->display->display_options['style_options']['info'] = array(
    'value0' => array(
      'sortable' => 0,
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'separator' => '',
    ),
    'value0_1' => array(
      'sortable' => 0,
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['tabledrag_order'] = array(
    'field' => 'value0',
    'handler' => 'native',
  );
  $handler->display->display_options['style_options']['tabledrag_order_visible'] = array(
    'visible' => 'visible',
  );
  $handler->display->display_options['style_options']['tabledrag_hierarchy'] = array(
    'field' => 'none',
    'handler' => 'native',
  );
  $handler->display->display_options['style_options']['tabledrag_hierarchy_visible'] = array(
    'visible' => 0,
  );
  $handler->display->display_options['style_options']['draggableviews_depth_limit'] = '0';
  $handler->display->display_options['style_options']['draggableviews_repair'] = array(
    0 => 'repair',
    'repair' => 'repair',
  );
  $handler->display->display_options['style_options']['tabledrag_expand'] = array(
    'expand_links' => 0,
    'collapsed' => 0,
    'by_uid' => 0,
  );
  $handler->display->display_options['style_options']['draggableviews_extensions'] = array(
    'extension_top' => '3',
    'extension_bottom' => '3',
  );
  $handler->display->display_options['style_options']['tabledrag_lock'] = array(
    'lock' => 0,
  );
  $handler->display->display_options['style_options']['draggableviews_default_on_top'] = '1';
  $handler->display->display_options['style_options']['draggableviews_arguments'] = array(
    'use_args' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: DraggableViews: Rekkefølge */
  $handler->display->display_options['fields']['value0']['id'] = 'value0';
  $handler->display->display_options['fields']['value0']['table'] = 'draggableviews_structure_node0';
  $handler->display->display_options['fields']['value0']['field'] = 'value0';
  $handler->display->display_options['fields']['value0']['label'] = 'Nr';
  $handler->display->display_options['fields']['value0']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['value0']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['value0']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['value0']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['value0']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['value0']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['value0']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['value0']['alter']['html'] = 0;
  $handler->display->display_options['fields']['value0']['hide_empty'] = 0;
  $handler->display->display_options['fields']['value0']['empty_zero'] = 0;
  $handler->display->display_options['fields']['value0']['hide_alter_empty'] = 1;
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
  /* Felt: DraggableViews: Rekkefølge */
  $handler->display->display_options['fields']['value0_1']['id'] = 'value0_1';
  $handler->display->display_options['fields']['value0_1']['table'] = 'draggableviews_structure_node0';
  $handler->display->display_options['fields']['value0_1']['field'] = 'value0';
  $handler->display->display_options['fields']['value0_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['value0_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['value0_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['value0_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['value0_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['value0_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['value0_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['value0_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['value0_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['value0_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['value0_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['path'] = 'redigerforside';

  /* Display: Sak 7-10 */
  $handler = $view->new_display('block', 'Sak 7-10', 'block_4');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'newslist sak-7 fire';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '6';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_main_image_fid']['format'] = 'v2_forside_b219_linked';
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
  /* Felt: Innhold: Info om utlyseren (field_teaser) */
  $handler->display->display_options['fields']['field_teaser_value']['id'] = 'field_teaser_value';
  $handler->display->display_options['fields']['field_teaser_value']['table'] = 'node_data_field_teaser';
  $handler->display->display_options['fields']['field_teaser_value']['field'] = 'field_teaser_value';
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

  /* Display: Sak 11-15 */
  $handler = $view->new_display('block', 'Sak 11-15', 'block_5');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'newslist sak-12 fem';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '10';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_main_image_fid']['format'] = 'v2_forside_b170_linked';
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
  /* Felt: Innhold: Info om utlyseren (field_teaser) */
  $handler->display->display_options['fields']['field_teaser_value']['id'] = 'field_teaser_value';
  $handler->display->display_options['fields']['field_teaser_value']['table'] = 'node_data_field_teaser';
  $handler->display->display_options['fields']['field_teaser_value']['field'] = 'field_teaser_value';
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

  /* Display: Sak 16-22 */
  $handler = $view->new_display('block', 'Sak 16-22', 'block_6');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'newslist sak-2 sak-16';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '7';
  $handler->display->display_options['pager']['options']['offset'] = '15';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_main_image_fid']['format'] = 'v2_forside_b170_linked';
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
  /* Felt: Innhold: Info om utlyseren (field_teaser) */
  $handler->display->display_options['fields']['field_teaser_value']['id'] = 'field_teaser_value';
  $handler->display->display_options['fields']['field_teaser_value']['table'] = 'node_data_field_teaser';
  $handler->display->display_options['fields']['field_teaser_value']['field'] = 'field_teaser_value';
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

  /* Display: Sak 23-27 */
  $handler = $view->new_display('block', 'Sak 23-27', 'block_7');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'newslist sak-23 fem';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '22';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_main_image_fid']['format'] = 'v2_forside_b170_linked';
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['group'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['multiple_number'] = '1';
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['multiple_from'] = '0';
  $handler->display->display_options['fields']['field_main_image_fid']['multiple']['multiple_reversed'] = 0;
  /* Felt: Node: Tittel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]';
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
  /* Felt: Innhold: Info om utlyseren (field_teaser) */
  $handler->display->display_options['fields']['field_teaser_value']['id'] = 'field_teaser_value';
  $handler->display->display_options['fields']['field_teaser_value']['table'] = 'node_data_field_teaser';
  $handler->display->display_options['fields']['field_teaser_value']['field'] = 'field_teaser_value';
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
  $translatables['forside'] = array(
    t('Forside'),
    t('mer'),
    t('Søk'),
    t('Nullstill'),
    t('Sortér på'),
    t('Asc'),
    t('Desc'),
    t('[title]'),
    t('Rekkefølge'),
    t('Siste nytt'),
    t('Sak 1'),
    t('Sak 2-3'),
    t('Sak 4-6'),
    t('Rediger forside'),
    t('Nr'),
    t('Sak 7-10'),
    t('Sak 11-15'),
    t('Sak 16-22'),
    t('Sak 23-27'),
  );

  $views[$view->name] = $view;

  // Exported view: kr_quizen
  $view = new view;
  $view->name = 'kr_quizen';
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
  $handler->display->display_options['cache']['type'] = 'views_content_cache';
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
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Felt: Innhold: Info om utlyseren (field_teaser) */
  $handler->display->display_options['fields']['field_teaser_value']['id'] = 'field_teaser_value';
  $handler->display->display_options['fields']['field_teaser_value']['table'] = 'node_data_field_teaser';
  $handler->display->display_options['fields']['field_teaser_value']['field'] = 'field_teaser_value';
  $handler->display->display_options['fields']['field_teaser_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_teaser_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_teaser_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_teaser_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_teaser_value']['label_type'] = 'none';
  /* Felt: Node: Lenke */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view_node']['text'] = 'Ta quizen';
  /* Sorteringskriterium: Node: Innleggsdato */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filtrer: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  /* Filtrer: Taksonomi: Term ID (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = array(
    0 => '1535',
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['term_node_tid_depth']['vid'] = '43';
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '0';
  /* Filtrer: Node: Publisert */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: Den nyeste quizen */
  $handler = $view->new_display('block', 'Den nyeste quizen', 'block_1');
  $translatables['kr_quizen'] = array(
    t('Standardverdier'),
    t('mer'),
    t('Søk'),
    t('Nullstill'),
    t('Sortér på'),
    t('Asc'),
    t('Desc'),
    t('Ta quizen'),
    t('Den nyeste quizen'),
  );

  $views[$view->name] = $view;

  // Exported view: lederlogg
  $view = new view;
  $view->name = 'lederlogg';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Standardverdier */
  $handler = $view->new_display('default', 'Standardverdier', 'default');
  $handler->display->display_options['title'] = 'Lederportrettet';
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
  $handler->display->display_options['fields']['field_main_image_fid']['format'] = 'v2_forside_b120_linked';
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
  /* Felt: Innhold: Info om utlyseren (field_teaser) */
  $handler->display->display_options['fields']['field_teaser_value']['id'] = 'field_teaser_value';
  $handler->display->display_options['fields']['field_teaser_value']['table'] = 'node_data_field_teaser';
  $handler->display->display_options['fields']['field_teaser_value']['field'] = 'field_teaser_value';
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
  $handler->display->display_options['fields']['view_node']['text'] = 'Les intervjuet';
  /* Sorteringskriterium: Node: Klistret */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sorteringskriterium: Node: Innleggsdato */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filtrer: Node: Publisert */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtrer: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
    'blog' => 'blog',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filtrer: Taksonomi: Term ID (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = array(
    0 => '1536',
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = FALSE;
  $handler->display->display_options['filters']['term_node_tid_depth']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['term_node_tid_depth']['vid'] = '43';
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '0';

  /* Display: Siste i lederloggen */
  $handler = $view->new_display('block', 'Siste i lederloggen', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $translatables['lederlogg'] = array(
    t('Standardverdier'),
    t('Lederportrettet'),
    t('mer'),
    t('Søk'),
    t('Nullstill'),
    t('Sortér på'),
    t('Asc'),
    t('Desc'),
    t('Les intervjuet'),
    t('Siste i lederloggen'),
  );

  $views[$view->name] = $view;

  // Exported view: scroll_bilder
  $view = new view;
  $view->name = 'scroll_bilder';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Standardverdier */
  $handler = $view->new_display('default', 'Standardverdier', 'default');
  $handler->display->display_options['title'] = 'Bildegalleri';
  $handler->display->display_options['css_class'] = 'jcar';
  $handler->display->display_options['use_more_text'] = 'mer';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Søk';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Nullstill';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér på';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'jcarousel';
  $handler->display->display_options['style_options']['wrap'] = 'circular';
  $handler->display->display_options['style_options']['skin'] = '';
  $handler->display->display_options['style_options']['visible'] = '';
  $handler->display->display_options['style_options']['auto'] = '0';
  $handler->display->display_options['style_options']['autoPause'] = 0;
  $handler->display->display_options['style_options']['easing'] = '';
  $handler->display->display_options['style_options']['vertical'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Felt: Innhold: Bilde (field_galleri_bilde) */
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['id'] = 'field_galleri_bilde_fid';
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['table'] = 'node_data_field_galleri_bilde';
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['field'] = 'field_galleri_bilde_fid';
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['format'] = 'v2_forside_b170_linked';
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['multiple']['group'] = 1;
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['multiple']['multiple_number'] = '1';
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['multiple']['multiple_from'] = '0';
  $handler->display->display_options['fields']['field_galleri_bilde_fid']['multiple']['multiple_reversed'] = 0;
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
  /* Filtrer: Node: Publisert */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filtrer: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bildegalleri' => 'bildegalleri',
  );

  /* Display: Nyeste galleri */
  $handler = $view->new_display('block', 'Nyeste galleri', 'bilde_scroller');
  $translatables['scroll_bilder'] = array(
    t('Standardverdier'),
    t('Bildegalleri'),
    t('mer'),
    t('Søk'),
    t('Nullstill'),
    t('Sortér på'),
    t('Asc'),
    t('Desc'),
    t('Nyeste galleri'),
  );

  $views[$view->name] = $view;

  // Exported view: siste_saker
  $view = new view;
  $view->name = 'siste_saker';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Standardverdier */
  $handler = $view->new_display('default', 'Standardverdier', 'default');
  $handler->display->display_options['title'] = 'Siste saker';
  $handler->display->display_options['css_class'] = 'siste-saker listeboks';
  $handler->display->display_options['use_more_text'] = 'mer';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'views_content_cache';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Søk';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Nullstill';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér på';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = 5;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_main_image_fid' => 'field_main_image_fid',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
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
  $handler->display->display_options['fields']['field_main_image_fid']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_main_image_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_main_image_fid']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_main_image_fid']['format'] = 'siste_saker_linked';
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
  /* Sorteringskriterium: Node: Innleggsdato */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filtrer: Node: Publisert */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtrer: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;

  /* Display: Siste saker block */
  $handler = $view->new_display('block', 'Siste saker block', 'block_1');
  $translatables['siste_saker'] = array(
    t('Standardverdier'),
    t('Siste saker'),
    t('mer'),
    t('Søk'),
    t('Nullstill'),
    t('Sortér på'),
    t('Asc'),
    t('Desc'),
    t('Siste saker block'),
  );

  $views[$view->name] = $view;

  return $views;
}
