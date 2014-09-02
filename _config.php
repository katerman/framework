<?php
$config_root = dirname(__FILE__);
$config_path = str_replace($_SERVER['DOCUMENT_ROOT'], '', $config_root);
	
$array = array(	
	'version' => '1.32',

	'config_path' => $config_root.'/',
	'root_path' => $config_path.'/',
	
	'css_path' => $config_path.'/includes/css/',
	'js_path' => $config_path.'/includes/js/',
	'img_path' => $config_path.'/includes/img/',
	'upload_path' => $config_path.'/uploads/',
	'update_path' => $config_root.'/includes/updates/',
	
	'template_path' => 'app/views/templates/',
	'views_path' => 'app/views/',
		
	'allow_image_upload' => true,
	
	'date_default_timezone_set' => 'America/New_York',
	
	'error_reporting' => true,
	'template_debug' => false,
	
	'caching' => true,//basic php caching
	
	'remote_update_loc' => 'http://refineddesigns.net/framework/'
);

$_CONFIG = (object) $array; //config object