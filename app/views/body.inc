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
	
	//globals for content
	global $config; //config in db
	global $areas;
	global $content;
	global $page;
	global $_CONFIG; //config file

	$r = $model->sqlSelect("*" , "templates", "", "WHERE id = '$page[page_template]'");
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
	<?php echo '<img src="'.$_CONFIG->upload_path.$config['global_logo'].'" alt="logo">';?>
</div>

<div id="content"><!-- start content -->
	
	<?php include_once('nav.inc'); ?>

	<div id="display">
	<?php		
			if(isset($areas->area)){
				echo '<br><h1>'.$areas->area .'</h1>' ;
			}
			
			if($page['page_template']){
				include_once($_CONFIG->template_path.$r[0]['template_name'].'.inc');
				echo $_CONFIG->template_path.$r[0]['template_name'].'.inc';
			}
						 
			 foreach($content as $cont){
				 if(empty($cont['content_area'])){
					 echo $cont['content'];
				 }
			 }
		?>

		<?php 
		
			if($helpers->getQuery('page','return') == false){
				header('Location:index.php?page=home');
			}		
			
		?>
		
	</div>
	
</div><!-- end content-->

