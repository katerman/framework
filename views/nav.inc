<?

		$x = $model->sqlSelect( "*", //select, 
					  "pages", //from
					  "", //column names
					  "ORDER BY page_order ASC" //where
				  ); 	
				  
		echo '<ul id="nav">';		  
		foreach($x as $key=>$value){
			echo '<li class="pull-left" style="margin-left: 10px;"><a href="?page='.$value[page_url].'">' . $value[page_name] . '</a></li>'; 
		}
		
		if($_SESSION){
			echo '<li class="pull-left" style="margin-left: 10px;"><a href="logout.php"> Log out </a></li>';
		}
		echo '</ul>';
		
?>