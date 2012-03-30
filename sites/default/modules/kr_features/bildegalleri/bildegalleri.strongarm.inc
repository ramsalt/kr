<?php

/**
 * Implementation of hook_strongarm().
 */
function bildegalleri_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_bildegalleri';
  $strongarm->value = 0;

  $export['comment_anonymous_bildegalleri'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_bildegalleri';
  $strongarm->value = '0';

  $export['comment_bildegalleri'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_bildegalleri';
  $strongarm->value = '3';

  $export['comment_controls_bildegalleri'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_bildegalleri';
  $strongarm->value = '4';

  $export['comment_default_mode_bildegalleri'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_bildegalleri';
  $strongarm->value = '1';

  $export['comment_default_order_bildegalleri'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_bildegalleri';
  $strongarm->value = '50';

  $export['comment_default_per_page_bildegalleri'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_bildegalleri';
  $strongarm->value = '0';

  $export['comment_form_location_bildegalleri'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_bildegalleri';
  $strongarm->value = '1';

  $export['comment_preview_bildegalleri'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_bildegalleri';
  $strongarm->value = '1';

  $export['comment_subject_field_bildegalleri'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_bildegalleri';
  $strongarm->value = array(
    'workflow' => '0',
    'title' => '-5',
    'revision_information' => '1',
    'author' => '2',
    'options' => '3',
    'comment_settings' => '5',
    'menu' => '-2',
    'path' => '6',
    'path_redirect' => '4',
  );

  $export['content_extra_weights_bildegalleri'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_bildegalleri';
  $strongarm->value = '0';

  $export['language_content_type_bildegalleri'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_bildegalleri';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );

  $export['node_options_bildegalleri'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_bildegalleri';
  $strongarm->value = '0';

  $export['upload_bildegalleri'] = $strongarm;
  return $export;
}
