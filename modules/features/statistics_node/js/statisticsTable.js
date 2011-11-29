Drupal.behaviors.statisticsTable = function (context) {
	console.log('ok');
	$('.data-table').dataTable({
		"iDisplayLength": 25
	});
};