<?php
global $page;
global $model;

$p = $helpers->sqlSelect( "*", //select, 
			  "pages", //from
			  "", //column names
			  "WHERE on_nav = 1 ORDER BY page_order ASC" //where
		  ); 
?>


<div class="navbar navbar-inverse" role="navigation">
    <div class="container-fluid">
        <div class="navbar-header">
            
            <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
				<span class="sr-only">Toggle navigation</span>
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
			</button>    
			<a class="navbar-brand" href="#"><?php echo '<img src="'.$_CONFIG->upload_path.$config['global_logo'].'" alt="logo">';?></a>
        </div>

        <div class="navbar-collapse collapse">
            <ul class="nav navbar-nav">
            
				<?php	
							  
					       
					foreach($p as $value){
						echo '<li '; 
					
						if($page['pages_id'] == $value['pages_id']){ echo 'class="active"'; } 
						
						echo '><a href="?page='.$value['page_url'].'">' . $value['page_name'] . '</a></li>';
					}
								
				?>
            </ul>

			<ul class="nav navbar-nav navbar-right">
				<?php
					if($_SESSION){
						echo '<li><a href="app/logout.php"> Log out </a></li>';
					}
				?>		
			</ul>  
		
        </div><!--/.nav-collapse -->
        
      
    </div><!--/.container-fluid -->
</div>

