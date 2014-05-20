<?php
	session_start();
		
	include_once "../../includes/scripts/app.php";

	
	$security = new security();
	$helpers = new helpers($dsn, $db_user, $db_pass);
	$name = $_SESSION['userInfo']['fullname'];
	$date_time = date( "F j, Y, g:i a");

	//print_r($_POST);
	
	$update_type = $_POST['update_type'];
	
	
	if(isset($_POST['update_crud'])){
		$update_crud = $_POST['update_crud'];
	}else{
		$update_crud = false;
	}
	
	$security->checkToken('token');	 // check security token

		
	try{
		$db = new PDO($dsn, $db_user, $db_pass);		
	}catch (PDOException $e){
		var_dump($e);		
	}

				
	if(isset($update_type)){
		if($update_type === 'pages'){ // ======== IF PAGES ========//
		
			$page_name = $helpers->custom_clean($_POST['page_name']);
			$page_meta_title = $helpers->custom_clean($_POST['page_meta_title']);
			$page_meta_keyword = $helpers->custom_clean($_POST['page_meta_keyword']);
 			$page_template = $helpers->custom_clean($_POST['page_template']);
			$page_group = $helpers->custom_clean($_POST['page_group']);
			$sub_page = $helpers->custom_clean($_POST['parent_page']);	
			$page_url = $helpers->custom_clean($_POST['page_url']);
			$page_order = $helpers->custom_clean($_POST['page_order']);		
			$on_nav = $helpers->custom_clean($_POST['on_nav']);		
		
		    
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
			
			//log for adding page
			$log_data = array(
				':log_name' => $name,
				':page_name' => $page_name,
				':date' => $date_time
			);
			$log = $db->prepare("INSERT INTO `log` (log_name, log_action, log_content, log_time) VALUES (:log_name, 'add page' , :page_name, :date)");
			$log->execute($log_data);

			
		}elseif($update_type==='user'){ // ======== IF USERS ========//

			function random_numbers($digits){ 
			    $min = pow(10, $digits - 1);
			    $max = pow(10, $digits) - 1;
			    return mt_rand($min, $max);
			}
			
			$salt = random_numbers(8); //heres our salt
			$username = $helpers->custom_clean($_POST['username']);		
			$fullname = $helpers->custom_clean($_POST['fullname']);		
			$access = $helpers->custom_clean($_POST['access']);		
			$password = $helpers->custom_clean($_POST['password']);		
		
			$x = array($username, $fullname, $access, $password, $salt);
			
			//print_r($x);
			
			
			$data = array(':user_uName' => $username, 
					  ':user_FullName' => $fullname, 
					  ':user_Access' => $access, 
					  ':user_Salt' => $salt, 
					  ':user_Pass' => MD5($salt.$password)
					 );
					
			
			$sql = $db->prepare("INSERT INTO `users` (user_uName, user_FullName, user_Access, user_Salt, user_Pass) VALUES (:user_uName, :user_FullName, :user_Access, :user_Salt, :user_Pass)");

            $sql->execute($data); 	
            
            //log for adding user
			$log_data = array(
				':log_name' => $name,
				':user_name' => $username . ' - ' .$fullname,
				':date' => $date_time
			);
			$log = $db->prepare("INSERT INTO `log` (log_name, log_action, log_content, log_time) VALUES (:log_name, 'add user' , :user_name, :date)");
			$log->execute($log_data);	
			
		}elseif($update_crud ==='add' && $update_type==='content'){ // ======== IF CONTENT ========//
			
			$content = $helpers->custom_clean($_POST['content'], true, false, false);
			$content_area = $helpers->custom_clean($_POST['content_area']);
			$content_name = $helpers->custom_clean($_POST['content_name']);
			$content_order = $helpers->custom_clean($_POST['content_order']);	
			$content_page = $helpers->custom_clean($_POST['content_order']);	
			$content_page_id = $helpers->custom_clean($_POST['content_page_id']);
			
			$data = array(':content' => $content, 
					  ':content_area' => $content_area, 
					  ':content_name' => $content_name, 
					  ':content_order' => $content_order,
					  ':page_id' => $content_page_id
					 );
					
			
			$sql = $db->prepare("INSERT INTO `content` (content, content_area, content_name, content_order, page_id) VALUES (:content, :content_area, :content_name, :content_order, :page_id)");

            $sql->execute($data); 	
            
            //log for adding content
			$log_data = array(
				':log_name' => $name,
				':log_content' => $content_name,
				':date' => $date_time
			);
			$log = $db->prepare("INSERT INTO `log` (log_name, log_action, log_content, log_time) VALUES (:log_name, 'add content' , :log_content, :date)");
			$log->execute($log_data);		
			
		}elseif($update_crud ==='add' && $update_type==='template'){ // ======== IF Template ========//
			
			$template_type = $helpers->custom_clean($_POST['template_type']);
			$template_name = $helpers->custom_clean($_POST['template_name']);

			$data = array(':template_type' => $template_type, 
					      ':template_name' => $template_name
					 );
					
			
			$sql = $db->prepare("INSERT INTO `templates` (template_type, template_name) VALUES (:template_type, :template_name)");

            $sql->execute($data); 	
            
            //log for adding template
			$log_data = array(
				':log_name' => $name,
				':log_content' => $template_name,
				':date' => $date_time
			);
			$log = $db->prepare("INSERT INTO `log` (log_name, log_action, log_content, log_time) VALUES (:log_name, 'add template' , :log_content, :date)");
			$log->execute($log_data);	
			
		}elseif($update_crud ==='add' && $update_type==='labels'){ // ======== IF labels ========//
			
			$label_name = $helpers->custom_clean($_POST['label_name']);
			$label_content = $helpers->custom_clean($_POST['label_content']);

			$data = array(':label_name' => $label_name, 
					  	  ':label_content' => $label_content
					 );
					
			
			$sql = $db->prepare("INSERT INTO `labels` (label_name, label_content) VALUES (:label_name, :label_content)");

            $sql->execute($data); 	
            
            //log for adding template
			$log_data = array(
				':log_name' => $name,
				':log_content' => $label_name,
				':date' => $date_time
			);
			$log = $db->prepare("INSERT INTO `log` (log_name, log_action, log_content, log_time) VALUES (:log_name, 'add label' , :log_content, :date)");
			$log->execute($log_data);		
			
		}else{
			die();
		}
		
	}else{
	
		die();
	
	}
	
	

