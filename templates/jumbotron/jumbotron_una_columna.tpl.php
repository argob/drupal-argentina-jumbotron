<div class="jumbotron_body">
  
  <div class="container">
    
    <div class="row">
      
      <div class="col-xs-12 col-md-8 col-md-offset-2 text-center">
        
        <?php if ($logo != NULL): ?>
        
        <p class="margin-20">
            
            <img src="<?= $logo; ?>">
        
        </p>
        
        <?php endif; ?>
          
        <?php if($mostrarTitulo): ?>
          
          <h1><?= $titulo ?></h1>
        
        <?php else: ?>
          
          <h1 class="sr-only"><?= $titulo ?></h1>
        
        <?php endif; ?>
          
        <p><?= $descripcion ?></p>

        <?php if($boton['href']): ?>
        
          <a href="<?php print($boton['href']);?>" class="<?php print($boton['claseColor']);?>" ><?php print ($boton['text']);?></a>

        <?php endif; ?>
          
      </div>
      
    </div>
    
  </div>
  
</div>
