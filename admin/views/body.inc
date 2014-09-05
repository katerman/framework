<?php
	global $helpers;
	$type = $helpers->getQuery('type','return');
	$tpl = $helpers->getQuery('tpl','return');
	$config = $helpers->sqlSelect("*" , "config", "", "");
	$config = $config[0];
?>

<div id="overlay"> 

	<?php 	// /forms/edit_form.inc
		if($type === 'edit_page'){ include_once('forms/edit_form.inc'); }
		else if($tpl === 'templates'){include_once('forms/template_form.inc');}
		else if($tpl === 'labels'){include_once('forms/label_form.inc');}
		else if($tpl === 'scattershot'){include_once('forms/scattershot_form.inc');}
	?>

</div>

<div id="header"><?php include_once('header.inc'); ?></div>

<div id="container"><!-- start content -->
	
	<div id="nav"><?php include_once('nav.inc'); ?></div>

	<div class="inner-padding container">
		<div class="custom columns">
			<div class="inner-padding-gray">		
		
				<?php 
				
					if($tpl == false){
						include_once('default_view.inc'); 
					}else if(file_exists('views/'.$tpl.'.inc')){
						include_once($tpl.'.inc'); 
					}else{
						include_once('default_view.inc'); 
					}			
					
				?>
			</div>
		</div>
	</div>
	
	<div id="footer">
		<div>
			<a href="https://github.com/katerman/framework">RefinedCMS &bull; v<?php echo $config['version'].  ' &bull; ' . date('Y'); ?></a>
		</div>
	</div>
	

	
</div><!-- end inner-padding/container-->

