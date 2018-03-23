<?php

/**
 * @file
 * FARE salva module.
 */

/**
 * Implements hook_views_default_views().
 *
 * Allows to create a new view called `view_ricerche` when the module is
 * installed.
 * Callback from the fare_salva.module.
 */
function fare_salva_views_default_views() {

  // Paste from Drupal view creator.
  $view = new view();
  $view->name = 'view_ricerche';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'view_ricerche';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Ricerche salvate';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access fare_salva';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« prima';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ precedente';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'seguente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'ultima »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'nid' => 'nid',
    'created' => 'created',
    'field_contatore' => 'field_contatore',
    'field_condiviso' => 'field_condiviso',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_contatore' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_condiviso' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Contenuto: Autore */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Content revision: Contenuto */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Campo: Contenuto: Titolo */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Campo: Contenuto: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Titolo';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '<a href="?q=/fare/elabora/[nid]">[title]</a>';
  /* Campo: Contenuto: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Data creazione';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  /* Campo: Contenuto: contatore */
  $handler->display->display_options['fields']['field_contatore']['id'] = 'field_contatore';
  $handler->display->display_options['fields']['field_contatore']['table'] = 'field_data_field_contatore';
  $handler->display->display_options['fields']['field_contatore']['field'] = 'field_contatore';
  $handler->display->display_options['fields']['field_contatore']['label'] = 'Numero elementi salvati';
  $handler->display->display_options['fields']['field_contatore']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Campo: Contenuto: condiviso */
  $handler->display->display_options['fields']['field_condiviso']['id'] = 'field_condiviso';
  $handler->display->display_options['fields']['field_condiviso']['table'] = 'field_data_field_condiviso';
  $handler->display->display_options['fields']['field_condiviso']['field'] = 'field_condiviso';
  $handler->display->display_options['fields']['field_condiviso']['label'] = 'Condiviso';
  $handler->display->display_options['fields']['field_condiviso']['alter']['text'] = '<?php  ?>';
  $handler->display->display_options['fields']['field_condiviso']['alter']['path'] = '?q=fare/share&[nid]';
  $handler->display->display_options['fields']['field_condiviso']['empty'] = 'NO';
  /* Campo: Content revision: Vid */
  $handler->display->display_options['fields']['vid']['id'] = 'vid';
  $handler->display->display_options['fields']['vid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['vid']['field'] = 'vid';
  $handler->display->display_options['fields']['vid']['label'] = 'Condividi';
  $handler->display->display_options['fields']['vid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['vid']['alter']['text'] = '<a href="?q=fare/share/[vid]">Condividi ora</a>';
  /* Sort criterion: Contenuto: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date';
  /* Filter criterion: Contenuto: Pubblicato */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Contenuto: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ricerche_salvate' => 'ricerche_salvate',
  );
  /* Filter criterion: Utente: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'ricerche-salvate';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Ricerche salvate';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['view_ricerche'] = array(
    t('Master'),
    t('Ricerche salvate'),
    t('more'),
    t('Apply'),
    t('Ripristina'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« prima'),
    t('‹ precedente'),
    t('seguente ›'),
    t('ultima »'),
    t('author'),
    t('Get the actual content from a content revision.'),
    t('Titolo'),
    t('<a href="?q=/fare/elabora/[nid]">[title]</a>'),
    t('Data creazione'),
    t('Numero elementi salvati'),
    t('Condiviso'),
    t('<?php  ?>'),
    t('NO'),
    t('Condividi'),
    t('<a href="?q=fare/share/[vid]">Condividi ora</a>'),
    t('Post date'),
    t('Page'),
  );

  // Preparing return.
  $views[$view->name] = $view;
  return $views;
}
