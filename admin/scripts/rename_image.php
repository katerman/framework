<?php

include_once "../../includes/scripts/app.php";

$security = new security();

$security->checkToken('token');	 // check security token


if($_POST){
	
	$old_name = $_POST['old_name'];
	$new_name = $_POST['new_name'];
	$dir = '../../uploads/';
	
	
	//rename image
	rename($dir.$old_name, $dir.$new_name);
	
	$dir = '../../uploads/resized/';
	//rename resized image, lets not leave anything behind now.
	rename($dir.$old_name.'-resized', $dir.$new_name.'-resized');
}