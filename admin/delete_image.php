<?php

include_once "../includes/scripts/app.php";

$security = new security();

$security->checkToken('token');	 // check security token



if($_POST){
$image = $_POST['delete_file'];
	
	if (file_exists($image)) {
	
		unlink($image);
/* 		echo '<p style="color: rgb(206, 36, 36); margin-bottom: 10px;">File '.$image.' has been deleted</p>'; */
	
	} else {
	
/* 		echo '<p style="color: rgb(206, 36, 36); margin-bottom: 10px;">Could not delete '.$image.', file does not exist</p>'; */
	
	}

}