<?
	session_start();
	
	include_once "../db.php";
	include_once "../includes/security.php";
	include_once "../includes/helpers.php";
	
	$security = new security();
	$helpers = new helpers();

	print_r($_POST);
	
	$update_type = $_POST['update_type'];
	$update_crud = $_POST['update_crud'];
	
	if($update_type === 'content'){
		$security->checkToken('edit_token');	 // because our content adding is on the page edit page, we'll stick it with the edit token
	}elseif($update_type === 'template'){
		$security->checkToken('template_token');
	}elseif($update_type === 'labels'){
		$security->checkToken('label_token');
	}else{
		$security->checkToken('add_token');	
	}
		
	try{
		$db = new PDO($dsn, $db_user, $db_pass);		
	}catch (PDOException $e){
		var_dump($e);		
	}

				
	if(isset($update_type)){
		if($update_type === 'pages'){ // ======== IF PAGES ========//
		
			$page_name = $_POST['page_name'];
			$page_meta_title = $_POST['page_meta_title'];
			$page_meta_keyword = $_POST['page_meta_keyword'];
			$page_template = $_POST['page_template'];
			$page_group = $_POST['page_group'];
			$sub_page = $_POST['parent_page'];	
			$page_url = $_POST['page_url'];
			$page_order = $_POST['page_order'];		
			$on_nav = $_POST['on_nav'];		
		
		    
			$data = array(':page_name' => $page_name, 
						  ':page_url' => $page_url, 
						  ':page_meta_title' => $page_meta_title, 
						  ':page_meta_keyword' => $page_meta_keyword, 
						  ':page_template' => $page_template, 
						  ':page_group' => $page_group, 
						  ':sub_page' => $sub_page, 
						  ':page_order' => $page_order,
						  ':on_nav' => $on_nav
						 );
			
			$sql = $db->prepare("INSERT INTO `pages` (page_name, page_url, page_meta_title, page_meta_keyword, page_template, page_group, sub_page, page_order, on_nav) 
			                                  VALUES (:page_name, :page_url, :page_meta_title, :page_meta_keyword, :page_template, :page_group, :sub_page, :page_order, :on_nav)");
								
			$sql->execute($data);
			
		}elseif($update_type==='user'){ // ======== IF USERS ========//

			function random_numbers($digits){ 
			    $min = pow(10, $digits - 1);
			    $max = pow(10, $digits) - 1;
			    return mt_rand($min, $max);
			}
			
			$salt = random_numbers(8); //heres our salt
			$username = $_POST['username'];		
			$fullname = $_POST['fullname'];		
			$access = $_POST['access'];		
			$password = $_POST['password'];		
		
			$x = array($username, $fullname, $access, $password, $salt);
			
			print_r($x);
			
			
			$data = array(':user_uName' => $username, 
					  ':user_FullName' => $fullname, 
					  ':user_Access' => $access, 
					  ':user_Salt' => $salt, 
					  ':user_Pass' => MD5($salt.$password)
					 );
					
			
			$sql = $db->prepare("INSERT INTO `users` (user_uName, user_FullName, user_Access, user_Salt, user_Pass) VALUES (:user_uName, :user_FullName, :user_Access, :user_Salt, :user_Pass)");

            $sql->execute($data); 	
            
         //   print_r($sql);
        //    print_r($data);		
			
		}elseif($update_crud ==='add' && $update_type==='content'){ // ======== IF CONTENT ========//
			
			$content = $_POST['content'];
			$content_area = $_POST['content_area'];
			$content_name = $_POST['content_name'];
			$content_order = $_POST['content_order'];	
			$content_page = $_POST['content_order'];	
			$content_page_id = $_POST['content_page_id'];
			
			$data = array(':content' => $content, 
					  ':content_area' => $content_area, 
					  ':content_name' => $content_name, 
					  ':content_order' => $content_order,
					  ':page_id' => $content_page_id
					 );
					
			
			$sql = $db->prepare("INSERT INTO `content` (content, content_area, content_name, content_order, page_id) VALUES (:content, :content_area, :content_name, :content_order, :page_id)");

            $sql->execute($data); 	
            
         //   print_r($sql);
        //    print_r($data);		
			
		}elseif($update_crud ==='add' && $update_type==='template'){ // ======== IF Template ========//
			
			$template_type = $_POST['template_type'];
			$template_name = $_POST['template_name'];

			$data = array(':template_type' => $template_type, 
					      ':template_name' => $template_name
					 );
					
			
			$sql = $db->prepare("INSERT INTO `templates` (template_type, template_name) VALUES (:template_type, :template_name)");

            $sql->execute($data); 	
            
         //   print_r($sql);
        //    print_r($data);		
			
		}elseif($update_crud ==='add' && $update_type==='labels'){ // ======== IF labels ========//
			
			$label_name = $_POST['label_name'];
			$label_content = $_POST['label_content'];

			$data = array(':label_name' => $label_name, 
					  	  ':label_content' => $label_content
					 );
					
			
			$sql = $db->prepare("INSERT INTO `labels` (label_name, label_content) VALUES (:label_name, :label_content)");

            $sql->execute($data); 	
            
         //   print_r($sql);
        //    print_r($data);		
			
		}else{
			die;
		}
		
	}else{
	
		die;
	
	}
	
	
?>

?>

