<div class="columns eleven permission_div">
	
	<div class="permission_div_header">
		<h2>Permission Levels <h6>Click To Open </h6></h2>
	</div>
	
	
	<div class="permission_div_body">
		<div>
			<h3>Top Levels</h3>
		</div>
		<div class="perms_access">
			<!-- Access -->
			<p>Access Level</p>
			
			<div>
				<label for="radio_admin">Admin</label>
				<input id="radio_admin" type="radio" name="access" class="radio" value="1"  <?php if($user_access == '1'){ echo 'checked'; } ?>>			
				
				<label for="radio_user">User</label>
				<input id="radio_user" type="radio" name="access" class="radio" value="2" <?php if($user_access == '2'){ echo 'checked'; } ?>><br/><br/>
			</div>
			<!-- Access -->
		</div>
		
		<div class="perms <?php if($user_custom_perms['config'] == 1){ echo 'checkbox_perms_bg_green'; }else{echo 'checkbox_perms_bg_red';} ?>">
			<!-- Config Access -->
			<p>Config Access</p>
			
			<div>
				<label for="checkbox_config_t"><?php if($user_custom_perms['config'] == 1){ echo 'Can Access'; }else{echo 'Cannot Access';} ?></label>
				<input id="checkbox_config_t" type="checkbox" name="checkbox_config" class="checkbox_perms" value="1"  <?php if($user_custom_perms['config'] == 1){ echo 'checked'; } ?>>
			</div>
			<!-- Config Access -->
		</div>
		
		<div class="perms <?php if($user_custom_perms['pages'] == 1){ echo 'checkbox_perms_bg_green'; }else{echo 'checkbox_perms_bg_red';} ?>">
			<!-- Pages Access -->
			<p>Pages Access</p>
			
			<div>
				<label for="checkbox_pages_t"><?php if($user_custom_perms['pages'] == 1){ echo 'Can Access'; }else{echo 'Cannot Access';} ?></label>
				<input id="checkbox_pages_t" type="checkbox" name="checkbox_pages" class="checkbox_perms" value="1"  <?php if($user_custom_perms['pages'] == 1){ echo 'checked'; } ?>>
			</div>
			<!-- Pages Access -->			
		</div>
		
		<div class="perms border-bottom <?php if($user_custom_perms['users'] == 1){ echo 'checkbox_perms_bg_green'; }else{echo 'checkbox_perms_bg_red';} ?>">
			<!-- user Access -->
			<p>Users Access</p>
			
			<div>
				<label for="checkbox_users_t"><?php if($user_custom_perms['users'] == 1){ echo 'Can Access'; }else{echo 'Cannot Access';} ?></label>
				<input id="checkbox_users_t" type="checkbox" name="checkbox_users" class="checkbox_perms" value="1"  <?php if($user_custom_perms['users'] == 1){ echo 'checked'; } ?>>
			</div>
			<!-- user Access -->			
		</div>	
		
		<div>
			<h3>Assets Access</h3>
		</div>
		
		<div class="perms <?php if($user_custom_perms['assets']['top_level'] == 1){ echo 'checkbox_perms_bg_green'; }else{echo 'checkbox_perms_bg_red';} ?>">
			<!-- Assets Top Level Access -->
			<p>Top Level</p>
			
			<div>
				<label for="checkbox_assets_tl_t"><?php if($user_custom_perms['assets']['top_level'] == 1){ echo 'Can Access'; }else{echo 'Cannot Access';} ?></label>
				<input id="checkbox_assets_tl_t" type="checkbox" name="checkbox_assets_tl" class="checkbox_perms" value="1"  <?php if($user_custom_perms['assets']['top_level'] == 1){ echo 'checked'; } ?>>
			</div>
			<!-- Assets Top Level Access -->	
		</div>
		
		<div class="perms <?php if($user_custom_perms['assets']['upload'] == 1){ echo 'checkbox_perms_bg_green'; }else{echo 'checkbox_perms_bg_red';} ?>">
			<!-- Upload Access -->
			<p>Upload Access</p>
			
			<div>
				<label for="checkbox_assets_upload_t"><?php if($user_custom_perms['assets']['upload'] == 1){ echo 'Can Access'; }else{echo 'Cannot Access';} ?></label>
				<input id="checkbox_assets_upload_t" type="checkbox" name="checkbox_assets_upload" class="checkbox_perms" value="1"  <?php if($user_custom_perms['assets']['upload'] == 1){ echo 'checked'; } ?>>
			</div>
			<!-- Upload Access -->				
		</div>
		
		<div class="perms <?php if($user_custom_perms['assets']['uploaded'] == 1){ echo 'checkbox_perms_bg_green'; }else{echo 'checkbox_perms_bg_red';} ?>">
			<!-- Uploaded Access -->
			<p>Uploaded Access</p>
			
			<div>
				<label for="checkbox_assets_uploaded_t"><?php if($user_custom_perms['assets']['uploaded'] == 1){ echo 'Can Access'; }else{echo 'Cannot Access';} ?></label>
				<input id="checkbox_assets_uploaded_t" type="checkbox" name="checkbox_assets_uploaded" class="checkbox_perms" value="1"  <?php if($user_custom_perms['assets']['uploaded'] == 1){ echo 'checked'; } ?>>
			</div>
			<!-- Uploaded Access -->	
		</div>
		
		<div class="perms <?php if($user_custom_perms['assets']['templates'] == 1){ echo 'checkbox_perms_bg_green'; }else{echo 'checkbox_perms_bg_red';} ?>">
			<!-- Templates Access -->
			<p>Templates Access</p>
			
			<div>
				<label for="checkbox_assets_templates_t"><?php if($user_custom_perms['assets']['templates'] == 1){ echo 'Can Access'; }else{echo 'Cannot Access';} ?></label>
				<input id="checkbox_assets_templates_t" type="checkbox" name="checkbox_assets_templates" class="checkbox_perms" value="1"  <?php if($user_custom_perms['assets']['templates'] == 1){ echo 'checked'; } ?>>
			</div>
			<!-- Templates Access -->		
		</div>
		
		<div class="perms <?php if($user_custom_perms['assets']['labels'] == 1){ echo 'checkbox_perms_bg_green'; }else{echo 'checkbox_perms_bg_red';} ?>">
			<!-- Labels Access -->
			<p>Labels Access</p>
			
			<div>
				<label for="checkbox_assets_labels_t"><?php if($user_custom_perms['assets']['labels'] == 1){ echo 'Can Access'; }else{echo 'Cannot Access';} ?></label>
				<input id="checkbox_assets_labels_t" type="checkbox" name="checkbox_assets_labels" class="checkbox_perms" value="1"  <?php if($user_custom_perms['assets']['labels'] == 1){ echo 'checked'; } ?>>
			</div>
			<!-- Labels Access -->		
		</div>
	</div>
	
</div>	
