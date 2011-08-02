<?php

/**
 * TIP: An example of importing from an XML feed where both the id and the
 * data to import are in the same file.  The id is a part of the data.  See
 * the file in the xml directory - producers.xml which contains all IDs and
 * producer data for this example.
 *
 * Note that, if basing a migration on an XML source, you need to derive it
 * from XMLMigration instead of Migration.
 */
class ArticlesMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->description = t('Articles from kommunal-rapport.no');
    //$this->dependencies = array('');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'krid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Article ID',
          'alias' => 'a',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $query = db_select('kr_import_articles', 'a')
             ->fields('a', array('krid', 'title', 'objid', 'data', 'locked', 'hidden', 'sections', 'created', 'modified', 'expire'))
						 ->condition('subid', 0)
             ->condition('objecttype', 'article');

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query);
		
    $this->destination = new MigrateDestinationNode('article');

		$this->addSimpleMappings(array('title', 'body'));
		$this->addFieldMapping('uid')
         ->defaultValue(1);
		$this->addFieldMapping('promote')
         ->defaultValue(0);
		$this->addFieldMapping('status')
         ->defaultValue(1);
		$this->addFieldMapping('field_articletype', 'article_type');
		$this->addFieldMapping('field_teaser', 'caption');
		$this->addFieldMapping('created', 'created')
				->callbacks('strtotime');
		$this->addFieldMapping('changed', 'modified')
				->callbacks('strtotime');
    $this->addFieldMapping('Kategori', 'categories')
				->separator('|');
		$this->addFieldMapping('field_fb_comments')
        ->defaultValue(1);
	  $this->addFieldMapping('field_op_author', 'author_id');			
		$this->addFieldMapping('field_show_author_info', 'show_author');		
				
		
		$this->addUnmigratedSources(array('hidden', 'locked'));
	}

	public function complete($entity, $source_row) {
			//drush_print_r($entity);
		/*
		$pattern = array(
			'/index.db2\?id\=(\d+)/', 
			'/id\/(\d+)/',
			'/<img[^>]+\>/i',
		); 

		$repl = array(
			'node/$1',
			'node/$1',
			'(image) ',
		);

		$entity->body = preg_replace($pattern, $repl, $entity->body);
		node_save($entity);

		*/
		// Replace old paths
	}
	
	public function prepareRow($current_row) {
		$current_row->data = unserialize($current_row->data);
		$current_row->sections = unserialize($current_row->sections);
		$current_row->body = $current_row->data['body'];
		$old = array('src="image/', 'src="cache/image/');
		$new   = array('src="/sites/default/files/imp_images/', 'src="/sites/default/files/imp_images/');
		$current_row->body = str_replace($old, $new, $current_row->body);
		
		$current_row->caption = $current_row->data['caption'];
		$current_row->payment_code = $current_row->data['betalingskode'];
		$current_row->payment_code = $current_row->data['betalingskode'];
		$current_row->article_type = $current_row->data['articletype'];
		$current_row->author = unserialize($current_row->data['author']);
		$current_row->free = $current_row->data['free'];
		
		$categories = array();
		foreach ($current_row->sections as $key => $section) {
			$query = db_select('kr_import_topics', 't')
             ->fields('t', array('title', 'objid'))
						 ->condition('objid', $section['objid']);
			$result = $query->execute();
		
			foreach($result as $row) {
				$categories[] = $row->title;
			}
		}
		$current_row->categories = implode('|', $categories);
		
		drush_print_r($current_row->author[0]['name']);
		$current_row->show_author = 0;
		
		if($current_row->author[0]['name']) {
			$query = db_select('node', 'n')
             ->fields('n', array('nid'))
             ->condition('type', 'author')
						 ->condition('title', $current_row->author[0]['name']);
			$result = $query->execute();
			if($record = $result->fetchObject()) {
				drush_print('Already exists: '.$current_row->title);
				$current_row->author_id = $record->nid;
				$current_row->show_author = 1;
			} else {
				drush_print('Not exists: '.$current_row->title);
				
				$current_row->body = $current_row->body.'<p class="author-info">'.t('Skrevet av: @author', array('@author'=>$current_row->author[0]['name'])).'</p>';
			}
			//show author må settes.
		}
		
	

    return TRUE;
  }
}

class TopicsMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->description = t('Import Topics');
    //$this->dependencies = array('');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Row ID',
          'alias' => 'a',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $query = db_select('kr_import_topics', 'a')
             ->fields('a', array('title', 'id'))
						 ->condition('mapable', 1);

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query);
		
    $this->destination = new MigrateDestinationTerm('Kategori');

		$this->addFieldMapping('name', 'title');
	}
	
	public function prepareRow($current_row) {
		$query = db_select('term_data', 't')
             ->fields('t', array('name'))
						 ->condition('name', $current_row->title);
		$result = $query->execute();
		
		if($record = $result->fetchObject()) {
			drush_print('Already exists: '.$current_row->title);
			return FALSE;
		}
		
    return TRUE;
  }
}
/*
 * Not in use. Too slow. 
class ArticlesStructureXMLMigration extends XMLMigration {
  public function __construct() {
    parent::__construct();
    $this->description = t('Import XML structure from kommunal-rapport.no');
    //$this->dependencies = array('');

    // There isn't a consistent way to automatically identify appropriate "fields"
    // from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'locked' => t('Is this accessible for non members'),
      'created' => t('When was the article created'),
      'modified' => t('When was the article modified'),
      'region' => t('Name of region'),
    );

    // The source ID here is the one retrieved from each data item in the XML file, and
    // used to identify specific items
		$this->map = new MigrateSQLMap($this->machineName,
			array(
				'style' => array('type' => 'varchar',
					'length' => 255,
					'not null' => TRUE,
					'description' => 'Object ID',
				)
       ),
			MigrateDestinationTerm::getKeySchema()
		);


    // This can also be an URL instead of a file path.
    $xml_folder = drupal_get_path('module', 'kr_import') . '/xml/';
    $items_url = $xml_folder . 'kommunal-rapport.xml';

    // We use the MigrateSourceMultiItems class for any source where we obtain the list
    // of IDs to process and the data for each item from the same file. Typically the data
    // for an item is not contained in a single line within the source file. Examples include
    // multiple items defined in a single xml file or a single json file where in both cases
    // the id is part of the item.

    $item_xpath = 'obj';  // relative to document

    $item_ID_xpath = 'objid';         // relative to item_xpath and gets assembled
                                         // into full path /producers/producer/sourceid

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);

    $this->destination = new MigrateDestinationTable('kr_import_articles');

    // TIP: Note that for XML sources, in addition to the source field passed to
    // addFieldMapping (the name under which it will be saved in the data row
    // passed through the migration process) we specify the Xpath used to retrieve
    // the value from the XML.
    // TIP: Note that all xpaths for fields begin at the last element of the item
    // xpath since each item xml chunk is processed individually.
    // (ex. xpath=name is equivalent to a full xpath of /producers/producer/name)
		
		$this->addFieldMapping('title', 'name')
         ->xpath('data/field[@name="title"]');
		
		$this->addFieldMapping('data', 'data')
     		 ->description('Serialized data array.');
		
		$this->addFieldMapping('sections', 'sections')
     		 ->description('Serialized data array.');
		 
		$this->addFieldMapping('created', 'created')
         ->xpath('created');
		
		$this->addFieldMapping('modified', 'modified')
         ->xpath('modified');
		
		$this->addFieldMapping('objecttype', 'objecttype')
         ->xpath('objecttype');
		
		$this->addFieldMapping('objid', 'objid')
         ->xpath('objid');
		
		$this->addFieldMapping('parobjid', 'parobjid')
         ->xpath('parobjid');
		
		$this->addFieldMapping('hidden', 'hidden')
         ->xpath('hidden');
		
		$this->addFieldMapping('locked', 'locked')
         ->xpath('locked');

		$this->addFieldMapping('subid', 'subid')
         ->xpath('subid');

		$this->addFieldMapping('parsubid', 'parsubid')
         ->xpath('parsubid');	

		$this->addFieldMapping('pos', 'pos')
         ->xpath('pos');
		
		$this->addFieldMapping('inspire', 'inspire')
         ->xpath('inspire');
				 
		$this->addFieldMapping('expire', 'expire')
         ->xpath('expire');
		
		$this->addFieldMapping('canvas', 'canvas')
         ->xpath('canvas');
 
	}	


	// TIP: Implement a prepareRow() method to manipulate the source row between
  // retrieval from the database and the automatic applicaton of mappings
  public function prepareRow($current_row) {
		$sections = array();
		foreach($current_row->xml->sections->section as $section) {
			$sections[] = array('objid'=>(string)$section['objid'], 'subid'=>(string)$section['subid']);
		}

		$current_row->sections = serialize($sections);
		
		$data = array();
  	foreach($current_row->xml->data->field as $field) {
			$data_key = isset($field['name']) ? (string)$field['name'] : $key;
			$data[$data_key] = (string)$field;
			
  	}
		$current_row->data = serialize($data);
		
    return TRUE;
  }
}
*/
