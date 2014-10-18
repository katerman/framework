<?php
	global $view;
?>
<div class="container">
	<div class="row">
		<div class="col-xs-6">
			<?php
				$view->show_content('header_col_one');
				$view->show_content('content_col_one');
				
				$user = new user();
				print_pre($user->get_Permissions());
			?>
	
		</div>
		
		<div class="col-xs-6">
			<?php
				$view->show_content('header_col_two');
				$view->show_content('content_col_two');
				
				$form = new form('form_Name');
				$inputs = array(
					array(
						'id' => 'test',
						'class' => 'test',
						'type' => 'input',
						'label' => 'This is a test input'
					),
					array(
						'id' => 'test',
						'class' => 'test',
						'type' => 'checkbox',
						'label' => 'This is a test checkbox',
						'values' => array(
									'1'=> 'One',
									'2'=> 'Two'
						)
					)
				);
				$form->set_FormInputs($inputs);
				$form->makeForm();
			?>
		</div>
	</div>
</div>
