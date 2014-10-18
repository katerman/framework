<?php
	global $view;
	global $content;
?>
<div class="container">
	<div class="row">
		<div class="col-sm-12">
			<?php
				echo'<h1>';
				$view->show_content('header'); // will specifically target any content with area = header
				echo '</h1>';
				
				$view->show_content('content');//will specifically target any content with area = content

				//to not lock doors, we'll show content without an area, but it wont be included in any template.
				foreach($content as $cont){
					if(empty($cont['content_area'])){
						echo $cont['content'];
					}
				}
			?>
			
			
	
		</div>
	</div>
</div>
