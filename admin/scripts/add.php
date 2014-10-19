<?php
session_start();

include_once "../../includes/scripts/app.php";

$security = new security();
$helpers = new helpers();
$user = new user();

$name = $user->get_Fullname();
$date_time = date( "F j, Y, g:i a");

if(isset($_POST['update_crud'])){
	$update_crud = $_POST['update_crud'];
}else{
	$update_crud = false;
}

$update_type = $_POST['update_type'];

$security->checkToken('token');  // check security token

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

		$helpers->sqlAdd('pages', $values);

		//log for adding page
		$helpers->sqlLog($page_name, 'Added Page');


	}elseif($update_type==='user'){ // ======== IF USERS ========//

		function random_numbers($digits){
			$min = pow(10, $digits - 1);
			$max = pow(10, $digits) - 1;
			return mt_rand($min, $max);
		}

		$min_perms = $user->get_minPermissions();

		$salt = random_numbers(8); //heres our salt
		$username = $helpers->custom_clean($_POST['username']);
		$fullname = $helpers->custom_clean($_POST['fullname']);
		$access = $helpers->custom_clean($_POST['access']);
		$password = $helpers->custom_clean($_POST['password']);

		$x = array($username, $fullname, $access, $password, $salt);

		$values = array(
			'user_uName' => $username,
			'user_FullName' => $fullname,
			'user_Access' => $access,
			'user_Salt' => $salt,
			'user_Pass' => md5($salt.$password),
			'user_custom_perms' => $min_perms
		);

		$helpers->sqlAdd('users', $values);

		//log for adding user
		$helpers->sqlLog($username . ' - ' . $fullname, 'Added User');

	}elseif($update_crud ==='add' && $update_type==='content'){ // ======== IF CONTENT ========//

		$content = $helpers->custom_clean(htmlentities($_POST['content'], ENT_QUOTES), true, false, false);
		$content_area = $helpers->custom_clean($_POST['content_area']);
		$content_name = $helpers->custom_clean($_POST['content_name']);
		$content_order = $helpers->custom_clean($_POST['content_order']);
		$content_page = $helpers->custom_clean($_POST['content_order']);
		$content_page_id = $helpers->custom_clean($_POST['content_page_id']);

		$values = array(
			'content' => $content,
			'content_area' => $content_area,
			'content_name' => $content_name,
			'content_order' => $content_order,
			'page_id' => $content_page_id
		);

		$helpers->sqlAdd('content', $values);

		//log for adding content
		$helpers->sqlLog($content_name, 'Added Content');

	}elseif($update_crud ==='add' && $update_type==='template'){ // ======== IF Template ========//

		$template_type = $helpers->custom_clean($_POST['template_type']);
		$template_name = $helpers->custom_clean($_POST['template_name']);

		$values = array(
			'template_type' => $template_type,
			'template_name' => $template_name
		);

		$helpers->sqlAdd('templates', $values);

		//log for adding template
		$helpers->sqlLog($template_name, 'Added Template');

	}elseif($update_crud ==='add' && $update_type==='labels'){ // ======== IF labels ========//

		$label_name = $helpers->custom_clean($_POST['label_name']);
		$label_content = $helpers->custom_clean($_POST['label_content']);

		$values = array(
			'label_name' => $label_name,
			'label_content' => $label_content
		);

		$helpers->sqlAdd('labels', $values);


		//log for adding Label
		$helpers->sqlLog($label_name, 'Added Label');

	}elseif($update_crud ==='add' && $update_type==='scattershot'){ // ======== IF Scattershot ========//

		$scattershot_name = $helpers->custom_clean($_POST['scattershot_name']);
		$scattershot_value = $helpers->custom_clean($_POST['scattershot_value']);
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

		$helpers->sqlAdd('scattershot', $values);

		//log for adding Scattershot
		$helpers->sqlLog($scattershot_name, 'Added Scattershot');


	}else{
		die();
	}

}else{

	die();

}
