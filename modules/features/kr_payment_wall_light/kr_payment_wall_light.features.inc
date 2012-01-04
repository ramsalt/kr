<?php

/**
 * Implementation of hook_rules_defaults().
 */
function kr_payment_wall_light_rules_defaults() {
  return array(
    'rules' => array(
      'rules_message_to_free_user_after_7_days_when_user_page_is_viewed' => array(
        '#type' => 'rule',
        '#set' => 'event_user_view',
        '#label' => 'Message to free user after 7 days when user page is viewed',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'free user',
          'kr_payment_wall_light' => 'kr_payment_wall_light',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#settings' => array(
              'roles' => array(
                '0' => 1,
                '1' => 9,
                '2' => 3,
                '3' => 5,
                '4' => 4,
                '5' => 8,
                '6' => 7,
                '7' => 6,
              ),
              'operation' => 'OR',
              '#argument map' => array(
                'user' => 'user',
              ),
            ),
            '#type' => 'condition',
            '#name' => 'rules_condition_user_hasrole',
            '#info' => array(
              'label' => 'Bruker har rolle(r)',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'Bruker',
                ),
              ),
              'module' => 'User',
            ),
            '#weight' => 0,
            '#negate' => 1,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Show a configurable message on the site',
              'module' => 'System',
              'eval input' => array(
                '0' => 'message',
              ),
            ),
            '#name' => 'rules_action_drupal_message',
            '#settings' => array(
              'message' => 'Du har nå hatt gratis tilgang til kommunal-rapport.no i sju dager. Om du ønsker å fortsette å lese våre nyheter, må du kjøpe abonnement.

Hvis du allerede er abonnent på papirutgaven til Kommunal Rapport, betaler du 750 kroner i året for abonnement på den digitale utgaven. Full pris er 1.550 kroner per år. Abonnementet løper til det blir sagt opp.

Fullfør skjemaet under for å kjøpe abonnement. Du fortsetter da å få full tilgang til kommunal-rapport.no, uten opphold.

Om du jobber i en virksomhet der flere har bruk for kommunal-rapport.no, kan det lønne seg å kjøpe IP-abonnement, som gir alle innenfor datanettverket tilgang. Dette er sterkt rabatterte abonnement. Ta kontakt på abonnement@kommunal-rapport.no for pristilbud.',
              'error' => 0,
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
      'rules_order_subscription' => array(
        '#type' => 'rule',
        '#set' => 'event_user_update_profile',
        '#label' => 'Order subscription',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'free user',
          'kr_payment_wall_light' => 'kr_payment_wall_light',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#info' => array(
              'label' => 'Check a truth value',
              'arguments' => array(
                'boolean' => array(
                  'type' => 'boolean',
                  'label' => 'Truth value',
                ),
              ),
              'module' => 'Rules',
            ),
            '#name' => 'rules_condition_check_boolean',
            '#settings' => array(
              'boolean' => '[account:user:profile_bestill_abo]',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'boolean' => array(
                    '0' => 'account',
                  ),
                ),
              ),
            ),
            '#type' => 'condition',
            '#weight' => 0,
          ),
          '1' => array(
            '#type' => 'condition',
            '#settings' => array(
              'profile_field' => 'profile_bestill_abo',
              'profile_field_value' => '1',
              '#argument map' => array(
                'user' => 'account',
              ),
            ),
            '#name' => 'profile_rules_string_condition',
            '#info' => array(
              'label' => 'Compare generic profile field',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'User to grab profile fields from',
                ),
              ),
              'module' => 'Profile',
            ),
            '#weight' => 0,
          ),
          '2' => array(
            '#settings' => array(
              'profile_field' => 'profile_bestill_abo',
              'profile_field_value' => '1',
              '#argument map' => array(
                'user' => 'account_unchanged',
              ),
            ),
            '#type' => 'condition',
            '#name' => 'profile_rules_string_condition',
            '#info' => array(
              'label' => 'Compare generic profile field, unchanged',
              'label callback' => FALSE,
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'User to grab profile fields from',
                ),
              ),
              'module' => 'Profile',
            ),
            '#weight' => 0,
          ),
          '3' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Compare generic profile field',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'User to grab profile fields from',
                ),
              ),
              'module' => 'Profile',
            ),
            '#name' => 'profile_rules_string_condition',
            '#settings' => array(
              'profile_field' => 'profile_bestill_abo',
              'profile_field_value' => '1',
              '#argument map' => array(
                'user' => 'user',
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              'message' => 'Takk for at du bestilte abonnement på Kommunal-Rapport.no. Din konto er blitt oppgradert slik at du kan starte å bruke abonnementet ditt umiddelbart. ',
              'error' => 0,
            ),
            '#name' => 'rules_action_drupal_message',
            '#info' => array(
              'label' => 'Show a configurable message on the site',
              'module' => 'System',
              'eval input' => array(
                '0' => 'message',
              ),
            ),
            '#weight' => 0,
          ),
          '1' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Fjern brukerrolle',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'User whos roles should be changed',
                ),
              ),
              'module' => 'User',
            ),
            '#name' => 'rules_action_user_removerole',
            '#settings' => array(
              'roles' => array(
                '0' => 8,
              ),
              '#argument map' => array(
                'user' => 'user',
              ),
            ),
            '#type' => 'action',
          ),
          '2' => array(
            '#type' => 'action',
            '#settings' => array(
              'roles' => array(
                '0' => 9,
              ),
              '#argument map' => array(
                'user' => 'user',
              ),
            ),
            '#name' => 'rules_action_user_addrole',
            '#info' => array(
              'label' => 'Legg til brukerrolle',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'User whos roles should be changed',
                ),
              ),
              'module' => 'User',
            ),
            '#weight' => 0,
          ),
          '3' => array(
            '#info' => array(
              'label' => 'Send a mail to a user',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'Mottaker',
                ),
              ),
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
              ),
            ),
            '#name' => 'rules_action_mail_to_user',
            '#settings' => array(
              'from' => 'abonnement@kommunal-rapport.no',
              'subject' => 'Endring av abonnementinformasjon hos Kommunal-Rapport.no',
              'message' => 'Du har endret dine kontoopplysninger hos Kommunal-Rapport.no. Vennligst kontrollert at informasjonen nedenfor er korrekt. 

Fullt navn: [account:user:profile_navn]	
E-postadressen for brukerkontoen: [account:mail]	
Kontoen ble opprettet: [account:user-created-small]

Fakturabetalers navn: [account:user:profile_fakturabetalers_navn]	
Referanse: [account:user:profile_referanse]	
Epost til fakturamottak: [account:user:profile_epost_fakturamottak]
Gateadresse: [account:user:profile_gateadresse]
Poststed: [account:user:profile_poststed]
Postnr: [account:user:profile_postnr]
Hvilken kommune er du tilknyttet: [account:user:profile_kommune]
Er du: [account:user:profile_stilling]
Ja, jeg ønsker å abonnere på kommunal-rapport.no nå [account:user:profile_bestill_abo]	

URL-en for din kontoredigeringssiden [account:account-edit-url]	',
              '#argument map' => array(
                'user' => 'user',
              ),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'message' => array(
                    '0' => 'account',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
            '#weight' => 0,
          ),
          '4' => array(
            '#weight' => 0,
            '#type' => 'action',
            '#settings' => array(
              'to' => 'abonnement@kommunal-rapport.no',
              'from' => '[account:mail]',
              'subject' => 'Ny bestilling på digitalt abonnement',
              'message' => 'URL-en for kontoredigeringssiden [account:account-edit-url]	

Fullt navn: [account:user:profile_navn]	
E-postadressen for brukerkontoen: [account:mail]	
Kontoen ble opprettet: [account:user-created-small]

Fakturabetalers navn: [account:user:profile_fakturabetalers_navn]	
Referanse: [account:user:profile_referanse]	
Epost til fakturamottak: [account:user:profile_epost_fakturamottak]
Gateadresse: [account:user:profile_gateadresse]
Poststed: [account:user:profile_poststed]
Postnr: [account:user:profile_postnr]
Hvilken kommune er du tilknyttet: [account:user:profile_kommune]
Er du: [account:user:profile_stilling]
Ja, jeg ønsker å abonnere på kommunal-rapport.no nå [account:user:profile_bestill_abo]	',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'message' => array(
                    '0' => 'account',
                  ),
                  'from' => array(
                    '0' => 'account',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_mail',
            '#info' => array(
              'label' => 'Send a mail to an arbitrary mail address',
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
                '3' => 'to',
              ),
            ),
          ),
        ),
        '#version' => 6003,
      ),
      'rules_remove_premium_access_after_x_days_triggered_rule_' => array(
        '#type' => 'rule',
        '#set' => 'event_sms_user_validated',
        '#label' => 'Schedule: Remove premium access after x days {triggered rule} ',
        '#active' => 1,
        '#weight' => '10',
        '#categories' => array(
          '0' => 'free user',
          'kr_payment_wall_light' => 'kr_payment_wall_light',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#settings' => array(
              'boolean' => '[user:user:profile_smsauthenticated]',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'boolean' => array(
                    '0' => 'user',
                  ),
                ),
              ),
            ),
            '#type' => 'condition',
            '#name' => 'rules_condition_check_boolean',
            '#info' => array(
              'label' => 'has the user authenticated with sms before',
              'label callback' => FALSE,
              'arguments' => array(
                'boolean' => array(
                  'type' => 'boolean',
                  'label' => 'Truth value',
                ),
              ),
              'module' => 'Rules',
            ),
            '#negate' => 1,
            '#weight' => 0,
          ),
          '1' => array(
            '#weight' => 0,
            '#type' => 'condition',
            '#settings' => array(
              'roles' => array(
                '0' => 8,
              ),
              'operation' => 'OR',
              '#argument map' => array(
                'user' => 'user',
              ),
            ),
            '#name' => 'rules_condition_user_hasrole',
            '#info' => array(
              'label' => 'user got role "free"',
              'label callback' => FALSE,
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'Bruker',
                ),
              ),
              'module' => 'User',
            ),
          ),
        ),
        '#actions' => array(
          '1' => array(
            '#info' => array(
              'module' => 'User',
              'arguments' => array(
                'user' => array(
                  'label' => 'Bruker',
                  'type' => 'user',
                ),
              ),
              'label' => 'Endre felter i profil',
              'base' => 'rules_core_action_execute',
              'action_name' => 'views_bulk_operations_profile_action',
              'configurable' => TRUE,
            ),
            '#name' => 'rules_core_views_bulk_operations_profile_action',
            '#settings' => array(
              'profile_navn_check' => 0,
              'profile_navn' => '',
              'profile_fakturabetalers_navn_check' => 0,
              'profile_fakturabetalers_navn' => '',
              'profile_epost_fakturamottak_check' => 0,
              'profile_epost_fakturamottak' => '',
              'profile_gateadresse_check' => 0,
              'profile_gateadresse' => '',
              'profile_poststed_check' => 0,
              'profile_poststed' => '',
              'profile_postnr_check' => 0,
              'profile_postnr' => '',
              'profile_kommune_check' => 0,
              'profile_kommune' => '',
              'profile_stilling_check' => 0,
              'profile_stilling' => '',
              'profile_referanse_check' => 0,
              'profile_referanse' => '',
              'profile_bestill_abo_check' => 0,
              'profile_bestill_abo' => 0,
              'profile_smsauthenticated_check' => 1,
              'profile_smsauthenticated' => '1',
              'profile_sms_authenticated_earlier_check' => 1,
              'profile_sms_authenticated_earlier' => '1',
              '#argument map' => array(
                'user' => 'user',
              ),
            ),
            '#type' => 'action',
            '#weight' => 0,
          ),
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              'task_identifier' => 'freeuser[user:uid]',
              'task_date' => '-60 minutes',
              '#argument map' => array(
                'user' => 'user',
              ),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'task_identifier' => array(
                    '0' => 'user',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_schedule_set_rules_remove_free_access_after_x_days',
            '#info' => array(
              'arguments' => array(
                'task_identifier' => array(
                  'type' => 'string',
                  'label' => 'Identifier',
                  'description' => 'User provided string to identify the task. Existing tasks for this rule set with the same identifier will be replaced.',
                ),
                'task_date' => array(
                  'type' => 'date',
                  'label' => 'Scheduled evaluation date',
                ),
                'user' => array(
                  'label' => 'Bruker {argument}',
                  'type' => 'user',
                ),
              ),
              'label' => 'Schedule "Remove free access after x days {rule set}"',
              'status' => 'custom',
              'categories' => array(
                '0' => 'free user',
              ),
              'module' => 'Rule Scheduler',
              'base' => 'rules_scheduler_action',
              'set' => 'rules_remove_free_access_after_x_days',
            ),
            '#weight' => 10,
          ),
        ),
        '#version' => 6003,
      ),
      'rules_remove_free_role_rule_' => array(
        '#type' => 'rule',
        '#set' => 'rules_remove_free_access_after_x_days',
        '#label' => 'Remove free role {rule}',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          'kr_payment_wall_light' => 'kr_payment_wall_light',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#type' => 'condition',
            '#settings' => array(
              'roles' => array(
                '0' => 8,
              ),
              'operation' => 'OR',
              '#argument map' => array(
                'user' => 'user',
              ),
            ),
            '#name' => 'rules_condition_user_hasrole',
            '#info' => array(
              'label' => 'Bruker har rolle(r)',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'Bruker',
                ),
              ),
              'module' => 'User',
            ),
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Fjern brukerrolle',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'User whos roles should be changed',
                ),
              ),
              'module' => 'User',
            ),
            '#name' => 'rules_action_user_removerole',
            '#settings' => array(
              'roles' => array(
                '0' => 8,
              ),
              '#argument map' => array(
                'user' => 'user',
              ),
            ),
            '#type' => 'action',
          ),
          '1' => array(
            '#weight' => 0,
            '#type' => 'action',
            '#settings' => array(
              'from' => 'abonnement@kommunal-rapport.no',
              'subject' => 'Gratisperioden går ut - bli abonnent på kommunal-rapport.no nå',
              'message' => 'Hei [user:user:profile_navn],

Du har nå hatt gratis tilgang til kommunal-rapport.no i sju dager. Om du ønsker å fortsette å lese våre nyheter, må du kjøpe abonnement.

Hvis du allerede er abonnent på papirutgaven til Kommunal Rapport, betaler du 750 kroner i året for abonnement på den digitale utgaven. Full pris er 1.550 kroner per år. Abonnementet løper til det blir sagt opp.

Du fortsetter da å få full tilgang til kommunal-rapport.no, uten opphold.

For å kjøpe abonnement trykk på følgende lenke: http://www.kommunal-rapport.no/user/[user:uid]/edit/Personlige%20opplysninger

Om du jobber i en virksomhet der flere har bruk for kommunal-rapport.no, kan det lønne seg å kjøpe IP-abonnement, som gir alle innenfor datanettverket tilgang. Dette er sterkt rabatterte abonnement. Ta kontakt på abonnement@kommunal-rapport.no for pristilbud.

Vennlig hilsen Kommunal Rapport',
              '#argument map' => array(
                'user' => 'user',
              ),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'message' => array(
                    '0' => 'user',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_mail_to_user',
            '#info' => array(
              'label' => 'Send a mail to a user',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'Mottaker',
                ),
              ),
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
              ),
            ),
          ),
        ),
        '#version' => 6003,
      ),
    ),
    'rule_sets' => array(
      'rules_remove_free_access_after_x_days' => array(
        'arguments' => array(
          'user' => array(
            'label' => 'Bruker {argument}',
            'type' => 'user',
          ),
        ),
        'label' => 'Remove free access after x days {rule set}',
        'status' => 'default',
        'categories' => array(
          '0' => 'free user',
          'kr_payment_wall_light' => 'kr_payment_wall_light',
        ),
      ),
    ),
  );
}
