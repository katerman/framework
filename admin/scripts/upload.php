<?php

include_once "../../includes/scripts/app.php";

$security = new security();

$security->checkToken('token');	 // check security token

$helpers = new helpers();

if (!empty($_FILES)) {

	$file_name = $_FILES['file']['name'];
	$check_image = $helpers->sqlSelect("image_name", "images", false, "WHERE image_name LIKE '%$file_name%'");
	//error_log($check_image . 'count: ' . count($check_image) );
	$user = new user();

	global $_CONFIG;
	$ds          = DIRECTORY_SEPARATOR;
	$storeFolder = 'uploads';
	$today = date("Y-m-d H:i:s");

   	$size = $helpers->display_filesize($_FILES['file']['size']);
    $tempFile = $_FILES['file']['tmp_name'];
    $targetPath = dirname(dirname(dirname(__FILE__))) . $ds. $storeFolder . $ds;    //id like to use $_CONFIG['upload_path'] here eventually..
    error_log($targetPath);
    $targetPath = $_CONFIG->upload_path;
    $targetFile =  $targetPath . $file_name;
	error_log($targetPath);

    move_uploaded_file($tempFile,$targetFile);

    if(count($check_image) === 0){
		$values = array(
			'image_name' => $file_name,
			'image_created' => $today,
			'image_size' => $size,
			'image_type' => $_FILES['file']['type'],
			'uploaded_by' => $user->get_Fullname(),
			'last_edited_by' => $user->get_Fullname()
		);
		$helpers->sqlAdd('images', $values);

		$helpers->sqlLog($file_name,'uploaded');
	}
}