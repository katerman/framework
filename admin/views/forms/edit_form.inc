<?
	global $_CONFIG, $helpers;
?>	

<form id="content_form" class="form" action="" method="" accept-charset="utf-8"><h1>Edit Content</h1><img class="form_close" src="<?php echo $_CONFIG->img_path; ?>admin/close.png" alt="close"> 

	<p> Press Escape, or Click the x to close.</p>
	
	<input type="hidden" id="content_id" name="content_id" value=""><br/>
	
	<label for="content_name">Content Name</label><br/> 
	<input id="content_name" name="content_name" value="" placeholder="Content Name" class="required"><br/>
	
	<label for="content">Content</label><br/> 
	<textarea id="content" class="html-code" name="content"></textarea><br/>
	
	<div class="pull-left">
		<label for="content_area">Area</label><br/> 
		<input id="content_area" name="content_area" value="" placeholder="Area">
	</div>
	
	<div class="pull-left">
		<label for="content_order">Order</label><br/> 
		<input id="content_order" name="content_order" value="" placeholder="Order">
	</div>
	
	<input type="hidden" id="content_token" name="token" value="">
	<input type="hidden" id="update_type" name="update_type" value="content">
	<input type="hidden" id="update_crud" name="update_crud" value="">
	<input type="hidden" id="content_page_id" name="content_page_id" value="<?php $helpers->getQuery('pageid','echo') ?> ">
	<input type="submit" value="Submit" class="btn clear-fix pull-left">
	
	<p class="feedback_content hidden clear-fix pull-left"></p>
</form>