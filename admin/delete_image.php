<?php

include_once "../includes/scripts/app.php";

$security = new security();

$security->checkToken('token');	 // check security token



if($_POST){
$image = $_POST['delete_file'];
	
	if (file_exists($image)) {
	
		unlink($image);
		
		$dir = dirname($image);
		$resized = $dir.'/resized/'.$image'-resized';
		
		if(file_exists($resized){
			unlink($resized);
		}
	
	}

}