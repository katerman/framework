<?php
	if($perms['pages'] == 1){
?>

<?php
			
	$z = $model->sqlSelect("*" , "pages", "", "ORDER BY page_order ASC");
	$token = $security->generateFormToken('token');
	
	function on_nav_val($x){
		if ($x === '1'){
			return 'True';
		}else{
			return 'False';
		}
	}
							
	echo '<table class="search_table">
			<tr class="th">
				<td>Page Name</td>
				<td>Page Url</td>
				<td>Page Order</td>
				<td>On Nav</td>
				<td>Actions</td>
				<td>  <input class="search" placeholder="Type to search"/></td>
			</tr>
		';		
					  
	foreach($z as $value) {
		echo '<tr class="data">'
				.'<td>'.$value['page_name'].'</td>'
				.'<td>'.$value['page_url'].'</td>'
				.'<td>'.$value['page_order'].'</td>'
				.'<td>'. on_nav_val($value['on_nav']) .'</td>'
				.'<td><a class="edit" href="?pageid='. $value['pages_id'] .'&tpl=edit&type=edit_page#pages"></a> ' . '<form style="position: relative;" class="pull-left" id="delete_form" action="" method=""> <a class="delete" href="?id='.$value['pages_id'].'#pages"></a> <input type="hidden" name="token" id="token" value="'.$token .'"> <input id="id" type="hidden" value="'. $helpers->stripcleantohtml($value['pages_id']) .'"/> <input id="type" type="hidden" value="'. $helpers->stripcleantohtml( 'pages' ) . '"/> <input id="db_id" type="hidden" value="'.$helpers->stripcleantohtml('pages_id').'"/> <input class="hidden" type="submit" id="submit"/> </form></td>'
			 .'</tr>';
	}				
	echo '</table>';		
					    
?>

<a href="?tpl=add&type=add_page#pages" class="add_page">Add a page</a>

<?php
	}else{
		header('Location: ?tpl=default_view#dashboard');
	}
?> 

