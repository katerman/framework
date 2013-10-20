		<p>Welcome back, <?php echo htmlentities($data['fullname']);?>.</p>
		<? 
					
				$z = $model->sqlSelect("*" , "pages", "", "ORDER BY page_order ASC");
				$deleteToken = $security->generateFormToken('delete_page_token');
						
				echo '<table>
						<tr class="th">
							<td>Pages ID</td>
							<td>Page Name</td>
							<td>Page Template</td>
							<td>Page Group</td>
							<td>Sub Page</td>
							<td>Page Meta Keyword</td>
							<td>Page Meta Title</td>
							<td>Page Url</td>
							<td>Page Order</td>
							<td>Actions</td>
						</tr>
					';		
								  
				foreach($z as $value) {
					echo '<tr>'.
							'<td>'.$value[pages_id].'</td>'
							.'<td>'.$value[page_name].'</td>'
							.'<td>'.$value[page_template].'</td>'
							.'<td>'.$value[page_group].'</td>'
							.'<td>'.$value[sub_page].'</td>'
							.'<td>'.$value[page_meta_keyword].'</td>'
							.'<td>'.$value[page_meta_title].'</td>'
							.'<td>'.$value[page_url].'</td>'
							.'<td>'.$value[page_order].'</td>'
							.'<td><a class="edit" href="?pageid='. $value[pages_id] .'&tpl=edit&type=edit_page#pages"></a> ' . '<form style="position: relative;" class="pull-left" id="delete_form" action="" method=""> <a class="delete" href="?id='.$value[pages_id].'#pages"></a> <input type="hidden" name="token" id="token" value="'. $helpers->stripcleantohtml($deleteToken) .'"> <input id="id" type="hidden" value="'. $helpers->stripcleantohtml($value[pages_id]) .'"/> <input id="type" type="hidden" value="'. $helpers->stripcleantohtml( 'pages' ) . '"/> <input id="db_id" type="hidden" value="'.$helpers->stripcleantohtml('pages_id').'"/> <input class="hidden" type="submit" id="submit"/> </form></td>'
						 .'</tr>';
				}				
				echo '</table>';		
							    
		?>