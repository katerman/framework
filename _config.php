<?php
$config_path = dirname(__FILE__);
$config_path = str_replace('home3/refinee9/public_html/', '', $config_path);
	
$array = array(
	'css_path' => $config_path.'/includes/css/',
	'js_path' => $config_path.'/includes/js/',
	'img_path' => $config_path.'/includes/img/',
	'upload_path' => $config_path.'/uploads/',
	'version' => 'v0.6 ALPHA ',
	'template_path' => 'app/views/templates/',
	'views_path' => 'app/views/',
	
	'allow_image_upload' => true,
	
	'date_default_timezone_set' => 'America/New_York',
	
	'error_reporting' => true,
	
	'template_debug' => false
);

$_CONFIG = (object) $array; //config object
   
#Debug#
//print_r($_CONFIG);
