<?php

//$Id: scs_views.pages.inc,v 1.1.2.3 2010/07/06 18:00:41 coworks Exp $

/**
 * @file
 * Integrate Simplenews Content Selection with views and views bulk operations
 */

/**
 * Views selection form
 */
function scs_views_selection_form() {
  $form = array();
  
  //General
  $form['newsletter_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => t('Enter the title of this newsletter'),
  	'#required' => TRUE,
  );
  
  //Newsletter type
  $content_types = variable_get('simplenews_content_types', array());
  if (count($content_types) != 1) {
	$form['newsletter_content_type'] = array(
		'#type' => 'select',
		'#title' => t('Content type'),
		'#description' => t('Select the content type of the newsletter you are creating. Only the content types selected ' . l('here', 'admin/settings/simplenews/general') . ' are displayed.'),
		'#options' => $content_types,
	);
  }
  
  //Views
  $views = views_get_all_views();
  
  foreach ($views as $name => $view) {
    $form['view_' . $name] = array(
      '#type' => 'checkbox',
      '#title' => $name,
    );
  }
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Create newsletter'),
  );
  
  return $form;
}

/**
 * Submit function for the selection form
 */
function scs_views_selection_form_submit($form, &$form_state) {
  $views = array();
  $output = '';
  
  foreach ($form_state['values'] as $field=>$value) {
    if (ereg('view_', $field) && $value == 1) {
      $field = substr($field, 5);
      $output .= views_embed_view($field, 'default');
    }
  }
  
  if (isset($form_state['values']['newsletter_content_type'])) {
  	$type = $form_state['values']['newsletter_content_types'];
  } else {
  	$types = variable_get('simplenews_content_types', array());
	
  	foreach ($types as $selected) {
	  $type = $selected;
	}
  }
  
  _scs_create_newsletter($form_state['values']['newsletter_title'], $output, 0, $type);
}