<?php

/**
 * Implementation of hook_strongarm().
 */
function kr_job_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_job';
  $strongarm->value = 0;
  $export['comment_anonymous_job'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_job';
  $strongarm->value = '3';
  $export['comment_controls_job'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_job';
  $strongarm->value = '4';
  $export['comment_default_mode_job'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_job';
  $strongarm->value = '1';
  $export['comment_default_order_job'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_job';
  $strongarm->value = '50';
  $export['comment_default_per_page_job'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_job';
  $strongarm->value = '0';
  $export['comment_form_location_job'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_job';
  $strongarm->value = '0';
  $export['comment_job'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_job';
  $strongarm->value = '1';
  $export['comment_preview_job'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_job';
  $strongarm->value = '1';
  $export['comment_subject_field_job'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_job';
  $strongarm->value = array(
    'workflow' => '6',
    'title' => '1',
    'body_field' => '4',
    'revision_information' => '7',
    'author' => '8',
    'options' => '9',
    'comment_settings' => '11',
    'menu' => '5',
    'taxonomy' => '-3',
    'path' => '12',
    'attachments' => '10',
    'path_redirect' => '13',
  );
  $export['content_extra_weights_job'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_job';
  $strongarm->value = '0';
  $export['language_content_type_job'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_job';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_job'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_job';
  $strongarm->value = '1';
  $export['upload_job'] = $strongarm;

  return $export;
}
