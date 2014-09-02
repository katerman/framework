<?php
	if($perms['assets']['scattershot'] == 1 && $perms['assets']['top_level'] == 1){
	
	//pager
	$amt = $helpers->getQuery('amt','return');
?>

<h1> Scattershot </h1>
<p>A useful area to create dynamic content, kind of like labels. However scattershot will allow for more specific types of information</p>
<?php		

	$token = $security->generateFormToken('token'); 
	echo '<p id="token" class="hidden">'.$token.'</p>';

	$pager = new pager($amt, 'scattershot', '*');  

	
				echo '
					
					    
					<table class="search_table table">
						<thead>
						<tr>
							<td class="vis-hidden"></td>
							<td><input class="search" placeholder="Type to Filter"/></td>
						</tr>
						<tr class="th">
							<td class="hidden">id</td>
							<td>Scattershot Name</td>
							<td>Scattershot Value</td>
							<td>Actions</td>
						</tr>
						</thead>
						<tbody>
					';		
								  
				foreach($pager->getTableData() as $value) {				
					echo '<tr class="data">'
							.'<td class="id hidden">'.$value['scattershot_id'].'</td>'
							.'<td class="scattershot_name">'.$value['name'].'</td>'
							.'<td class="scattershot_value">'.$value['value'].'</td>'
							.'<td class="scattershot_type hidden">'.$value['type'].'</td>'
							.'<td class="scattershot_anchor hidden">'.$value['anchor'].'</td>'
							.'<td class="scattershot_class hidden">'.$value['class'].'</td>'
							.'<td class="scattershot_id hidden">'.$value['id'].'</td>'
							.'<td><a class="edit edit_scattershot" href="#"></a> ' . '<form style="position: relative;" class="pull-left delete_form" action="" method=""> <a class="delete" href="#"></a> <input id="id" type="hidden" value="'. $value['scattershot_id'] .'"/> <input id="type" type="hidden" value="scattershot"/> <input id="db_id" type="hidden" value="scattershot_id"/> <input class="hidden" type="submit" id="submit"/> </form></td>'				
						 .'</tr>';
				}				
				echo '</tbody></table>';	
					
	echo '<p class="add_scattershot">Add new Scattershot</p>';

	$pager->ShowPaging();
?>


<?php
	}else{
		header('Location: ?tpl=default_view');
	}
?> 	

