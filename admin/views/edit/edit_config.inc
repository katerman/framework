<h1>  <? $helpers->getQuery('pagename','echo'); ?> </h1>

		<? 
				$page = $helpers->getQuery('pageid','return');
				$z = $model->sqlSelect("*" , "config", "", "");
				
				print_r($z);
				
				echo '<table>
						<tr class="th">
							<td>ID</td>
							<td>Site Name</td>
							<td>Global Logo</td>
							<td>Extra Js</td>
							<td>Extra Css</td>
						</tr>
					';		
								  
				foreach($z as $value) {
					echo '<tr>'.
							'<td>'.$value[id].'</td>'
							.'<td>'.$value[site_name].'</td>'
							.'<td><img src="../uploads/'.$value[global_logo].'" alt="logo" width="150"></td>'
							.'<td>'.$value[extra_js].'</td>'
							.'<td>'.$value[extra_css].'</td>'
						 .'</tr>';
				}				
				echo '</table>';		
					    

			$edit_token = $security->generateFormToken('edit_token'); 
			
			$id = $helpers->stripcleantohtml($z[0][id]);
			$site_name = $helpers->stripcleantohtml($z[0][site_name]);
			$global_logo = $helpers->stripcleantohtml($z[0][global_logo]);
			$extra_js = $helpers->stripcleantohtml($z[0][extra_js]);
			$extra_css = $helpers->stripcleantohtml($z[0][extra_css]);
			
			//File location (images)
			$ds          = DIRECTORY_SEPARATOR;  			 
			$storeFolder = 'uploads'; 						
			$dirname = '..'.$ds.$storeFolder.$ds;
			$images = glob("{$dirname}*.*");
			
			//print_r($dirname);

		?>
		<form id="edit_form" class="form" action="" method="" accept-charset="utf-8">
		
            <input type="hidden" id="config_id" name="config_id" value="<? echo $id; ?>">


			<label for="site_name">Site Name</label><br/>
		    <input id="site_name" name="site_name" value="<? echo $site_name; ?>" placeholder="Site Name"><br/><br/>
		
			<label for="global_logo">Site Logo</label><br/>
		    <select name="global_logo" id="global_logo">
		    	<?
					if($images){
						foreach($images as $image) {
							$i = str_replace('../uploads/', '', $image);
							$x = '';
							if($i === $global_logo){
								$x = 'selected';
							}
							echo '<option class="logo_dropdown" value="'.$i.'"'.$x.'>'.$i.'</option>';
						}
					}		    	
		    	 ?>
		    </select><br/><br/>
		
			<label for="extra_js">Extra Javascript</label><br/>
		    <textarea cols="40" rows="10" id="extra_js" name="extra_js" placeholder="Extra JavaScript"><? echo $extra_js; ?></textarea><br/><br/>

			<label for="extra_css">Extra CSS</label><br/>
		    <textarea cols="40" rows="10" id="extra_css" name="extra_css" placeholder="Extra CSS"><? echo $extra_css; ?></textarea><br/>
			
			

			
			<input type="hidden" id="token" name="token" value="<?php echo $edit_token; ?>">
			<input type="hidden" id="update_type" name="update_type" value="config">

			<input type="submit" value="Submit" class="btn clear-fix pull-left">
			<p class="feedback_text hidden clear-fix pull-left"></p>
		</form>
		
		

		