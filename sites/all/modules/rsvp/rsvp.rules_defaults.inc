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
  return $items;
}
