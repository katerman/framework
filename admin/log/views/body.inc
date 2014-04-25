<div class="container"> <!- Container for skeleton -->
	<?php
		global $helpers;
		global $model;
		
		$log = $helpers->sqlSelect("*" , "log", "", "");
		$purge = $helpers->getQuery('purge', 'return');
		
		if($purge == 1){
			$helpers->sqlDelete("*" , "log", "");
			header('Location: ?purge=0');
		}

	?>
	

	
	<div id="header"><? include_once('header.inc'); ?></div>
	
	<div id="container"><!-- start content -->
			
		<div class="inner-padding container">
			<div class="custom columns">
				<div class="inner-padding-gray">
				
				<h1>The Log</h1>
				<a href="?purge=1" id="purge" class="btn" style="margin: 5xp 0;">Purge The Log</a>
				<table class="table" style="margin-top: 10px;">
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
			</div>
		</div>
	</div><!-- end content-->
</div>