<?php
	session_start();
		
	include_once "../includes/scripts/app.php";

	$helpers = new helpers($dsn, $db_user, $db_pass);

	//print_r($_POST);
	
	function is_ajax() {
		return isset($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest';
	}

	if(is_ajax()){
		
		$username = $_POST['username'];
		$sql = $helpers->sqlSelect("user_uName" , "users", "", "WHERE user_uName LIKE '$username'");
		
		echo json_encode($sql);
	}