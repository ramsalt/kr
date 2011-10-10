<?php

include 'rest.inc';

class sendega {

  private $CID = '';
  private $password = '';
  private $rest;
	private $schema;
  public $success = false;
  public $result = '';

  function __construct($CID, $password, $schema) {
		$this->schema = $schema.'://';
    $this->rest = new rest($this->schema.'api.sendega.com/');
    $this->CID = $CID;
    $this->password = $password;
  }

  function sendSMS($Recipient, $Msg, $Optionals) {
    $this->rest->clear();
    $this->rest->addArgs(array('recipient' => $Recipient, 'msg' => $Msg));
    $this->rest->addArgs($Optionals);
    $this->call('sendSMS.asp');
  }
  
  function call($function) {
    // Do the call
    $this->rest->addArgs(array('CID' => $this->CID, 'Password' => $this->password));
    $this->rest->call($function);

    // Parse result, report errors
    $xml = simplexml_load_string($this->rest->result);
    if ($xml->success == "true") {
        $this->result = (string)$xml->msgid;
        $this->success = true;
    } else {
        $this->result = (string)$xml->errormsg;
        $this->success = false;
    }
  }

}

?>