<?php

include_once "../../includes/scripts/app.php";

$security = new security();

$security->checkToken('token');	 // check security token


if($_POST){
$image = $_POST['delete_file'];
$dir = '../../uploads/';	
	//print_r(dirname($image));
	
	if (file_exists($dir.$image)) {
	
		unlink($dir.$image);

		$resized = $dir.'/resized/'.$image.'-resized';
		
		if(file_exists($resized)){
			unlink($resized);
		}
	
	}

}