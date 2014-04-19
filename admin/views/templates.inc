<?php
	if($perms['assets']['templates'] == 1 && $perms['assets']['top_level'] == 1){
?>

<h1> Templates </h1>
<?php	

	$template_token = $security->generateFormToken('template_token'); 
	echo '<p id="token" class="hidden">'.$template_token.'</p>';
	$r = $helpers->sqlSelect("*" , "templates", "", "");
	//print_r($r);
	
	echo '<table class="search_table table">
			<thead>
			<tr>
				<td class="vis-hidden"></td>
				<td><input class="search" placeholder="Type to search"/></td>
			</tr>
			<tr>
				<td class="hidden">id</td>
				<td>Template Name</td>
				<td>Template Type</td>
				<td>Actions</td>
			</tr>
			</thead>
			<tbody>
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
	echo '</tbody></table>';		

?>

<p class="add_template">Add new template</p>

<?php
	}else{
		header('Location: ?tpl=default_view#dashboard');
	}
?> 	
