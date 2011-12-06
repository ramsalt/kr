Drupal.behaviors.statisticsTable = function (context) {
	$('.data-table').dataTable({
		"iDisplayLength": 25,
					"sPaginationType": "full_numbers",
		"oLanguage": {
			"sProcessing":   "Laster...",
			"sLengthMenu":   "Vis _MENU_ linjer",
			"sZeroRecords":  "Ingen linjer matcher søket",
			"sInfo":         "Viser _START_ til _END_ av _TOTAL_ linjer",
			"sInfoEmpty":    "Viser 0 til 0 av 0 linjer",
			"sInfoFiltered": "(filtrert fra _MAX_ totalt antall linjer)",
			"sInfoPostFix":  "",
			"sSearch":       "Søk:",
			"sUrl":          "",
		  "oPaginate": {
			    "sFirst":    "Første",
			    "sPrevious": "Forrige",
			    "sNext":     "Neste",
			    "sLast":     "Siste"
		   }
		}
	});
};