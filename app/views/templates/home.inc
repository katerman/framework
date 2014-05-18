<?php
	global $view;
?>

<div class="jumbotron">
    <div class="container">
	<?php $view->show_content('jumbotron');?>
    </div>
</div>

<div class="container">
    <!-- Example row of columns -->

<div class="row">
    <div class="col-md-4">
		<?php
			$view->show_content('column_one');
		?>
    </div>

    <div class="col-md-4">
		<?php
			$view->show_content('column_two');
		?>
    </div>

    <div class="col-md-4">
		<?php
			$view->show_content('column_three');
		?>
    </div>
</div>
   
</div>
