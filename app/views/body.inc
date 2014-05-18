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

	$r = $helpers->sqlSelect("*" , "templates", "", "WHERE id = '$page[page_template]'");
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

	//if there is no page query return page=home
	if($helpers->getQuery('page','return') == false){
		header('Location:index.php?page=home');
	}	

?>


	
		
	<?php include_once('nav.inc'); ?>
	
	<?php 
		//if current page has a template display it.
		if($page['page_template']){
			$view->show('templates/'.$r[0]['template_name']);
		}
		
		//to not lock doors, we'll show content without an area, but it wont be included in any template.
		foreach($content as $cont){
			if(empty($cont['content_area'])){
				echo $cont['content'];
			}
		}
	
	?>


    <footer>
    	<div class="container">
    		<div class="row">
			    <hr>
		        <p><?php $view->show_label('refined_designs');?></p>
    		</div>
    	</div>
    </footer>
</div><!-- /container -->
