<?php

//use Drupar\Helpers\ImageHelper;

class JumbotronPattern extends Jumbotron
{
    function background()
    {
        if ($this->configuracion['patron']) {
            
            $file = file_load($this->configuracion['patron']);
            $fileURL = file_create_url($file->uri);
            
        } else {
    
            $fileURL = NULL;
            
        }
        
        return [
            
            'link' => isset($fileURL) ? $fileURL : null,
            'align' => isset($this->configuracion['align']) ? $this->configuracion['align']  : "",
            'class' => "jumbotron jumbotron-pattern",
            
        ];
    }
}
