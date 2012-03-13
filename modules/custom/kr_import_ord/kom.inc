<?php
class OrdMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->description = t('Legg inn ordf');
    
    $query = db_select('webform_submissions', 's')
             ->fields('s', array('sid'))
						 ->condition('nid', 82560);

    // Create a MigrateSource object, which manages retrieving the input data.
    $source_fields = array(
      'title' => t('The name of ordf'),
      'born' => 'born year',
      'mob' => 'mob',
      'parti' => 'parti',
      'mail' => 'mail',
      'ord_for' => 'ord_for',
      'med_kom' => 'med kommunestyret',
      'yrke_for' => 'yrke_for',
      'perm' => 'permission eller ikke',
      'utd' => 'utdanning',
      'utd_som' => 'utdannet som',
      'stilling_str' => 'Hvor stor stilling tilsv',
      'stilling_fast' => 'Hvordan fastsettes godt',
      'stilling_prosent' => 'prosent',
      'hobby' => 'hobby',
      'forfatter' => 'forfatter',
      'artist' => 'artist',
      'org' => 'org',
      'beste' => 'beste',
      'slag' => 'slag',
      'kommune' => 'kommune',
      'periodestart' => 'periodestart',
      'image_file_fid' => 'image_file_fid'
      
      
      
    );
    $this->source = new MigrateSourceSQL($query, $source_fields);
    $this->destination = new MigrateDestinationNode('ordforer');
    $this->map = new MigrateSQLMap($this->machineName,
        array('sid' => array( // this field is used to connect user und profile2
                'type' => 'varchar',
                'length' => 6,
                'not null' => TRUE,
                'description' => 'sid' // description never used
              )
             ),
        MigrateDestinationNode::getKeySchema()
    );
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_ordf_born', 'born');
    $this->addFieldMapping('field_ordf_mob', 'mob');
    $this->addFieldMapping('field_ordf_parti', 'parti');
    $this->addFieldMapping('field_ordf_mail', 'mail');
    $this->addFieldMapping('field_ordf_ar_forst', 'ord_for');
    $this->addFieldMapping('field_ordf_lenge_med_kom', 'med_kom');
    $this->addFieldMapping('field_ordf_yrke_for', 'yrke_for');
    $this->addFieldMapping('field_ordf_perm', 'perm'); 
    $this->addFieldMapping('field_ordf_utd', 'utd'); 
    $this->addFieldMapping('field_ordf_utdan_som', 'utd_som');
    $this->addFieldMapping('field_ordf_stilling_str', 'stilling_str');
    $this->addFieldMapping('field_ord_stilling_fast', 'stilling_fast');
    $this->addFieldMapping('field_stilling_prosent', 'stilling_prosent');
    $this->addFieldMapping('field_ordf_hobby', 'hobby');
    $this->addFieldMapping('field_ordf_forfatter', 'forfatter');
    $this->addFieldMapping('field_ordf_artist', 'artist');
    $this->addFieldMapping('field_ordf_org_med', 'org');
    $this->addFieldMapping('field_ordf_beste', 'beste');
    $this->addFieldMapping('field_ordf_slag', 'slag');
   
    $this->addFieldMapping('field_rel_kommune', 'kommune');
    $this->addFieldMapping('field_ordf_perioder', 'periodestart'); 
    
    $this->addFieldMapping('field_ordf_bilde', 'image_file_fid')
         ->arguments(array('file_function' => 'file_copy'));
    
   
  }
  public function prepareRow($current_row) {

    $query = db_select('webform_submitted_data', 'd')
           ->fields('d', array('data'))
           ->condition('cid', 1)
    			 ->condition('sid', $current_row->sid);
    $result = $query->execute();
    if($record = $result->fetchObject()) {
      $current_row->title = $record->data;
    }

    $query = db_select('webform_submitted_data', 'd')
           ->fields('d', array('data'))
           ->condition('cid', 2)
    			 ->condition('sid', $current_row->sid);
    $result = $query->execute();
    if($record = $result->fetchObject()) {
      $current_row->mob = $record->data;
    }

    $query = db_select('webform_submitted_data', 'd')
           ->fields('d', array('data'))
           ->condition('cid', 3)
    			 ->condition('sid', $current_row->sid);
    $result = $query->execute();
    if($record = $result->fetchObject()) {
      $current_row->mail = $record->data;
    }
    $query = db_select('webform_submitted_data', 'd')
           ->fields('d', array('data'))
           ->condition('cid', 6)
    			 ->condition('sid', $current_row->sid);
    $result = $query->execute();
    if($record = $result->fetchObject()) {
      $current_row->parti = $record->data;
    }

    $query = db_select('webform_submitted_data', 'd')
           ->fields('d', array('data'))
           ->condition('cid', 7)
    			 ->condition('sid', $current_row->sid);
    $result = $query->execute();
    if($record = $result->fetchObject()) {
      if(strlen($record->data) == 4){
        $year = new DateTime('10/10/'.$record->data);
        $current_row->born = $year->format('U');
      }
    }   
    
     $query = db_select('webform_submitted_data', 'd')
            ->fields('d', array('data'))
            ->condition('cid', 8)
     			 ->condition('sid', $current_row->sid);
     $result = $query->execute();
     if($record = $result->fetchObject()) {
       $current_row->ord_for = $record->data;
       if(strlen($current_row->ord_for) == 4){
        $year2 = new DateTime('10/10/'.$record->data);
        $current_row->periodestart = $year2->format('U');
       }
     }   
     
     $query = db_select('webform_submitted_data', 'd')
            ->fields('d', array('data'))
            ->condition('cid', 9)
     			 ->condition('sid', $current_row->sid);
     $result = $query->execute();
     if($record = $result->fetchObject()) {
       $current_row->med_kom = $record->data;
     }  
     $query = db_select('webform_submitted_data', 'd')
            ->fields('d', array('data'))
            ->condition('cid', 10)
     			 ->condition('sid', $current_row->sid);
     $result = $query->execute();
     if($record = $result->fetchObject()) {
       $current_row->yrke_for = $record->data;
     }  
    $query = db_select('webform_submitted_data', 'd')
           ->fields('d', array('data'))
           ->condition('cid', 11)
    			 ->condition('sid', $current_row->sid);
    $result = $query->execute();
    if($record = $result->fetchObject()) {
      $current_row->perm = $record->data;
    }     
    $query = db_select('webform_submitted_data', 'd')
           ->fields('d', array('data'))
           ->condition('cid', 12)
    			 ->condition('sid', $current_row->sid);
    $result = $query->execute();
    if($record = $result->fetchObject()) {
      $current_row->utd = $record->data;
    }
    $query = db_select('webform_submitted_data', 'd')
           ->fields('d', array('data'))
           ->condition('cid', 13)
    			 ->condition('sid', $current_row->sid);
    $result = $query->execute();
    if($record = $result->fetchObject()) {
      $current_row->utd_som = $record->data;
    }   
    $query = db_select('webform_submitted_data', 'd')
           ->fields('d', array('data'))
           ->condition('cid', 14)
    			 ->condition('sid', $current_row->sid);
    $result = $query->execute();
    if($record = $result->fetchObject()) {
      $current_row->stilling_str = $record->data;
    }  
    $query = db_select('webform_submitted_data', 'd')
           ->fields('d', array('data'))
           ->condition('cid', 15)
    			 ->condition('sid', $current_row->sid);
    $result = $query->execute();
    if($record = $result->fetchObject()) {
      $current_row->stilling_fast = $record->data;
    }  
    $query = db_select('webform_submitted_data', 'd')
           ->fields('d', array('data'))
           ->condition('cid', 16)
    			 ->condition('sid', $current_row->sid);
    $result = $query->execute();
    if($record = $result->fetchObject()) {
      $current_row->stilling_prosent = $record->data;
    }      
    $query = db_select('webform_submitted_data', 'd')
           ->fields('d', array('data'))
           ->condition('cid', 17)
    			 ->condition('sid', $current_row->sid);
    $result = $query->execute();
    if($record = $result->fetchObject()) {
      $current_row->hobby = $record->data;
    }     
    $query = db_select('webform_submitted_data', 'd')
           ->fields('d', array('data'))
           ->condition('cid', 18)
    			 ->condition('sid', $current_row->sid);
    $result = $query->execute();
    if($record = $result->fetchObject()) {
      $current_row->forfatter = $record->data;
    }       
    $query = db_select('webform_submitted_data', 'd')
           ->fields('d', array('data'))
           ->condition('cid', 19)
    			 ->condition('sid', $current_row->sid);
    $result = $query->execute();
    if($record = $result->fetchObject()) {
      $current_row->artist = $record->data;
    }      
    $query = db_select('webform_submitted_data', 'd')
           ->fields('d', array('data'))
           ->condition('cid', 20)
    			 ->condition('sid', $current_row->sid);
    $result = $query->execute();
    if($record = $result->fetchObject()) {
      $current_row->org = $record->data;
    }       
    $query = db_select('webform_submitted_data', 'd')
           ->fields('d', array('data'))
           ->condition('cid', 21)
    			 ->condition('sid', $current_row->sid);
    $result = $query->execute();
    if($record = $result->fetchObject()) {
      $current_row->beste = $record->data;
    }      
    $query = db_select('webform_submitted_data', 'd')
           ->fields('d', array('data'))
           ->condition('cid', 23)
    			 ->condition('sid', $current_row->sid);
    $result = $query->execute();
    
    if($record = $result->fetchObject()) {
      $current_row->slag = $record->data;
    }    
    $query = db_select('webform_submitted_data', 'd')
           ->fields('d', array('data'))
           ->condition('cid', 5)
    			 ->condition('sid', $current_row->sid);
    $result = $query->execute();
    if($record = $result->fetchObject()) {
      if(strlen($record->data) == 4){
        $input = $record->data;
        $query2 = db_select('content_type_kommune', 'k')
               ->fields('k', array('nid'))
               ->condition('field_kommunenummer_value', $input);
        $result2 = $query2->execute();
        if($record2 = $result2->fetchObject()) {
          $current_row->kommune = array('nid' => $record2->nid);
        }

      }

    }    
    
    $query = db_select('webform_submitted_data', 'd')
           ->fields('d', array('data'))
           ->condition('cid', 22)
    			 ->condition('sid', $current_row->sid);
    $result = $query->execute();
    if($record = $result->fetchObject()) {
      $image = field_file_load($record->data);
      $current_row->image_file_fid = $image['filepath'];
    }
  
    return TRUE;
  }
}