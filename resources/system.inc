<?php

/**
 * @file
 * Contains the resource callbacks for commerce system services.
 */

/**
 * Starts user session forcefully
 * This is useful in case of mobile apps where sessid is required for anonymous users
 *
 * @return
 *   User session object
 */

function commerce_system_services_connect() {
  global $user;
  
  // checks if session is already started
  // if not start a new session and send back session object
  if(!drupal_session_started()) {
    drupal_session_start();
    $return = new stdClass();
    $return->sessid = session_id();
    $return->session_name = session_name();
    $return->user = $user;
    services_remove_user_data($account);
    return $return;
  } else {
    $return = new stdClass();
    $return->sessid = session_id();
    $return->session_name = session_name();
    $return->user = $user;
    services_remove_user_data($account);
    return $return;
  }
}

/**
 * Deletes user session
 *
 * @return
 */

function commerce_system_services_session_destroy() {
  return session_destroy();
}

/**
 * Returns values of system variables/mobile configuration settings
 *
 * @param $variables
 *	An array of system variables
 * @return
 *   Array of requested system variable values
 */

function commerce_system_services_variables_get($variables = array()) {
	$conf = array();
	foreach($variables as $u) {
		$conf[$u] = variable_get($u);
	}
	return $conf;
}
