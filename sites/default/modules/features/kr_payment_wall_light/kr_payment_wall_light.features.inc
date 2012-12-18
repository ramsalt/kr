<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function kr_payment_wall_light_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "boxes" && $api == "box") {
    return array("version" => 1);
  }
}

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
            '#type' => 'condition',
            '#settings' => array(
              'roles' => array(
                '0' => 1,
                '1' => 11,
                '2' => 3,
                '3' => 5,
                '4' => 4,
                '5' => 10,
                '6' => 9,
                '7' => 8,
                '8' => 7,
                '9' => 6,
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
            '#negate' => 1,
          ),
        ),
        '#actions' => array(),
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
            '#weight' => 0,
            '#type' => 'condition',
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
            '#name' => 'rules_condition_check_boolean',
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
              'message' => 'Takk for at du bestilte abonnement på Kommunal-Rapport.no. Din konto er blitt oppgradert slik at du kan starte å bruke abonnementet ditt umiddelbart. ',
              'error' => 0,
            ),
            '#type' => 'action',
          ),
          '1' => array(
            '#weight' => 0,
            '#type' => 'action',
            '#settings' => array(
              'roles' => array(
                '0' => 13,
                '1' => 12,
              ),
              '#argument map' => array(
                'user' => 'account',
              ),
            ),
            '#name' => 'rules_action_user_removerole',
            '#info' => array(
              'label' => 'Fjern brukerrolle "free" og "disabled"',
              'label callback' => FALSE,
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'User whos roles should be changed',
                ),
              ),
              'module' => 'User',
            ),
          ),
          '2' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Legg til brukerrolle "abonnent"',
              'label callback' => FALSE,
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'User whos roles should be changed',
                ),
              ),
              'module' => 'User',
            ),
            '#name' => 'rules_action_user_addrole',
            '#settings' => array(
              'roles' => array(
                '0' => 11,
              ),
              '#argument map' => array(
                'user' => 'account',
              ),
            ),
            '#type' => 'action',
          ),
          '3' => array(
            '#type' => 'action',
            '#settings' => array(
              'from' => 'abonnement@kommunal-rapport.no',
              'subject' => 'Endring av abonnementinformasjon hos Kommunal-Rapport.no',
              'message' => 'Takk for at du bestilte abonnement på Kommunal-Rapport.no. Din konto er blitt oppgradert slik at du kan starte å bruke abonnementet umiddelbart.
Faktura for abonnement ut 2012 blir sendt til oppgitt fakturaadresse.

Fullt navn: [account:user:profile_navn]	
E-postadressen for brukerkontoen: [account:mail]

Fakturabetalers navn: [account:user:profile_fakturabetalers_navn]	
Epost til fakturamottak: [account:user:profile_epost_fakturamottak]
Gateadresse: [account:user:profile_gateadresse]
Poststed: [account:user:profile_poststed]
Postnr: [account:user:profile_postnr]
Hvilken kommune er du tilknyttet: [account:user:profile_kommune]
Jobber som: [account:user:profile_stilling]
[account:user:profile_bestill_abo]	
Papirabonnent? [account:user:profile_papirabonnent]
[user:user:profile_ipabonnent]

URL-en for din kontoredigeringssiden [account:account-edit-url]	',
              '#argument map' => array(
                'user' => 'account',
              ),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'message' => array(
                    '0' => 'account',
                    '1' => 'user',
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
            '#weight' => 0,
          ),
          '4' => array(
            '#weight' => 0,
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
            '#name' => 'rules_action_mail',
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
[account:user:profile_bestill_abo]	
Papirabonnent? [account:user:profile_papirabonnent]
IP-abonnent? [user:user:profile_ipabonnent]',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'message' => array(
                    '0' => 'account',
                    '1' => 'user',
                  ),
                  'from' => array(
                    '0' => 'account',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
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
            '#weight' => 0,
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
            '#name' => 'rules_condition_user_hasrole',
            '#settings' => array(
              'roles' => array(
                '0' => 12,
              ),
              'operation' => 'OR',
              '#argument map' => array(
                'user' => 'user',
              ),
            ),
            '#type' => 'condition',
          ),
          '1' => array(
            '#weight' => 0,
            '#negate' => 1,
            '#type' => 'condition',
            '#settings' => array(
              'boolean' => '[user:user:profile_bestill_abo]',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'boolean' => array(
                    '0' => 'user',
                  ),
                ),
              ),
            ),
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
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              'roles' => array(
                '0' => 12,
              ),
              '#argument map' => array(
                'user' => 'user',
              ),
            ),
            '#name' => 'rules_action_user_removerole',
            '#info' => array(
              'label' => 'Fjern brukerrolle free',
              'label callback' => FALSE,
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
          '1' => array(
            '#weight' => 0,
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
              'subject' => 'Gratisperioden går ut - bli abonnent på kommunal-rapport.no nå',
              'message' => 'Hei [user:user:profile_navn],

Du har nå hatt gratis tilgang til kommunal-rapport.no i sju dager. Om du ønsker å fortsette å lese oss, må du kjøpe abonnement.

Hvis du allerede er abonnent på papirutgaven til Kommunal Rapport, betaler du 750 kroner i året for abonnement på den digitale utgaven. Full pris er 1.550 kroner per år. Abonnementet løper til det blir sagt opp.

Du fortsetter da å få full tilgang til kommunal-rapport.no, uten opphold.

For å kjøpe abonnement trykk på følgende lenke: www.kommunal-rapport.no/user/bestillabonnement

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
            '#type' => 'action',
          ),
          '2' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Legg til brukerrolle disabled',
              'label callback' => FALSE,
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'User whos roles should be changed',
                ),
              ),
              'module' => 'User',
            ),
            '#name' => 'rules_action_user_addrole',
            '#settings' => array(
              'roles' => array(
                '0' => 13,
              ),
              '#argument map' => array(
                'user' => 'user',
              ),
            ),
            '#type' => 'action',
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
