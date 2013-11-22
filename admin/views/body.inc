<div class="container"> <!- Container for skeleton -->
	<?php
	global $helpers;
	$type = $helpers->getQuery('type','return');
	$tpl = $helpers->getQuery('tpl','return');
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
	
	<div id="overlay" class="ten columns"> <?if($type === 'edit_page'){ include_once('forms/content_form.inc'); }
											 else if($tpl === 'templates'){include_once('forms/template_form.inc');}
											 else if($tpl === 'labels'){include_once('forms/label_form.inc');}
	?></div>
	
	<div id="header" class="sixteen columns"><? include_once('header.inc'); ?></div>
	
	<div id="container" class="sixteen columns"><!-- start content -->
		
		<div id="nav" class="three columns"><? include_once('nav.inc'); ?></div>
	
		<div id="display" class="thirteen columns">
	
			<? 
			
				if($tpl == false){
					include_once('default_view.inc'); 
				}else if(file_exists('views/'.$tpl.'.inc')){
					include_once($tpl.'.inc'); 
				}else{
					include_once('default_view.inc'); 
				}			
				
			?>
			
		</div>
		
	</div><!-- end content-->
</div>
