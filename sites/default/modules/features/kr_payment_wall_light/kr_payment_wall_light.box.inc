<?php

/**
 * Implementation of hook_default_box().
 */
function kr_payment_wall_light_default_box() {
  $export = array();

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'premium_box_disabled_user';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Premium box: Show to disabled free user';
  $box->options = array(
    'body' => '<p>
	Du har n&aring; hatt gratis tilgang til kommunal-rapport.no i sju dager. Om du &oslash;nsker &aring; fortsette &aring; lese oss, m&aring; du kj&oslash;pe abonnement. <a href="/user/bestillabonnement">Det kan du bestille her</a>.</p>
',
    'format' => '1',
  );
  $export['premium_box_disabled_user'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'show_to_disabled_free_user';
  $box->plugin_key = 'simple';
  $box->title = 'Din prøveperiode er over';
  $box->description = 'Show to disabled free user';
  $box->options = array(
    'body' => '<p>
	Du har n&aring; hatt gratis tilgang til kommunal-rapport.no i sju dager. Om du &oslash;nsker &aring; fortsette &aring; lese oss, m&aring; du kj&oslash;pe abonnement.</p>
<p>
	<strong><a href="/user/bestillabonnement">Klikk her for &aring; kj&oslash;pe abonnement</a>. Du fortsetter da &aring; f&aring; full tilgang til kommunal-rapport.no, uten opphold.</strong><br />
	<br />
	Hvis du allerede er abonnent p&aring; papirutgaven til Kommunal Rapport, betaler du 750 kroner i &aring;ret for abonnement p&aring; den digitale utgaven. Full pris er 1.550 kroner per &aring;r. Abonnementet l&oslash;per til det blir sagt opp.<br />
	<br />
	Om du jobber i en virksomhet der flere har bruk for kommunal-rapport.no, kan det l&oslash;nne seg &aring; kj&oslash;pe IP-abonnement, som gir alle innenfor datanettverket tilgang. Dette er sterkt rabatterte abonnement. Ta kontakt p&aring; <a href="mailto:abonnement@kommunal-rapport.no?subject=IP-abonnement%20p%C3%A5%20kommunal-rapport.no">abonnement@kommunal-rapport.no</a> for pristilbud.</p>
',
    'format' => '2',
  );
  $export['show_to_disabled_free_user'] = $box;

  return $export;
}
