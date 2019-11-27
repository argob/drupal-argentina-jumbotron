<div class="jumbotron_body">
  
  <div class="container">
    
    <div class="row">
      
      <div class="col-xs-12 col-md-6">
    
          <?php if($mostrarTitulo): ?>

              <h1><?= $titulo ?></h1>
    
          <?php else: ?>

              <h1 class="sr-only"><?= $titulo ?></h1>
    
          <?php endif; ?>
          
          <p><?= ($descripcion); ?></p>

          <?php if($boton['href']): ?>
          
            <a href="<?php print ($boton['href']);?>" class="<?php print ($boton['claseColor']);?>" ><?php print  ($boton['text']);?></a>

          <?php endif; ?>
        
      </div>
      
      <div class="col-xs-12 col-md-6">
          
          <?php if ($logo != NULL): ?>
              
              <img class="img-responsive" src="<?= $logo; ?>">
    
          <?php endif; ?>
          
      </div>
      
    </div>
    
  </div>
  
</div>
