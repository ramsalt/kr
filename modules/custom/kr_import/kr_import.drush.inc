<?php

/**
 * Implementation of hook_drush_command().
 */
function kr_import_drush_command() {
  $items['kr-import-xmltodb'] = array(
    'description' => 'List all migrations with current status.',
    'drupal dependencies' => array('migrate'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'aliases' => array('kit'),
  );
	
	$items['kr-import-hierarchy'] = array(
    'description' => 'Show hierarchy of folders.',
    'drupal dependencies' => array('migrate'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'aliases' => array('kih'),
  );
  return $items;
}

function drush_kr_import_hierarchy () {
	$query = db_select('kr_import_articles', 'kia');
	$query
		->condition('objecttype', 'folder')
		->fields('kia', array('title', 'objid', 'parobjid'))
		->orderby('objid', 'ASC');
	$result = $query->execute();
		
	$structure = array(1=>array('children'=>array()));
	foreach($result as $row) {
		$structure = _drush_kr_import_hierarchy_add($structure, $row);
	}
	drush_print_r($structure);
}

function _drush_kr_import_hierarchy_add ($structure, $item, $depth = 0) {
	drush_print($item->title.' '.$item->objid.' '.$item->parobjid);
	foreach($structure as $key => $level) {
		if($key == $item->parobjid) {
			$structure[$item->parobjid]['depth'] = $depth;
			$structure[$item->parobjid]['children'][$item->objid]['data'] = $item->title;
			if(!isset($structure[$item->parobjid]['children'][$item->objid]['children'])){
				$structure[$item->parobjid]['children'][$item->objid]['children'] = array();
			}
		} else {
			$depth++;
			$structure[$key]['children'] = _drush_kr_import_hierarchy_add($structure[$key]['children'], $item, $depth);
		}
	}
	return $structure;
}

function drush_kr_import_xmltodb () {
		// This can also be an URL instead of a file path.
    $xml_folder = drupal_get_path('module', 'kr_import') . '/xml/';
    $items_url = $xml_folder . 'kommunal-rapport.xml';
		$xml = simplexml_load_file($items_url);
		
		$count = 0;
		$round = 0;
		foreach ($xml->obj as $obj) {
			$values = array(
				'objid' => (string) $obj->objid,
	    	'objecttype' => (string) $obj->objecttype,
	    	'locked' => (int) $obj->locked,
	    	'hidden' => (int) $obj->hidden,
	    	'parobjid' => (int) $obj->parobjid,
	    	'created' => (string) $obj->created,
	    	'modified' => (string) $obj->modified,
	    	'subid' => (int) $obj->subid,
	    	'parsubid' => (int) $obj->parsubid,
	    	'pos' => (int) $obj->pos,
	    	'inspire' => (string) $obj->inspire,
	    	'expire' => (string) $obj->expire,
	    	'canvas' => (string) $obj->canvas,
			);
			
			$sections = array();
			foreach($obj->sections->section as $section) {
				$sections[] = array('objid'=>(string)$section['objid'], 'subid'=>(string)$section['subid']);
			}
			
			_kr_import_save_sections($sections);
			$values['sections'] = serialize($sections);
			
		
			$data = array();
  		foreach($obj->data->field as $field) {
  			if($field['name'] == 'title') {
  				$values['title'] =  (string)$field;
  			}
				
				$data_key = isset($field['name']) ? (string)$field['name'] : $key;
				$data[$data_key] = (string)$field;
  		}
			
			$values['data'] = serialize($data);
			
			_kr_import_save_import_row($values);
			if($values['objecttype'] == 'article') {
				_kr_import_save_attribute_row($values['objid'], $data);	
			}
			
			if($round == 100) {
				//break;
				drush_print('Parsed '.$count);
				$round = 0;
			}
			$round++;
			$count++;
		}		
}

function _kr_import_save_sections ($sections) {
	foreach ($sections as $section) {
		if($section['objid']) {
			$query = db_select('kr_import_articles', 'a')
             ->fields('a', array('title', 'objid'))
						 ->condition('objid', $section['objid']);
			$result = $query->execute();
		
			$row = $result->fetchObject();
			if($row->title) {
				$id = db_merge('kr_import_topics')
					->key(array('title' => $row->title))
  				->fields(array(
    			'title' => $row->title,
  			))
  			->execute();	
			}
		}
	}
}

function _kr_import_save_attribute_row ($objid, $values) {
	$id = db_merge('kr_import_articles_attributes')
  	->key(array('objid' => $objid))
  	->fields(array(
     	//'objid' => $objid,
    	'title' => $values['title'],
    	'body' => $values['body'],
    	'caption' => $values['caption'],
    	'author' => $values['author'],
    	'utgavenr' => $values['utgavenr'],
    	'utgaveaar' => $values['utgaveaar'],
    	'betalingskode' => $values['betalingskode'],
    	'articletype' => $values['articletype'],
    	'free' => $values['free'],
  ))
  ->execute();
}

function _kr_import_save_import_row ($values) {
	$id = db_insert('kr_import_articles')
  	->fields(array(
    	'objid' => $values['objid'],
    	'title' => $values['title'],
    	'data' => $values['data'],
    	'sections' => $values['sections'],
    	'objecttype' => $values['objecttype'],
    	'locked' => $values['locked'],
    	'hidden' => $values['hidden'],
    	'parobjid' => $values['parobjid'],
    	'created' => $values['created'],
    	'modified' => $values['modified'],
    	'subid' => $values['subid'],
    	'parsubid' => $values['parsubid'],
    	'pos' => $values['pos'],
    	'inspire' => $values['inspire'],
    	'expire' => $values['expire'],
    	'canvas' => $values['canvas'],
  ))
  ->execute();
}

