<?php

/**
 * Implementation of hook_user_default_roles().
 */
function kr_payment_wall_light_user_default_roles() {
  $roles = array();

  // Exported role: abonnent
  $roles['abonnent'] = array(
    'name' => 'abonnent',
  );

  // Exported role: free
  $roles['free'] = array(
    'name' => 'free',
  );

  return $roles;
}
