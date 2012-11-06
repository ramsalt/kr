<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function kr2012_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_fakta
  $groups['article-group_fakta'] = array(
    'group_type' => 'standard',
    'type_name' => 'article',
    'group_name' => 'group_fakta',
    'label' => 'Fakta og sitat',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset_collapsed',
        'description' => '',
      ),
      'display' => array(
        'weight' => '22',
        'parent' => '',
        'label' => 'hidden',
        'teaser' => array(
          'format' => 'fieldset_collapsed',
          'exclude' => 1,
        ),
        'full' => array(
          'format' => 'fieldset_collapsed',
          'exclude' => 1,
        ),
        'description' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'email_plain' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'email_html' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '22',
    'parent' => '',
    'fields' => array(
      '0' => 'field_article_fakta',
      '1' => 'field_sitat',
      '2' => 'field_fb_comments',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Fakta og sitat');

  return $groups;
}
