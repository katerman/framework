<h1> Labels </h1>
<?	

	$label_token = $security->generateFormToken('label_token'); 
	echo '<p id="token" class="hidden">'.$label_token.'</p>';
	$r = $model->sqlSelect("*" , "labels", "", "");
	
	//print_r($r);
	
				echo '
					
					    
					<table class="search_table">
						<tr class="th">
							<td class="hidden">id</td>
							<td>Label Name</td>
							<td>Label Content</td>
							<td>Actions</td>
							<td>  <input class="search" placeholder="Type to search"/></td>
						</tr>
					';		
								  
				foreach($r as $value) {				
					echo '<tr class="data">'
							.'<td class="id hidden">'.$value[label_id].'</td>'
							.'<td class="label_name">'.$value[label_name].'</td>'
							.'<td class="label_content">'.$value[label_content].'</td>'
							.'<td id="token" class="hidden">'.$label_token.'</td>'
							.'<td><a class="edit edit_labels" href="#assets"></a> ' . '<form style="position: relative;" class="pull-left" id="delete_form" action="" method=""> <a class="delete" href="#assets"></a>  <input id="id" type="hidden" value="'. $helpers->stripcleantohtml($value[label_id]) .'"/> <input id="type" type="hidden" value="labels"/> <input id="db_id" type="hidden" value="'.$helpers->stripcleantohtml('label_id').'"/> <input class="hidden" type="submit" id="submit"/> </form></td>'				
						 .'</tr>';
				}				
				echo '</table>';		
	
?>

			<p class="add_labels">Add new label</p>
