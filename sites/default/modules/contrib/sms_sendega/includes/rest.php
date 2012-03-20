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
  
  function getArgsString() {
    return drupal_query_string_encode($this->args);
  }
  
  // Does not add args that already exists in array
  function addArgs($args) {
    if (!empty($args) && is_array($args))
      $this->args = $this->args + $args;
  }
  
  function call($function) {
    $postdata = $this->getArgsString();
    $cxopts = array(
      'http' => array(
        'method' => 'POST',
        'content' => $postdata
      )
    );
    $cx = stream_context_create($cxopts);
    $this->lastcall = $this->base . $function . "?" .  $this->getArgsString();
    $this->result = file_get_contents($this->base . $function, FALSE, $cx);
  }
}

?>