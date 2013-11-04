<?
	session_start();
	
	include_once "../db.php";
	include_once "../includes/security.php";
	include_once "../includes/helpers.php";
	
	$security = new security();
	$helpers = new helpers();

	
	$token = $_POST['token'];
	$security->checkToken('add_page_token');	
		
	try{
		$db = new PDO($dsn, $db_user, $db_pass);		
	}catch (PDOException $e){
		var_dump($e);		
	}

	$update_type = $_POST['update_type'];
	
	print_r($_POST);
	
	if(isset($update_type)){
		if($update_type === 'pages'){ // ======== IF PAGES ========//
		
			$page_name = $_POST['page_name'];
			$page_meta_title = $_POST['page_meta_title'];
			$page_meta_keyword = $_POST['page_meta_keyword'];
			$page_template = $_POST['page_template'];
			$page_group = $_POST['page_group'];
			$sub_page = $_POST['sub_page'];	
			$page_url = $_POST['page_url'];
			$page_order = $_POST['page_order'];		
		
		    
			$data = array(':page_name' => $page_name, 
						  ':page_url' => $page_url, 
						  ':page_meta_title' => $page_meta_title, 
						  ':page_meta_keyword' => $page_meta_keyword, 
						  ':page_template' => $page_template, 
						  ':page_group' => $page_group, 
						  ':sub_page' => $sub_page, 
						  ':page_order' => $page_order
						 );
			
			$sql = $db->prepare("INSERT INTO `pages` (page_name, page_url, page_meta_title, page_meta_keyword, page_template, page_group, sub_page, page_order) VALUES (:page_name, :page_url, :page_meta_title, :page_meta_keyword, :page_template, :page_group, :sub_page, :page_order)");
								
			$sql->execute($data);
			
		}elseif($update_type==='user'){ // ======== IF USERS ========//
			
			$username = $_POST['user_uname'];		
			$fullname = $_POST['user_fullname'];		
			$access = $_POST['user_access'];		
			$password = $_POST['user_pass'];		
		
			$x = array($username, $fullname, $access, $password);
			
			print_r($x);
			
			function random_numbers($digits){ 
			    $min = pow(10, $digits - 1);
			    $max = pow(10, $digits) - 1;
			    return mt_rand($min, $max);
			}
			
			$salt = random_numbers(8); //heres our salt
			
			$data = array(':user_uName' => $username, 
					  ':user_FullName' => $fullname, 
					  ':user_Access' => $access, 
					  ':user_Salt' => $salt, 
					  ':user_Pass' => MD5($salt.$password), 
					 );
					
			
			$sql = $db->prepare("INSERT INTO `users` (user_uName, user_FullName, user_Access, user_Salt, user_Pass) VALUES (:user_uName, :user_FullName, :user_Access, :user_Salt, :user_Pass)");

            $sql->execute($data); 	
            
            print_r($sql);		
			
		}else{
			die;
		}
		
	}else{
	
		die;
	
	}
	
	
?>

