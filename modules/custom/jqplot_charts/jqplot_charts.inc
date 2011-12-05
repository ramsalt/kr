<?php

/**
 * Implementation of hook_charts_render().
 *
 * Its a Charts module hook. It transform the data into a HTML chart.
 *
 * @param &$data
 *   Array. The
 */
function _jqplot_charts_render(&$data) {
	$id = 'chart-'.time();
	
	// Variables to set:
	// width
	// height
	// color??
	// Max Y
	// Max X
	// Min Y
	// Min x
	
	_jqplot_charts_init_jqplot ();
	
	_jqplot_charts_chart ($id, $data);
	
	return '<div style="width:'.$data['#width'].'px; height:'.$data['#height'].'px;" class="jqplot-container" id="'.$id.'"></div>';
}

function _jqplot_charts_chart ($id, &$data) {	
	$series = array();
	$series_options = array();
	foreach (element_children($data) as $xid => $serieid) {
    	// Get only the numeric values from the series
	    $series[] = _charts_series_values($data[$serieid]);
		$series_options[$serieid]['color'] = $data[$serieid]['#color'];
		$series_options[$serieid]['label'] = $data[$serieid]['#legend'];
	}	
	
	
	$test = array(array(array(2001,5), array(2002,10), array(2003,7)));
	dsm(drupal_to_js($test));
	
	
	// Define defaults!
	//dsm($series);
	//dsm($series_options);
	dsm(drupal_to_js($series));
	
	switch ($data['#type']) {
		case 'line2D':
			drupal_add_js('(function ($) { Drupal.behaviors.jqplotCharts = function(context) {
					 $.jqplot("'.$id.'", '.drupal_to_js($test).',{
					 legend:{show:true},
					 series: '.drupal_to_js($series_options).'
					}); 
				}; 
			})(jQuery);', 
			'inline');
			break;
		
		default:
			
			break;
	}
}

function _jqplot_charts_init_jqplot () {
	$path = libraries_get_path('jqplot');
	$plugins = $path.'/plugins';
	drupal_add_js($path.'/jquery.jqplot.min.js');
	drupal_add_js($plugins.'/jqplot.canvasAxisLabelRenderer.min.js');
	drupal_add_css($path.'/jquery.jqplot.min.css');
}

/**
 * Even if the series have values with attributes,
 * return only the numeric values of them.
 *
 * @param
 *   Array. A given data series with or without attributes.
 * @return
 *   Array. A data series, but only with the values, without
 *   the attributes.
 */
function _jqplot_charts_series_values($series) {
  $data = array();

  foreach ($series as $index => $value) {
    if (!is_numeric($index)) {
      continue;
    }

    if (is_array($value)) {
      $data[$index] = $value['#value'];
    }
    else {
      $data[$index] = $value;
    }
  }

  return $data;
}
