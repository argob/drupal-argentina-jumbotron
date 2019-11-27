<?php

function drupar_jumbotron_theme($existing, $type, $theme, $path){
  return array(
    'drupar_jumbotron' => array(
      'path' => drupal_get_path('module', 'drupar_jumbotron') . '/templates/jumbotron',
      'template' => 'jumbotron',
    ),
    'drupar_jumbotron_una_columna' => array(
      'path' => drupal_get_path('module', 'drupar_jumbotron') . '/templates/jumbotron',
      'template' => 'jumbotron_una_columna',
    ),
    'drupar_jumbotron_dos_columna' => array(
      'path' => drupal_get_path('module', 'drupar_jumbotron') . '/templates/jumbotron',
      'template' => 'jumbotron_dos_columna',
    ),
  );
}
