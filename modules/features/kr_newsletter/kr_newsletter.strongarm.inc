<?php

/**
 * Implementation of hook_strongarm().
 */
function kr_newsletter_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_simplenews';
  $strongarm->value = 0;

  $export['comment_anonymous_simplenews'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_simplenews';
  $strongarm->value = '3';

  $export['comment_controls_simplenews'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_simplenews';
  $strongarm->value = '4';

  $export['comment_default_mode_simplenews'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_simplenews';
  $strongarm->value = '1';

  $export['comment_default_order_simplenews'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_simplenews';
  $strongarm->value = '50';

  $export['comment_default_per_page_simplenews'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_simplenews';
  $strongarm->value = '0';

  $export['comment_form_location_simplenews'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_simplenews';
  $strongarm->value = '1';

  $export['comment_preview_simplenews'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_simplenews';
  $strongarm->value = '2';

  $export['comment_simplenews'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_simplenews';
  $strongarm->value = '1';

  $export['comment_subject_field_simplenews'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_simplenews';
  $strongarm->value = '0';

  $export['language_content_type_simplenews'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_simplenews';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );

  $export['node_options_simplenews'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scs_content_types';
  $strongarm->value = array(
    'blog' => 'blog',
    'article' => 'article',
    'author' => 'author',
    'editors_choice' => 'editors_choice',
    'op_image' => 'op_image',
    'package' => 'package',
    'resource' => 'resource',
    'slideshow' => 'slideshow',
    'video' => 'video',
    'stillingsannonse' => 'stillingsannonse',
    'panel' => 'panel',
    'page' => 'page',
    'simplenews' => 'simplenews',
    'topichub' => 'topichub',
  );

  $export['scs_content_types'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scs_default_title';
  $strongarm->value = 'Nyheter';

  $export['scs_default_title'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scs_format';
  $strongarm->value = 'html';

  $export['scs_format'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scs_publish_default';
  $strongarm->value = '1';

  $export['scs_publish_default'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplenews_receipt';
  $strongarm->value = 0;

  $export['simplenews_receipt'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplenews_send';
  $strongarm->value = '0';

  $export['simplenews_send'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplenews_test_address';
  $strongarm->value = 'yngve@ramsalt.com';

  $export['simplenews_test_address'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplenews_test_address_override';
  $strongarm->value = 1;

  $export['simplenews_test_address_override'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_simplenews';
  $strongarm->value = '1';

  $export['upload_simplenews'] = $strongarm;
  return $export;
}
