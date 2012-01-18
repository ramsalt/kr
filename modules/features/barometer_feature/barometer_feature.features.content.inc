<?php

/**
 * Implementation of hook_content_default_fields().
 */
function barometer_feature_content_default_fields() {
  $fields = array();

  // Exported field: field_barometer_data
  $fields['barometer-field_barometer_data'] = array(
    'field_name' => 'field_barometer_data',
    'type_name' => 'barometer',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 0,
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '1',
    'multiple' => '1',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '1',
    'widget' => array(
      'file_extensions' => 'txt csv',
      'file_path' => 'barometerdata',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'filefield_sources' => array(
        'imce' => 0,
        'remote' => 0,
        'reference' => 0,
        'attach' => 0,
      ),
      'filefield_source_attach_path' => 'file_attach',
      'filefield_source_attach_absolute' => '0',
      'filefield_source_attach_mode' => 'move',
      'filefield_source_autocomplete' => '0',
      'label' => 'Barometerdata',
      'weight' => '-4',
      'description' => 'Last opp en semikolonseparert fil med verdiene for en periode. For å legge til flere perioder kan du laste opp flere filer.',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_table_description
  $fields['barometer-field_table_description'] = array(
    'field_name' => 'field_table_description',
    'type_name' => 'barometer',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_table_description][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Tabel description',
      'weight' => '-2',
      'description' => 'Legg til en beskrivelse som vil vises under tabellen.',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_table_modus
  $fields['barometer-field_table_modus'] = array(
    'field_name' => 'field_table_modus',
    'type_name' => 'barometer',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '1',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '1',
    'max' => '2',
    'allowed_values' => '1|Etter nøkler
2|Etter kommuner',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '1',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Tabellmodus',
      'weight' => '-1',
      'description' => '',
      'type' => 'optionwidgets_buttons',
      'module' => 'optionwidgets',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Barometerdata');
  t('Tabel description');
  t('Tabellmodus');

  return $fields;
}
