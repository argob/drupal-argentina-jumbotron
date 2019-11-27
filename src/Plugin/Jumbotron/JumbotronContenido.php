<?php

abstract class JumbotronContenido
{
    abstract function theme();
    
    function __construct($conf)
    {
        $this->conf = $conf;
    }
    
    public function render()
    {
        return theme(

            $this->theme(),

            [
                'titulo' => $this->titulo(),
                'descripcion' =>$this->descripcion(),
                'logo'=> $this->logo(),
                'boton' => $this->boton(),
                'mostrarTitulo' => $this->mostrarTitulo()
            ]
        );
    }
    
    protected function descripcion()
    {
        return !is_null($this->conf['node']->body->value()) ? $this->conf['node']->body->summary->value() : null;
    }
    
    protected function titulo()
    {
        return $this->conf['override_title'] ? $this->conf['override_title_text'] : $this->conf['node']->title->value();
    }
    
    protected function boton()
    {
        return $this->mostrarBoton() ? $this->crearBoton() : null;
    }
    
    protected function crearBoton()
    {
        return [
            'text' => isset($this->conf['texto_boton']) ? $this->conf['texto_boton'] : t('Click'),
            'claseColor' => isset($this->conf['color_boton']) ? 'btn btn-primary ' . $this->conf['color_boton'] : 'btn btn-default',
            'href' => isset($this->conf['href']) ? $this->conf['href'] : null
        ];
    }
    
    protected function logo()
    {
        return $this->mostrarIcono() ? $this->crearLogo() : null;
    }
    
    protected function mostrarIcono()
    {
        return $this->conf['showIcono'];
    }
    
    protected function crearLogo()
    {
        if ($this->conf['logotipo']) {
            
            $file = file_load($this->conf['logotipo']);
            $fileURL = file_create_url($file->uri);
        }
        
        return isset($fileURL) ? $fileURL : null;
    }
    
    protected function mostrarBoton()
    {
        return $this->conf['mostrar_boton'];
    }
    
    protected function mostrarTitulo()
    {
        return $this->conf['visualizacion_titulo'];
    }
}