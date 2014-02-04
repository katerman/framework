<?php
session_start();

//includes
include_once "../../db.php";
include_once "../../AuthModel.php";
include_once "../../AuthView.php";
include_once "../../includes/helpers.php";
include_once "../../includes/security.php";
include_once "../../_config.php";

//class calls
$model = new AuthModel($dsn, $db_user, $db_pass);
$view = new AuthView();
$helpers = new helpers();
$security = new security();

global $_CONFIG;

//check for user/pass in post
$username = empty($_POST['username']) ? '' : strtolower(trim($_POST['username']));
$password = empty($_POST['password']) ? '' : trim($_POST['password']);

//make default page login.inc
$contentPage = 'login';

//get our user var from session information
$user = $_SESSION['userInfo'];

//if our session isnt empty, but access doesnt equal 1 return them back to login(.inc) page, if it is one, bring them to the body.inc
if(!empty($_SESSION['userInfo'])){
	if($user['access'] != 1){
		$contentPage = 'login';		
	}else{	
		$contentPage = 'body';
		$_SESSION['userInfo'] = $user;
	}
}

//if both our $username and $password arent empty call getuserbynamepass() to validate, then check if $user is an array, and display the body(.inc) also start a session again(redundent).
if (!empty($username) && !empty($password)){

	$user = $model->getUserByNamePass($username, $password);
	
	if(is_array($user)){
		$contentPage = 'body';
		session_start();
		$_SESSION['userInfo'] = $user;				
	}
}


//if our users access doesnt equal 1 and our page is anything other than login return a 403 error and kick them out, else run admin as it should be.
if($user['access'] != 1 && $contentPage != 'login'){
	$e = header("HTTP/1.1 403 Forbidden");
}else{
	$view->show('head');
	$view->show($contentPage, $user);
	$view->show('footer');
} 


?>
