<?php
	if($perms['users'] == 1){
	
		//pager
		$amt = $helpers->getQuery('amt','return');
		include_once "scripts/pager.class.php"; //include this class where needed

?>

<h1> this is the edit <?php $helpers->getQuery('pagename','echo'); ?> page</h1>

<?php 
	
	//$q = $helpers->sqlSelect("*" , "users", "", "ORDER BY user_Access ASC LIMIT $amt");
	$pager = new pager($amt, 'users', 'user_uName, user_FullName, user_Access, users_Id');  
	 
	$token = $security->generateFormToken('token');

	echo '<table class="search_table table">
			<thead>
			<tr>
				<td class="vis-hidden"></td>
				<td><input class="search" placeholder="Type to Filter"/></td>
			</tr>
			<tr>
				<td>username</td>
				<td>full name</td>
				<td>access</td>
				<td>Actions</td>
			</tr>
			</thead>
			<tbody>
		';		
			  
	foreach($pager->getTableData() as $value) {
		echo '<tr class="data">'
				.'<td>'.$value['user_uName'].'</td>'
				.'<td>'.$value['user_FullName'].'</td>'
				.'<td>';
				
				if($value['user_Access'] === '1'){echo 'Admin';}else{echo 'User';}  
				
				echo '</td>'
				.'<td><a class="edit" href="?userid='. $value['users_Id'] .'&tpl=edit&type=edit_user#users"></a> ' . '<form style="position: relative;" class="pull-left" id="delete_form" action="" method=""> <a class="delete" href="?id='.$value['users_Id'].'#users"></a> <input type="hidden" name="token" id="token" value="'. $token .'"> <input id="id" type="hidden" value="'. $value['users_Id'] .'"/> <input id="type" type="hidden" value="users"/> <input id="db_id" type="hidden" value="users_Id"/> <input class="hidden" type="submit" id="submit"/> </form></td>'
			 .'</tr>';
	}				
	echo '</tbody></table>';		
			 
	$pager->ShowPaging();
?>



<?php
	}else{
		header('Location: ?tpl=default_view');
	}
		

		