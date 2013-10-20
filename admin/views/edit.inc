<?  

$tpl = $helpers->getQuery('tpl','return');
$type = $helpers->getQuery('type','return');


if($tpl && $type){
	include($tpl.'/'.$type.'.inc'); //should return something like edit/edit_page.inc
}else{
	header('location: index.php?tpl=default_view');
}

?>


		