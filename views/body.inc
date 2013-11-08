<?php
/*
	echo 'full: ' . helpers::url(full) . '<br>';
	echo 'fullpage: ' . helpers::url(fullpage) . '<br>';
	echo 'folder: ' . helpers::url(folder) . '<br>';
	echo 'base: ' . helpers::url(base) . '<br>';
	echo 'lastpath: ' . helpers::url(lastpath). '<br>';
	echo 'current: ' . helpers::url(current);
*/

?>


<?php
	global $model; 
	global $helpers; 
	global $view;
	global $security;
	global $config;
	global $areas;

	
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

<div id="header">
	<? echo '<img src="uploads/'.$config['global_logo'].'" alt="logo">';?>
</div>

<div id="content"><!-- start content -->
	
	<? include_once('nav.inc'); ?>

	<div id="display">
		<? //print_r($areas); 
			 echo '<br><h1>'.$areas->header_one .'</h1>' ;
			
		?>

		<? 
		
			if($helpers->getQuery('page','return') == false){
				header('Location:index.php?page=home');
			}		
			
		?>
		
	</div>
	
</div><!-- end content-->

