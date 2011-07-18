<?php

/**
 * Theme a complete newsletter.
 */
function theme_scs_newsletter_output($nodes, $toc) {
  $body = '';
  $titles = array();
  $i = 0;
  $ad1 = "<div style='text-align: center'><a href='http://openx.dev.ramsalt.com/delivery/ck.php?zoneid=4' target='_blank'><img src='http://openx.dev.ramsalt.com/delivery/avw.php?zoneid=4' border='0' alt='' /></a></div>";
  $ad2 = "<div style='text-align: center'><a href='http://openx.dev.ramsalt.com/delivery/ck.php?zoneid=5' target='_blank'><img src='http://openx.dev.ramsalt.com/delivery/avw.php?zoneid=5' border='0' alt='' /></a></div>";

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
    if ($i == 3) {
        $body .= $ad1;
    } elseif ($i == 8) {
        $body .= $ad2;
    }
    $body .= theme('scs_node_output', $node);
    $i++;
  }

  // ToC (if required)
  if ($toc) {
    $body = theme('scs_node_titles', $titles) . $body;
  }

  // Complete newsletter body
  return $body;
}

/**
 * Each selected node goes true this function to create a nice body
 */
function kr2011_scs_node_output($node) {
  $output = '';
    
  $output = '<div id="node_' . $node->nid . '" style="padding:10px 3px 0 3px;border-bottom:1px solid #cfcfcf">';
    $output .= '<h2 style="font-size:21px;margin:0 0 10px;font-family:Helvetica, sans-serif">' . $node->title . '</h2>';
    //$output .= '<p>' . node_teaser($node->body) . '</p>';
    $output .= '<p>' . l(t('Read more'), 'node/' . $node->nid, array('attributes' => array('style' => 'color:#0a2339;font-weight:700;text-decoration:none;font-family:Helvetica, sans-serif'))) . ' <span style="color:gray">' . format_date($node->created) .'</span></p>';
  $output .= '</div>';
  
  return $output;
}

function kr2011_preprocess_views_slideshow_ddblock(&$vars) {
  drupal_rebuild_theme_registry();
  $settings = $vars['views_slideshow_ddblock_slider_settings'];
  // for showing debug info
  views_slideshow_ddblock_show_content_debug_info($vars);
  if ($settings['output_type'] == 'view_fields') {
    if ($settings['view_name'] == 'news_items' && $settings['view_display_id'] == 'block_1') {
      if (!empty($vars['views_slideshow_ddblock_content'])) {
        foreach ($vars['views_slideshow_ddblock_content'] as $key1 => $result) {
          // add slide image variable
          $slider_items[$key1]['slide_image'] = views_slideshow_ddblock_add_image(
            $vars,
            // determines which imagcache preset to use, leave to 'slider_item_image'
            'slider_item_image',
            // name of CCK generated image field, change if needed.
            $result->node_data_field_pager_item_text_field_image_fid,
            // alt attribute of image or NULL
            $result->node_title,
            // cck content type for default image or NULL, change if needed
            NULL, //'ddblock_news_item',
            // cck fieldname for default image or NULL, change if needed
            NULL, //'field_image',
            // to link the image to or NULL, change if needed
            NULL // base_path() . 'node/' . $result->nid
          );
          // add slide_text variable
          if (isset($result->node_data_field_pager_item_text_field_slide_text_value)) {
            $slider_items[$key1]['slide_text'] =  check_markup($result->node_data_field_pager_item_text_field_slide_text_value);
          }
          // add slide_title variable
          if (isset($result->node_title)) {
            $slider_items[$key1]['slide_title'] =  check_plain($result->node_title);
          }
          // add slide_read_more variable and slide_node variable
          if (isset($result->nid)) {
            $slider_items[$key1]['slide_read_more'] = '<a href="' . base_path() . 'node/' .  $result->nid . '">' . t('Read more') . '</a>';
            $slider_items[$key1]['slide_node'] = base_path() . 'node/' . $result->nid;
          }
        }
      }
    }    
    $vars['views_slideshow_ddblock_slider_items'] = $slider_items;
  }
}  
/**
 * Override or insert variables into the views_slideshow_ddblock_cycle_pager_content templates.
 *   Used to convert variables from view_fields  to pager_items template variables
 *  Only used for custom pager items
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 *
 */
function kr2011_preprocess_views_slideshow_ddblock_pager_content(&$vars) {
  $settings = $vars['views_slideshow_ddblock_pager_settings'];
  // for showing debug info
  views_slideshow_ddblock_show_pager_debug_info($vars);
  if (($settings['output_type'] == 'view_fields') && 
      ($settings['pager'] == 'number-pager' || 
      $settings['pager'] == 'custom-pager' ||
      $settings['pager'] == 'scrollable-pager' )) {
    if ($settings['view_name'] == 'news_items' && $settings['view_display_id'] == 'block_1') {
      if (!empty($vars['views_slideshow_ddblock_content'])) {
        foreach ($vars['views_slideshow_ddblock_content'] as $key1 => $result) {
          // add pager_item_image variable
          $pager_items[$key1]['image'] = views_slideshow_ddblock_add_image(
            $vars,
            // determines which imagcache preset to use, leave to 'pager_item_image'
            'pager_item_image',
            // name of CCK generated image field, change if needed.
            $result->node_data_field_pager_item_text_field_image_fid,
            // alt attribute of image or NULL
            $result->node_data_field_pager_item_text_field_pager_item_text_value,
            // cck content type for default image or NULL, change if needed
            NULL, //'ddblock_news_item',
            // cck fieldname for default image or NULL, change if needed
            NULL, //'field_image',
            // to link the image to or NULL, change if needed
            NULL // base_path() . 'node/' . $result->nid
          );
          // add pager_item _text variable
          if (isset($result->node_data_field_pager_item_text_field_pager_item_text_value)) {
            $pager_items[$key1]['text'] =  check_plain($result->node_data_field_pager_item_text_field_pager_item_text_value);
          }
        }
      }
    }
    $vars['views_slideshow_ddblock_pager_items'] = $pager_items;
  }    

}
function kr2011_preprocess_views_slideshow_thumbnailhover(&$vars) {
  $options = $vars['options'];
  $view = $vars['view'];
  $rows = $vars['rows'];
  $vss_id = $view->name . '-' . $view->current_display;
  //drupal_set_message('rows: '.count($rows));
  $vars['image_count']= count($rows);
  $settings = array_merge(
    array(
      'num_divs' => sizeof($vars['rows']),
      'teasers_last' => ($options['thumbnailhover']['teasers_last']) ? TRUE : FALSE,
      'id_prefix' => '#views_slideshow_thumbnailhover_main_',
      'div_prefix' => '#views_slideshow_thumbnailhover_div_',
      'vss_id' => $vss_id,
      'view_id' => $vss_id,
    ),
    $options['views_slideshow_thumbnailhover']
  );

  // We need to go through the current js setting values to make sure the one we
  // want to add is not already there. If it is already there then append -[num]
  // to the id to make it unique.
  $slideshow_count = 1;
  $current_settings = drupal_add_js();
  foreach ($current_settings['setting'] AS $current_setting) {
    if (isset($current_setting['viewsSlideshowThumbnailHover'])) {
      $current_keys = array_keys($current_setting['viewsSlideshowThumbnailHover']);
      if (stristr($current_keys[0], '#views_slideshow_thumbnailhover_main_' . $vss_id)) {
        $slideshow_count++;
      }
    }
  }

  if ($slideshow_count > 1) {
    $vss_id .= '-' . $slideshow_count;
    $settings['vss_id'] = $vss_id;  
  }

  drupal_add_js(array('viewsSlideshowThumbnailHover' => array(
    "#views_slideshow_thumbnailhover_main_" . $vss_id => $settings)), 'setting');

  // Add the hoverIntent plugin.
  if ($settings['pager_event'] == 'hoverIntent') {
    if (module_exists('jq')) {
      $loaded_plugins = jq_plugins();
      if (!empty($loaded_plugins['hoverIntent'])) {
        jq_add('hoverIntent');
      }
    }
    if (module_exists('hoverintent')) {
      hoverintent_add();
    }
  }

  $teaser = ($options['views_slideshow_thumbnailhover']['hover_breakout'] == 'teaser') ? TRUE : FALSE;
  $hidden_elements = theme('views_slideshow_thumbnailhover_no_display_section', $view, $rows, $vss_id, $options, $teaser);
  $vars['slideshow'] = theme('views_slideshow_main_section', $vss_id, $hidden_elements, 'views_slideshow_thumbnailhover');

  $thumbnailhover = $vars['options']['views_slideshow_thumbnailhover'];
  if(count($rows)>1){
  	$vars['ctr_prev']=theme_views_slideshow_thumbnailhover_control_previous($vss_id, $view, $options);
  	$vars['ctr_next']=theme_views_slideshow_thumbnailhover_control_next($vss_id, $view, $options);
  }
  // Only show controls when there is more than one result.
  if ($settings['num_divs'] > 1) {
    if ($thumbnailhover['controls'] == 1) {
      $vars['controls_top'] = theme('views_slideshow_thumbnailhover_controls', $vss_id, $view, $options);
    }
    elseif ($thumbnailhover['controls'] == 2) {
      $vars['controls_bottom'] = theme('views_slideshow_thumbnailhover_controls', $vss_id, $view, $options);
    }
  }

  if (!$thumbnailhover['teasers_last']) {
    $vars['breakout_top'] = theme('views_slideshow_thumbnailhover_breakout_teasers', $view, $rows, $vss_id, $options);
  }
  else {
    $vars['breakout_bottom'] = theme('views_slideshow_thumbnailhover_breakout_teasers', $view, $rows, $vss_id, $options);
  }

  if ($thumbnailhover['image_count'] == 1) {
    $vars['image_count_top'] = theme('views_slideshow_thumbnailhover_image_count', $vss_id, $view, $options);
  }
  elseif ($thumbnailhover['image_count'] == 2) {
    $vars['image_count_bottom'] = theme('views_slideshow_thumbnailhover_image_count', $vss_id, $view, $options);
  }
}
function kr2011_views_slideshow_thumbnailhover_no_display_section($view, $rows, $vss_id, $options, $teaser = TRUE) {
  // Add the slideshow elements.
  $attributes['id'] = "views_slideshow_thumbnailhover_teaser_section_" . $vss_id;
  $attributes['class'] = 'views_slideshow_thumbnailhover_teaser_section views_slideshow_teaser_section';
  $attributes = drupal_attributes($attributes);

  $output = "<div$attributes>";
  foreach ($view->result as $count => $node) {
    if ($view->display_handler->uses_fields()) {
      $rendered = '';
      foreach ($options['views_slideshow_thumbnailhover']['main_fields'] as $field => $use) {
        if ($use !== 0 && is_object($view->field[$field]) && !$view->field[$field]->options['exclude']) {
          $rendered .= '<div class="views-field-'. views_css_safe($view->field[$field]->field) .'">';
          if ($view->field[$field]->label()) {
            $rendered .= '<label class="view-label-'. views_css_safe($view->field[$field]->field) . '">';
            $rendered .= $view->field[$field]->label() . ':';
            $rendered .= '</label>';
          }
		  //field-main-image-data
		  if(views_css_safe($view->field[$field]->field)=='field-main-image-data'){
		  	if(strlen($view->style_plugin->rendered_fields[$count][$field])>3){
	          	$rendered .= '<div class="views-content-'. views_css_safe($view->field[$field]->field) .'">';
	          	$rendered .=  $view->style_plugin->rendered_fields[$count][$field];
	          	$rendered .= '</div>';
	          	$rendered .= '</div>';
			}else{
			  $rendered .= '</div>';
			}
		  }else{
          	$rendered .= '<div class="views-content-'. views_css_safe($view->field[$field]->field) .'">';
          	$rendered .=  $view->style_plugin->rendered_fields[$count][$field];
          	$rendered .= '</div>';
          	$rendered .= '</div>';
		  }
        }
      }
    }
    else {
      $rendered = node_view(node_load($node->nid), $teaser, FALSE, FALSE);
    }
    $output .= theme('views_slideshow_thumbnailhover_no_display_teaser', $rendered, $vss_id, $count);
  }
  $output .= "</div>";
  return $output;
}

function kr2011_preprocess_node(&$vars){
	if($vars['type']=='Article'){
		if(strlen($vars['field_article_fakta'][0]['value'])>4){
			$vars['fakta']=$vars['field_article_fakta'][0]['safe'];
		}
		if(strlen($vars['field_teaser'][0]['value'])>2){
			$vars['ingress']=1;
			$vars['ingress_value']=$vars['field_teaser'][0]['safe'];
		}
    $updated = format_date($vars['node']->changed, 'medium');
    if($vars['node']->changed != $vars['node']->created){
      $vars['node_updated_rdfa'] = _openpublish_get_rdfa_date($vars['node']->changed, $updated);
    }
    
  //  $vars['node_created_rdfa'] = _openpublish_get_rdfa_date($vars['node']->created, $vars['node_created']);
  //  $vars['node_created_rdfa'] .= _openpublish_get_rdfa_date($vars['node']->updated, $updated);
		drupal_add_js(drupal_get_path('theme', 'kr2011').'/js/kr2011.js');
	//	print_R($vars['node']);
	}
	
}

function kr2011_preprocess_page(&$vars){
	if($vars['node']->type=='article' && strlen($vars['node']->field_deck[0]['safe'])>0){
		
		$vars['field_deck']=1;
		$vars['field_deck_value']=$vars['node']->field_deck[0]['safe'];
	}
//	print_r($vars);
	
}
