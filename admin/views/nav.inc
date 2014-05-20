<?php
	global $user;
	
	$uid = $user['id'];
	$perms = $helpers->sqlSelect("user_custom_perms" , "users", "", "WHERE users_Id = $uid" );
	$perms = unserialize($perms[0]['user_custom_perms']);
	
?>
	<div class="search_bg"> 
		<div class="retract-nav"><span class="fa fa-bars"></span></div>
<!-- NOT READY YET
		<form>
			<input class="search_field" type="text" Placeholder="Search Here"> 
			<button class="search_submit"></button>
			<button class="search_submit_min hidden"></button>
		</form>
-->
	</div> 	   
		    
	<ul>
		<li><span class="fa fa-bar-chart-o"></span><a class="nav-spot" href="">Dashboard</a></li>
		<li>
			<ul class="dropdown">
				<li><a href="?tpl=default_view">Dashboard</a></li>
			</ul>
		</li>
	</ul>	
	
	<?php 
	
		if($perms['config'] == 1){
			echo '
				<ul>
					<li><span class="fa fa-wrench"></span><a href="" class="nav-spot">Config</a></li>
					<li>
						<ul class="dropdown">
							<li><a class="nav-spot" href="?tpl=edit&type=edit_config&pagename=config">Config</a></li>
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
					<li><span class="fa fa-files-o"></span><a href="" class="nav-spot">Pages</a></li>
					<li>
						<ul class="dropdown">
							<li><a class="nav_view-page" href="?tpl=page_view&amt=10&page=1">Page Viewer</a></li>
							<li><a class="nav_add-page" href="?tpl=add&type=add_page">Add Page</a></li>
			';					
						
						
							$x = $helpers->sqlSelect("*" , "pages", "", "WHERE on_nav = '1'");
							
			
							foreach($x as $key=>$value) {
								echo '<li><a class="nav-spot" href="?pageid='. $value['pages_id'] .'&tpl=edit&type=edit_page&pagename='.$value['page_name'].'&amt=10&page=1">'. $value['page_name'] .'</a></li>';
							}
			echo '				
											
					
						</ul>
					</li>
				</ul>		
			';
		}
	
	if($perms['users'] == 1){
		echo'<ul>
			<li><span class="fa fa-users"></span><a href="" class="nav-spot">Users</a></li>
			<li>
				<ul class="dropdown">
					<li><a class="nav_view-page nav-spot" href="?tpl=users&pagename=users&amt=10&page=1">View Users</a></li>
					<li><a class="nav_add-page nav-spot" href="?tpl=add&type=add_user">Add User</a></li>					
					<li><a class="nav-spot" href="?tpl=log">User Log</a></li>					
				</ul>
			</li>
		</ul>
		';
	}
	
	if($perms['assets']['top_level'] == 1){
		echo '
	<ul>
		<li><span class="fa fa-picture-o"></span><a href="" class="nav-spot">Assets</a></li>
		<li>
			<ul class="dropdown">
		';
				if($perms['assets']['upload'] == 1 && $perms['assets']['top_level'] == 1){ echo'<li><a class="nav-spot" href="?tpl=upload&pagename=upload">Upload</a></li>';}
				if($perms['assets']['uploaded'] == 1 && $perms['assets']['top_level'] == 1){ echo'<li><a class="nav-spot" href="?tpl=uploaded&pagename=uploaded">Uploaded</a></li>';}
				if($perms['assets']['templates'] == 1 && $perms['assets']['top_level'] == 1){ echo'<li><a class="nav-spot" href="?tpl=templates&pagename=templates&amt=10&page=1">Templates</a></li>';}
				if($perms['assets']['labels'] == 1 && $perms['assets']['top_level'] == 1){ echo'<li><a class="nav-spot" href="?tpl=labels&pagename=labels&amt=10&page=1">Labels</a></li>';}
		echo'	</ul>
		</li>
	</ul>	
		';			
	}
	?>