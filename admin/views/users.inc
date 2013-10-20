<h1> this is the edit page for <? $helpers->getQuery('pagename','echo'); ?> page</h1>

<? 
	
	$q = $model->sqlSelect("*" , "users", "", "ORDER BY user_Access ASC");
	$deleteToken = $security->generateFormToken('delete_page_token');

	echo '<table>
			<tr class="th">
				<td>Users Id</td>
				<td>username</td>
				<td>password</td>
				<td>full name</td>
				<td>salt</td>
				<td>access</td>
				<td>Actions</td>
			</tr>
		';		
					  
	foreach($q as $value) {
		echo '<tr>'.
				'<td>'.$value[users_Id].'</td>'
				.'<td>'.$value[user_uName].'</td>'
				.'<td>'.$value[user_Pass].'</td>'
				.'<td>'.$value[user_FullName].'</td>'
				.'<td>'.$value[user_Salt].'</td>'
				.'<td>'.$value[user_Access].'</td>'
				.'<td><a class="edit" href="?pageid='. $value[users_Id] .'&tpl=edit&type=edit_user#users"></a> ' . '<form style="position: relative;" class="pull-left" id="delete_form" action="" method=""> <a class="delete" href="?id='.$value[users_Id].'#users"></a> <input type="hidden" name="token" id="token" value="'. $helpers->stripcleantohtml($deleteToken) .'"> <input id="id" type="hidden" value="'. $helpers->stripcleantohtml($value[users_Id]) .'"/> <input id="type" type="hidden" value="'. $helpers->stripcleantohtml( 'users' ) . '"/> <input id="db_id" type="hidden" value="'.$helpers->stripcleantohtml('users_Id').'"/> <input class="hidden" type="submit" id="submit"/> </form></td>'
			 .'</tr>';
	}				
	echo '</table>';		
		    

?>


		

		