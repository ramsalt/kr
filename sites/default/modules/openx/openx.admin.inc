<?php

/**
 * @author Gerd Riesselmann
 * @author Jeff Warrington (jaydub) is new maintainer March 2008
 * @author Chris Nutting <Chris.Nutting@openx.org>
 * @author Bruno Massa
 *
 * @file
 * Module settings.
 */

/**
 * Module settings page form.
 */
function _openx_settings(&$form_state) {
  $form['blocks'] = array(
    '#description'  => t('<ul>
        <li>'. t('The zone ID can be found in the OpenX administration interface.') .'</li>
        <li>'. t('The name can be any alpha-numeric string, this will be used for the block name.') .'</li>
    </ul>'),
    '#title'        => t('OpenX blocks'),
    '#type'         => 'fieldset',
  );

  $form['blocks']['openx_zones'] = array(
    '#tree'         => TRUE,
    '#theme'        => 'openx_settings_zones',
    '#element_validate' => array('_openx_settings_zones_clean'),
  );
  $form_state['storage']['zones'] = isset($form_state['storage']['zones']) ? $form_state['storage']['zones'] : variable_get('openx_zones', array_fill(0, 3, array('id' => '', 'name' => '')));
  if (empty($form_state['storage']['zones'])) {
    $form_state['storage']['zones'] = array_fill(0, 3, array('id' => '', 'name' => ''));
  }
  foreach ($form_state['storage']['zones'] as $id => $zone) {
    $form['blocks']['openx_zones'][$id]['id'] = array(
      '#type'           => 'textfield',
      '#default_value'  => isset($form_state['values']['openx_zones'][$id]['id']) ? $form_state['values']['openx_zones'][$id]['id'] : $form_state['storage']['zones'][$id]['id'],
      '#size'           => 6,
    );
    $form['blocks']['openx_zones'][$id]['name'] = array(
      '#type'           => 'textfield',
      '#default_value'  => isset($form_state['values']['openx_zones'][$id]['name']) ? $form_state['values']['openx_zones'][$id]['name'] : $form_state['storage']['zones'][$id]['name'],
      '#size'           => 64,
    );
    $form['blocks']['openx_zones'][$id]['delete'] = array(
      '#type' => 'submit',
      '#value' => t('delete'),
      '#submit' => array('_openx_settings_del_zone'),
      '#name' => 'openx-zones-delete-' . $id,
      '#key' => $id,
      '#disabled' => count($form_state['storage']['zones']) == 1,
    );
  }
  
  $form['blocks']['add_zone'] = array(
    '#type' => 'submit',
    '#value' => t('Add zone'),
    '#submit' => array('_openx_settings_add_zone'),
  );

  $form['targeting'] = array(
    '#type' => 'fieldset',
    '#title' => t('Site Variables'),
    '#description' => t('Specify site variables to allow OpenX to target ads to particular pages.'),
  );
  
  $form_state['storage']['site_vars'] = isset($form_state['storage']['site_vars']) ? $form_state['storage']['site_vars'] : variable_get('openx_site_vars', array_fill(0, 3, array('key' => '', 'value' => '')));
  if (empty($form_state['storage']['site_vars'])) {
    $form_state['storage']['site_vars'] = array_fill(0, 3, array('key' => '', 'value' => ''));
  }
  $form['targeting']['openx_site_vars'] = array(
     '#tree' => TRUE,
     '#element_validate' => array('_openx_settings_site_vars_clean'),
     '#theme' => 'openx_site_vars',
     '#prefix' => '<div id="openx-site-vars-wrapper">',
     '#suffix' => '</div>',
  );
  
  foreach ($form_state['storage']['site_vars'] as $key => $vars) {
    $form['targeting']['openx_site_vars'][$key]['key'] = array(
      '#type' => 'textfield',
      '#default_value' => $vars['key'],
      '#size' => 16,
    );
    $form['targeting']['openx_site_vars'][$key]['value'] = array(
      '#type' => 'textfield',
      '#default_value' => $vars['value'],
      '#size' => 64,
    );
    $form['targeting']['openx_site_vars'][$key]['delete'] = array(
      '#type' => 'submit',
      '#value' => t('delete'),
      '#submit' => array('_openx_settings_del_variable'),
      '#name' => 'openx-site-vars-delete-' . $key,
      '#key' => $key,
      '#disabled' => count($form_state['storage']['site_vars']) == 1,
    );
  }
  
  $form['targeting']['add_row'] = array(
    '#type' => 'submit',
    '#value' => t('Add variable'),
    '#submit' => array('_openx_settings_add_variable'),
  );
  $form['targeting']['token_vars_tree'] = array(
    '#theme' => 'token_tree',
    '#token_types' => array('node', 'user'),
  );

  $form['adserver'] = array(
    '#collapsible'    => TRUE,
    '#collapsed'      => variable_get('openx_delivery_url', FALSE),
    '#type'           => 'fieldset',
    '#title'          => t('OpenX server'),
    '#description'    => t('These settings are located on your OpenX server at <strong>Settings -> Main Settings -> Delivery Settings</strong><br />'),
  );
  $form['adserver']['openx_delivery_url'] = array(
    '#type'           => 'textfield',
    '#default_value'  => isset($form_state['values']['openx_delivery_url']) ? $form_state['values']['openx_delivery_url'] : variable_get('openx_delivery_url', 'd.openx.org'),
    '#title'          => t('OpenX delivery url'),
    '#description'    => t('For example "ads.example.org/delivery". "http://" is automatically prefixed.'),
    '#required'       => TRUE,
  );
  $form['adserver']['openx_delivery_url_https'] = array(
    '#type'           => 'textfield',
    '#default_value'  => isset($form_state['values']['openx_delivery_url_https']) ? $form_state['values']['openx_delivery_url_https'] : variable_get('openx_delivery_url_https', 'd.openx.org'),
    '#title'          => t('OpenX https delivery url'),
    '#description'    => t('For example "ads.example.org/delivery". "https://" is automatically prefixed.'),
    '#required'       => TRUE,
  );

  $form['#submit'] = array('_openx_settings_submit');
  return system_settings_form($form);
}

function _openx_settings_submit(&$form, &$form_state) {
  unset($form_state['storage']);
}

function _openx_settings_zones_clean(&$form, &$form_state) {
  $errors = FALSE;

  if (isset($form_state['clicked_button']['#submit'])) {
    return;
  }
  
  $zones = $form_state['values']['openx_zones'];
  foreach ($zones as $key => $var) {
    if (empty($var['id']) && empty($var['name'])) {
      unset($zones[$key]);
    }
    elseif (empty($var['id']) && !empty($var['value'])) {
      $errors = TRUE;
      form_error($form[$key]['id'], t('Zone Id field is required when there is a name present'));
    }
  }
  
  if (!$errors) {
    form_set_value($form, $zones, $form_state);
  }
}

function _openx_settings_site_vars_clean(&$form, &$form_state) {
  $errors = FALSE;

  if (isset($form_state['clicked_button']['#submit'])) {
    return;
  }

  $site_vars = $form_state['values']['openx_site_vars'];
  foreach ($site_vars as $key => $var) {
    if (empty($var['key']) && empty($var['value'])) {
      unset($site_vars[$key]);
    }
    elseif (empty($var['key']) && !empty($var['value'])) {
      $errors = TRUE;
      form_error($form[$key]['key'], t('Key field is required when there is a value present'));
    }
  }
  
  if (!$errors) {
    form_set_value($form, $site_vars, $form_state);
  }
}

function _openx_settings_del_zone(&$form, &$form_state) {
  $form_state['storage']['zones'] = $form_state['values']['openx_zones'];
  unset($form_state['storage']['zones'][$form_state['clicked_button']['#key']]);
  $form_state['rebuild'] = 1;
}

function _openx_settings_add_zone(&$form, &$form_state) {
  $form_state['storage']['zones'] = $form_state['values']['openx_zones'];
  $form_state['storage']['zones'][] = array('id' => '', 'name' => '');
  $form_state['rebuild'] = 1;
}

function _openx_settings_del_variable(&$form, &$form_state) {
  $form_state['storage']['site_vars'] = $form_state['values']['openx_site_vars'];
  unset($form_state['storage']['site_vars'][$form_state['clicked_button']['#key']]);
  $form_state['rebuild'] = 1;
}

function _openx_settings_add_variable(&$form, &$form_state) {
  $form_state['storage']['site_vars'] = $form_state['values']['openx_site_vars'];
  $form_state['storage']['site_vars'][] = array('key' => '', 'value' => '');
  $form_state['rebuild'] = 1;
}

/**
 * Theme the OpenX blocks list as a table
 */
function theme_openx_settings_zones($form) {
  $header = array(t('Zone ID'), t('Name'), '');
  foreach (element_children($form) as $zone) {
    $rows[] = array(
      drupal_render($form[$zone]['id']),
      drupal_render($form[$zone]['name']),
      drupal_render($form[$zone]['delete']),
    );
  }
  return theme('table', $header, $rows);
}

function theme_openx_site_vars($form) {
  $head = array(
    t('Variable'),
    t('Value'),
    '',
  );
  $rows = array();
  
  foreach (element_children($form) as $key) {
    $rows[] = array(
      drupal_render($form[$key]['key']),
      drupal_render($form[$key]['value']),
      drupal_render($form[$key]['delete']),
    );
  }
  
  return theme('table', $head, $rows);
}
