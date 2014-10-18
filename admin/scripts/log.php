<?php

	session_start();

	include_once "../../includes/scripts/app.php";

	$security = new security();
	$helpers = new helpers();

	$security->checkToken('token');	 // check security token
	$data = array();

	if($_POST['purge'] == 1){
		$trun = $helpers->sqlTruncateTable("log");
		$data['status'] = 'success';
		echo json_encode($data['status']);
	}else{
		$data['status'] = 'failed';
		echo json_encode($data['status']);
	}
?>