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
	
	_jqplot_charts_init_jqplot ($data['#type']);
	_jqplot_charts_chart ($id, $data);
	
	return '<div style="width:'.$data['#width'].'px; height:'.$data['#height'].'px;" class="jqplot-container" id="'.$id.'"></div>';
}

function _jqplot_charts_chart ($id, &$data) {
	//dsm($data);

	$series = array();
	$series_options = array();
	foreach (element_children($data) as $xid => $serieid) {
   	// Get only the numeric values from the series
	  $series[] = _jqplot_charts_series_values($data[$serieid]);
		$series_options[$serieid]['color'] = $data[$serieid]['#color'];
		$series_options[$serieid]['label'] = $data[$serieid]['#legend'];
	}	
	
	$settings = _jqplot_charts_parse_settings($data['#settings']);
	$settings['series'] = $series_options;

	
	//$series = array(array(array(2001,5), array(2002,10), array(2003,7)));
	//dsm(drupal_to_js($test));
	
	
	// Define defaults!
	//dsm($series);
	//dsm($series_options);
	//dsm(drupal_to_js($series));
	
	//dsm($data['#type']);
	
	switch ($data['#type']) {
		case 'line2D':
		  if(isset($data['#ticks'])) {
		    $settings['axes']['xaxis']['renderer'] = "$.jqplot.CategoryAxisRenderer";
		    $settings['seriesDefaults']['rendererOptions']['fillToZero'] = true;
		    $settings['axes']['xaxis']['ticks'] = $data['#ticks'];
		  }
			break;
			
		case 'hbar2D':
			$settings['seriesDefaults']['renderer'] = "$.jqplot.BarRenderer";
			$settings['seriesDefaults']['rendererOptions']['fillToZero'] = true;
			if(!isset($settings['axes']['xaxis']['renderer'])) {
			  $settings['axes']['xaxis']['renderer'] = "$.jqplot.CategoryAxisRenderer";
			}
			if(isset($data['#ticks'])) {
			  $settings['axes']['xaxis']['ticks'] = $data['#ticks'];
			}
			break;
			
		case 'vbar2D':
			$settings['seriesDefaults']['renderer'] = '$.jqplot.BarRenderer';
			$settings['seriesDefaults']['rendererOptions']['fillToZero'] = true;
			$settings['seriesDefaults']['rendererOptions']['barDirection'] = 'horizontal';
			$settings['axes']['yaxis']['renderer'] = "$.jqplot.CategoryAxisRenderer";			
			break;
		
		default:
			
			break;
	}
	
	$settings_string = json_encode($settings);
	$settings_string = str_replace('"$.jqplot.BarRenderer"', '$.jqplot.BarRenderer', $settings_string);
	$settings_string = str_replace('"$.jqplot.DateAxisRenderer"', '$.jqplot.DateAxisRenderer', $settings_string);
	$settings_string = str_replace('"$.jqplot.CategoryAxisRenderer"', '$.jqplot.CategoryAxisRenderer', $settings_string);
	
	drupal_add_js('(function ($) { Drupal.behaviors.jqplotCharts = function(context) {
			 $.jqplot("'.$id.'", '.json_encode($series).',
			  '.$settings_string.'); 
		}; 
	})(jQuery);', 
	'inline');
}

function _jqplot_charts_init_jqplot ($type = 'line2D') {
	$path = libraries_get_path('jqplot');
	$plugins = $path.'/plugins';
	drupal_add_js($path.'/jquery.jqplot.min.js');
	
	switch ($type) {
		case 'line2D':
			break;
		
		case 'hbar2D':	
		case 'vbar2D':

			break;
		
		default:
			
			break;
	}
	drupal_add_js($plugins.'/jqplot.barRenderer.min.js');
	drupal_add_js($plugins.'/jqplot.categoryAxisRenderer.min.js');
	drupal_add_js($plugins.'/jqplot.pointLabels.min.js');
	drupal_add_js($plugins.'/jqplot.canvasAxisLabelRenderer.min.js');
	drupal_add_js($plugins.'/jqplot.canvasTextRenderer.min.js');
	drupal_add_js($plugins.'/jqplot.canvasAxisTickRenderer.min.js');
	drupal_add_js($plugins.'/jqplot.dateAxisRenderer.min.js');
	drupal_add_js($plugins.'/jqplot.highlighter.min.js');
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
  foreach (element_children($series) as $index) {
  	$value = $series[$index];

    if (!is_numeric($index)) {
      continue;
    }
    if (is_array($value)) {
    	if(isset($value['#key'])) {
	    	$data[] = array($value['#key'], $value['#value']);
    	} else {
    		$data[] = $value['#value'];
    	}    
    }
    else {
      $data[] = $value['#value'];
    }
  }

  return $data;
}

function _jqplot_charts_parse_settings ($settings) {
	
	return $settings;
}