<?php
//this will redirect to the install page, then db.php will be overwritten with relvent info
global $_CONFIG;

function url(){
	$request = parse_url($_SERVER['REQUEST_URI']);
	$path = $request["path"];
	
	$result = trim(str_replace(basename($_SERVER['SCRIPT_NAME']), '', $path), '/');
	
	$result = explode('/', $result);

	$max_level = 3;
	while ($max_level < count($result)) {
	    unset($result[0]);
	}
	$result = '/'.implode('/', $result);
	return $result;
	
}

if(!preg_match('/install/', url())){
	header('Location: '.$_CONFIG->root_path.'install');
}