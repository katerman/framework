<?php
session_start();

include_once "../db.php";
include_once "../includes/security.php";
include_once "../AuthModel.php";


$security = new security();
$model = new AuthModel($dsn, $db_user, $db_pass);

$name = $_SESSION['userInfo']['fullname'];
$date_time = date( "F j, Y, g:i a");
	
$token = $_POST['token'];
$id = $_POST['id'];	
$type = $_POST['type'];
$db_id = $_POST['db_id'];

if($type === 'content'){
	$security->checkToken('edit_token');
}elseif($type === 'sub_page'){
	$security->checkToken('edit_token');
	$type = "pages";	
}elseif($type === 'templates'){
	$security->checkToken('template_token');
}elseif($type === 'labels'){
	$security->checkToken('label_token');
}else{
	$security->checkToken('delete_page_token');
}

try{
	$db = new PDO($dsn, $db_user, $db_pass);		
}catch (PDOException $e){
	var_dump($e);		
}


if(isset($token)){	//delete from pages WHERE pages_id = :id  /  :id bound to 0

	// Delete
	$sql = $db->prepare('DELETE FROM '.$type.' WHERE '. $db_id .' = :id'); 
	$sql->bindValue(':id', $id, PDO::PARAM_INT);
	$sql->execute();
	
	
	if($type === 'pages'){
		$sql = $db->prepare('DELETE FROM content WHERE page_id = :id'); 
		$sql->bindValue(':id', $id, PDO::PARAM_INT);
		$sql->execute();
	}	
	
	//log for deleting

	$log_data = array(
	':log_name' => $name,
	':log_content' => $type . ' - ' . $id,
	':date' => $date_time
	);
	$log = $db->prepare("INSERT INTO `log` (log_name, log_action, log_content, log_time) VALUES (:log_name, 'deleted' , :log_content, :date)");
	$log->execute($log_data);	
	
}
?>