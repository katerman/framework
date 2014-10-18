<?php  

$tpl = $helpers->getQuery('tpl','return');
$type = $helpers->getQuery('type','return');


if($tpl && $type){
	global $view, $_CONFIG;
	
	$tpl = "$tpl/$type";
	$view->show($tpl); //should return something like edit/edit_page.inc

}else{
	$helpers->redirect('index.php?tpl=default_view');
}