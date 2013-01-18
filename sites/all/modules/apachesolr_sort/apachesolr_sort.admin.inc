<?php

/*
 * The form where you set the variables.
 */
function apachesolr_sort_page_form() {
  $query = apachesolr_drupal_query('apachesolr_sort');
  $sorts = $query->getAvailableSorts();
  $form['apachesolr_sort_enable'] = array(
    '#type' => 'fieldset',
    '#title' => t('enable/disable sort fields'),
    '#tree' => FALSE,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['apachesolr_sort_weight'] = array(
    '#type' => 'fieldset',
    '#title' => t('adapt the weight on sort fields'),
    '#tree' => FALSE,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  foreach ($sorts as $key => $sort)    {
    $variable = 'apachesolr_sort_sort_' . $key;
    $weight_variable = 'apachesolr_sort_sort_weight_' . $key;

    $form['apachesolr_sort_enable'][$variable] = array(
      '#type' => 'checkbox',
      '#title' => $sort['title'],
      '#default_value' => variable_get($variable, TRUE),
      '#description' => t('enable this sort. '),
    );
    $form['apachesolr_sort_weight'][$weight_variable] = array(
      '#type' => 'textfield',
      '#title' => t('The weight of ' . $sort['title']),
      '#default_value' => variable_get($weight_variable, 0),
      '#description' => t('Change the order of the facest by altering this weight. '),
      '#size' => 5,
    );
  }
  return system_settings_form($form);
}


/*
 * The submit handler of the form that saves the input content into the DB.
 */
function apachesolr_sort_page_form_submit($form, &$form_state) {
  foreach ($form['#post'] as $key => $field) {
    if (is_array($field)) {
      $keys = array_keys($field);
      if (isset($field['apachesolr_sort_sort_' . $key])) {
          variable_set('apachesolr_sort_sort_' . $key, TRUE);
      }
      else {
        variable_set('apachesolr_sort_sort_' . $key, FALSE);
      }
      variable_set('apachesolr_sort_sort_weight_' . $key, $field['apachesolr_sort_sort_weight_' . $key]);
    }
  }
}