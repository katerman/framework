<?
	global $_CONFIG;
?>	


<form id="label_form" class="form" action="" method="" accept-charset="utf-8"><h1>edit/add label</h1><img class="form_close" src="<? echo $_CONFIG->img_path; ?>admin/close.png" alt="close"> 

	<p> Press Escape, or Click the x to close.</p>
	
	<input type="hidden" id="id" name="id" value=""><br/>
	
	<label for="label_name">Label Name</label><br/> 
	<input id="label_name" name="label_name" value="" placeholder="Label Name" class="required"><br/>	
	
	<label for="label_content">Label Content</label><br/> 
	<input id="label_content" name="label_content" value="" placeholder="Label Content"><br/>	

	
	<input type="hidden" id="label_token" name="token" value="">
	<input type="hidden" id="update_type" name="update_type" value="labels">
	<input type="hidden" id="update_crud" name="update_crud" value="">

	<input type="submit" value="Submit" class="btn clear-fix pull-left">
	
	<p class="feedback_content hidden clear-fix pull-left"></p>
</form>