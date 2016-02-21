<?php
/**
 * @file
 * rsvp.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function rsvp_default_rules_configuration() {
  $items = array();
  $items['rules_alert_dessert_czar'] = entity_import('rules_config', '{ "rules_alert_dessert_czar" : {
      "LABEL" : "Alert Dessert Czar",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "rsvp" : "rsvp" } } } },
        { "AND" : [
            { "data_is" : { "data" : [ "node:field-attending" ], "value" : "1" } },
            { "data_is" : { "data" : [ "node:field-dessert" ], "value" : "1" } }
          ]
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "annekachan@yahoo.com, john@moorelevesque.com, christa.levesque@gmail.com",
            "subject" : "Contact Info for Dessert Czar",
            "message" : "An RSVP has been created for [node:title], and they have indicated that they are willing to provide a dessert.\\r\\n\\r\\nTheir contact information is:\\r\\nLast name: [node:title]\\r\\nFirst name(s): [node:field_name]\\r\\nEmail: [node:field-email]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_redirect_guest'] = entity_import('rules_config', '{ "rules_redirect_guest" : {
      "LABEL" : "Redirect Guest",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_login" : [] },
      "IF" : [
        { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "4" : "4" } } } }
      ],
      "DO" : [ { "redirect" : { "url" : "node\\/add\\/rsvp" } } ]
    }
  }');
  $items['rules_rsvp_alert'] = entity_import('rules_config', '{ "rules_rsvp_alert" : {
      "LABEL" : "RSVP alert",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "rsvp" : "rsvp" } } } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "john@moorelevesque.com, christa.levesque@gmail.com",
            "subject" : "An RSVP has been created for [node:title]. They have indicated they: [node:field-attending]",
            "message" : "[node:title]\\r\\n[node:field-name]\\r\\n[node:field-attending]\\r\\n[node:field-email]\\r\\n[node:field-dessert]",
            "from" : "info@moorelevesque.com",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_rsvp_created'] = entity_import('rules_config', '{ "rules_rsvp_created" : {
      "LABEL" : "RSVP created",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "rsvp" : "rsvp" } } } },
        { "AND" : [
            { "data_is" : { "data" : [ "node:field-attending" ], "value" : "1" } },
            { "data_is" : { "data" : [ "node:field-dessert" ], "value" : "0" } }
          ]
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "node:field-email" ],
            "subject" : "Thank you for your RSVP",
            "message" : "Thank you for your RSVP. We are looking forward to seeing you in April! If you have any questions, please call us at 508-380-2743.",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_rsvp_created_dessert_'] = entity_import('rules_config', '{ "rules_rsvp_created_dessert_" : {
      "LABEL" : "RSVP created (dessert)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "rsvp" : "rsvp" } } } },
        { "AND" : [
            { "data_is" : { "data" : [ "node:field-attending" ], "value" : "1" } },
            { "data_is" : { "data" : [ "node:field-dessert" ], "value" : "1" } }
          ]
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "node:field-email" ],
            "subject" : "Thank you for your RSVP",
            "message" : "Thank you for your RSVP. We are looking forward to seeing you in April! If you have any questions, please call us at 508-380-2743. \\r\\n\\r\\nYour contact information will be forwarded to the Dessert Czar (a.k.a., the sister of the groom). She will be contacting you to make arrangements for the dessert table.",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_rsvp_created_not_coming_'] = entity_import('rules_config', '{ "rules_rsvp_created_not_coming_" : {
      "LABEL" : "RSVP created (not coming)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "rsvp" : "rsvp" } } } },
        { "AND" : [ { "data_is" : { "data" : [ "node:field-attending" ], "value" : "0" } } ] }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "node:field-email" ],
            "subject" : "Thank you for your RSVP",
            "message" : "Thank you for your RSVP. We are sorry that you will not be able to join us in April. Please keep us in your thoughts and prayers as we begin our lives together.\\r\\n\\r\\nWith Love,\\r\\nJohn and Christa",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
