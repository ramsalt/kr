<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function tema_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_tema_group
  $groups['tema-group_tema_group'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'tema',
    'group_name' => 'group_tema_group',
    'label' => 'Artikler relatert',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '104',
        'parent' => '',
        'label' => 'above',
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
        'cck_blocks' => array(
          'format' => 'fieldset',
        ),
        '5' => array(
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
          'label' => 'above',
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
          'cck_blocks' => array(
            'format' => 'fieldset',
            'exclude' => 0,
          ),
          '5' => array(
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
    'weight' => '104',
    'parent' => '',
    'fields' => array(
      '0' => 'field_tema_saker',
      '1' => 'field_tema_vis_pa_forsiden',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Artikler relatert');

  return $groups;
}
