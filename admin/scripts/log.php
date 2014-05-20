<?php

	session_start();
		
	include_once "../../includes/scripts/app.php";
	
	$security = new security();
	$helpers = new helpers($dsn, $db_user, $db_pass);
		
	$security->checkToken('token');	 // check security token	
		
	if($_POST['purge'] == 1){
		$trun = $helpers->sqlTruncateTable("log");
	}

?>