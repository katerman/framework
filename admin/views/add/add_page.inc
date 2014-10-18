<?php
	global $helpers, $security;
	
	$user = new user();
	$perms = $user->get_Permissions();

	if($perms['pages'] == 1){
?>

<h1> Lets add a page!</h1>

<?php 								
	$r = $helpers->sqlSelect("*" , "templates", "", "");
	$pp = $helpers->sqlSelect("*" , "pages", "", "WHERE on_nav = '1'");
	$parent_page = $helpers->getQuery('parent_page','return');

	$token = $security->generateFormToken('token'); 
	
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
	<?php 
		foreach($r as $k=>$temp){
			if($k === 0){
				echo '<option value="none" selected>None</option>';
			}
			echo '<option value="'.$temp['id'].'">'.$temp['template_name'].'</option>';
		}
		
	?>
	</select><br/>			
	
	<label for="parent_page">Parent Page</label><br/>
	<select id="parent_page" name="parent_page" style="margin-bottom: 10px; width: 150px;"><div></div>
	<?php 
		foreach($pp as $k=>$p){
		
			if(isset($parent_page) && $parent_page === $p['pages_id']){
				if($k === 0){
					echo '<option value="none">None</option>';
				}
				
				echo '<option value="'.$p['pages_id'].'" selected>'.$p['page_name'].'</option>';
				
			}else{
			
				if($k === 0){
					echo '<option value="none" selected>None</option>';
				}
				
				echo '<option value="'.$p['pages_id'].'">'.$p['page_name'].'</option>';
			}
		}
		
	?>
	</select><br/>
	
	<label for="page_group">Page Group</label><br/>
    <input id="page_group" name="page_group" value="" placeholder="Page Group"><br/>

	<label for="page_order">Page Order</label><br/>
    <input id="page_order" name="page_order" value="" placeholder="Page Order"><br/>

	<label for="on_nav">Appear On Navigation?</label>           
    <input id="on_nav" type="checkbox" name="on_nav" value="1" /><br/>

	<input type="hidden" id="token" name="token" value="<?php echo $token; ?>">
	<input type="hidden" id="update_type" name="update_type" value="pages">

	<input type="submit" value="Submit" class="btn">
	<p class="feedback_text hidden"></p>
</form>

<?php
	}else{
		$helpers->redirect('index.php?tpl=default_view');
	}
?> 

