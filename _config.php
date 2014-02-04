<?
$path = 'http://refineddesigns.net'; 
	
$array = array(
	'css_path' => $path.'/framework/css/',
	'js_path' => $path.'/framework/js/',
	'img_path' => $path.'/framework/img/',
	'upload_path' => $path.'/framework/uploads/',
	'version' => 'v0.4 ALPHA ',
	'template_path' => 'views/templates/',
	'upload_path' => 'uploads/'
);

$_CONFIG = (object) $array; //config object

	

   
#Debug#
//print_r($_CONFIG);

?>