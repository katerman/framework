<?php
session_start();

//includes
$log = false;
$admin = false;
include_once "includes/scripts/app.php";


//class calls
$model = new appModel($dsn, $db_user, $db_pass);
$view = new appView();
$helpers = new helpers();
$security = new security(); 
  
$username = empty($_POST['username']) ? '' : strtolower(trim($_POST['username']));
$password = empty($_POST['password']) ? '' : trim($_POST['password']);

$contentPage = 'body';
$user = null;

if(!empty($_SESSION['userInfo'])){
	$user = $_SESSION['userInfo'];
	$contentPage = 'body';
	$_SESSION['userInfo'] = $user;
}

if (!empty($username) && !empty($password)){

	$user = $model->getUserByNamePass($username, $password);
	
	if(is_array($user)){
		$contentPage = 'body';
		session_start();
		$_SESSION['userInfo'] = $user;

	}
}



$view->show('header');
$view->show($contentPage, $user);
$view->show('footer');

?>