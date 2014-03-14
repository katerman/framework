<?php
	global $user;
	
	$uid = $user['id'];
	$perms = $model->sqlSelect("user_custom_perms" , "users", "", "WHERE users_Id = $uid" );
	$perms = unserialize($perms[0]['user_custom_perms']);
	
?>
	<ul>
		<li><a href="#dashboard">Dashboard</a></li>
		<li>
			<ul class="dropdownBtn">
				<li><a href="?tpl=default_view#dashboard">Dashboard</a></li>
			</ul>
		</li>
	</ul>	
	
	<?php 
	
		if($perms['config'] == 1){
			echo '
				<ul>
					<li><a href="#config">Config</a></li>
					<li>
						<ul class="dropdownBtn">
							<li><a href="?tpl=edit&type=edit_config&pagename=config#config">Config</a></li>
						</ul>
					</li>
				</ul>
			';	
		}
	?>
	
	<?php 
	
		if($perms['pages'] == 1){
			echo '
				<ul>
					<li><a href="#pages">Pages</a></li>
					<li>
						<ul class="dropdownBtn">
							<li><a class="nav_view-page" href="?tpl=page_view#pages">Page Viewer</a></li>
							<li><a class="nav_add-page" href="?tpl=add&type=add_page#pages">Add Page</a></li>
			';					
						
						
							$x = $model->sqlSelect("*" , "pages", "", "WHERE on_nav = '1'");
							
			
							foreach($x as $key=>$value) {
								echo '<li><a href="?pageid='. $value['pages_id'] .'&tpl=edit&type=edit_page&pagename='.$value['page_name'].'#pages">'. $value['page_name'] .'</a></li>';
							}
			echo '				
											
					
						</ul>
					</li>
				</ul>		
			';
		}
	
	if($perms['users'] == 1){
		echo'<ul>
			<li><a href="#users">Users</a></li>
			<li>
				<ul class="dropdownBtn">
					<li><a class="nav_view-page" href="?tpl=users&pagename=users#users">View Users</a></li>
					<li><a class="nav_add-page" href="?tpl=add&type=add_user#users">Add User</a></li>					
				</ul>
			</li>
		</ul>
		';
	}
	
	if($perms['assets']['top_level'] == 1){
		echo '
	<ul>
		<li><a href="#assets">Assets</a></li>
		<li>
			<ul class="dropdownBtn">
		';
				if($perms['assets']['upload'] == 1 && $perms['assets']['top_level'] == 1){ echo'<li><a href="?tpl=upload&pagename=upload#assets">Upload</a></li>';}
				if($perms['assets']['uploaded'] == 1 && $perms['assets']['top_level'] == 1){ echo'<li><a href="?tpl=uploaded&pagename=uploaded#assets">Uploaded</a></li>';}
				if($perms['assets']['templates'] == 1 && $perms['assets']['top_level'] == 1){ echo'<li><a href="?tpl=templates&pagename=templates#assets">Templates</a></li>';}
				if($perms['assets']['labels'] == 1 && $perms['assets']['top_level'] == 1){ echo'<li><a href="?tpl=labels&pagename=labels#assets">Labels</a></li>';}
		echo'	</ul>
		</li>
	</ul>	
		';			
	}
	?>