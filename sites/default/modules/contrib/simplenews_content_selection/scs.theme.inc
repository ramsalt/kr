<?php
//$Id: scs.theme.inc,v 1.1.2.1.2.10 2010/08/10 22:06:43 coworks Exp $
  
/**
 * @file
 * Select Drupal content to create a newsletter
 */

/**
 * Theme the node selection form
 */
function theme_scs_node_selection($form) {
  if ($form['step']['#value'] == 1) {
    $headers = array('', t('Nid'), t('Title'), t('Created'));
      
    //Headers
    $headers = array(
      '',
      array(
        'data' => t('Nid'),
        'field' => 'nid',
        'sort' => 'asc',
      ),
      array(
        'data' => t('Title'),
        'field' => 'title',
      ),
      array(
        'data' => t('Created'),
        'field' => 'created',
      ),
    );
      
    $nodes = _scs_get_nodes($headers);
     
    $data = array();
      
    $explain = '';
      
    if (user_access('administer scs')) {
      $explain = '<div class="form-item">' . t('Want to select more nodes? Add more content types ') . l('here', 'admin/settings/simplenews/scs') . '.' . '</div>';
    }
  
    foreach ($nodes as $node) {
      if (array_key_exists('nid_' . $node->nid, $form)) {
        $nodearray = array();
        $nodearray[] = drupal_render($form['nid_' . $node->nid]);
        $nodearray[] = $node->nid;
        $nodearray[] = $node->title;
        $nodearray[] = $node->created;
            
        $data[] = $nodearray;
      }
    }
      
    return drupal_render($form['newsletter_title']) . drupal_render($form['newsletter_toc']) . drupal_render($form['newsletter_content_type']) . $explain . drupal_render($form['filters']) . theme('table', $headers, $data) . drupal_render($form);
  } 
  else {
    return theme('scs_sort_nodes', $form);
  }
}
  
/**
 * Each selected node goes true this function to create a nice body
 */
function theme_scs_node_output($node) {
  $output = '';
    
  $output = '<div id="node_' . $node->nid . '">';
    $output .= '<h1>' . $node->title . '</h1>';
    $output .= '<p>' . node_teaser($node->body) . '</p>';
    $output .= '<p>' . l(t('Read more'), 'node/' . $node->nid) . '</p>';
  $output .= '</div>';
  
  return $output;
}
  
/**
 * Theme the node sort form into a table
 */
function theme_scs_sort_nodes($form) {
  $headers = array(t('Node title'), t('Weight'));
  $rows = array();

  foreach ($form as $name=>$field) {
    if (ereg('weight_', $name)) {
      $nid = explode('_', $name);
      $nid = $nid[1];
      $title = db_result(db_query('SELECT title FROM {node} WHERE nid = %d', $nid));
      unset($form[$name]['#title']);
      
      $row = array();
      $row[] = $title;
      $row[] = drupal_render($form[$name]);
      $rows[] = array(
        'data' => $row,
        'class' => 'draggable',
      );
    }
  }
    
  return drupal_render($form['newsletter_title']) . drupal_render($form['newsletter_toc']) . drupal_render($form['newsletter_content_type']) . theme('table', $headers, $rows, array('id' => 'scs_node_sort_table')) . drupal_render($form);
}
  
/**
 * Theme function to add the titles of the selected nodes at top of the newsletter
 */
function theme_scs_node_titles($titles) {
  if (variable_get('scs_format', 'plain') == 'plain') {
    return implode("\n", $titles);
  }
  else {
    return '<div id="toc">' . theme('item_list', $titles) . '</div>';
  }
}

/**
 * Theme a complete newsletter.
 */
function theme_scs_newsletter_output($nodes, $toc) {
  $body = '';
  $titles = array();

  // Node information
  foreach ($nodes as $node) {
    if ($toc) {
      if (variable_get('scs_format', 'plain') == 'plain') {
        $titles[] = $node->title;
      }
      else {
        $titles[] = '<a href="#node_' . $node->nid . '">' . $node->title . '</a>';
      }
    }
    $body .= theme('scs_node_output', $node);
  }

  // ToC (if required)
  if ($toc) {
    $body = theme('scs_node_titles', $titles) . $body;
  }

  // Complete newsletter body
  return $body;
}