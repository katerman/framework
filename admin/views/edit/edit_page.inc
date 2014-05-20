<?php
	if($perms['pages'] == 1){
	
		//pager
		$amt = $helpers->getQuery('amt','return');
		include_once "scripts/pager.class.php"; //include this class where needed
	
		$page = $helpers->getQuery('pageid','return');
		$z = $helpers->sqlSelect("*" , "pages", "", "WHERE pages_id = $page" );
		$r = $helpers->sqlSelect("*" , "templates", "", "");
		$sub_p = $helpers->sqlSelect("*" , "pages", "", "WHERE sub_page = $page");
		$pp = $helpers->sqlSelect("*" , "pages", "", "WHERE on_nav = '1'");
	
		echo '<h1> Edit '.$helpers->custom_clean($z[0]['page_name']).'</h1>';
			echo '<table class="table">
				<thead>
					<tr>
						<td class="hidden">Pages ID</td>
						<td>Page Name</td>
						<td>On Nav</td>
						<td>Page Template</td>
						<td>Page Group</td>
						<td>Sub Page</td>
						<td>Page Meta Keyword</td>
						<td>Page Meta Description</td>
						<td>Page Url</td>
						<td>Page Order</td>
					</tr>
				</thead>
				<tbody>
			';		
						  
		foreach($z as $value) {
			echo '<tr>'.
					'<td class="hidden">'.$value['pages_id'].'</td>'
					.'<td>'.$value['page_name'].'</td>'
					.'<td>'.$value['on_nav'].'</td>'
					.'<td class="page_template">'.$value['page_template'].'</td>'
					.'<td>'.$value['page_group'].'</td>'
					.'<td class="sub_page">'.$value['sub_page'].'</td>'
					.'<td>'.$value['page_meta_keyword'].'</td>'
					.'<td>'.$value['page_meta_title'].'</td>'
					.'<td>'.$value['page_url'].'</td>'
					.'<td>'.$value['page_order'].'</td>'
				 .'</tr>';
		}				
		echo '</tbody></table>';		
			    
	
	$token = $security->generateFormToken('token'); 
				
				
	$pages_id = $helpers->custom_clean($z[0]['pages_id']);
	$page_name = $helpers->custom_clean($z[0]['page_name']);
	$page_url = $helpers->custom_clean($z[0]['page_url']);
	$meta_title = $helpers->custom_clean($z[0]['page_meta_title']);
	$meta_keyword = $helpers->custom_clean($z[0]['page_meta_keyword']);
	$page_template = $helpers->custom_clean($z[0]['page_template']);
	$page_group = $helpers->custom_clean($z[0]['page_group']);
	$sub_page = $helpers->custom_clean($z[0]['sub_page']);
	$page_order = $helpers->custom_clean($z[0]['page_order']);
	$on_nav = $helpers->custom_clean($z[0]['on_nav']);
	
	$on_nav_val;
	if($on_nav === '1'){
		$on_nav_val = '1';
	}else{
		$on_nav_val = '0';
	}
	
	?>
	<form id="edit_form" class="form" action="" method="" accept-charset="utf-8">
	
	<input type="hidden" id="pages_id" name="pages_id" value="<?php echo $pages_id; ?>" placeholder="Pages Id"><br/>
	
	<div class="pull-left">
		<h2>Page Information</h2><br/>
		<label for="page_name">Page Name</label><br/>
	    <input id="page_name" name="page_name" value="<?php echo $page_name; ?>" placeholder="Page Name" class="required"><br/>
		
		<label for="page_url">Page Url</label><br/>
	    <input id="page_url" name="page_url" value="<?php echo $page_url; ?>" placeholder="Page url"><br/>
	
			
		<label for="page_template">Page Template</label><br/>
		<select id="page_template" name="page_template" style="margin-bottom: 10px; width: 150px;">
			<option value="none">None</option>
		<?php 
			foreach($r as $temp){
				if($page_template === $temp['id']){
					echo '<option value="'.$temp['id'].'" selected>'.$temp['template_name'].'</option>';
				}else{
					echo '<option value="'.$temp['id'].'">'.$temp['template_name'].'</option>';
				}
			}
			
		?>
		</select><br/>
		
		<label for="parent_page">Parent Page</label><br/>
		<select id="parent_page" name="parent_page" style="margin-bottom: 10px; width: 150px;">
			<option value="none">None</option>
		<?php 
			foreach($pp as $p){
				if($sub_page === $p['pages_id']){
					echo '<option value="'.$p['pages_id'].'" selected>'.$p['page_name'].'</option>';
				}else{
					echo '<option value="'.$p['pages_id'].'">'.$p['page_name'].'</option>';
				}
			}
			
		?>
		</select><br/>
		
		<label for="page_group">Page Group</label><br/>
	    <input id="page_group" name="page_group" value="<?php echo $page_group; ?>" placeholder="Page Group"><br/>
	
		<label for="page_order">Page Order</label><br/>
	    <input id="page_order" name="page_order" value="<?php echo $page_order; ?>" placeholder="Page Order"><br/>
	
		<label for="on_nav">Appear on navigation:</label>           
	    <input id="on_nav" type="checkbox" name="on_nav" value="1" <?php if($on_nav_val === '1'){ echo 'checked';} ?>/>
	</div>
	
	<div class="pull-left seo_column">
	
		<h2>SEO</h2><br/>
		<label for="page_meta_title">Page Meta Description</label><br/>
	    <textarea id="page_meta_title" name="page_meta_title" placeholder="Page Meta Title"><?php echo $meta_title; ?></textarea><br/>
	
		<label for="page_meta_keyword">Page Meta Keywords <span style="font-size: 10px">Seperate each keyword by a comma</span></label><br/>
	    <textarea id="page_meta_keyword" name="page_meta_keyword" placeholder="Page Meta Keywords"><?php echo $meta_keyword; ?></textarea><br/>
	</div>
	
	<input type="hidden" id="token" name="token" value="<?php echo $token; ?>">
	<input type="hidden" id="update_type" name="update_type" value="pages">
	
	<input type="submit" value="Submit" class="btn clear-fix pull-left">
	<p class="feedback_text hidden clear-fix pull-left"></p>
	</form>
	
	
	<?php
	//$c = $helpers->sqlSelect("*" , "content", "", "WHERE page_id = $page ORDER BY content_order ASC" );
	$pager = new pager($amt, 'content', '*');  
	$pager->setTableSqlDataWhere("WHERE page_id = $page ORDER BY content_order ASC");
	
	echo '<h2 style="padding-top: 20px;" class="clear-fix">Content for '.$page_name.'</h2> 
		  <table style="padding-top: 20px;" class="clear-fix search_table table">
			<thead>
				<tr>
					<td class="vis-hidden"></td>
					<td><input class="search" placeholder="Type to Filter"/></td>
				</tr>					
				<tr class="th">
					<td>Content Name</td>
					<td class="hidden">Content ID</td>
					<td class="hidden">Page ID</td>
					<td class="hidden">Content</td>
					<td>Content Area</td>
					<td>Order</td>
					<td>Actions</td>
				</tr>
			<thead>
			<tbody>
		';		
					  
	foreach($pager->getTableData() as $value) {
		echo '<tr class="content-table data">'.
				'<td class="content_name">'.$value['content_name'].'</td>'
				.'<td class="content_id hidden">'.$value['content_id'].'</td>'
				.'<td class="hidden">'.$value['page_id'].'</td>'
				.'<td class="content hidden">'.$value['content'].'</td>'
				.'<td class="content_area">'.$value['content_area'].'</td>'
				.'<td class="content_order">'.$value['content_order'].'</td>'
				.'<td id="content_token" class="hidden">'.$token.'</td>'
				.'<td><a class="edit edit_content" href="#pages"></a> ' . '<form style="position: relative;" class="pull-left" id="delete_form" action="" method=""> <a class="delete" href="#pages"></a> <input type="hidden" name="token" id="token" value="'.$token.'"> <input id="id" type="hidden" value="'.$value['content_id'].'"/> <input id="type" type="hidden" value="content"/> <input id="db_id" type="hidden" value="content_id"/> <input class="hidden" type="submit" id="submit"/> </form></td>'				
			 .'</tr>';
	}				
	echo '</tbody></table>';	
	echo '<p class="add_content">Add new content</p>';

	$pager->ShowPaging();
	?>
	<br><br>
	
	
	
	<h2 style="margin-top: 20px;">Sub-Pages</h2>
	<table class="table">
	<thead>
		<tr>
			<td class="vis-hidden"></td>
			<td><input class="search" placeholder="Type to Filter"/></td>
		</tr>
		<tr>
			<td>Page Name</td>
			<td>Page Url</td>
			<td>Page Order</td>
			<td>Actions</td>
		</tr>
	<thead>
	
	<tbody>
	<?php
		foreach($sub_p as $value) {
			echo '<tr class="data">'
					.'<td>'.$value['page_name'].'</td>'
					.'<td>'.$value['page_url'].'</td>'
					.'<td>'.$value['page_order'].'</td>'
					.'<td><a class="edit" href="?pageid='. $value['pages_id'] .'&tpl=edit&type=edit_page#pages"></a> ' . '<form style="position: relative;" class="pull-left" id="delete_form" action="" method=""> <a class="delete" href="?id='.$value['pages_id'].'#pages"></a> <input type="hidden" name="token" id="token" value="'. $token.'"> <input id="id" type="hidden" value="'. $value['pages_id'] .'"/> <input id="type" type="hidden" value="sub_page"/><input id="special" type="hidden" value="pages"/> <input id="db_id" type="hidden" value="pages_id"/> <input class="hidden" type="submit" id="submit"/> </form></td>'
				 .'</tr>';
		}				
	?>
			</tbody>
		</table>
		
			<a href="?tpl=add&type=add_page&parent_page=<?php echo $page ?>" class="add_page">Add new sub-page</a>
		
<?php
	}else{
		header('Location: ?tpl=default_view');
	}
?> 
		