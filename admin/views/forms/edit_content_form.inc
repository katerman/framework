

<form id="edit_content_form" class="form edit_content_form" action="" method="" accept-charset="utf-8"><h1>Edit Content</h1><img class="form_close" src="img/close.png" alt="close"> 

	<p> Press Escape, or Click the x to close.</p>
	
	<input type="hidden" id="content_id" name="content_id" value=""><br/>
	
	<label for="content_name">Content Name</label><br/> 
	<input id="content_name" name="content_name" value="" placeholder="Content Name" class="required"><br/>
	
	<label for="content">Content</label><br/> 
	<textarea cols="50" rows="10" id="content" name="content" placeholder="Content goes here!"></textarea><br/>
	
	<div class="editcontent_form_float">
		<label for="content_area">Area</label><br/> 
		<input id="content_area" name="content_area" value="" placeholder="Area">
	</div>
	
	<div class="editcontent_form_float">
		<label for="content_order">Order</label><br/> 
		<input id="content_order" name="content_order" value="" placeholder="Order">
	</div>
	
	<input type="hidden" id="content_token" name="token" value="">
	<input type="hidden" id="update_type" name="update_type" value="content">
	<input type="submit" value="Submit" class="btn clear-fix pull-left">
	
	<p class="feedback_content hidden clear-fix pull-left"></p>
</form>