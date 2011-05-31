<?php
  //$Id: scs.pages.inc,v 1.1.2.1.2.7 2010/08/18 19:15:03 coworks Exp $
  
  /*
   * @file
   * Select Drupal content to create a newsletter
   */

  /*
   * Node selection page
   * First way to use this module
   */
  function scs_node_selection($form_state) {
  	$filters = array();
  	
  	if (!empty($form_state['post'])) {
  		if (!empty($form_state['post']['nid'])) {
  			$filters['nid'] = $form_state['post']['nid'];
  		}
  		
  		if (!empty($form_state['post']['title'])) {
  			$filters['title'] = $form_state['post']['title']; 
  		}
  		
  		if (!is_numeric($form_state['post']['type'])) {
  			$filters['type'] = $form_state['post']['type'];
  		}
  	}
  	
  	$form = array();
  	
  	if (is_null($form_state['storage'])) {
  		//First step
  		$form['step'] = array(
  			'#type' => 'hidden',
  			'#value' => 1,
  		);
    	
  		$nodes = _scs_get_nodes(array(), $filters);
    	
    	foreach ($nodes as $node) {
    	  $form['nid_' . $node->nid] = array(
    	    '#type' => 'checkbox',
    	  	'#return_value' => $node->nid,
    	  );
    	}
    	
    	$form['newsletter_title'] = array(
    	  '#type' => 'textfield',
    	  '#title' => t('Title'),
    	  '#description' => t('Enter the title of this newsletter'),
    	  '#default_value' => variable_get('scs_default_title', ''),
    	);
    	
    	$form['newsletter_toc'] = array(
    	  '#type' => 'checkbox',
    	  '#title' => t('Create a table of contents'),
    	  '#description' => t('Create a table of contents at top of the newsletter with the titles of the selected nodes. If newsletter is HTML format, these table of contents will be bookmarks.'),
    	);
    	
    	$content_types = variable_get('simplenews_content_types', array());
    	
    	if (count($content_types) != 1) {
    		$form['newsletter_content_type'] = array(
    			'#type' => 'select',
    			'#title' => t('Content type'),
    			'#description' => t('Select the content type of the newsletter you are creating. Only the content types selected ' . l('here', 'admin/settings/simplenews/general') . ' are displayed.'),
    			'#options' => $content_types,
    		);
    	}
    	
    	//Filters
    	$form['filters'] = array(
    		'#type' => 'fieldset',
    		'#title' => t('Filters'),
    		'#collapsible' => TRUE,
    		'#collapsed' => (empty($filters) ? TRUE : FALSE),
    	);
    	
    	$form['filters']['nid'] = array(
    		'#type' => 'textfield',
    		'#title' => t('Nid'),
    		'#description' => t('Filter on nid'),
    		'#size' => 10,
    	);
    	
    	$form['filters']['title'] = array(
    		'#type' => 'textfield',
    		'#title' => t('Title'),
    		'#description' => t('Filter on title. Used as LIKE \'title%\'.'),
    	);
    	
    	$form['filters']['type'] = array(
    		'#type' => 'select',
    		'#title' => t('Type'),
    		'#options' => _scs_get_typefilter(),
    	);
    	
    	$form['filters']['filter'] = array(
    		'#type' => 'button',
    		'#value' => t('Filter'),
    	);
    	
    	$form['submit'] = array(
    	  '#type' => 'submit',
    	  '#value' => t('Sort nodes'),
    	);
  	} else {
  		$form['step'] = array(
  			'#type' => 'hidden',
  			'#value' => 2,
  		);
  		
  		$form = array_merge($form, scs_sort_nodes($form_state['storage']['nodes']));
  	}
  	
  	return $form;
  }
  
  function scs_node_selection_validate($form, &$form_state) {
  	if ($form_state['values']['op'] != t('Filter')) {
  		if ($form_state['values']['newsletter_title'] == '' && $form_state['values']['step'] == 1) {
  			form_set_error('newsletter_title', t('This field is required.'));
  		}
  	}
  }
  
  /*
   * Submit function of the node selection page
   */
  function scs_node_selection_submit($form, &$form_state) {
  	if ($form_state['values']['step'] == 1) {
  		//Standard fields
  		$form_state['storage']['title'] = $form_state['values']['newsletter_title'];
  		$form_state['storage']['toc'] = $form_state['values']['newsletter_toc'];
  		
  		//Content type
  		if (array_key_exists('newsletter_content_type', $form_state['values'])) {
  			$form_state['storage']['type'] = $form_state['values']['newsletter_content_type'];
  		} else {
  			$types = variable_get('simplenews_content_types', array());
  			foreach ($types as $type) {
  				$form_state['storage']['type'] = $type;
  			}
  		}
  		
  		//Selected nodes
    	foreach ($form_state['values'] as $field=>$value) {
    		if (ereg('nid_', $field) && $value != 0) {
    		  $nodes[] = $value;
    		}
    	}
    	
    	$form_state['storage']['nodes'] = $nodes;
  		
  		//Next step
  		$form_state['storage']['step'] = 2;
  		$form_state['rebuild'] == TRUE;
  	} else {
    	foreach($form_state['values'] as $key=>$value) {
          if (ereg('weight_', $key)) {
            $nid = explode('_', $key);
            $nid = $nid[1];
            $nodes[$nid] = $value;
          }
      	}
      	
      	asort($nodes);
    	$nodes = array_keys($nodes);
    	
      	_scs_create_newsletter($form_state['storage']['title'], $nodes, $form_state['storage']['toc'], $form_state['storage']['type']);
  	}
  }
  
  /**
   * Node sort page
   */
  function scs_sort_nodes($nodes = array()) {
    drupal_add_tabledrag('scs_node_sort_table', 'order', 'sibling', 'scs_weight');
  	$fields = false;
    if (array_key_exists('storage', $nodes)) {
      if (count($_GET) != 0) {
      	$fields = true;
      	$nodes = array();
      	foreach ($_GET as $key=>$nid) {
      		if ($key != 'q') {
      			$nodes[] = $nid;
      		}
      	}
      } else {
      	drupal_set_message(t('There was an error. No nodes found'));
      	return array();
      }
    }
    
    $form = array();
    
    if ($fields == TRUE) {
      $form['newsletter_title'] = array(
    	  '#type' => 'textfield',
    	  '#title' => t('Title'),
    	  '#description' => t('Enter the title of this newsletter'),
      	  '#default_value' => variable_get('scs_default_title', t('Please edit the title of this newsletter.')),
    	  '#required' => true,
    	);
    	
    	$form['newsletter_toc'] = array(
    	  '#type' => 'checkbox',
    	  '#title' => t('Create a table of contents'),
    	  '#description' => t('Create a table of contents at top of the newsletter with the titles of the selected nodes. If newsletter is HTML format, these table of contents will be bookmarks.'),
    	);
    	
    	$content_types = variable_get('simplenews_content_types', array());
    	
    	if (count($content_types) != 1) {
    		$form['newsletter_content_type'] = array(
    			'#type' => 'select',
    			'#title' => t('Content type'),
    			'#description' => t('Select the content type of the newsletter you are creating. Only the content types selected ' . l('here', 'admin/settings/simplenews/general') . ' are displayed.'),
    			'#options' => $content_types,
    		);
    	}
    }
    
	$counter = 0;
    
    foreach ($nodes as $nid) {
      $form['weight_' . $nid] = array(
        '#type' => 'select',
        '#title' => t('Weight'),
        '#options' => array(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10),
        '#default_value' => $counter, 
        '#attributes' => array('class' => 'scs_weight'),
      );
      
      $counter++;
    }
    
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Create newsletter'),
    );
    
    return $form;
  }
  
  /**
   * Submit function of the node sorter page
   */
  function scs_sort_nodes_submit($form, &$form_state) {
    $nodes = array();

    foreach($form_state['values'] as $key=>$value) {
      if (ereg('weight_', $key)) {
        $nid = explode('_', $key);
        $nid = $nid[1];
        $nodes[$nid] = $value;
      }
    }
    
    //Content type
  	if (array_key_exists('newsletter_content_type', $form_state['values'])) {
		$type = $form_state['values']['newsletter_content_type'];
	} else {
		$types = variable_get('simplenews_content_types', array());
		foreach ($types as $selected) {
			$type = $selected;
		}
	}
    
    asort($nodes);
    $nodes = array_keys($nodes);
    
    _scs_create_newsletter($form_state['values']['newsletter_title'], $nodes, $form_state['values']['newsletter_toc'], $type);
  }