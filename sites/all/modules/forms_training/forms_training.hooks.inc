<?php

/**
 * Implements hook_theme().
 */
function forms_training_theme($existing, $type, $theme, $path){
  return array(
    'samplerange' => array(
      'render element' => 'element',
    ),
    'forms_training_draggable_table' => array(
      'render element' => 'form',
    )
  );
}

/**
 * Theme function for sample range element
 */
function theme_samplerange($variables){
  $element = $variables['element'];
  $element['#attributes']['type'] = 'range';
  element_set_attributes($element, array('id', 'name', 'value', 'min', 'max', 'step'));
  $output = '<input' . drupal_attributes($element['#attributes']) . ' />';
  return $output;
}

/**
 * Theme function for draggable tables
 */
function theme_forms_training_draggable_table($variables){
  drupal_add_tabledrag('forms-training-dt', 'order', 'sibling', 'item-weight');
  
  $header = array(
    t('Textfield'),
    t('Select'),
    array(
      'data' => t('Weight'),
      'class' => 'tabledrag-hide'
    )
  );
  $rows = array();
  $index = 0;
  $items = element_children($variables['form']);
  foreach($items as $mlid){
   $variables['form'][$mlid]['weight']['#attributes']['class'] = array('item-weight');
   $rows[] = array(
      'data' => array(
        array(
          'data' => drupal_render($variables['form'][$mlid]['textfield']),
          'class' => array(''),
        ),
        array(
          'data' => drupal_render($variables['form'][$mlid]['select']),
          'class' => array(''),
        ),
        array(
          'data' => drupal_render($variables['form'][$mlid]['weight']),
          'class' => array(''),
        ), 
      ),
      'class' => array('draggable')
    );
    $index++;
  }
  $output = theme('table', array('header' =>$header, 'rows' => $rows, 'attributes' => array('id' => 'forms-training-dt')));
  return $output;
}
