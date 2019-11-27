<?php

$plugin = array(
    'single' => true,
    'title' => t('Jumbotron'),
    'description' => t(''),
    'category' => t('Drupar'),
    'edit form' => 'drupar_componentes_jumbotron_imagen_destacada_edit_form',
    'render callback' => 'drupar_componentes_jumbotron_imagen_destacada_render',
    'admin info' => 'drupar_componentes_jumbotron_imagen_destacada_admin_info',
    'defaults' => array(
        'formato' => 'JumbotronUnaColumna',
        'tipo_background' => 'JumbotronImage',
        'patron' => null,
        'align' => 'align-mid',
        'overlay' => true,
        'visualizacion_titulo' => true,
        'showIcono' => "",
        'logotipo' => null,
        'mostrar_boton' => true,
        'texto_boton'=> '',
        'href' => '',
        'color_boton' => '',
    )
);

function drupar_componentes_jumbotron_imagen_destacada_edit_form($form, &$form_state)
{
    form_load_include($form_state, 'inc', 'drupar_jumbotron','plugins/content_types/jumbotron');
    
    $form['mostrar_boton'] = array(
        '#type' => 'hidden',
        '#value' => $form_state['conf']['mostrar_boton'],
    );
    
    $form['configuracion'] = array(
        '#type' => 'fieldset',
        '#title' => t('Configurar Jumbotrón'),
        '#collapsible' => true,
        '#collapsed' => true,
    );
    
    $form['container_fondo'] = array(
        '#type' => 'fieldset',
        '#title' => t('Configurar Background'),
        '#attributes' => array(),
        '#collapsible' => true,
        '#collapsed' => true,
    );
    
    $form['configuracion']['formato'] = array(
        '#type' => 'select',
        '#title' => t('Formato de visualización'),
        '#options' => array(
            'JumbotronUnaColumna' => t('1 Columna'),
            'JumbotronDosColumnas' => t('2 Columnas')
        ),
        '#default_value' => $form_state['conf']['formato'],
    );
    
    $form['container_fondo']['tipo_background'] = array(
        '#type' => 'radios',
        '#title' => t('Tipo de Background'),
        '#options' => array(
            'JumbotronImage' => t("Imagen"),
            'JumbotronPattern' => t("Motivo"),
        ),
        '#description' => t('Imagen: una sóla imagen que se acomoda al tamaño del dispositivo. Motivo: Una imagen repetida indefinidamente.'),
        '#default_value' => $form_state['conf']['tipo_background']
    );
    
    $form['container_fondo']['patron'] = array(
        "#type" => "managed_file",
        "#title" => t('Subir imagen del patrón'),
        '#description' => t(''),
        '#default_value' => isset($form_state['conf']['patron']) ? $form_state['conf']['patron'] : 0,
        '#upload_location' => 'public://',
        '#progress_indicator' => 'bar',
        '#progress_message' => t('Subiendo archivo ...'),
        '#upload_validators' => array(
            'file_validate_extensions' => array('jpg jpeg'),
        ),
        '#states' => array(
            'visible' => array(
                ':input[name="tipo_background"]' => array('value' => 'JumbotronPattern')
            ),
        ),
    );
    
    $form['container_fondo']['align'] = array(
        '#type' => 'radios',
        '#title' => t('Alineación de imagen de Background'),
        '#options' => array(
            'align-top' => t('Alineación superior'),
            'align-mid' => t('Alineación central'),
            'align-bottom' => t('Alineación inferior'),
        ),
        '#states' => array(
            'visible' => array(
                ':input[name="tipo_background"]' => array('value' => 'JumbotronImage')
            ),
        ),
        '#default_value' => $form_state['conf']['align']
    );
    
    $form['container_fondo']['overlay'] = array(
        '#type' => 'checkbox',
        '#title' => t('Oscurecer fondo'),
        '#default_value' => $form_state['conf']['overlay'],
    );

    $form['container_fondo']['visualizacion_titulo'] = array(
        '#type' => 'checkbox',
        '#title' => t('Mostrar título'),
        '#default_value' => $form_state['conf']['visualizacion_titulo'],
    );
    
    $form['configuracion']['logotipo'] = array(
        "#type" => "managed_file",
        "#title" => t('Logotipo'),
        '#description' => t('The uploaded image will be displayed on this page using the image style choosen below.'),
        '#default_value' => $form_state['conf']['logotipo'],
        '#upload_location' => 'public://',
    );
    
    $form['configuracion']['showIcono'] = array(
        '#type' => 'checkbox',
        '#title' => t('Mostrar logotipo'),
        '#default_value' => $form_state['conf']['showIcono'],
    );
    
    if ($form_state['conf']['mostrar_boton']) {
        
        $form['container_boton'] = array(
            '#type' => 'fieldset',
            '#title' => t('Configuración de Boton'),
            '#attributes' => array(),
            '#collapsible' => true,
            '#collapsed' => false,
        );
    
        $form['container_boton']['texto_boton'] = array(
            '#type' => 'textfield',
            '#title' => t('Texto del Boton'),
            '#default_value'=> $form_state['conf']['texto_boton'],
        );
    
        $form['container_boton']['href'] = array(
            '#type' => 'textfield',
            '#title' => t('Link del Boton'),
            '#rules' => array(
                'url',
            ),
            '#default_value'=> $form_state['conf']['href'],
        );
    
        $form['container_boton']['color_boton'] = array(
            '#type' => 'select',
            '#title' => t('Color del Boton'),
            '#options' => array(
                'btn-default' => t('Gris'),
                'btn-primary' => t('Azul'),
                'btn-success' => t('Verde'),
                'btn-danger' => t('Rojo'),
                'btn-link' => t('Link'),
            ),
            '#default_value'=> $form_state['conf']['color_boton'],
        );
    }
    
    $form['agregar_boton'] = array(
        '#type' => 'submit',
        '#value' => t('Mostrar / Ocultar botón'),
        '#submit' => array('jumbotron_switch_btn'),
    );
    
    return $form;
}

function jumbotron_agregar_boton($form, &$form_state)
{
    $form_state['conf']['mostrar_boton'] = true;
    $form_state['rebuild'] = true;
}

function jumbotron_switch_btn($form, &$form_state)
{
    $form_state['conf']['mostrar_boton'] = !$form_state['conf']['mostrar_boton'];
    $form_state['rebuild'] = true;
}


/**
* 'admin info' callback for panel pane.
*/
function drupar_componentes_jumbotron_imagen_destacada_admin_info($subtype, $conf, $contexts)
{
    if (!empty($conf)) {
        $block = new stdClass;
        $block->title = $conf['override_title'] ? $conf['override_title_text'] : t('Imagen destacada');
        $block->content = t('Imagen destacada.');
        return $block;
    }
}


function drupar_componentes_jumbotron_imagen_destacada_render($subtype, $conf, $panel_args, $context = null, $form_state)
{
    $block = new stdClass();
    $block->title = '';
  
    corregirConfiguracionJumbotron($conf);
  
    $conf['node'] = entity_metadata_wrapper('node', arg(1));
    $contenido = new $conf['formato']($conf);
    
    $conf['breadcrumb'] = theme('breadcrumb', array('breadcrumb' => drupal_get_breadcrumb()));
    $conf['menuBar'] = module_invoke('og_menu_single', 'block_view', 'menu');
  
    $jumbotron = new $conf['tipo_background']($conf, $contenido);

    $block->content = $jumbotron->render();

    return $block;
}

function corregirConfiguracionJumbotron(&$conf)
{
    $conf['overlay'] = $conf['overlay'] != null ? $conf['overlay'] : false;
    $conf['visualizacion_titulo'] = $conf['visualizacion_titulo'] != null ? $conf['visualizacion_titulo'] : false;
    $conf['formato'] = $conf['formato'] == null ? "JumbotronUnaColumna" : $conf['formato'];
    $conf['tipo_background'] = $conf['tipo_background'] != null ? $conf['tipo_background'] : "JumbotronImage";
}


function drupar_componentes_jumbotron_imagen_destacada_edit_form_submit($form, &$form_state)
{
    if ($form_state['values']['patron'] != 0) {
        $imagen = file_load($form_state['values']['patron']);
        $imagen->status = FILE_STATUS_PERMANENT;
        file_usage_add($imagen, 'argentinagobar_bloques', 'file', $imagen->fid);
        file_save($imagen);
    }

    if ($form_state['values']['logotipo'] != 0) {
        $logotipo = file_load($form_state['values']['logotipo']);
        $logotipo->status = FILE_STATUS_PERMANENT;
        file_usage_add($logotipo, 'argentinagobar_bloques', 'file', $logotipo->fid);
        file_save($logotipo);
    }

    foreach (array_keys($form_state['plugin']['defaults']) as $key) {
        if (isset($form_state['values'][$key])) {
            $form_state['conf'][$key] = $form_state['values'][$key];
        }
    }
}
