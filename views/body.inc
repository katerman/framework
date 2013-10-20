<?php
/*
	echo 'full: ' . helpers::url(full) . '<br>';
	echo 'fullpage: ' . helpers::url(fullpage) . '<br>';
	echo 'folder: ' . helpers::url(folder) . '<br>';
	echo 'base: ' . helpers::url(base) . '<br>';
	echo 'lastpath: ' . helpers::url(lastpath);
*/

?>


<?php
	global $model; 
	global $helpers; 
	global $view;
	global $security;

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


<div id="content"><!-- start content -->
	
	<? include_once('nav.inc'); ?>

	<div id="display">

		<? 
		
			if($helpers->getQuery('page','return') == false){
				header('Location:index.php?page=home');
			}		
			
		?>
		
	</div>
	
</div><!-- end content-->

