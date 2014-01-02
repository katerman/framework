<h1> Lets add a page!</h1>

		<? 								
			$r = $model->sqlSelect("*" , "templates", "", "");
			$pp = $model->sqlSelect("*" , "pages", "", "WHERE on_nav = '1'");
		    

			$addToken = $security->generateFormToken('add_token'); 
			
		?>
		<form id="add_form" class="form" action="" method="" accept-charset="utf-8">
				
			<label for="page_name">Page Name</label><br/>
            <input id="page_name" name="page_name" value="" placeholder="Page Name" class="required"><br/>
			
			<label for="page_url">Page Url</label><br/>
            <input id="page_url" name="page_url" value="" placeholder="Page url"><br/>
			
			
			<label for="page_meta_title">Page Meta Description</label><br/>
            <input id="page_meta_title" name="page_meta_title" value="" placeholder="Page Meta Title"><br/>

			<label for="page_meta_keyword">Page Meta Keywords</label><br/>
            <input id="page_meta_keyword" name="page_meta_keyword" value="" placeholder="Page Meta Keywords"><br/>

			
			<label for="page_template">Page Template</label><br/>
			<select id="page_template" name="page_template" style="margin-bottom: 10px; width: 150px;">
				<option value="">None</option>
			<? 
				foreach($r as $temp){
					echo '<option value="'.$temp[id].'">'.$temp[template_name].'</option>';
				}
				
			?>
			</select><br/>			
			
			<label for="parent_page">Parent Page</label><br/>
			<select id="parent_page" name="parent_page" style="margin-bottom: 10px; width: 150px;">
				<option value="">None</option>
			<? 
				foreach($pp as $p){
					echo '<option value="'.$p[pages_id].'">'.$p[page_name].'</option>';
				}
				
			?>
			</select><br/>
			
			<label for="page_group">Page Group</label><br/>
            <input id="page_group" name="page_group" value="" placeholder="Page Group"><br/>

			<label for="page_order">Page Order</label><br/>
            <input id="page_order" name="page_order" value="" placeholder="Page Order"><br/>

			<label for="on_nav">On Nav?</label>           
            <input id="on_nav" type="checkbox" name="on_nav" value="0" /><br/>

			<input type="hidden" id="token" name="token" value="<?php echo $addToken; ?>">
			<input type="hidden" id="update_type" name="update_type" value="pages">
		
			<input type="submit" value="Submit" class="btn">
			<p class="feedback_text hidden"></p>
		</form>
		
		

		