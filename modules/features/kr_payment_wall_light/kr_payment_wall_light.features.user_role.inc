<?php

/**
 * Implementation of hook_user_default_roles().
 */
function kr_payment_wall_light_user_default_roles() {
  $roles = array();

  // Exported role: 7 dagers prøveperiode
  $roles['7 dagers prøveperiode'] = array(
    'name' => '7 dagers prøveperiode',
  );

  // Exported role: Abonnement har utløpt
  $roles['Abonnement har utløpt'] = array(
    'name' => 'Abonnement har utløpt',
  );

  // Exported role: Løpende abonnent
  $roles['Løpende abonnent'] = array(
    'name' => 'Løpende abonnent',
  );

  return $roles;
}
