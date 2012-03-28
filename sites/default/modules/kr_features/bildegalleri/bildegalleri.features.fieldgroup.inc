<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function bildegalleri_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_galleri_bilder
  $groups['bildegalleri-group_galleri_bilder'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'bildegalleri',
    'group_name' => 'group_galleri_bilder',
    'label' => 'Bilder',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '-4',
        'parent' => '',
        'label' => 'hidden',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'settings' => array(),
        '4' => array(
          'format' => 'fieldset',
        ),
        '2' => array(
          'format' => 'fieldset',
        ),
        '3' => array(
          'format' => 'fieldset',
        ),
        'email_plain' => array(
          'format' => 'fieldset',
        ),
        'email_html' => array(
          'format' => 'fieldset',
        ),
        'token' => array(
          'format' => 'fieldset',
        ),
        'description' => NULL,
      ),
      'multigroup' => array(
        'multiple' => 1,
        'subgroup' => array(
          'weight' => -20,
          'label' => 'hidden',
          'teaser' => array(
            'format' => 'fieldset',
            'exclude' => 0,
          ),
          'full' => array(
            'format' => 'fieldset',
            'exclude' => 0,
          ),
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
    ),
    'weight' => '-4',
    'parent' => '',
    'fields' => array(
      '0' => 'field_galleri_bilde',
      '1' => 'field_galleri_kredit',
      '2' => 'field_galleri_desc',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Bilder');

  return $groups;
}
