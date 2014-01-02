<?
	global $_CONFIG;
?>	


<form id="template_form" class="form" action="" method="" accept-charset="utf-8"><h1>edit/add template</h1><img class="form_close" src="<? echo $_CONFIG->img_path; ?>admin/close.png" alt="close"> 

	<p> Press Escape, or Click the x to close.</p>
	
	<input type="hidden" id="id" name="id" value=""><br/>
	
	<label for="template_name">Template Name</label><br/> 
	<input id="template_name" name="template_name" value="" placeholder="Template Name" class="required"><br/>
	
	<label for="template_type">Template Type</label>
	<select id="template_type">
		<option value="0" selected>Page</option>
		<option value="1">Content</option>
	</select>
	<br/>
	

	
	<input type="hidden" id="template_token" name="token" value="">
	<input type="hidden" id="update_type" name="update_type" value="template">
	<input type="hidden" id="update_crud" name="update_crud" value="">

	<input type="submit" value="Submit" class="btn clear-fix pull-left">
	
	<p class="feedback_content hidden clear-fix pull-left"></p>
</form>