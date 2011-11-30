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
	foreach (element_children($data) as $serieid) {
    // Get only the numeric values from the series
    $series[] = _charts_series_values($data[$serieid]);
		$series_options[$serieid]['color'] = $data[$serieid]['#color'];
		$series_options[$serieid]['label'] = $data[$serieid]['#legend'];
	}	
	
	// Define defaults!
	
	switch ($data['#type']) {
		case 'line2D':
			drupal_add_js('(function ($) { Drupal.behaviors.jqplotCharts = function(context) {
					 $.jqplot("'.$id.'", '.drupal_to_js($series).',{
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
