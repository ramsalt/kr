<?php

/**
 * Implementation of hook_content_default_fields().
 */
function tema_content_default_fields() {
  $fields = array();

  // Exported field: field_tema_saker
  $fields['tema-field_tema_saker'] = array(
    'field_name' => 'field_tema_saker',
    'type_name' => 'tema',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_plain' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_html' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'article' => 'article',
      'poll' => 0,
      'barometer' => 0,
      'op_image' => 0,
      'bildegalleri' => 0,
      'blog' => 0,
      'book' => 0,
      'chart' => 0,
      'ekstern_blogg' => 0,
      'eksternt_blogginnlegg' => 0,
      'multichoice' => 0,
      'author' => 0,
      'kommune' => 0,
      'simplenews' => 0,
      'ordforer' => 0,
      'page' => 0,
      'panel' => 0,
      'quiz' => 0,
      'resource' => 0,
      'job' => 0,
      'table' => 0,
      'tema' => 0,
      'topichub' => 0,
      'webform' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_tema_saker][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Artikler',
      'weight' => '-4',
      'description' => 'Legg inn artikler/saker som skal være med dette temaet',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Artikler');

  return $fields;
}
