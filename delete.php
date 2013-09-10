<?php
session_start();


require_once 'db.php';

if( isset($_GET['id']))
{
	$sql = $db->prepare('DELETE FROM stats WHERE playerId = :id');
	$sql->bindValue(':id', $_GET['id'], PDO::PARAM_INT);
	$sql->execute();
}

	header('Location: index.php');
	//exit;

?>
