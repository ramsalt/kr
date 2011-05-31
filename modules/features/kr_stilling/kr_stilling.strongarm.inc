<?php

/**
 * Implementation of hook_strongarm().
 */
function kr_stilling_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_stillingsannonse';
  $strongarm->value = 0;

  $export['comment_anonymous_stillingsannonse'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_stillingsannonse';
  $strongarm->value = '3';

  $export['comment_controls_stillingsannonse'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_stillingsannonse';
  $strongarm->value = '4';

  $export['comment_default_mode_stillingsannonse'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_stillingsannonse';
  $strongarm->value = '1';

  $export['comment_default_order_stillingsannonse'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_stillingsannonse';
  $strongarm->value = '50';

  $export['comment_default_per_page_stillingsannonse'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_stillingsannonse';
  $strongarm->value = '0';

  $export['comment_form_location_stillingsannonse'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_stillingsannonse';
  $strongarm->value = '1';

  $export['comment_preview_stillingsannonse'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_stillingsannonse';
  $strongarm->value = '0';

  $export['comment_stillingsannonse'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_stillingsannonse';
  $strongarm->value = '1';

  $export['comment_subject_field_stillingsannonse'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_stillingsannonse';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-3',
    'revision_information' => '8',
    'author' => '9',
    'options' => '10',
    'comment_settings' => '11',
    'menu' => '6',
    'path' => '12',
    'scheduler_settings' => '-2',
    'workflow' => '7',
  );

  $export['content_extra_weights_stillingsannonse'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_stillingsannonse';
  $strongarm->value = '0';

  $export['language_content_type_stillingsannonse'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_stillingsannonse';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_stillingsannonse'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_stillingsannonse';
  $strongarm->value = '0';

  $export['upload_stillingsannonse'] = $strongarm;
  return $export;
}
