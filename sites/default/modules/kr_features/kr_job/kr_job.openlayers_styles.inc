<?php

/**
 * Implementation of hook_openlayers_styles().
 */
function kr_job_openlayers_styles() {
  $export = array();
  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'stillingskartstyle';
  $openlayers_styles->title = 'Stillingskart';
  $openlayers_styles->description = '';
  $openlayers_styles->data = array(
    'pointRadius' => 6,
    'fillColor' => '#EE9900',
    'strokeColor' => '#EE9900',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicOpacity' => 1,
    'labelAlign' => 'cm',
  );

  $export['stillingskartstyle'] = $openlayers_styles;
  return $export;
}
