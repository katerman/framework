<?php
	if($perms['pages'] == 1){
?>

<?php
	//pager
	$amt = $helpers->getQuery('amt','return');
	include_once "scripts/pager.class.php"; //include this class where needed
	
	//$z = $helpers->sqlSelect("*" , "pages", "", "ORDER BY page_order ASC");
	$token = $security->generateFormToken('token');
	
	$pager = new pager($amt, 'pages', '*');  	
	$pager->setTableSqlDataWhere("ORDER BY page_order ASC");

	function on_nav_val($x){
		if ($x === '1'){
			return 'True';
		}else{
			return 'False';
		}
	}
							
	echo '<h1>Page View</h1>
		
		  <table class="search_table table">
			<thead>
			<tr>
				<td class="vis-hidden"></td>
				<td><input class="search" placeholder="Type to Filter"/></td>
			</tr>
			<tr>
				<td>Page Name</td>
				<td>Page Url</td>
				<td>Page Order</td>
				<td>On Nav</td>
				<td>Actions</td>
			</tr>
			</thead><tbody>
		';		
					  
	foreach($pager->getTableData() as $value) {
		echo '<tr class="data">'
				.'<td>'.$value['page_name'].'</td>'
				.'<td>'.$value['page_url'].'</td>'
				.'<td>'.$value['page_order'].'</td>'
				.'<td>'. on_nav_val($value['on_nav']) .'</td>'
				.'<td><a class="edit" href="?pageid='. $value['pages_id'] .'&tpl=edit&type=edit_page&amt=10&page=1"></a> ' . '<form style="position: relative;" class="pull-left delete_form" action="" method=""> <a class="delete" href="?id='.$value['pages_id'].'"></a> <input type="hidden" name="token" id="token" value="'.$token .'"> <input id="id" type="hidden" value="'. $helpers->custom_clean($value['pages_id']) .'"/> <input id="type" type="hidden" value="pages"/> <input id="db_id" type="hidden" value="pages_id"/> <input class="hidden" type="submit" id="submit"/> </form></td>'
			 .'</tr>';
	}				
	echo '</tbody></table>';		
	echo '<a href="?tpl=add&type=add_page" class="add_page">Add a page</a><br>';
	$pager->ShowPaging();					    
?>



<?php
	}else{
		header('Location: ?tpl=default_view');
	}
?> 

