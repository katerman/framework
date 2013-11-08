<?php

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

<div id="overlay"> <? include_once('forms/edit_content_form.inc');?></div>

<? include_once('header.inc'); ?>

<div id="container"><!-- start content -->
	
	<? include_once('nav.inc'); ?>

	<div id="display">

		<? 
		
			if($helpers->getQuery('tpl','return') == false){
				include_once('default_view.inc'); 
			}else if(file_exists('views/'.$helpers->getQuery('tpl','return').'.inc')){
				include_once($helpers->getQuery('tpl','return').'.inc'); 
			}else{
				include_once('default_view.inc'); 
			}			
			
		?>
		
	</div>
	
</div><!-- end content-->

