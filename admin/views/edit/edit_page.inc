<h1> this is the edit page for <? $helpers->getQuery('pagename','echo'); ?> page</h1>

		<? 
				$page = $helpers->getQuery('pageid','return');
				$z = $model->sqlSelect("*" , "pages", "", "WHERE pages_id = $page" );
						
				echo '<table>
						<tr class="th">
							<td>Pages ID</td>
							<td>Page Name</td>
							<td>Page Template</td>
							<td>Page Group</td>
							<td>Sub Page</td>
							<td>Page Meta Keyword</td>
							<td>Page Meta Title</td>
							<td>Page Url</td>
							<td>Page Order</td>
						</tr>
					';		
								  
				foreach($z as $value) {
					echo '<tr>'.
							'<td>'.$value[pages_id].'</td>'
							.'<td>'.$value[page_name].'</td>'
							.'<td>'.$value[page_template].'</td>'
							.'<td>'.$value[page_group].'</td>'
							.'<td>'.$value[sub_page].'</td>'
							.'<td>'.$value[page_meta_keyword].'</td>'
							.'<td>'.$value[page_meta_title].'</td>'
							.'<td>'.$value[page_url].'</td>'
							.'<td>'.$value[page_order].'</td>'
						 .'</tr>';
				}				
				echo '</table>';		
					    

			$newToken = $security->generateFormToken('edit_page_token'); 
			
			$pages_id = $helpers->stripcleantohtml($z[0][pages_id]);
			$page_name = $helpers->stripcleantohtml($z[0][page_name]);
			$page_url = $helpers->stripcleantohtml($z[0][page_url]);
			$meta_title = $helpers->stripcleantohtml($z[0][page_meta_title]);
			$meta_keyword = $helpers->stripcleantohtml($z[0][page_meta_keyword]);
			$page_template = $helpers->stripcleantohtml($z[0][page_template]);
			$page_group = $helpers->stripcleantohtml($z[0][page_group]);
			$sub_page = $helpers->stripcleantohtml($z[0][sub_page]);
			$page_order = $helpers->stripcleantohtml($z[0][page_order]);
		?>
		<form id="edit_page_form" class="form" action="" method="" accept-charset="utf-8">
		
            <input type="hidden" id="pages_id" name="pages_id" value="<? echo $pages_id; ?>" placeholder="Pages Id"><br/>
		
			<label for="page_name">Page Name</label><br/>
            <input id="page_name" name="page_name" value="<? echo $page_name; ?>" placeholder="Page Name" class="required"><br/>
			
			<label for="page_url">Page Url</label><br/>
            <input id="page_url" name="page_url" value="<? echo $page_url; ?>" placeholder="Page url"><br/>
			
			
			<label for="page_meta_title">Page Meta Title</label><br/>
            <input id="page_meta_title" name="page_meta_title" value="<? echo $meta_title; ?>" placeholder="Page Meta Title"><br/>

			<label for="page_meta_keyword">Page Meta Keywords</label><br/>
            <input id="page_meta_keyword" name="page_meta_keyword" value="<? echo $meta_keyword; ?>" placeholder="Page Meta Keywords"><br/>

			
			<label for="page_template">Page Template</label><br/>
            <input id="page_template" name="page_template" value="<? echo $page_template; //need to add template db to handle this ?>" placeholder="Page Template"><br/>
			
			<label for="page_group">Page Group</label><br/>
            <input id="page_group" name="page_group" value="<? echo $page_group; ?>" placeholder="Page Group"><br/>
			
			<label for="sub_page">Sub Pages</label><br/>
            <input id="sub_page" name="sub_page" value="<? echo $sub_page; //need to add subpage db to handle this ?>" placeholder="Sub Pages"><br/>

			<label for="page_order">Page Order</label><br/>
            <input id="page_order" name="page_order" value="<? echo $page_order; ?>" placeholder="Page Order"><br/>

			<input type="hidden" id="token" name="token" value="<?php echo $newToken; ?>">
		
			<input id="pages" type="submit" value="Submit" class="btn">
			<p class="feedback_text hidden"></p>
		</form>
		
		

		