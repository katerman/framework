<?php
	global $view;
?>
<div class="container">
	<div class="row">
		<div class="col-xs-6">
			<?php
				$view->show_content('header_col_one');
				$view->show_content('content_col_one');
			?>
	
		</div>
		
		<div class="col-xs-6">
			<?php
				$view->show_content('header_col_two');
				$view->show_content('content_col_two');
			?>
		</div>
	</div>
</div>
