<?php

class rest {

  public $base = '';
  public $args = array();
  public $result = false;
  public $lastcall = '';
  
  function __construct($base='') {
    $this->base = $base;
  }
  
  function clear() {
    $this->args = array();
  }

  function addArg($arg, $value) {
    $this->args[$arg] = $value;
  }
  
  function addArgs($args) {
    if (!empty($args) && is_array($args))
      $this->args = $this->args + $args;
  }
  
  function getArgsString() {
    return '?' . drupal_query_string_encode($this->args);
  }
  
  function call($function) {
    $url = $this->base . $function . $this->getArgsString();
		$this->result = file_get_contents($url);
  }

}