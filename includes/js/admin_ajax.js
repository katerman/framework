$(document).ready(function(){
	var body = $('body');
	
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
					var access = $('#edit_page_form input[type="radio"]:checked').val(); 
					var update_type = $('#update_type').val();
				 	var token = $('#token').val();
				 	
					data = new Object; //make data object to hold data passed through post
					
					data['user_id'] = user_id;
					data['user_uname'] = user_name;
					data['user_pass'] = pass_word;
					data['user_fullname'] = full_name;
					data['user_comments'] = user_comments;
					data['user_access'] = access;
					data['token'] = token;	
					data['update_type'] = update_type;
					
				}else if(update_type === 'config'){
					
		       		values = ['config_id','extra_css','extra_js','site_name','token'];
		
					data = new Object; //make data object to hold data passed through post
				
				    for(var i = 0; i <values.length; i++) {
				        data[values[i]] = $('#'+values[i]).val();
				        // == data[page_name] = $('#page_name').val();
				    }
				    
				    data['global_logo'] = $('select.logo_dropdown option:selected').val();

				}
								
				$(form).ajaxSubmit({
						url:"update.php",
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
				
				console.log(auth_token);
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
						url:"delete.php",
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
						url:"add.php",
						type:"POST",
						data: data,
						timeout: 2000,
						clearForm: false,
						cache: false,
						success: function(){
							var feedb_text = $('.feedback_text');
							feedb_text.show().css('color', 'green').text('Added: ' + added + ' !');						
							//location.reload();
							console.log(data);
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
						
						url = "update.php";
						feedback = 'Updated!';
						
					}else if(update_type === 'content' && update_crud == 'add'){
										
						values = ['content_order','content','content_area','content_name','token', 'content_page_id'];
										
						for(var i = 0; i <values.length; i++) {
							data[values[i]] = $('#'+values[i]).val();
							// == data[page_name] = $('#page_name').val();
						}
						
						url = "add.php";
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
						
						url = "update.php";
						feedback = 'Updated!';
						
					}else if(update_type === 'template' && update_crud == 'add'){
										
						values = ['template_name'];
										
						for(var i = 0; i <values.length; i++) {
							data[values[i]] = $('#'+values[i]).val();
						}
						
						url = "add.php";
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
												
						url = "update.php";
						feedback = 'Updated!';
						
					}else if(update_type === 'labels' && update_crud === 'add'){
							
									
						values = ['label_name','label_content'];
										
						for(var i = 0; i <values.length; i++) {
							data[values[i]] = $('#'+values[i]).val();
						}
												
						url = "add.php";
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
							url:"delete_image.php",
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




	function init(){
		edit_validation();
		login_validation();
		delete_validation();
		add_validation();
		content_validation();
		template_validation();
		labels_validation();
		delete_image_validation();
		// the amount of seperate functions is silly, but makes it much easier to seperate things out.
	}
	
	init();	
	
});