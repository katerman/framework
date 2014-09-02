<div id="search_page">
<?php
	if($perms['pages'] == 1){

	$query = $_GET['search'];
	if(isset($query)){
		require_once 'scripts/search.php';
		echo '<h1>Searching for '.$query.'</h1>';
	}
	
	$user_perm = $perms['users'];
	$label_perm = $perms['assets']['labels'];
	$templates_perm = $perms['assets']['templates'];
	$page_perm = $perms['pages'];
	$filter = $_GET['filter'];
	
	
	$html_select = '<div class="full search_field"><input class="search_query" placeholder="Search" type="text"><select class="change_filter">';
		 	
	if($label_perm && $user_perm && $templates_perm && $page_perm){//all
		$selected = $filter == 'all' ? 'selected' : '';
		$html_select .= '<option value="all" '. $selected .'>All</option>';	
	}
	if($user_perm){
		$selected = $filter == 'users' ? 'selected' : '';
		$html_select .= '<option value="users" '.$selected.'>Users</option>';
	}
	if($label_perm){
		$selected = $filter == 'labels' ? 'selected' : '';
		$html_select .= '<option value="labels"'.$selected.'>Labels</option>';
	}	
	if($templates_perm){
		$selected = $filter == 'templates' ? 'selected' : '';	
		$html_select .= '<option value="templates" '.$selected.'>Templates</option>';
	}	
	if($page_perm){
		$selected = $filter == 'pages' ? 'selected' : '';	
		$html_select .= '<option value="pages" '.$selected.'>Pages</option>';
	}
	if($page_perm){
		$selected = $filter == 'content' ? 'selected' : '';		
		$html_select .= '<option value="content" '.$selected.'>Content</option>';
	}		
	$html_select .= '</select><button class="search_submit"></div>';
	echo $html_select;
	
	
	if(isset($content) && $filter == 'users' || $filter == 'all' && $user_perm){
		echo '<h2>Users</h2>';
		
		$users_table = new Table();
		$user_heads = array('Username'=>'user_uName', 'User Fullname' => 'user_FullName', 'User Comments' => 'user_Comments');
	
		$users_table->set_TableHead($user_heads);
		$users_table->set_TableRows($users->getTableData());
		$users_table->set_TableClass('table search_table');
		$users_table->set_TableStrLen(50);
		$users_table->set_TableActions(array('view' => array('query' => '?&tpl=edit&type=edit_user&userid=', 'id' => 'users_Id'), 
											   'delete' => array('id' => 'users_Id', 'table_name' => 'users'))
										);
		//$users_table->set_ToolTip(true);								
		$users_table->set_Token($token);
		$users_table->make_Table();
		
		$users->ShowPaging();

		
	}		
	
	if(isset($labels) && $filter == 'labels' || $filter == 'all' && $label_perm){
		echo '<h2>Labels</h2>';

		$label_table = new Table();
		$label_head = array('Content'=>'label_content', 'Name' => 'label_name');
	
		$label_table->set_TableHead($label_head);
		$label_table->set_TableRows($labels->getTableData());
		$label_table->set_TableClass('table search_table');
		$label_table->set_TableActions(array('link' => array('query' => '?tpl=labels')));
		
		$label_table->set_TableStrLen(50);
		//$users_table->set_ToolTip(true);								
		$label_table->make_Table();
		
		$labels->ShowPaging();
	}
	
	if(isset($templates) && $filter == 'templates' || $filter == 'all' && $templates_perm){
		echo '<h2>Templates</h2>';

		$template_table = new Table();
		$template_head = array('Name'=>'template_name', 'Type' => 'template_type');
	
		$template_table->set_TableHead($template_head);
		$template_table->set_TableRows($templates->getTableData());
		$template_table->set_TableClass('table search_table');
		$template_table->set_TableActions(array('link' => array('query' => '?tpl=templates')));
		
		$template_table->set_TableStrLen(50);
		//$template_table->set_ToolTip(true);								
		$template_table->make_Table();
		
		$templates->ShowPaging();		
		
	}	

	if(isset($pages) && $filter == 'pages' || $filter == 'all' && $page_perm){
		echo '<h2>Pages</h2>';
//WHERE page_name LIKE '%$query%' OR page_group LIKE '%$query%' OR page_template LIKE '%$query%' 
//OR page_meta_keyword LIKE '%$query%' OR page_meta_title LIKE '%$query%'
		$pages_table = new Table();
		$pages_head = array('Name'=>'page_name', 'Group' => 'page_group', 'Template'=>'page_template', 'Meta Keywords'=>'page_meta_keyword', 'Meta Title'=>'page_meta_title');
	
		$pages_table->set_TableHead($pages_head);
		$pages_table->set_TableRows($pages->getTableData());
		$pages_table->set_TableClass('table search_table');
		$pages_table->set_TableActions(array('view' => array('query' => '?tpl=edit&type=edit_page&pageid=', 'id'=>'pages_id')));
		
		$pages_table->set_TableStrLen(50);
		//$users_table->set_ToolTip(true);								
		$pages_table->make_Table();
		
		$pages->ShowPaging();

	}				
	
	if(isset($content) && $filter == 'content' || $filter == 'all' && $page_perm){
		echo '<h2>Content</h2>';
		
		$content_table = new Table();
		$content_heads = array('Content'=>'content', 'Content Area' => 'content_area', 'Content Name' => 'content_name');
	
		$content_table->set_TableHead($content_heads);
		$content_table->set_TableRows($content->getTableData());
		$content_table->set_TableClass('table search_table');
		$content_table->set_TableStrLen(50);
		$content_table->set_TableActions(array('view' => array('query' => '?tpl=edit&type=edit_page&amt=10&page=1&pageid=', 'id' => 'page_id'), //for viewing the content we want to send them to the page its on, so ive added the page query in there and the id is the sql column name, it will auto populate each rows page_id
											   'delete' => array('id' => 'content_id', 'table_name' => 'content')) //to delete a row we wont want to delete the contents page id, instead we'll want the content_id as id
										);
		//$content_table->set_ToolTip(true);								
		$content_table->set_Token($token);
		$content_table->make_Table();
		
		$content->ShowPaging();
		
	}				
	
	}else{
		header('Location: ?tpl=default_view');
	}
?> 
</div>
