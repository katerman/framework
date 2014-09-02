<?php
	global $_CONFIG;
?>	


<form id="scattershot_form" class="form" action="" method="" accept-charset="utf-8"><h1>edit/add Scattershot</h1><img class="form_close" src="<?php echo $_CONFIG->img_path; ?>admin/close.png" alt="close"> 

	<p> Press Escape, or Click the x to close.</p>
	
	<input type="hidden" id="id" name="id" value=""><br/>
	
	<label for="scattershot_name">Scattershot Name</label><br/> 
	<input id="scattershot_name" name="scattershot_name" value="" placeholder="Name" class="required"><br/>	
	
	<label for="scattershot_value">Scattershot Value</label><br/> 
	<input id="scattershot_value" name="scattershot_value" value="" placeholder="Value"><br/>	

	<label for="scattershot_type">Scattershot Type</label><br/> 
	<input id="scattershot_type" name="scattershot_type" value="" placeholder="Type"><br/>	

	<label for="scattershot_anchor">Scattershot Anchor</label><br/> 
	<input id="scattershot_anchor" name="scattershot_anchor" value="" placeholder="Anchor"><br/>	

	<label for="scattershot_class">Scattershot Class</label><br/> 
	<input id="scattershot_class" name="scattershot_class" value="" placeholder="Class"><br/>	

	<label for="scattershot_id">Scattershot ID</label><br/> 
	<input id="scattershot_id" name="scattershot_id" value="" placeholder="ID"><br/>	

	
	<input type="hidden" id="token" name="token" value="">
	<input type="hidden" id="update_type" name="update_type" value="scattershot">
	<input type="hidden" id="update_crud" name="update_crud" value="">

	<input type="submit" value="Submit" class="btn clear-fix pull-left">
	
	<p class="feedback_content hidden clear-fix pull-left"></p>
</form>