<?php
session_start();

include_once "../db.php";
include_once "../includes/security.php";
$security = new security();


$token = $_POST['token'];
$id = $_POST['id'];	
$type = $_POST['type'];
$db_id = $_POST['dbid'];

$security->checkToken('delete_page_token');

try{
	$db = new PDO($dsn, $db_user, $db_pass);		
}catch (PDOException $e){
	var_dump($e);		
}


if(isset($token))
{							//delete from pages WHERE pages_id = :id  /  :id bound to 0
	$sql = $db->prepare('DELETE FROM '.$type.' WHERE '. $db_id .' = :id'); 
	$sql->bindValue(':id', $id, PDO::PARAM_INT);
	$sql->execute();
}

?>