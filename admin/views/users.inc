<h1> this is the edit <? $helpers->getQuery('pagename','echo'); ?> page</h1>

<? 
	
	$q = $model->sqlSelect("*" , "users", "", "ORDER BY user_Access ASC");
	$token = $security->generateFormToken('token');

	echo '<table class="search_table">
			<tr class="th">
				<td>username</td>
				<td>full name</td>
				<td>access</td>
				<td>Actions</td>
				<td>  <input class="search" placeholder="Type to search"/></td>
			</tr>
		';		
					  
	foreach($q as $value) {
		echo '<tr class="data">'
				.'<td>'.$value['user_uName'].'</td>'
				.'<td>'.$value['user_FullName'].'</td>'
				.'<td>';if($value['user_Access'] === '1'){echo 'Admin';}else{echo 'User';}  echo '</td>'
				.'<td><a class="edit" href="?userid='. $value['users_Id'] .'&tpl=edit&type=edit_user#users"></a> ' . '<form style="position: relative;" class="pull-left" id="delete_form" action="" method=""> <a class="delete" href="?id='.$value['users_Id'].'#users"></a> <input type="hidden" name="token" id="token" value="'. $token .'"> <input id="id" type="hidden" value="'. $helpers->stripcleantohtml($value['users_Id']) .'"/> <input id="type" type="hidden" value="'. $helpers->stripcleantohtml( 'users' ) . '"/> <input id="db_id" type="hidden" value="'.$helpers->stripcleantohtml('users_Id').'"/> <input class="hidden" type="submit" id="submit"/> </form></td>'
			 .'</tr>';
	}				
	echo '</table>';		
		    

?>


		

		