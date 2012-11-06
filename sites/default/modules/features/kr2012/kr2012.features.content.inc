<?php

/**
 * Implementation of hook_content_default_fields().
 */
function kr2012_content_default_fields() {
  $fields = array();

  // Exported field: field_rel_bildegalleri
  $fields['article-field_rel_bildegalleri'] = array(
    'field_name' => 'field_rel_bildegalleri',
    'type_name' => 'article',
    'display_settings' => array(
      'weight' => '32',
      'parent' => '',
      'label' => array(
        'format' => 'above',
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
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'bildegalleri' => 'bildegalleri',
      'article' => 0,
      'poll' => 0,
      'barometer' => 0,
      'op_image' => 0,
      'blog' => 0,
      'book' => 0,
      'chart' => 0,
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
          '_error_element' => 'default_value_widget][field_rel_bildegalleri][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Bildegalleri',
      'weight' => '32',
      'description' => 'Relater et eksisterende bildegalleri til denne artikkelen',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_rel_kommune
  $fields['article-field_rel_kommune'] = array(
    'field_name' => 'field_rel_kommune',
    'type_name' => 'article',
    'display_settings' => array(
      'weight' => '31',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'hidden',
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
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'kommune' => 'kommune',
      'article' => 0,
      'poll' => 0,
      'barometer' => 0,
      'op_image' => 0,
      'bildegalleri' => 0,
      'blog' => 0,
      'book' => 0,
      'chart' => 0,
      'multichoice' => 0,
      'author' => 0,
      'simplenews' => 0,
      'ordforer' => 0,
      'page' => 0,
      'panel' => 0,
      'quiz' => 0,
      'resource' => 0,
      'job' => 0,
      'table' => 0,
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
          '_error_element' => 'default_value_widget][field_rel_kommune][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Kommune',
      'weight' => '31',
      'description' => 'Knytt saken opp mot en eller flere kommuner',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Bildegalleri');
  t('Kommune');

  return $fields;
}
