<?php

/**
 * @author Gerd Riesselmann
 * @author Jeff Warrington (jaydub) is new maintainer March 2008
 * @author Chris Nutting <Chris.Nutting@openx.org>
 * @author Bruno Massa
 *
 * @file
 * Module settings.
 */

/**
 * Insert the JavaScript into the page's header.
 */
function _openx_javascript() {
  global $user;
  static $spc_code;

  // No need to add the header more than once
  if (!empty($spc_code)) {
    return;
  }

  if (!empty($_SERVER['HTTPS'])) {
    $protocol = 'https';
    $server = variable_get('openx_delivery_url_https', 'd.openx.org');
  }
  else {
    $protocol = 'http';
    $server = variable_get('openx_delivery_url', 'd.openx.org');
  }
  $url = $protocol .'://'. trim($server, '/') .'/spcjs.php';
  
  if ($site_vars = variable_get('openx_site_vars', FALSE)) {
    $vars = array();
    if (module_exists('token')) {
      $objects = array('global' => NULL, 'user' => $user);
      
      $node = menu_get_object('node');
      
      if (isset($node)) {
        $objects['node'] = $node;
      }
    }
    foreach ($site_vars as $var) {
      if (!empty($var['key'])) {
        if (module_exists('token')) {
          $vars[$var['key']] = token_replace_multiple($var['value'], $objects, '[', ']', array('clear' => TRUE));
        }
        else {
          $vars[$var['key']] = $var['value'];
        }
      }
    }
    
    if (!empty($vars)) {
      $url .= '?' . drupal_query_string_encode($vars);
    }
  }

  $zones = variable_get('openx_zones', array());
  $spc_code = "<script type='text/javascript'><!--// <![CDATA[\n  var OA_zones = {\n";

  $js_zones = array();
  foreach ($zones as $idx => $zone) {
    if (!empty($zone['id'])) {
      $js_zones[] = "    '". $zone['name'] ."' : ". $zone['id'];
    }
  }
  $spc_code .= implode(",\n", $js_zones);
  $spc_code .= "  }\n// ]]> --></script>\n<script type='text/javascript' src='{$url}'></script>";

  drupal_set_html_head($spc_code);
}

/**
 * Return zone with given index
 */
function _openx_get_zone($index_or_key) {
  $zones = variable_get('openx_zones', array());
  if (isset($zones[$index_or_key])) {
    return $zones[$index_or_key];
  }
  else {
    foreach ($zones as $zone) {
      if ($zone['name'] == $index_or_key) {
        return $zone;
      }
    }
  }

  // There is no zone with such ID or name
  return FALSE;
}
