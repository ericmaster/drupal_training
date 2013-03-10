<?php
// == Devsu branding =========================================================

/**
 * Implements hook_init().
 */
function drupal_training_init() {
  global $conf;

  // Use this early opportunity to brand the install/runtime experience.
  // Once the generic theme settings are saved, or a custom theme's settings
  // are saved to override it, this will not be effective anymore, which is
  // intended.
  if (empty($conf['theme_settings'])) {
    $conf['theme_settings'] = array(
      'default_logo' => 0,
      // Default to different logos depending on whether Drupal is installed or not.
      'logo_path' => empty($conf['site_name']) ? 'profiles/drupal_training/logo-devsu.png' : 'profiles/drupal_training/logo-devsu.png',
    );
  }
}

// == Configuration UI =========================================================

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function drupal_training_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = 'Drupal Training';
}
