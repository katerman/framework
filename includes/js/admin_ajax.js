$(document).ready(function(){
	var body = $('body');

	function insertParam(key, value) {
		 key = encodeURI(key); value = encodeURI(value);
	
		 var kvp = document.location.search.substr(1).split('&');
	
		 var i=kvp.length; var x; while(i--) 
		 {
			 x = kvp[i].split('=');
	
			 if (x[0]==key)
			 {
				 x[1] = value;
				 kvp[i] = x.join('=');
				 break;
			 }
		 }
	
		 if(i<0) {kvp[kvp.length] = [key,value].join('=');}
	
		 //this will reload the page, it's likely better to store this until finished
		 document.location.search = kvp.join('&'); 
	}		
	
	var QueryString = function () {
		// This function is anonymous, is executed immediately and 
		// the return value is assigned to QueryString!
		var query_string = {};
		var query = window.location.search.substring(1);
		var vars = query.split("&");
		for (var i=0;i<vars.length;i++) {
			var pair = vars[i].split("=");
			// If first entry with this name
			if (typeof query_string[pair[0]] === "undefined") {
				query_string[pair[0]] = pair[1];
				// If second entry with this name
			} else if (typeof query_string[pair[0]] === "string") {
				var arr = [ query_string[pair[0]], pair[1] ];
				query_string[pair[0]] = arr;
				// If third or later entry with this name
			} else {
				query_string[pair[0]].push(pair[1]);
			}
		} 
		return query_string;
	} ();	
	
	function login_validation(){		
         $("#login_form").validate({				     
            submitHandler: function(form) {                
				$(form).ajaxSubmit({
						url:"index.php",
						data: $(this).serialize(),
						type:"POST",
						timeout: 2000,
						clearForm: false,
						cache: false,
						success: function(){
							//console.log('success');
							
						},
						error: function(x, status, error) {
							//console.log('Error======');
								
							//console.log('jqXHR' + x);
							//console.log('text status' + status);
							//console.log('error thrown' + error);
							
						},
						statusCode: {
							200: function() {
								//console.log('200');
								var feedb_text = $('.feedback_text');
								feedb_text.show().css('color', 'green').text('Logging in..');	
								location.reload();								
								
							},
							403:function(){
								//console.log('403');
								var feedb_text = $('.feedback_text');
								feedb_text.show().css('color', 'red').text('Username/Password Wrong, or no Access.');								
							}
						}										
				});
			}
        }); 	
	}// end of login_validation	
	
	
	function edit_validation(){
         $("#edit_form").validate({
            submitHandler: function(form) {
            
		        
				var update_type = $('#update_type').val(); // need to grab the update type to send the correct data

				if(update_type === 'pages'){ //if the update type is pages
				
		       		values = ['page_name','page_meta_title','page_meta_keyword','page_group','pages_id','page_order','page_url','token','on_nav'];
			   		
					data = new Object; //make data object to hold data passed through post
				
				    for(var i = 0; i <values.length; i++) {
				        data[values[i]] = $('#'+values[i]).val();
				        // == data[page_name] = $('#page_name').val();
				    }
				    
				    data['page_template'] = $('#page_template option:selected').val(); 
				    data['parent_page'] = $('#parent_page option:selected').val(); 
				   
				}else if(update_type === 'user'){ // if user
					var user_id = $('#user_id').val();
					var user_name = $('#user_uname').val();	
					var pass_word = $('#user_pass').val();	
					var full_name = $('#user_fullname').val();	
					var user_comments = $('#user_comments').val();	
					var access = $('#edit_page_form input[name="access"]:checked').val(); 
					var update_type = $('#update_type').val();
				 	var token = $('#token').val();
				 
				 	/* list of perms */
					var perm_config = $('#edit_page_form input[name="checkbox_config"]'); 
					if (perm_config.is(":checked")){ perm_config = 1; }else{ perm_config = 0; }
					
					var perm_pages = $('#edit_page_form input[name="checkbox_pages"]'); 
					if (perm_pages.is(":checked")){ perm_pages = 1; }else{ perm_pages = 0; }
					
					var perm_toplevel = $('#edit_page_form input[name="checkbox_assets_tl"]'); 
					if (perm_toplevel.is(":checked")){ perm_toplevel = 1; }else{ perm_toplevel = 0; }
					
					var perm_upload = $('#edit_page_form input[name="checkbox_assets_upload"]'); 
					if (perm_upload.is(":checked")){ perm_upload = 1; }else{ perm_upload = 0; }
					
					var perm_uploaded = $('#edit_page_form input[name="checkbox_assets_uploaded"]'); 
					if (perm_uploaded.is(":checked")){ perm_uploaded = 1; }else{ perm_uploaded = 0; }
					
					var perm_templates = $('#edit_page_form input[name="checkbox_assets_templates"]'); 
					if (perm_templates.is(":checked")){ perm_templates = 1; }else{ perm_templates = 0; }
					
					var perm_labels = $('#edit_page_form input[name="checkbox_assets_labels"]'); 
					if (perm_labels.is(":checked")){ perm_labels = 1; }else{ perm_labels = 0; }
					
					var perm_users = $('#edit_page_form input[name="checkbox_users"]'); 
					if (perm_users.is(":checked")){ perm_users = 1; }else{ perm_users = 0; }

					data = new Object; //make data object to hold data passed through post
					
					data['user_id'] = user_id;
					data['user_uname'] = user_name;
					data['user_pass'] = pass_word;
					data['user_fullname'] = full_name;
					data['user_comments'] = user_comments;
					data['user_access'] = access;
					data['token'] = token;	
					data['update_type'] = update_type;
					
					/*perms*/
					data['perm_config'] = perm_config;
					data['perm_pages'] = perm_pages;
					data['perm_users'] = perm_users;
					data['perm_toplevel'] = perm_toplevel;
					data['perm_upload'] = perm_upload;
					data['perm_uploaded'] = perm_uploaded;
					data['perm_templates'] = perm_templates;
					data['perm_labels'] = perm_labels;
					
					
					
				}else if(update_type === 'config'){
					
		       		values = ['config_id','extra_css','extra_js','site_name','token', 'global_logo'];
		
					data = new Object; //make data object to hold data passed through post
				
				    for(var i = 0; i <values.length; i++) {
				        data[values[i]] = $('#'+values[i]).val();
				        // == data[page_name] = $('#page_name').val();
				    }
				    
				    //data['global_logo'] = $('select.logo_dropdown option:selected').val(); // Revet this to use a dropdown method

				}
								
				$(form).ajaxSubmit({
						url:"scripts/update.php",
						type:"POST",
						data: data,
						timeout: 2000,
						clearForm: false,
						cache: false,
						success: function(){
						//console.log('success');

							var feedb_text = $('.feedback_text');
							feedb_text.show().css('color', 'green').text('Updated!');
							location.reload();
						},
						error: function(x,t,m){
						//console.log('failure');

							if(t==="timeout"){
								var feedb_text = $('.feedback_text');
								feedb_text.show().css('color', 'red').text('Something has gone wrong..');
								
							}
						}
				});
			}
        }); 	
	}// end of edit_validation

	function delete_validation(){	
		data = new Object;
		
		var d_click = $('.delete').click(function(e) {
			$(this).parent().prepend('<div class="yn-overlay"><div class="yesBtn"></div> <div class="noBtn"></div></div>');

			body.on('click', '.yesBtn', function(){
				$(this).parents('form').submit();	
				$('.yn-overlay').remove();		
			});
			
			body.on('click', '.noBtn', function(){
				$(this).parent().remove();		
			});
			
				
				var update_type = $(this).siblings('#type').val();
				var id = $(this).siblings('#id').val();   
				var db_id = $(this).siblings('#db_id').val();
				
				if(update_type === 'templates' || update_type === 'labels'){
					var auth_token = $('p#token').text();     
				}else{
					var auth_token = $('#token').val();     
				}
				
				//console.log(auth_token);
				//object to hold info
				data['type'] = update_type;
				data['id'] = id;
				data['token'] = auth_token;
				data['db_id'] = db_id;
				
				e.preventDefault();
		});
		
		$("#delete_form").validate({				     
		    submitHandler: function(form) {                
										
				$(form).ajaxSubmit({
						url:"scripts/delete.php",
						type:"POST",
						data: data,
						timeout: 2000,
						clearForm: true,
						cache: false,
						success: function(){
							location.reload();
						},
						error: function(x,t,m){
							if(t==="timeout"){
								//console.log('timeout');
								
							}
							
							//console.log( ' bad: ' + x + m);
						}										
				});
			}
		}); 	
	}// end of delete_validation	

	function add_validation(){	
	
		$('#user_uname').bind('input', function(){

			var u = $(this).val();			
			var data = {
				"username": u,
			};			
		
			$('.error-taken').remove();
			
			$.ajax({
				type: "POST",
				dataType: "json", 
				url: "scripts/check_user.php",
				data: data,
				clearform: false,
				success: function(data) {
					//console.log('Data: '+ data.length);
					if(data.length != 0){
						$('input.btn').attr('disabled', 'true');
						$('#user_uname').after('<label for="user_uname" class="error-taken">Username Taken</label>');
					}else{
						$('input.btn').removeAttr('disabled');
					}
				},
				error: function(jxhr,ts,et){
					//console.log(JSON.stringify(jxhr) + '  ' + ts + '  ' + et);
				}
			}).done(function() {
				//console.log('done');
			});//ajax
			
		});	//change
	
         $("#add_form").validate({   
            submitHandler: function(form) {
            			 	
				var update_type = $('#update_type').val(); // need to grab the update type to send the correct data
				var added = '';
				data = new Object; //make data object to hold data passed through post

				if(update_type === 'pages'){ //if the update type is pages
				
					values = ['page_name','page_meta_title','page_meta_keyword','page_group','pages_id','page_order','page_url','token', 'update_type'];
						
				    for(var i = 0; i <values.length; i++) {
				        data[values[i]] = $('#'+values[i]).val();
				        // == data[page_name] = $('#page_name').val();
				    }
				    
				    data['page_template'] = $('#page_template option:selected').val(); 
				    data['parent_page'] = $('#parent_page option:selected').val(); 
				    data['on_nav'] = $('#add_form #on_nav:checked').val();
					
					if(data['on_nav'] != '1') {
						data['on_nav'] = '0';
					}
					
					var added = data['page_name'];
					
				}else if(update_type === 'user'){ // if user
					var user_name = $('#user_uname').val();	
					var pass_word = $('#user_pass').val();	
					var full_name = $('#user_fullname').val();	
					var access = $('#add_page_form input[type="radio"]:checked').val(); 
					var update_type = $('#update_type').val();
				 	var token = $('#token').val();
				 	
							
					data['user_uname'] = user_name;
					data['user_pass'] = pass_word;
					data['user_fullname'] = full_name;
					data['user_access'] = access;
					data['token'] = token;	
					data['update_type'] = update_type;
					
					var added = data['user_uname'];	
				}
				
            
				$(form).ajaxSubmit({
						url:"scripts/add.php",
						type:"POST",
						data: data,
						timeout: 2000,
						clearForm: false,
						cache: false,
						success: function(){
							var feedb_text = $('.feedback_text');
							feedb_text.show().css('color', 'green').text('Added: ' + added + ' !');						
							//location.reload();
							//console.log(data);
						},
						error: function(x,t,m){
							if(t==="timeout"){
								var feedb_text = $('.feedback_text');
								feedb_text.show().css('color', 'red').text('Something has gone wrong..');
								
							}
						}
				});
			}
        }); 	
	}// end of add_validation
		
		function content_validation(){
			$("#content_form").validate({   
				submitHandler: function(form) {
				
				
					var update_type = $('#update_type').val(); // need to grab the update type to send the correct data
					var update_crud = $('#update_crud').val(); // since we can edit or add using the same form we have to figure out which crud type we're using in that moment
					var url = '';
					var feedback = '';
					data = new Object; //make data object to hold data passed through post
						
					if(update_type === 'content' && update_crud == 'edit'){
						values = ['content_order','content','content_area','content_name','content_id','token'];
										
						for(var i = 0; i <values.length; i++) {
							data[values[i]] = $('#'+values[i]).val();
							// == data[page_name] = $('#page_name').val();
						}
						
						url = "scripts/update.php";
						feedback = 'Updated!';
						
					}else if(update_type === 'content' && update_crud == 'add'){
										
						values = ['content_order','content','content_area','content_name','token', 'content_page_id'];
										
						for(var i = 0; i <values.length; i++) {
							data[values[i]] = $('#'+values[i]).val();
							// == data[page_name] = $('#page_name').val();
						}
						
						url = "scripts/add.php";
						feedback = 'Added!';
					}
				
				
					$(form).ajaxSubmit({
							url:url,
							type:"POST",
							data: data,
							timeout: 2000,
							clearForm: false,
							cache: false,
							success: function(){
							//console.log('success');
								location.reload();
								var feedb_text = $('.feedback_content');
								feedb_text.show().css('color', 'green').text(feedback);
								
							},
							error: function(x,t,m){
							//console.log('failure: ' + '			x: ' + JSON.stringify(x) + '			t: ' + t +'			m: ' +m);
	
								if(t==="timeout"){
									var feedb_text = $('.feedback_content');
									feedb_text.show().css('color', 'red').text('Something has gone wrong..');
									
								}
								
							}
					});
				}
        }); 	
	}// end of content_validation

		function template_validation(){
			$("#template_form").validate({   
				submitHandler: function(form) {
				
				
					var update_type = $('#update_type').val(); // need to grab the update type to send the correct data
					var update_crud = $('#update_crud').val(); // since we can edit or add using the same form we have to figure out which crud type we're using in that moment
					var url = '';
					var feedback = '';
					data = new Object; //make data object to hold data passed through post
					data['template_type'] = $('#template_type option:selected').val();
					data['token'] = $('p#token').text();
					//console.log(data['token']);
						
					if(update_type === 'template' && update_crud == 'edit'){
						values = ['template_name','id'];
										
						for(var i = 0; i <values.length; i++) {
							data[values[i]] = $('#'+values[i]).val();
						}
						
						url = "scripts/update.php";
						feedback = 'Updated!';
						
					}else if(update_type === 'template' && update_crud == 'add'){
										
						values = ['template_name'];
										
						for(var i = 0; i <values.length; i++) {
							data[values[i]] = $('#'+values[i]).val();
						}
						
						url = "scripts/add.php";
						feedback = 'Added!';
					}
				
				
					$(form).ajaxSubmit({
							url:url,
							type:"POST",
							data: data,
							timeout: 2000,
							clearForm: false,
							cache: false,
							success: function(){
							//console.log('success');
							
								var feedb_text = $('.feedback_content');
								feedb_text.show().css('color', 'green').text(feedback);
								location.reload();
							},
							error: function(x,t,m){
							//console.log('failure: ' + '			x: ' + JSON.stringify(x) + '			t: ' + t +'			m: ' +m);
	
								if(t==="timeout"){
									var feedb_text = $('.feedback_content');
									feedb_text.show().css('color', 'red').text('Something has gone wrong..');
									
								}
								
							}
					});
				}
        }); 	
	}// end of template_validation
	
	
	
		function labels_validation(){
			$("#label_form").validate({   
				submitHandler: function(form) {
				
				
					var update_type = $('#update_type').val(); // need to grab the update type to send the correct data
					var update_crud = $('#update_crud').val(); // since we can edit or add using the same form we have to figure out which crud type we're using in that moment
					var url = '';
					var feedback = '';
					data = new Object; //make data object to hold data passed through post
					data['token'] = $('p#token').text();
					//console.log(data['token']);
											
					if(update_type === 'labels' && update_crud === 'edit'){
						values = ['label_name','label_content','id'];
										
						for(var i = 0; i <values.length; i++) {
							data[values[i]] = $('#'+values[i]).val();
						}
												
						url = "scripts/update.php";
						feedback = 'Updated!';
						
					}else if(update_type === 'labels' && update_crud === 'add'){
							
									
						values = ['label_name','label_content'];
										
						for(var i = 0; i <values.length; i++) {
							data[values[i]] = $('#'+values[i]).val();
						}
												
						url = "scripts/add.php";
						feedback = 'Added!';
					}
				
				
					$(form).ajaxSubmit({
							url:url,
							type:"POST",
							data: data,
							timeout: 2000,
							clearForm: false,
							cache: false,
							success: function(){
							//console.log('success');
							
								var feedb_text = $('.feedback_content');
								feedb_text.show().css('color', 'green').text(feedback);
								location.reload();
							},
							error: function(x,t,m){
							//console.log('failure: ' + '			x: ' + JSON.stringify(x) + '			t: ' + t +'			m: ' +m);
	
								if(t==="timeout"){
									var feedb_text = $('.feedback_content');
									feedb_text.show().css('color', 'red').text('Something has gone wrong..');
									
								}
								
							}
					});
				}
        }); 	
	}// end of template_validation

	function delete_image_validation(){	
		data = new Object;
		
		var d_click = $('.delete_btn').click(function(e) {
			$(this).parent().prepend('<div class="yn-overlay"><div class="yesBtn"></div> <div class="noBtn"></div></div>');

			body.on('click', '.yesBtn', function(){
				form = $(this).parents('form');
				$('.yn-overlay').remove();		
				delete_which_image(form);
				form.submit();	

			});
			
			body.on('click', '.noBtn', function(){
				$(this).parent().remove();		
			});
			
				
				var image_value = $(this).siblings('.image_value').val();
				var auth_token = $('#uploaded #token').text();     
				
				
				//object to hold info
				data['image_value'] = image_value;
				data['token'] = auth_token;
			
				
				e.preventDefault();
		});
		
		function delete_which_image(f){
			
			f.validate({				     
			    submitHandler: function(form) {                
											
					$(form).ajaxSubmit({
							url:"scripts/delete_image.php",
							type:"POST",
							data: data,
							timeout: 2000,
							clearForm: true,
							cache: false,
							success: function(){
								location.reload();
								$('.result').text(data['image_value']+' was deleted');
							},
							error: function(x,t,m){
								if(t==="timeout"){
									//console.log('timeout');
									
								}
								
								//console.log( ' bad: ' + x + m);
							}										
					});
				}
			}); 
							
		}
		
		
	}// end of delete_image_validation	

	function rename_image_validation(){	
		data = new Object;
		start_names = new Object;
		new_names = new Object;
		
		var form;
		var input = $('.new_name');
		var r_click = $('.rename');
		var auth_token = $('#uploaded #token').text();
		
		r_click.click(function(e) {
			
			data['old_name'] = $(this).siblings('.old_name').val();
			data['new_name'] = $(this).siblings('.new_name').val();
			data['token'] = auth_token;
			
			form = $(this).parents('form');		
			
			rename_which_image(form);
			form.submit();	
			$(this).hide();
			
			e.preventDefault();		
		});
		
		
		
		//get each image and make two data objects to contain every name.
		$.each(input,function(){
			start_names[$(this).parent().attr('class')] = $(this).val(); //these will never change and will always be the starting name on page load
			new_names[$(this).parent().attr('class')] = $(this).val(); //this will change with each keyup, and be compaired to the initial start_names obj
		});
		
		//console.log(start_names);
		
		input.keyup(function(){
			
			new_names[$(this).parent().attr('class')] = $(this).val();
			
			if(start_names[$(this).parent().attr('class')] == new_names[$(this).parent().attr('class')]){ //if the name is the same as before hide the rename checkbox
				$(this).siblings('.rename').hide();					
			}else{
				$(this).siblings('.rename').show(); //if its different show it
			}
		});

		
		function rename_which_image(f){
			
			f.validate({				     
			    submitHandler: function(form) {                
											
					$(form).ajaxSubmit({
							url:"scripts/rename_image.php",
							type:"POST",
							data: data,
							timeout: 2000,
							clearForm: false,
							cache: false,
							success: function(){
								//console.log(data);
								//location.reload();
							},
							error: function(x,t,m){
								if(t==="timeout"){
									//console.log('timeout');
									
								}
								
								//console.log( ' bad: ' + x + m);
							}										
					});
				}
			}); 
							
		}
		
		
	}// end of rename_image_validation	

	function log_purge(){
		var data = {
			"purge": 1,
			"token": $('.token').val()
		};
	
		$('#purge').on('click', function(){
			$.ajax({
				type: "POST",
				dataType: "json", 
				url: "scripts/log.php",
				data: data,
				clearform: true,
				success: function(data) {
					//console.log('Data: '+ data.length);
				},
				error: function(jxhr,ts,et){
					//console.log(JSON.stringify(jxhr) + '  ' + ts + '  ' + et);
				}
			}).done(function() {
				location.reload();
			});//ajax
		});
	}//log purge

	function pager(){
		var amount = $('.pager-amount').val();
		var page = parseInt(QueryString.page);
		var max = $('.pager-max').text();
			
		$('.pager-amount').change(function(){
			var amount = $(this).val();
			insertParam('amt',amount);
			insertParam('page',1);
		});//pager amount change - dropdown
		
		$('.pager-forward').click(function(e){
					
			if(page + 1 > parseInt(max)){
				insertParam('page',1);
			}else{
				insertParam('page', parseInt(page)+1);
			}
			
		});
		
		$('.pager-back').click(function(e){
					
			if(page - 1 == 0){
				insertParam('page',parseInt(max));
			}else{
				insertParam('page', parseInt(page)-1);
			}
			
		});		
		
		$('.pager-input').keydown(function(e){
		
			if(e.which == 13){ // fire on enter, then check if the value entered is higher than our max, if it is  bring them to the last page. If not bring them to the page they want
				if($(this).val() > max){
					insertParam('page',max);
				}else{
					insertParam('page',$(this).val());
				}
			}
		});
		
	}//pager 


	function init(){
		edit_validation();
		login_validation();
		delete_validation();
		add_validation();
		content_validation();
		template_validation();
		labels_validation();
		delete_image_validation(); //created a new function for deleting images, it works in a seperate way than the regular delete, and dont want to over saturate the orginal function.
		rename_image_validation();
		
		log_purge();
		
		pager();
		// the amount of seperate functions is silly, but makes it much easier to seperate things out.
	}
	
	init();	
	
});