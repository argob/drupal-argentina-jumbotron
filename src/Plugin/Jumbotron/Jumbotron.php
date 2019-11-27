<?php

abstract class Jumbotron
{
    public $data;
    
    public static $theme = 'drupar_jumbotron';
    
    function __construct($configuracion, $contenido)
    {
        $this->configuracion = $configuracion;
        $this->columna = $contenido;
    }

    public function render()
    {
        return theme(
            
            static::$theme,
            
            [
                'data' => [
                    'overlay' => $this->configuracion['overlay'],
                    'menuBar' => $this->configuracion['menuBar'],
                    'showTitle' => $this->configuracion['visualizacion_titulo'],
                    'descripcion' => isset($this->configuracion['resumen']) ? $this->configuracion['resumen'] : null,
                    'columna' => $this->columna,
                ],
                
                'breadcrumb' => $this->configuracion['breadcrumb'],
                'menu' => $this->configuracion['menuBar'],
                'background' => $this->background(),
            ]
        );
    }
}
