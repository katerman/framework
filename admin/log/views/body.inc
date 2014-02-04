<div class="container"> <!- Container for skeleton -->
	<?php
	global $helpers;
	global $model;
	
	$log = $model->sqlSelect("*" , "log", "", "");

	
	/*
		echo 'full: ' . helpers::url(full) . '<br>';
		echo 'fullpage: ' . helpers::url(fullpage) . '<br>';
		echo 'folder: ' . helpers::url(folder) . '<br>';
		echo 'base: ' . helpers::url(base) . '<br>';
		echo 'lastpath: ' . helpers::url(lastpath);
		
		$model->sqlSelect( "*" //select, 
						  "pages", //from
						  array("page_template"), //column names
						  "" //where
					  ); 	
	*/
	
	?>
	

	
	<div id="header" class="sixteen columns"><? include_once('header.inc'); ?></div>
	
	<div id="container" class="sixteen columns"><!-- start content -->
			
		<div id="display" class="sixteen columns">
			<h1>The Log</h1>
			<table>
				<thead>
					<td>Name</td>
					<td>Action</td>
					<td>Content</td>
					<td>Time</td>
				</thead>
				
				
				<tbody>
					<?
						foreach($log as $l){
							echo '<tr><td>'.$l['log_name'].'</td>';
							echo '<td>'.$l['log_action'].'</td>';
							echo '<td>'.$l['log_content'].'</td>';
							echo '<td>'.$l['log_time'].'</td></tr>';
							
						}
					?>
				</tbody>
			</table>
			
			
			
		</div>
		
	</div><!-- end content-->
</div>
