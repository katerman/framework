<h1> Lets add a page!</h1>

		<? 								
					    

			$addToken = $security->generateFormToken('add_page_token'); 
			
		?>
		<form id="add_form" class="form" action="" method="" accept-charset="utf-8">
				
			<label for="page_name">Page Name</label><br/>
            <input id="page_name" name="page_name" value="" placeholder="Page Name" class="required"><br/>
			
			<label for="page_url">Page Url</label><br/>
            <input id="page_url" name="page_url" value="" placeholder="Page url"><br/>
			
			
			<label for="page_meta_title">Page Meta Title</label><br/>
            <input id="page_meta_title" name="page_meta_title" value="" placeholder="Page Meta Title"><br/>

			<label for="page_meta_keyword">Page Meta Keywords</label><br/>
            <input id="page_meta_keyword" name="page_meta_keyword" value="" placeholder="Page Meta Keywords"><br/>

			
			<label for="page_template">Page Template</label><br/>
            <input id="page_template" name="page_template" value="" placeholder="Page Template"><br/>
			
			<label for="page_group">Page Group</label><br/>
            <input id="page_group" name="page_group" value="" placeholder="Page Group"><br/>
			
			<label for="sub_page">Sub Pages</label><br/>
            <input id="sub_page" name="sub_page" value="" placeholder="Sub Pages"><br/>

			<label for="page_order">Page Order</label><br/>
            <input id="page_order" name="page_order" value="" placeholder="Page Order"><br/>

			<input type="hidden" id="token" name="token" value="<?php echo $addToken; ?>">
			<input type="hidden" id="update_type" name="update_type" value="pages">
		
			<input type="submit" value="Submit" class="btn">
			<p class="feedback_text hidden"></p>
		</form>
		
		

		