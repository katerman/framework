<?php
	if($perms['config'] == 1){
?>

<h1>  <?php $helpers->getQuery('pagename','echo'); ?> </h1>

		<?php 
				$page = $helpers->getQuery('pageid','return');
				$z = $helpers->sqlSelect("*" , "config", "", "");
				$token = $security->generateFormToken('token'); 
				
				$id = $helpers->custom_clean($z[0]['id']);
				$site_name = $helpers->custom_clean($z[0]['site_name']);
				$global_logo = $helpers->custom_clean($z[0]['global_logo']);
				$extra_js = $helpers->custom_clean($z[0]['extra_js'],false);
				$extra_css = $helpers->custom_clean($z[0]['extra_css'],true,false);

			//	print_r($z);
				
				echo '<table class="table">
						<thead>
						<tr>
							<td>ID</td>
							<td>Site Name</td>
							<td>Global Logo</td>
							<td>Extra Js</td>
							<td>Extra Css</td>
						</tr>
						</thead>
						<tbody>
					';		
					
				foreach($z as $value) {
					echo '<tr>'.
							'<td>'.$id.'</td>'
							.'<td>'.$site_name.'</td>'
							.'<td><img src="../uploads/resized/'.$global_logo.'-resized" alt="logo" width="150"></td>'
							.'<td>'.$extra_js.'</td>'
							.'<td>'.$extra_css.'</td>'
						 .'</tr>';
				}				
				echo '</tbody></table>';		
					    
			
			//File location (images)
			$ds          = DIRECTORY_SEPARATOR;  			 
			$storeFolder = 'uploads'; 						
			$dirname = '..'.$ds.$storeFolder.$ds;
			$images = glob($dirname . '*.{jpg,jpeg,png,gif,JPG,JPEG,PNG,GIF}', GLOB_BRACE);
			
			//print_r($images);

		?>
		<form id="edit_form" class="form" action="" method="" accept-charset="utf-8">
		
            <input type="hidden" id="config_id" name="config_id" value="<?php echo $id; ?>">


			<label for="site_name">Site Name</label><br/>
		    <input id="site_name" name="site_name" value="<?php echo $site_name; ?>" placeholder="Site Name"><br/><br/>
		
			<label for="global_logo">Site Logo</label><br/>
			
		    <div class="images_for_chooser hidden"><img class="image_chooser_close" src="<?php echo $_CONFIG->img_path; ?>admin/close.png" alt="close">
		    <div class="image_chooser_search">
		    	<h1>Choose an image</h1>
				<input class="search" placeholder="Type to search"/>
		    </div>
		    	<ul id="the_image_ul">
		    	<?php
		    	
					if($images){
						foreach($images as $k=>$image) {
							$image = str_replace('../uploads/', '', $image);
							$image_name = $image;
							
							$i = '../uploads/resized/'.$image_name.'-resized';
							if(!file_exists($i)){
								$helpers->smart_resize_image('../uploads/'.$image_name , 100 , 100 , false , $i , false , false ,80 );
							}
							
							echo '<li class="images"><p>'.$image_name.'</p><img src="'.$i.'" alt="imagechooser'.$k.'"></li>';
						}
					}		    	
		    	 ?>
		    	</ul>
		    	<div class="image_chooser_info_div">
			    	<p class="picked"></p>
			    	<button class="image_chooser_submit btn blue">Done</button>
		    	</div>
	    	</div>
			
		    <button class="btn blue image_chooser">Choose Image</button>
		    <input id="global_logo" class="global_logo_value hidden" value="" type="hidden">
		    <p class="picked"></p>
		    <br/><br/>
		
			<label for="extra_js">Extra Javascript</label><br/>
		    <textarea cols="40" rows="10" id="extra_js" name="extra_js" placeholder="Extra JavaScript"><?php echo $extra_js; ?></textarea><br/><br/>

			<label for="extra_css">Extra CSS</label><br/>
		    <textarea cols="40" rows="10" id="extra_css" name="extra_css" placeholder="Extra CSS"><?php echo $extra_css; ?></textarea><br/>
			
			

			
			<input type="hidden" id="token" name="token" value="<?php echo $token; ?>">
			<input type="hidden" id="update_type" name="update_type" value="config">

			<input type="submit" value="Submit" class="btn clear-fix pull-left">
			<p class="feedback_text hidden clear-fix pull-left"></p>
		</form>
		
		
<?php
	}else{
		header('Location: ?tpl=default_view');
	}
?>
		