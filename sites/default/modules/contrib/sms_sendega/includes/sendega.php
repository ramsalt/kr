<?php

include 'rest.php';

class sendega {

  private $CID = '';
  private $password = '';
  private $rest;
  public $success = false;
  public $result = '';

  function __construct($CID, $password) {
    $this->rest = new rest('https://smsc.sendega.com/');
    $this->CID = $CID;
    $this->password = $password;
  }
  
  function send($args) {
    $this->rest->clear();
    $this->rest->addArgs($args);
    // Add defaults if missing
    $this->rest->addArgs(array(
      'priceGroup'    => 0,
      'contentTypeID' => 1,
      'contentHeader' => '',
      'dlrUrl'        => '',
      'ageLimit'      => 0,
      'extID'         => '',
      'sendDate'      => '',
      'refID'         => '',
      'priority'      => 0,
      'gwid'          => 0,
      'pid'           => 0,
      'dcs'           => 0,
    ));
    $this->call('content.asmx/Send');
  }
  
  function call($function) {
    // Do the call
    $this->rest->addArgs(array('username' => $this->CID, 'password' => $this->password));
    $this->rest->call($function);

    // Parse result, report errors
    $xml = simplexml_load_string($this->rest->result);
    if ($xml->Success == "true") {
        $this->success = true;
        $this->result = $xml->MessageID;
    } else {
        $this->success = false;
        $this->result = $xml->ErrorNumber . " : " . $xml->ErrorMessage;
    }
  }

  function getLastCall() {
    return $this->rest->lastcall;
  }

  function getRestResult() {
    return $this->rest->result;
  }
}

?>