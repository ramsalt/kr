<?php
function kr2012_byline($node){
	$antall_forfattere = count($node->field_op_author);
	if($antall_forfattere > 0){
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
      $updated_html = '<div class="updated">(Oppdatert: '._openpublish_get_rdfa_date($node->changed, $updated).')</div>';
    }
	$html .= $forfattere_html. $created_html.$updated_html .'<div class="addthis">'.theme(variable_get('addthis_widget_type', 'addthis_button')).'</div>';
	return $html;
}
function kr2012_preprocess_node(&$vars){
	$byline = kr2012_byline($vars['node']);
	$vars['byline'] = $byline;
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
    drupal_add_js(drupal_get_path('theme', 'kr2011').'/flex/bilde.js', 'theme', 'header');
    
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
	$byline = kr2012_byline($vars['node']);
	$vars['byline'] = $byline;
}
?>