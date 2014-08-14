<?php
	if($perms['assets']['labels'] == 1 && $perms['assets']['top_level'] == 1){
	
	//pager
	$amt = $helpers->getQuery('amt','return');


?>

<h1> Labels </h1>
<?php		

	$token = $security->generateFormToken('token'); 
	echo '<p id="token" class="hidden">'.$token.'</p>';
	//$r = $helpers->sqlSelect("*" , "labels", "", "");

	$pager = new pager($amt, 'labels', '*');  

	//print_r($r);
	
				echo '
					
					    
					<table class="search_table table">
						<thead>
						<tr>
							<td class="vis-hidden"></td>
							<td><input class="search" placeholder="Type to Filter"/></td>
						</tr>
						<tr class="th">
							<td class="hidden">id</td>
							<td>Label Name</td>
							<td>Label Content</td>
							<td>Actions</td>
						</tr>
						</thead>
						<tbody>
					';		
								  
				foreach($pager->getTableData() as $value) {				
					echo '<tr class="data">'
							.'<td class="id hidden">'.$value['label_id'].'</td>'
							.'<td class="label_name">'.$value['label_name'].'</td>'
							.'<td class="label_content">'.$value['label_content'].'</td>'
							.'<td><a class="edit edit_labels" href="#assets"></a> ' . '<form style="position: relative;" class="pull-left delete_form" action="" method=""> <a class="delete" href="#assets"></a> <input id="id" type="hidden" value="'. $value['label_id'] .'"/> <input id="type" type="hidden" value="labels"/> <input id="db_id" type="hidden" value="label_id"/> <input class="hidden" type="submit" id="submit"/> </form></td>'				
						 .'</tr>';
				}				
				echo '</tbody></table>';	
					
	echo '<p class="add_labels">Add new label</p>';

	$pager->ShowPaging();
?>


<?php
	}else{
		header('Location: ?tpl=default_view');
	}
?> 	

