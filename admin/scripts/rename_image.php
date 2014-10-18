<?php

include_once "../../includes/scripts/app.php";

$security = new security();

$security->checkToken('token');	 // check security token

if($_POST){

	$helpers = new helpers();
	
	$old_name = $_POST['old_name'];
	$new_name = $_POST['new_name'];
	$dir = '../../uploads/';
	$id = $_POST['image_id'];
	
	//rename image
	$values = array(
		'image_name' => $new_name
	);
	
	if(file_exists($dir.$old_name)){
		$helpers->sqlUpdate('images', $values, "id = $id");
		
		rename($dir.$old_name, $dir.$new_name);
		
		$dir = $dir . 'resized/';
		if(file_exists($dir.$old_name.'-resized')){
			//rename resized image, lets not leave anything behind now.
			rename($dir.$old_name.'-resized', $dir.$new_name.'-resized');
		}else{
			echo 'Warning: Resized file does not exist ' . $dir.$old_name . '-resized <br>';
			return true;
		}
	}else{
		echo 'File does not exist '. $dir.$old_name .'<br>';
	}
}
