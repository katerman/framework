<?php
session_start();

include_once "../../includes/scripts/app.php";

$security = new security();
$helpers = new helpers($dsn, $db_user, $db_pass);
$update_type = $_POST['update_type'];

$user = new user();
$name = $user->get_Fullname();

$date_time = date( "F j, Y, g:i a");

$security->checkToken('token');  // check security token

error_log(print_r($_POST), true);

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

		$values = array(
			'page_name' => $page_name,
			'page_url' => $page_url,
			'page_meta_title' => $page_meta_title,
			'page_meta_keyword' => $page_meta_keyword,
			'page_template' => $page_template,
			'page_group' => $page_group,
			'sub_page' => $sub_page,
			'page_order' => $page_order,
			'on_nav' => $on_nav
		);

		$helpers->sqlUpdate('pages', $values, "pages_id = $id");


		//log for updating page
		$helpers->sqlLog($page_name, 'Update Page');

	}



	if($update_type === 'user'){ //User
		error_log(print_r($_POST,true));
		$user_id = $helpers->custom_clean($_POST['user_id']);
		$username = $helpers->custom_clean($_POST['username']);
		$user_pass = $helpers->custom_clean($_POST['password']);
		$fullname = $helpers->custom_clean($_POST['fullname']);
		$access = $helpers->custom_clean($_POST['access']);
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
				"labels"=>$helpers->custom_clean($_POST['checkbox_assets_labels']),
				"scattershot"=>$helpers->custom_clean($_POST['checkbox_assets_scattershot'])
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
			$pw = md5($salt.$user_pass);
	
			$values = array(
				'user_uName' => $username,
				'user_FullName' => $fullname,
				'user_Access' => $access,
				'user_Salt' => $salt,
				'user_Pass' => $pw,
				'user_custom_perms' => $perms_array,
				'user_Comments' => $user_comments
			);
	
			$helpers->sqlUpdate('users', $values, "users_id = $user_id");
	
	
		}else{
			$values = array(
				'user_uName' => $username,
				'user_FullName' => $fullname,
				'user_Access' => $access,
				'user_custom_perms' => $perms_array,
				'user_Comments' => $user_comments
			);
	
			$helpers->sqlUpdate('users', $values, "users_id = $user_id");
		}

		//log for updating user
		$helpers->sqlLog($username . ' - ' . $fullname, 'Update User');

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
		
		$values = array(
			'site_name' => $site_name,
			'global_logo' => $global_logo,
			'extra_js' => $extra_js,
			'extra_css' => $extra_css
		);

		$helpers->sqlUpdate('config', $values, "id = $id");
		

		//log for updating config
		$helpers->sqlLog('config', 'Update Config');
	}

	if($update_type === 'content'){

		$content_id = $helpers->custom_clean($_POST['content_id']);
		$content = $helpers->custom_clean(htmlspecialchars_decode(stripslashes($_POST['content']), ENT_QUOTES), true, false, false);
		$content_area = $helpers->custom_clean($_POST['content_area']);
		$content_name = $helpers->custom_clean($_POST['content_name']);
		$content_order = $helpers->custom_clean($_POST['content_order']);

		$values = array(
			'content' => $content,
			'content_area' => $content_area,
			'content_name' => $content_name,
			'content_order' => $content_order
		);

		$helpers->sqlUpdate('content', $values, "content_id = $content_id");

		//log for updating content
		$helpers->sqlLog($content_name, 'Update Content');
	}

	if($update_type === 'template'){
		$template_name = $helpers->custom_clean($_POST['template_name']);
		$template_type = $helpers->custom_clean($_POST['template_type']);
		$id = $_POST['id'];

		$values = array(
			'template_name' => $template_name,
			'template_type' => $template_type
		);

		$helpers->sqlUpdate('templates', $values, "id = $id");


		//log for updating template
		$helpers->sqlLog($template_name, 'Update Templates');

	}

	if($update_type === 'labels'){
		$label_name = $helpers->custom_clean($_POST['label_name']);
		$label_content = $helpers->custom_clean($_POST['label_content'], true, false, false);
		$id = $helpers->custom_clean($_POST['id']);

		$values = array(
			'label_name' => $label_name,
			'label_content' => $label_content
		);

		$helpers->sqlUpdate('labels', $values, "label_id = $id");

		//log for updating labels
		$helpers->sqlLog($label_name, 'Update Labels');

	}

	if($update_type === 'scattershot'){
	
		// $id is unique id (scattershot_id), $scattershot_id is keyword shortcut for any html id (id="whatever")
		$id = $helpers->custom_clean($_POST['id']);
		$scattershot_name = $helpers->custom_clean($_POST['scattershot_name']);
		$scattershot_value = $helpers->custom_clean($_POST['scattershot_value'], true, false, false);//Html/Css yes
		$scattershot_type = $helpers->custom_clean($_POST['scattershot_type']);
		$scattershot_anchor = $helpers->custom_clean($_POST['scattershot_anchor']);
		$scattershot_class = $helpers->custom_clean($_POST['scattershot_class']);
		$scattershot_id = $helpers->custom_clean($_POST['scattershot_id']);

		$values = array(
			'name' => $scattershot_name,
			'value' => $scattershot_value,
			'type' => $scattershot_type,
			'anchor' => $scattershot_anchor,
			'class' => $scattershot_class,
			'id' => $scattershot_id
		);

		$helpers->sqlUpdate('scattershot', $values, "scattershot_id = $id");


		//log for adding Scattershot
		$helpers->sqlLog($scattershot_name, 'Update Scattershot');
		
	}	

}else{
	die();
}


?>
