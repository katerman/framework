

	<ul>
		<li><a href="#config">Config</a></li>
		<li>
			<ul class="dropdownBtn">
				<li><a href="?tpl=edit&type=edit_config&pagename=config#config">Config</a></li>
			</ul>
		</li>
	</ul>	

	<ul>
		<li><a href="#pages">Pages</a></li>
		<li>
			<ul class="dropdownBtn">
				<li><a class="nav_view-page" href="?tpl=default_view#pages">Page Viewer</a></li>
				<li><a class="nav_add-page" href="?tpl=add&type=add_page#pages">Add Page</a></li>					
				<? 
				
					$x = $model->sqlSelect("*" , "pages", "", "");
					
	
					foreach($x as $key=>$value) {
						echo '<li><a href="?pageid='. $value[pages_id] .'&tpl=edit&type=edit_page&pagename='.$value[page_name].'#pages">'. $value[page_name] .'</a></li>';
					}
					
									
				?>
			</ul>
		</li>
	</ul>		
	
	<ul>
		<li><a href="#users">Users</a></li>
		<li>
			<ul class="dropdownBtn">
				<li><a class="nav_view-page" href="?tpl=users&pagename=users#users">View Users</a></li>
				<li><a class="nav_add-page" href="?tpl=add&type=add_user#users">Add User</a></li>					
			</ul>
		</li>
	</ul>	
	
	<ul>
		<li><a href="#assets">Assets</a></li>
		<li>
			<ul class="dropdownBtn">
				<li><a href="?tpl=upload&pagename=upload#assets">Upload</a></li>
				<li><a href="?tpl=uploaded&pagename=uploaded#assets">Uploaded</a></li>
				<li><a href="?tpl=templates&pagename=templates#assets">Templates</a></li>
			</ul>
		</li>
	</ul>				
