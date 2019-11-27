<section class="<?php print $background['class']?> <?php print $background['align']; ?>" style="background-image:url(<?php print $background['link'];?>);">
  <?php if($data['overlay']): ?>
    <div class="overlay"></div>
  <?php endif ?>
  <div class="jumbotron_bar">
    <div class="container">
      <div class="row">
        <div class="col-md-12">
          <?php $node = node_load(arg(1));?>
          <?php if($data['menuBar'] && property_exists($node,"group_group") == 1): ?>
            <ul class="list-inline pull-right">
              <li>
                <div class="dropdown">
                  <?php print render($data['menuBar']); ?>
                </div>
              </li>
            </ul>
          <?php endif ?>
          <?= $breadcrumb ?>
        </div>
      </div>
    </div>
  </div>
  <?php print $data['columna']->render(); ?>
</section>
