<?		global $page;
		global $model;

		$p = $helpers->sqlSelect( "*", //select, 
					  "pages", //from
					  "", //column names
					  "WHERE on_nav = 1 ORDER BY page_order ASC" //where
				  ); 	
				  
		echo '<ul id="nav">';		
		       
		foreach($p as $value){
			echo '<li '; 

			if($page['pages_id'] == $value['pages_id']){ echo 'id="active"'; } 
			
			echo 'class="" style="padding-left:10px;"><a href="?page='.$value['page_url'].'">' . $value['page_name'] . '</a></li>';
		}
		
		if($_SESSION){
			echo '<li class="pull-left" style="padding-left: 10px;"><a href="app/logout.php"> Log out </a></li>';
		}
		echo '</ul>';	

?>