<?php
$path = dirname(__FILE__);
$path = str_replace('home3/refinee9/public_html/', '', $path);
	
$array = array(
	'css_path' => $path.'/includes/css/',
	'js_path' => $path.'/includes/js/',
	'img_path' => $path.'/includes/img/',
	'upload_path' => $path.'/uploads/',
	'version' => 'v0.5 ALPHA ',
	'template_path' => 'app/views/templates/',
	'views_path' => 'app/views/'
);

$_CONFIG = (object) $array; //config object
   
#Debug#
//print_r($_CONFIG);
