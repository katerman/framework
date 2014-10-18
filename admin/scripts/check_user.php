<?php
	session_start();

	include_once "../../includes/scripts/app.php";

	$helpers = new helpers();

	//print_r($_POST);

	function is_ajax() {
		return isset($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest';
	}

	if(is_ajax()){

		$username = $_POST['username'];

		$user = new user();
		$return = $user->is_New($username);

		echo json_encode( array('taken' => (bool)$return ) );
	}