<h1> Edit <?  $helpers->getQuery('pagename','echo'); ?></h1>

		<? 
				$page = $helpers->getQuery('pageid','return');
				$z = $model->sqlSelect("*" , "pages", "", "WHERE pages_id = $page" );
				$r = $model->sqlSelect("*" , "templates", "", "");
				$sub_p = $model->sqlSelect("*" , "pages", "", "WHERE sub_page = $page");
				$pp = $model->sqlSelect("*" , "pages", "", "WHERE on_nav = '1'");

		
				echo '<table>
						<tr class="th">
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
					';		
								  
				foreach($z as $value) {
					echo '<tr>'.
							'<td class="hidden">'.$value['pages_id'].'</td>'
							.'<td>'.$value['pages_name'].'</td>'
							.'<td>'.$value['on_nav'].'</td>'
							.'<td class="page_template">'.$value['page_template'].'</td>'
							.'<td>'.$value['page_group'].'</td>'
							.'<td class="sub_page">'.$value[sub_page].'</td>'
							.'<td>'.$value['page_meta_keyword'].'</td>'
							.'<td>'.$value['page_meta_title'].'</td>'
							.'<td>'.$value['pages_url'].'</td>'
							.'<td>'.$value['page_order'].'</td>'
						 .'</tr>';
				}				
				echo '</table>';		
					    

			$edit_token = $security->generateFormToken('edit_token'); 
						
						
			$pages_id = $helpers->stripcleantohtml($z[0]['pages_id']);
			$page_name = $helpers->stripcleantohtml($z[0]['pages_name']);
			$page_url = $helpers->stripcleantohtml($z[0]['pages_url']);
			$meta_title = $helpers->stripcleantohtml($z[0]['page_meta_title']);
			$meta_keyword = $helpers->stripcleantohtml($z[0]['page_meta_keyword']);
			$page_template = $helpers->stripcleantohtml($z[0]['page_template']);
			$page_group = $helpers->stripcleantohtml($z[0]['page_group']);
			$sub_page = $helpers->stripcleantohtml($z[0]['sub_page']);
			$page_order = $helpers->stripcleantohtml($z[0]['page_order']);
			$on_nav = $helpers->stripcleantohtml($z[0]['on_nav']);
			
			$on_nav_val;
			if($on_nav === '1'){
				$on_nav_val = '1';
			}else{
				$on_nav_val = '0';
			}
			
		?>
		<form id="edit_form" class="form" action="" method="" accept-charset="utf-8">
		
            <input type="hidden" id="pages_id" name="pages_id" value="<? echo $pages_id; ?>" placeholder="Pages Id"><br/>
		
			<div class="pull-left">
				<h2>Page Information</h2><br/>
				<label for="page_name">Page Name</label><br/>
	            <input id="page_name" name="page_name" value="<? echo $page_name; ?>" placeholder="Page Name" class="required"><br/>
				
				<label for="page_url">Page Url</label><br/>
	            <input id="page_url" name="page_url" value="<? echo $page_url; ?>" placeholder="Page url"><br/>
			</div>

			<div style="margin-left: 200px;" class="pull-left">
				<h2>SEO</h2><br/>
				<label for="page_meta_title">Page Meta Description</label><br/>
	            <input id="page_meta_title" name="page_meta_title" value="<? echo $meta_title; ?>" placeholder="Page Meta Title"><br/>
	
				<label for="page_meta_keyword">Page Meta Keywords <span style="font-size: 10px">Seperate each keyword by a comma</span></label><br/>
	            <input id="page_meta_keyword" name="page_meta_keyword" value="<? echo $meta_keyword; ?>" placeholder="Page Meta Keywords"><br/>
			</div>
			
			<div class="pull-left">
				<label for="page_template">Page Template</label><br/>
				<select id="page_template" name="page_template" style="margin-bottom: 10px; width: 150px;">
					<option value="none">None</option>
				<? 
					foreach($r as $temp){
						echo '<option value="'.$temp['id'].'">'.$temp['template_name'].'</option>';
					}
					
				?>
				</select><br/>
				
				<label for="parent_page">Parent Page</label><br/>
				<select id="parent_page" name="parent_page" style="margin-bottom: 10px; width: 150px;">
					<option value="none">None</option>
				<? 
					foreach($pp as $p){
						echo '<option value="'.$p['pages_id'].'">'.$p['pages_name'].'</option>';
					}
					
				?>
				</select><br/>
				
				<label for="page_group">Page Group</label><br/>
	            <input id="page_group" name="page_group" value="<? echo $page_group; ?>" placeholder="Page Group"><br/>
	
				<label for="page_order">Page Order</label><br/>
	            <input id="page_order" name="page_order" value="<? echo $page_order; ?>" placeholder="Page Order"><br/>
	
				<label for="on_nav">On Nav?</label>           
	            <input id="on_nav" type="checkbox" name="on_nav" value="1" <? if($on_nav_val === '1'){ echo 'checked';} ?>/>
			</div>
			
			<input type="hidden" id="token" name="token" value="<?php echo $edit_token; ?>">
			<input type="hidden" id="update_type" name="update_type" value="pages">

			<input type="submit" value="Submit" class="btn clear-fix pull-left">
			<p class="feedback_text hidden clear-fix pull-left"></p>
		</form>
		
		
		<?
			$c = $model->sqlSelect("*" , "content", "", "WHERE page_id = $page ORDER BY content_order ASC" );
			//print_r($c);
			echo '<h2 style="padding-top: 20px;" class="clear-fix">Content for '.$page_name.'</h2> 
				  <table style="padding-top: 20px;" class="clear-fix search_table">
					<tr class="th">
						<td>Content Name</td>
						<td class="hidden">Content ID</td>
						<td class="hidden">Page ID</td>
						<td class="hidden">Content</td>
						<td>Content Area</td>
						<td>Order</td>
						<td>Actions</td>
						<td>  <input class="search" placeholder="Type to search"/></td>
					</tr>
				';		
							  
			foreach($c as $value) {
				echo '<tr class="content-table data">'.
						'<td class="content_name">'.$value['content_name'].'</td>'
						.'<td class="content_id hidden">'.$value['content_id'].'</td>'
						.'<td class="hidden">'.$value['page_id'].'</td>'
						.'<td class="content hidden">'.$value['content'].'</td>'
						.'<td class="content_area">'.$value['content_area'].'</td>'
						.'<td class="content_order">'.$value['content_order'].'</td>'
						.'<td id="content_token" class="hidden">'.$edit_token.'</td>'
						.'<td><a class="edit edit_content" href="#pages"></a> ' . '<form style="position: relative;" class="pull-left" id="delete_form" action="" method=""> <a class="delete" href="#pages"></a> <input type="hidden" name="token" id="token" value="'.$edit_token.'"> <input id="id" type="hidden" value="'. $helpers->stripcleantohtml($value['content_id']) .'"/> <input id="type" type="hidden" value="content"/> <input id="db_id" type="hidden" value="'.$helpers->stripcleantohtml('content_id').'"/> <input class="hidden" type="submit" id="submit"/> </form></td>'				
					 .'</tr>';
			}				
			echo '</table>';	
		
		?>
		
			<p class="add_content">Add new content</p>
		
		
		
		<h2 style="margin-top: 20px;">Sub-Pages</h2>
		<table>
		
			<tr class="th">
				<td>Page Name</td>
				<td>Page Url</td>
				<td>Page Order</td>
				<td>Actions</td>
				<td>  <input class="search" placeholder="Type to search"/></td>
			</tr>
			<?
				foreach($sub_p as $value) {
					echo '<tr class="data">'
							.'<td>'.$value['pages_name'].'</td>'
							.'<td>'.$value['pages_url'].'</td>'
							.'<td>'.$value['page_order'].'</td>'
							.'<td><a class="edit" href="?pageid='. $value['pages_id'] .'&tpl=edit&type=edit_page#pages"></a> ' . '<form style="position: relative;" class="pull-left" id="delete_form" action="" method=""> <a class="delete" href="?id='.$value['pages_id'].'#pages"></a> <input type="hidden" name="token" id="token" value="'. $edit_token.'"> <input id="id" type="hidden" value="'. $value['pages_id'] .'"/> <input id="type" type="hidden" value="sub_page"/><input id="special" type="hidden" value="pages"/> <input id="db_id" type="hidden" value="'.$helpers->stripcleantohtml('pages_id').'"/> <input class="hidden" type="submit" id="submit"/> </form></td>'
						 .'</tr>';
				}				
			?>
		</table>
		
			<a href="?tpl=add&type=add_page&parent_page=<?= $page ?>#pages" class="add_page">Add new sub-page</a>
		

		