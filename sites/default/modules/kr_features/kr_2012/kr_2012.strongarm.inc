<?php

/**
 * Implementation of hook_strongarm().
 */
function kr_2012_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'kr_2012_link_0';
  $strongarm->value = 'artikkel/byer_i_norge';
  $export['kr_2012_link_0'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'kr_2012_link_1';
  $strongarm->value = 'ordførere';
  $export['kr_2012_link_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'kr_2012_link_2';
  $strongarm->value = 'artikkel/R_dmenn_i_norske_kommuner';
  $export['kr_2012_link_2'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'kr_2012_text_0';
  $strongarm->value = 'Det er 101 steder med bystatus i Norge. Her er oversikten over alle.';
  $export['kr_2012_text_0'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'kr_2012_text_1';
  $strongarm->value = 'Oversikt over alle landets ordførere. 
Hvem er de og hva er deres interesser?';
  $export['kr_2012_text_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'kr_2012_text_2';
  $strongarm->value = 'Hvem er øverste leder av administrasjonen i din kommune? Finn svaret her.';
  $export['kr_2012_text_2'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'kr_2012_tittel_0';
  $strongarm->value = 'Byer i Norge';
  $export['kr_2012_tittel_0'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'kr_2012_tittel_1';
  $strongarm->value = 'Ordførerleksikon';
  $export['kr_2012_tittel_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'kr_2012_tittel_2';
  $strongarm->value = 'Norske rådmenn';
  $export['kr_2012_tittel_2'] = $strongarm;

  return $export;
}
