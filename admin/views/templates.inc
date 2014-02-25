<h1> Templates </h1>
<?php	

	$template_token = $security->generateFormToken('template_token'); 
	echo '<p id="token" class="hidden">'.$template_token.'</p>';
	$r = $model->sqlSelect("*" , "templates", "", "");
	//print_r($r);
	
				echo '<table class="search_table">
						<tr class="th">
							<td class="hidden">id</td>
							<td>Template Name</td>
							<td>Template Type</td>
							<td>Actions</td>
							<td>  <input class="search" placeholder="Type to search"/></td>
						</tr>
					';		
								  
				foreach($r as $value) {
					$type = $value['template_type'];
					if($type === '0'){
						$type = 'page';
					}else{
						$type = 'content';
					}
					
					echo '<tr class="data">'
							.'<td class="id hidden">'.$value['id'].'</td>'
							.'<td class="template_name">'.$value['template_name'].'</td>'
							.'<td class="template_type">'.$type.'</td>'
							.'<td id="token" class="hidden">'.$template_token.'</td>'
							.'<td><a class="edit edit_template" href="#assets"></a> ' . '<form style="position: relative;" class="pull-left" id="delete_form" action="" method=""> <a class="delete" href="#assets"></a>  <input id="id" type="hidden" value="'. $helpers->stripcleantohtml($value['id']) .'"/> <input id="type" type="hidden" value="templates"/> <input id="db_id" type="hidden" value="'.$helpers->stripcleantohtml('id').'"/> <input class="hidden" type="submit" id="submit"/> </form></td>'				
						 .'</tr>';
				}				
				echo '</table>';		
	
?>

			<p class="add_template">Add new template</p>
