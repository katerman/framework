<?
	session_start();
	
	if($_SESSION['userInfo']['access'] === '1'){

	}else{
		die();
	}
	
	include_once "../db.php";
	include_once "../includes/security.php";
	$security = new security();

	
	$token = $_POST['token'];
	$security->checkToken('edit_page_token');	

	try{
		$db = new PDO($dsn, $db_user, $db_pass);		
	}catch (PDOException $e){
		var_dump($e);		
	}
	
	$update_type = $_POST['update_type'];
	
	if(isset($update_type)){
		if($update_type === 'pages'){
			$id = $_POST['pages_id'];
			$page_name = $_POST['page_name'];
			$page_meta_title = $_POST['page_meta_title'];
			$page_meta_keyword = $_POST['page_meta_keyword'];
 			$page_template = $_POST['page_template'];
			$page_group = $_POST['page_group'];
			$sub_page = $_POST['sub_page'];	
			$page_url = $_POST['page_url'];
			$page_order = $_POST['page_order'];		
		
		    try{
		        $query = "UPDATE pages SET page_name = ?, page_meta_title = ?, page_meta_keyword = ?, page_template = ?, page_group = ?, sub_page = ?, page_url = ?, page_order = ? WHERE pages_id = ?";
		        $q = $db->prepare($query);
		        $q->execute(array($page_name, $page_meta_title, $page_meta_keyword, $page_template, $page_group, $sub_page, $page_url, $page_order, $id));
				echo 'your bidding has been completed';
		    }catch(PDOException $e){
		        echo 'ERROR: ' . $e->getMessage();
		    }		
		}
	}else{
		die;
	}
	
	
?>

