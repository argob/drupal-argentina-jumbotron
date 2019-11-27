<?php

//use Drupar\Helpers\ImageHelper;

class JumbotronImage extends Jumbotron
{
   
    function background()
    {
        
        if ($file = $this->configuracion['node']->field_featured_image->value()) {
    
            if ($file['type'] == 'image' && $file['filemime'] == 'image/png') {
        
                $fileURL = image_style_url('jumbotron', ImageHelper::png2jpg($file));
        
            } else {
    
                $fileURL = image_style_url('jumbotron', $file['uri']);
            }
            
        } else {
    
            $fileURL = null;
            
        }
        
        return [
            'link'  => $fileURL,
            'align' => $this->configuracion['align'],
            'class' => "jumbotron ",
        ];
    }
}
