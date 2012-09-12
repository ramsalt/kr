<?php
/**
 * @file: openlayers-geocoder-result.tpl.php
 *
 * Template file theming geocoder's response results.
 */
?>
<span class="openlayers-geocoder-result detail-row-1"><?php print $result['street_address']; ?></span>
<span class="openlayers-geocoder-result detail-row-2"><?php print $result['postal_code'] .' '. $result['locality']; ?><?php print $result['locality'] ? ' - ' : ''; ?><?php print $result['country']; ?></span>