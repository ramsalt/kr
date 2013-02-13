<?php


/**
 * Theme a complete newsletter.
 */
function kr2012_scs_newsletter_output($nodes, $toc) {
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
function kr2012_scs_node_output($node) {
  $output = '';
    
  $output = '<div id="node_' . $node->nid . '" style="padding:10px 3px 0 3px;border-bottom:1px solid #cfcfcf">';
    $output .= '<h2 style="font-size:21px;margin:0 0 10px;font-family:Helvetica, sans-serif">' . $node->title . '</h2>';
    //$output .= '<p>' . node_teaser($node->body) . '</p>';
    $output .= '<p>' . l(t('Read more'), 'node/' . $node->nid, array('attributes' => array('style' => 'color:#0a2339;font-weight:700;text-decoration:none;font-family:Helvetica, sans-serif'))) . ' <span style="color:gray">' . format_date($node->created) .'</span></p>';
  $output .= '</div>';
  
  return $output;
}

function phptemplate_preprocess_node(&$vars, $hook) {
  $node = $vars['node'];
  $vars['template_file'] = 'node-'. $node->nid;
}
function kr2012_byline($node){
	$antall_forfattere = count($node->field_op_author);
	if($antall_forfattere > 0 && $node->field_op_author[0]['nid'] != NULL){
		$nummer = 1;
		$forfattere_html = '<div class="forfatter">Av ';
		foreach($node->field_op_author as $delta => $author){
			if(($nummer == 1 && $antall_forfattere == 1) || ($antall_forfattere > 1 && $nummer == $antall_forfattere)){
				$forfattere_html .= $author['view'];
			}
			elseif(($antall_forfattere == 2 && $nummer == 1) || ($antall_forfattere > 2 && $nummer == ($antall_forfattere-1))){
				$forfattere_html .= $author['view'] . ' og ';
			}
			else{
				$forfattere_html .= $author['view'] . ', ';
			}
			$nummer++;
		}
		$forfattere_html.='</div>';
	}
	$created = format_date($node->created, 'medium');
    $updated = format_date($node->changed, 'medium');
	$created_html = '<div class="created">'._openpublish_get_rdfa_date($node->created, $created).'</div>';
	$updated_html = '';
    if($node->changed != $node->created){
      $updated_html = '<div class="updated"> (Oppdatert: '._openpublish_get_rdfa_date($node->changed, $updated).')</div>';
    }
	$html .= $forfattere_html. $created_html.$updated_html .'<div class="addthis">'.theme(variable_get('addthis_widget_type', 'addthis_button')).'</div>';
	return $html;
}
function kr2012_preprocess_node(&$vars){
	$byline = kr2012_byline($vars['node']);
	$vars['byline'] = $byline;
	
	$vars['title'] = check_plain(strip_tags(str_replace('&#173;', '', $vars['node']->title)));
	//$vars['title'] = str_replace('&hyphen;', '', $vars['title']);
	if($vars['type']=='Article'){
		if(strlen($vars['field_article_fakta'][0]['value'])>4){
			$vars['fakta']=$vars['field_article_fakta'][0]['safe'];
		}
		if(strlen($vars['field_teaser'][0]['value'])>2){
			$vars['ingress']=1;
			$vars['ingress_value']=$vars['field_teaser'][0]['safe'];
		}
	if(isset($vars['field_sitat'])){
	    foreach($vars['field_sitat'] as $sitatlinje){
	      $sitater .= '<div class="sitat-line"><div class="mark"></div><span>'.$sitatlinje['value'].'</span></div>';
	      if(strlen($sitatlinje['value'])>2){
	        $vars['sitat']=1;
	      }
	    }
	    $vars['sitat_content']='<div class="sitat-wrapper">'.$sitater.'</div>';
	}
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

    drupal_add_js(drupal_get_path('theme', 'kr2012').'/flex/jquery.min.js');
    drupal_add_js(drupal_get_path('theme', 'kr2012').'/flex/jquery-noconflict.js');
    drupal_add_js(drupal_get_path('theme', 'kr2012').'/flex/jquery.flexslider.js', 'theme', 'header');
    drupal_add_js(drupal_get_path('theme', 'kr2012').'/flex/jquery.colorbox.js', 'theme', 'header');    
    drupal_add_css(drupal_get_path('theme', 'kr2012').'/flex/flexslider.css');
    drupal_add_css(drupal_get_path('theme', 'kr2012').'/flex/kr-flex.css');
    drupal_add_css(drupal_get_path('theme', 'kr2012').'/flex/colorbox.css');
    drupal_add_js(drupal_get_path('theme', 'kr2012').'/flex/bilde.js', 'theme', 'header');
    
    $hidden = '<div class="colorbox-images-container">';
    $html = '<div class="flexslider">
        <ul class="slides">';
    foreach ($vars['field_galleri_bilde'] as $delta => $item) {
      $html .= '<li>';
      $html .= '<a class="colorboks1" href="#bilde_'.$vars['nid'].'_'.$delta.'">';
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
      $hidden.= '<div id="bilde_'.$vars['nid'].'_'.$delta.'" class="cimage">
      '.theme_imagecache('slider_stort', $vars['field_galleri_bilde'][$delta]['filepath']).'
      
      <div class="caption">'.$vars['field_galleri_desc'][$delta]['safe'].'</div>
      </div>';
    }
    $html .='</ul></div>';
    $hidden .='</div>';
    $vars['content'] = $html;
    $vars['content'] .=$hidden;
  }
  elseif($vars['type'] == 'eksternt_blogginnlegg'){
    $blogcontent = node_load($vars['nid']);
    $blog = node_load($blogcontent->feeds_node_item->feed_nid);
    $html = '<div class="bloginfo">';
    $html.='<div class="section-date-author">';
    $date_label= date('d. ',$blogcontent->created).t(date('M',$blogcontent->created)).date(' Y - H:i',$blogcontent->created);
    $html.=_openpublish_get_rdfa_date($blogcontent->created, $date_label);
    $html.=' | Fra bloggen: '.l($blog->title, 'node/'.$blog->nid);
    $html.='</div></div>';
    $html2 = '<div class="bloggfooter">Dette blogginnlegget er hentet fra: '.l($blogcontent->feeds_node_item->url, $blogcontent->feeds_node_item->url).'</div>';
    $vars['content'] = $html.$vars['content'].$html2;
  }
  
  
}

function kr2012_preprocess_page(&$vars){
	if(drupal_is_front_page()){
		drupal_add_js(drupal_get_path('theme', 'kr2012').'/js/front.js', 'theme', 'header');		
		drupal_add_css(drupal_get_path('theme', 'kr2012').'/css/jcar.css');
		
	}
	if($vars['node']->nid == 94892){
		//$vars['head'] .= '<script src="http://service.utdanning.no/finn/scripts/ajax-solr-complete.min.js"></script>';
		drupal_add_js(drupal_get_path('theme', 'kr2012').'/js/utdanning.js', 'theme', 'header');	
		
	}
	$byline = kr2012_byline($vars['node']);
	$vars['byline'] = $byline;
	
	if($vars['node'] && module_exists('node_class')){
		$vars['body_classes'] .= ' '.node_class($vars['node']);
	}
	
}
function kr2012_nopremium_message($node){
	global $user;

	  // Check if this is a free account disabled or has just authenticated role
	if (isset($user->roles[2]) && $user->sms_user['status'] != 2) {
		$block = module_invoke('boxes', 'block', 'view', 'premium_box_non_authenticated');
	} else if (isset($user->roles[12]) || !(count($user->roles) && isset($user->roles[1])) ) {
        $block = module_invoke('boxes', 'block', 'view', 'premium_box_disabled_user');
	} else {
		$html ='<div class="msg">';
	    $html.=check_markup(t(nopremium_get_message($node->type)));
		//$html .= 'Logg inn | ';
		$html .= l('<span>Registrere deg her</span>', 'user/register', array('html' => true, 'attributes' => array('class' => 'registerhere'),'query' => array('destination' => 'node/'.$node->nid)));
		$html .='</div>';
		$html .= '<div class="hr"></div>';
		// $html .= l(t('Login'), 'user',array('query' => array('destination' => 'node/'.$node->nid))).' | ';
		//$html .= l(t('Request new password'), 'user/password',array('query' => array('destination' => 'node/'.$node->nid)));
		$block = module_invoke('user', 'block', 'view', '0');
	}
  
  $html .= $block['content'];
  return $html;
}
function kr2012_nopremium_body($node) {
  $output  = $node->teaser;
  $output .= '<div class="nopremium-message clearfix">'. $node->nopremium_message .'</div>';
  return $output;
}
function kr2012_preprocess_block(&$variables, $hook){
	//print_r($variables);
	if($variables['block']->module == 'cck_blocks' && $variables['block']->bid == 'cck_blocks-field_stilling_geopos'){
		$nid = arg(1);
		if(is_numeric($nid)){
			$node = node_load($nid);
			if(strlen($node->field_stilling_geopos[0]['openlayers_wkt'])>0){
				
			}else{
				unset($variables['block']->content);
				unset($variables['block']->subject);
			}
		}
  	}
}
function kr2012_preprocess_search_result(&$variables) {
  global $language;

  $result = $variables['result'];
  $variables['url'] = check_url($result['link']);
  $variables['url'] = str_replace('178.79.186.243', 'kommunal-rapport.no', $variables['url']);
  $variables['title'] = check_plain($result['title']);
  if (isset($result['language']) && $result['language'] != $language->language && $result['language'] != LANGUAGE_NONE) {
    $variables['title_attributes_array']['xml:lang'] = $result['language'];
    $variables['content_attributes_array']['xml:lang'] = $result['language'];
  }

  $info = array();
  if (!empty($result['module'])) {
    $info['module'] = check_plain($result['module']);
  }
  if (!empty($result['user'])) {
    $info['user'] = $result['user'];
  }
  if (!empty($result['date'])) {
    $info['date'] = format_date($result['date'], 'short');
  }
  if (isset($result['extra']) && is_array($result['extra'])) {
    $info = array_merge($info, $result['extra']);
  }
  // Check for existence. User search does not include snippets.
  //$variables['snippet'] = isset($result['snippet']) ? $result['snippet'] : '';
  //dsm($variables);
  $node = node_load($variables['result']['node']->entity_id);
  $variables['snippet'] = strip_tags($node->teaser);
  if(isset($node->field_main_image['und'][0])){
  	$variables['img'] = theme_imagecache('thumbnail', $node->field_main_image['und'][0]['filepath']);
  }
  
  // Provide separated and grouped meta information..
  $variables['info_split'] = $info;
  $variables['info'] = implode(' - ', $info);
  $variables['theme_hook_suggestions'][] = 'search_result__' . $variables['module'];
  
}
?>