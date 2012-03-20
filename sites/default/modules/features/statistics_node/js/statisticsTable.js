Drupal.behaviors.statisticsTable = function (context) {
	$('.data-table').dataTable({
		"iDisplayLength": 50,
					"sPaginationType": "full_numbers",
		"oLanguage": {
			"sProcessing":   "Laster...",
			"sZeroRecords":  "Ingen linjer matcher søket",
			"sInfo":         "Viser _START_ til _END_ av _TOTAL_ linjer",
			"sInfoEmpty":    "Viser 0 til 0 av 0 linjer",
			"sInfoFiltered": "(filtrert fra _MAX_ totalt antall linjer)",
			"sInfoPostFix":  "",
			"sSearch":       "Søk:",
			"sUrl":          "",
			"sLengthMenu": 'Vis <select>'+
				'<option value="25">25</option>'+
				'<option value="50">50</option>'+
				'<option value="75">75</option>'+
				'<option value="100">100</option>'+
				'<option value="-1">Alle</option>'+
				'</select> linjer',
		
		  "oPaginate": {
			    "sFirst":    "Første",
			    "sPrevious": "Forrige",
			    "sNext":     "Neste",
			    "sLast":     "Siste"
		   }
		}
	});
};