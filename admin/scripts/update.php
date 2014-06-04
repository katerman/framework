<?
	session_start();
	
	if($_SESSION['userInfo']['access'] === '1'){

	}else{
		die();
	}
	
	include_once "../../includes/scripts/app.php";
	
	$security = new security();
	$helpers = new helpers($dsn, $db_user, $db_pass);
	$update_type = $_POST['update_type'];
	
	$name = $_SESSION['userInfo']['fullname'];
	$date_time = date( "F j, Y, g:i a");
	
	$security->checkToken('token');	 // check security token


	try{
		$db = new PDO($dsn, $db_user, $db_pass);		
	}catch (PDOException $e){
		var_dump($e);		
	}
		
	///print_r($_POST);
	
	if(isset($update_type)){
		if($update_type === 'pages'){
			$id = $helpers->custom_clean($_POST['pages_id']);
			$page_name = $helpers->custom_clean($_POST['page_name']);
			$page_meta_title = $helpers->custom_clean($_POST['page_meta_title']);
			$page_meta_keyword = $helpers->custom_clean($_POST['page_meta_keyword']);
 			$page_template = $helpers->custom_clean($_POST['page_template']);
			$page_group = $helpers->custom_clean($_POST['page_group']);
			$sub_page = $helpers->custom_clean($_POST['parent_page']);	
			$page_url = $helpers->custom_clean($_POST['page_url']);
			$page_order = $helpers->custom_clean($_POST['page_order']);		
			$on_nav = $helpers->custom_clean($_POST['on_nav']);		
		
		    try{
		        $query = "UPDATE pages SET page_name = ?, page_meta_title = ?, page_meta_keyword = ?, page_template = ?, page_group = ?, sub_page = ?, page_url = ?, page_order = ?, on_nav = ? WHERE pages_id = ?";
		        $q = $db->prepare($query);
		        $q->execute(array($page_name, $page_meta_title, $page_meta_keyword, $page_template, $page_group, $sub_page, $page_url, $page_order, $on_nav , $id));
				echo 'your bidding has been completed';
		    }catch(PDOException $e){
		        echo 'ERROR: ' . $e->getMessage();
		    }
		    
		    //log for updating page
			$log_data = array(
				':log_name' => $name,
				':log_content' => $page_name,
				':date' => $date_time
			);
			$log = $db->prepare("INSERT INTO `log` (log_name, log_action, log_content, log_time) VALUES (:log_name, 'update page' , :log_content, :date)");
			$log->execute($log_data);
		    		
		}
		
		
		
		if($update_type === 'user'){ //User
		
			$user_id = $helpers->custom_clean($_POST['user_id']);
			$user_username = $helpers->custom_clean($_POST['username']);
			$user_pass = $helpers->custom_clean($_POST['password']);
			$user_fullname = $helpers->custom_clean($_POST['fullname']);
			$user_access = $helpers->custom_clean($_POST['access']);
			$user_comments = $helpers->custom_clean($_POST['user_comments'], false, false);
			$perms_array =  array(
								"config" => $helpers->custom_clean($_POST['checkbox_config']),
								"pages" => $helpers->custom_clean($_POST['checkbox_pages']),
								"users" => $helpers->custom_clean($_POST['checkbox_users']),
								"assets" => array(
												"top_level"=>$helpers->custom_clean($_POST['checkbox_assets_tl']),
												"upload"=>$helpers->custom_clean($_POST['checkbox_assets_upload']),
												"uploaded"=>$helpers->custom_clean($_POST['checkbox_assets_uploaded']),
												"templates"=>$helpers->custom_clean($_POST['checkbox_assets_templates']),
												"labels"=>$helpers->custom_clean($_POST['checkbox_assets_labels'])
											)
							);
			
			$perms_array = serialize($perms_array);
			
			function random_numbers($digits){ 
			    $min = pow(10, $digits - 1);
			    $max = pow(10, $digits) - 1;
			    return mt_rand($min, $max);
			}
									
			if(strlen($user_pass) != 0){ // we have to split up to see if we're updating the password or not, if the password field is empty it wont pass any new password/salt data to the db
				$salt = random_numbers(8); //heres our new salt
				$pw = MD5($salt.$user_pass);
				
		        $query = "UPDATE users SET user_uName = ?, user_Pass = ?, user_FullName = ?, user_Access = ?, user_Salt = ?, user_Comments,  user_custom_perms = ? WHERE users_id = ?";
    			$data = array($user_username, $pw, $user_fullname, $user_access, $salt, $user_comments, $perms_array, $user_id);
			}else{
				$query = "UPDATE users SET user_uName = ?, user_FullName = ?, user_Access = ?, user_Comments = ?, user_custom_perms = ? WHERE users_id = ?";
    			$data = array($user_username, $user_fullname, $user_access, $user_comments, $perms_array, $user_id);
			}
			

		    try{
				$q = $db->prepare($query);
		        $q->execute($data);
				echo 'your bidding has been completed';
		    }catch(PDOException $e){
		        echo 'ERROR: ' . $e->getMessage();
		    }	
		    
		    //log for updating user
			$log_data = array(
				':log_name' => $name,
				':log_content' => $user_username,
				':date' => $date_time
			);
			$log = $db->prepare("INSERT INTO `log` (log_name, log_action, log_content, log_time) VALUES (:log_name, 'update page' , :log_content, :date)");
			$log->execute($log_data);
			
		}
		
		if($update_type === 'config'){
			$id = $helpers->custom_clean($_POST['config_id']);
			$site_name = $helpers->custom_clean($_POST['site_name']);
			$global_logo = $helpers->custom_clean($_POST['global_logo']);
			$extra_js = $helpers->custom_clean($_POST['extra_js'], false);
 			$extra_css = $helpers->custom_clean($_POST['extra_css'], true, false);

			$ds          = DIRECTORY_SEPARATOR;  			 
			$storeFolder = 'uploads'; 
			$dirname = '..'.$ds.$storeFolder.$ds;
			
		
		    try{
		        $query = "UPDATE config SET site_name = ?, global_logo = ?, extra_js = ?, extra_css = ? WHERE id = ?";
		        $q = $db->prepare($query);
		        $q->execute(array($site_name,$global_logo, $extra_js, $extra_css, $id));
				echo 'your bidding has been completed';
		    }catch(PDOException $e){
		        echo 'ERROR: ' . $e->getMessage();
		    }
		    
		    //log for updating config
			$log_data = array(
				':log_name' => $name,
				':log_content' => 'config',
				':date' => $date_time
			);
			$log = $db->prepare("INSERT INTO `log` (log_name, log_action, log_content, log_time) VALUES (:log_name, 'update config' , :log_content, :date)");
			$log->execute($log_data);
		}
		
		if($update_type === 'content'){	
		
			$content_id = $helpers->custom_clean($_POST['content_id']);
			$content = $helpers->custom_clean(htmlspecialchars_decode(stripslashes($_POST['content']), ENT_QUOTES), true, false, false);
			$content_area = $helpers->custom_clean($_POST['content_area']);
			$content_name = $helpers->custom_clean($_POST['content_name']);
			$content_order = $helpers->custom_clean($_POST['content_order']);

			
		
		    try{
		        $query = "UPDATE content SET content = ?, content_area = ?, content_name = ?, content_order = ? WHERE content_id = ?";
		        $q = $db->prepare($query);
		        $q->execute(array($content, $content_area, $content_name,$content_order, $content_id));
				echo 'your bidding has been completed';
		    }catch(PDOException $e){
		        echo 'ERROR: ' . $e->getMessage();
		    }	
		    
		    //log for updating content
			$log_data = array(
				':log_name' => $name,
				':log_content' => $content_name,
				':date' => $date_time
			);
			$log = $db->prepare("INSERT INTO `log` (log_name, log_action, log_content, log_time) VALUES (:log_name, 'update content' , :log_content, :date)");
			$log->execute($log_data);
		}
		
		if($update_type === 'template'){
			$template_name = $helpers->custom_clean($_POST['template_name']);
			$template_type = $helpers->custom_clean($_POST['template_type']);
			$id = $_POST['id'];
		
		    try{
		        $query = "UPDATE templates SET template_name = ?, template_type = ? WHERE id = ?";
		        $q = $db->prepare($query);
		        $q->execute(array($template_name, $template_type, $id));
				echo 'your bidding has been completed';
		    }catch(PDOException $e){
		        echo 'ERROR: ' . $e->getMessage();
		    }	
		    
		    //log for updating template
			$log_data = array(
				':log_name' => $name,
				':log_content' => $template_name,
				':date' => $date_time
			);
			$log = $db->prepare("INSERT INTO `log` (log_name, log_action, log_content, log_time) VALUES (:log_name, 'update template' , :log_content, :date)");
			$log->execute($log_data);		    
		    	
		}
		
		if($update_type === 'labels'){
			$label_name = $helpers->custom_clean($_POST['label_name']);
			$label_content = $helpers->custom_clean($_POST['label_content'], true, false, false);
			$id = $helpers->custom_clean($_POST['id']);

		    try{
		        $query = "UPDATE labels SET label_name = ?, label_content = ? WHERE label_id = ?";
		        $q = $db->prepare($query);
		        $q->execute(array($label_name, $label_content, $id));
				echo 'your bidding has been completed';
		    }catch(PDOException $e){
		        echo 'ERROR: ' . $e->getMessage();
		    }	
		    
		    //log for updating labels
			$log_data = array(
				':log_name' => $name,
				':log_content' => $label_name,
				':date' => $date_time
			);
			$log = $db->prepare("INSERT INTO `log` (log_name, log_action, log_content, log_time) VALUES (:log_name, 'update labels' , :log_content, :date)");
			$log->execute($log_data);		    
		    	
		}
				
	}else{
		die();
	}
	
	
?>

