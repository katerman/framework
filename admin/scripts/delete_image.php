<?php

include_once "../../includes/scripts/app.php";

$security = new security();

$security->checkToken('token');	 // check security token

if($_POST){

	$helpers = new helpers($dsn, $db_user, $db_pass);

	$image = $_POST['image_name'];
	$dir = '../../uploads/';	
	$id = $_POST['image_id'];
	
	$image_path = $dir.$image;
		
	if (file_exists($image_path)) {
		
		$helpers->sqlDelete('images', "id = $id");	

		unlink($dir.$image);
		
		$resized = $dir.'/resized/'.$image.'-resized';
		
		if(file_exists($resized)){
			unlink($resized);
		}
			
	}else{
		echo 'file does not exist' . $image_path;
	}
	
	$data = array("id" => $id, "image"=>$image);
	echo json_encode($data);
}