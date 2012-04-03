<?php

/**
 * Theme a complete newsletter.
 */
function kr2011_scs_newsletter_output($nodes, $toc) {
  $addedAd2 = FALSE;
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
    } elseif ($i == 7) {
        $body .= $ad2;
        $addedAd2 = TRUE;
    }
    $body .= theme('scs_node_output', $node);
    $i++;
  }
  if (!$addedAd2) {
      $body .= $ad2;
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
    foreach($vars['field_sitat'] as $sitatlinje){
      $sitater .= '<div class="sitat-line"><span>'.$sitatlinje['value'].'</span></div>';
      if(strlen($sitatlinje['value'])>2){
        $vars['sitat']=1;
      }
    }
    $vars['sitat_content']='<div class="sitat-wrapper">'.$sitater.'</div>';
    
    $updated = format_date($vars['node']->changed, 'medium');
    if($vars['node']->changed != $vars['node']->created){
      $vars['node_updated_rdfa'] = _openpublish_get_rdfa_date($vars['node']->changed, $updated);
    }
    
  //  $vars['node_created_rdfa'] = _openpublish_get_rdfa_date($vars['node']->created, $vars['node_created']);
  //  $vars['node_created_rdfa'] .= _openpublish_get_rdfa_date($vars['node']->updated, $updated);
		drupal_add_js(drupal_get_path('theme', 'kr2011').'/js/kr2011.js', 'theme', 'footer');
	//	print_R($vars['node']);
	}
  elseif($vars['type']=='bildegalleri'){

    drupal_add_js(drupal_get_path('theme', 'kr2011').'/flex/jquery.min.js');
    drupal_add_js(drupal_get_path('theme', 'kr2011').'/flex/jquery-noconflict.js');
    drupal_add_js(drupal_get_path('theme', 'kr2011').'/flex/jquery.flexslider.js', 'theme', 'header');
    drupal_add_js(drupal_get_path('theme', 'kr2011').'/flex/jquery.colorbox.js', 'theme', 'header');    
    drupal_add_css(drupal_get_path('theme', 'kr2011').'/flex/flexslider.css');
    drupal_add_css(drupal_get_path('theme', 'kr2011').'/flex/kr-flex.css');
    drupal_add_css(drupal_get_path('theme', 'kr2011').'/flex/colorbox.css');
    drupal_add_js('$(window).load(function() {
    jQuery164(".flexslider").flexslider({
      slideshow: "false",
    });
    jQuery164(".color'.$vars['nid'].'").colorbox({
    rel:"color", 
    transition:"fade",
    inline:true,
    width:"75%", 
    height:"75%"
    }); 
    
    });','inline');
    $hidden = '<div class="colorbox-images-container">';
    $html = '<div class="flexslider">
        <ul class="slides">';
    foreach ($vars['field_galleri_bilde'] as $delta => $item) {
      $html .= '<li>';
      $html .= '<a class="color'.$vars['nid'].'" href="#bilde_'.$vars['nid'].'_'.$delta.'">';
      $html .= $item['view'];
      if($vars['field_galleri_desc'][$delta]['safe'] && $vars['field_galleri_kredit'][$delta]['safe']){
        $html .= '<p>'.$vars['field_galleri_desc'][$delta]['safe'];
        $html .= '<span class="kredit">'.$vars['field_galleri_kredit'][$delta]['safe'].'</span></p>';
      }elseif($vars['field_galleri_desc'][$delta]['safe']){
        $html .= '<p>'.$vars['field_galleri_desc'][$delta]['safe'].'</p>';
      }elseif ($vars['field_galleri_kredit'][$delta]['safe']) {
        $html .= '<p><span class="kredit">'.$vars['field_galleri_kredit'][$delta]['safe'].'</span></p>';
      }
      $html .='</a>';
      $html .='</li>';
      $image = image_get_info(imagecache_create_path('slider_stort', $vars['field_galleri_bilde'][$delta]['filepath']));

      $hidden.= '<div id="bilde_'.$vars['nid'].'_'.$delta.'">
      '.theme_imagecache('slider_stort', $vars['field_galleri_bilde'][$delta]['filepath']).'
      <img src="'.imagecache_create_path('slider_stort', $vars['field_galleri_bilde'][$delta]['filepath']).'">
      <div class="caption" style="width: '.$image['width'].'px;">'.$vars['field_galleri_desc'][$delta]['safe'].'</div>
      </div>';
    }
    $html .='</ul></div>';
    $hidden .='</div>';
    $vars['content'] = $html. $hidden;
  }
}
function kr2011_preprocess_page(&$vars){
	if($vars['node']->type=='article' && strlen($vars['node']->field_deck[0]['safe'])>0){
		
		$vars['field_deck']=1;
		$vars['field_deck_value']=$vars['node']->field_deck[0]['safe'];
	}
//print '<pre>';	print_r($vars); print '</pre>';
	
}

function kr2011_form($element){
  
   // Anonymous div to satisfy XHTML compliance.
  $action = $element['#action'] ? 'action="' . check_url($element['#action']) . '" ' : '';
  $element['#title'] = 'Hei der';
  return '<form ' . $action . ' accept-charset="UTF-8" method="' . $element['#method'] . '" id="' . $element['#id'] . '"' . drupal_attributes($element['#attributes']) . ">\n<div>" . $element['#children'] . "\n</div></form>\n";
}


function kr2011_views_view_field__comment_count($view, $field, $row){

  // check if node has comments
  if(intval($view->result[0]->node_comment_statistics_comment_count)<1 || intval($view->field[$field->options['id']]->render($row))<1){
    // do nothing
    
    //drupal_set_message('ja');
  }else{
    // if comments, return field
 //   dpm(get_class_methods($view->field[$field->options['id']]));
 //   var_dump(intval($view->field[$field->options['id']]->render($row)));
 //   drupal_set_message('s: '.intval($view->field[$field->options['id']]->render($row)));
    $html = $view->field[$field->options['id']]->advanced_render($row);
    //drupal_set_message('html: '.$html);
    if(strlen($html)>70){
      //drupal_set_message(strlen($html));
      return $html;
    }
  }
  

}
function kr2011_preprocess_block(&$variables) {
  
  // unset fb_comment block
  if($variables['block']->bid == 'fb_social_comments-comments'){
    $node =  node_load(arg(1));
    
    if($node->field_fb_comments[0]['value'] != 1){
      unset($variables['block']->content);
    }
  }
  static $block_counter = array();
  // All blocks get an independent counter for each region.
  if (!isset($block_counter[$variables['block']->region])) {
    $block_counter[$variables['block']->region] = 1;
  }
  // Same with zebra striping.
  $variables['block_zebra'] = ($block_counter[$variables['block']->region] % 2) ? 'odd' : 'even';
  $variables['block_id'] = $block_counter[$variables['block']->region]++;

  $variables['template_files'][] = 'block-' . $variables['block']->region;
  $variables['template_files'][] = 'block-' . $variables['block']->module;
  $variables['template_files'][] = 'block-' . $variables['block']->module . '-' . $variables['block']->delta;
}

function kr2011_nopremium_message($node){
  global $user;

  // Check if this is a free account disabled or has just authenticated role
  if (isset($user->roles[12]) || !(count($user->roles) && isset($user->roles[1])) ) {
      $block = module_invoke('boxes', 'block', 'view', 'premium_box_disabled_user');
  } else {
    $html = check_markup(t(nopremium_get_message($node->type)));
    $html .= '<p>';
    $html .= 'Logg inn | ';
    $html .= l(t('Register'), 'user/register',array('query' => array('destination' => 'node/'.$node->nid))).' | ';
    // $html .= l(t('Login'), 'user',array('query' => array('destination' => 'node/'.$node->nid))).' | ';
    $html .= l(t('Request new password'), 'user/password',array('query' => array('destination' => 'node/'.$node->nid)));
    $html .= '</p>';
    $block = module_invoke('user', 'block', 'view', '0');
  }
  
  $html .= $block['content'];
  return $html;
}
function kr2011_content_multigroup_display_table_multiple($element) {
  $headers = array();
  foreach ($element['#fields'] as $field_name => $field) {
    $label_display = isset($field['display_settings']['label']['format']) ? $field['display_settings']['label']['format'] : 'above';
    $headers[] = array(
      'data' => ($label_display != 'hidden' ? check_plain(t($field['widget']['label'])) : ''),
      'class' => 'content-multigroup-cell-'. str_replace('_', '-', $field_name),
    );
  }
  $rows = array();
  foreach (element_children($element) as $delta) {
    $cells = array();
    $empty = TRUE;
    foreach ($element['#fields'] as $field_name => $field) {
      $item = drupal_render($element[$delta][$field_name]);
      
      if($element[$delta][$field_name]['#field_name']== 'field_periode_til' && empty($item)){
        $item = '
        <div class="field field-type-date field-field-periode-til"> <div class="field-label">Til:&nbsp;</div> <div class="field-items"> <div class="field-item odd"> <span class="date-display-single">--></span> </div> </div> </div> 
        ';
      }
      
      $cells[] = array(
        'data' => $item,
        'class' => $element[$delta]['#attributes']['class'] .' content-multigroup-cell-'. str_replace('_', '-', $field_name),
      );
      if (!empty($item)) {
        $empty = FALSE;
      }
    }
    // Get the row only if there is at least one non-empty field.
    if (!$empty) {
      $rows[] = $cells;
    }
  }

  return count($rows) ? theme('table', $headers, $rows, $element['#attributes']) : '';
}
/**
 * Registers overrides for various functions.
 *
 * In this case, overrides three user functions
 */
/*
function kr2011_theme() {
  return array(
    'user_login' => array(
      'template' => 'user-login',
      'arguments' => array('form' => NULL),
    ),
    'user_register' => array(
      'template' => 'user-register',
      'arguments' => array('form' => NULL),
    ),
    'user_pass' => array(
      'template' => 'user-pass',
      'arguments' => array('form' => NULL),
    ),
  );
}
*/
/*
function kr2011_preprocess_user_register(&$variables) {
  $variables['intro_text'] = t('This is my super awesome reg form');
  $variables['rendered'] = drupal_render($variables['form']);
}

 */