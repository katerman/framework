$(document).ready(function(){
	var body = $('body');
	var nav_tab = window.location.hash;
	
	function navdropdowns(){
		var fb = $('#nav > ul > li'); //parents
		var allBtns = $('#nav .dropdownBtn li').removeClass('bottomBtnBorder');
		var lastBtn = $('#nav .dropdownBtn li').last().addClass('bottomBtnBorder');
		
		
		fb.click(function(e){
			$(this).next('li').stop().slideToggle();
			
			allBtns;
			lastBtn;
	
		});
		
		$('#nav').find("a[href*='"+nav_tab+"']").click();
		
	}
	

	function content(){
		var content = $('.edit_content');
		var overlay = $('#overlay');
		var add_content = $('.add_content');
		var KEYCODE_ESC = 27;     
		var x = '0'; 
		var update = $('#update_crud');
		var form = $('#content_form');
			
		overlay.on('click', '.form_close', function() { 
	        overlay.hide();
			x = '0';
        });      
        
		content.click(function(e){ //edit content
			overlay.toggle();
			form.children('h1').text('Edit Content');			
			values = ['content_order','content_area','content_name','content_id'];
			update.val('edit');
			
			data = new Object;
			
			for(var i = 0; i <values.length; i++) {
				data[values[i]] = $(this).parents('tr').children('.'+values[i]).text();
				$('#content_form '+'#'+values[i]).val(data[values[i]]);

			}
			
			var content = $(this).parents('tr').children('.content');
						
			if (content.html().match(/<(\w+)((?:\s+\w+(?:\s*=\s*(?:(?:"[^"]*")|(?:'[^']*')|[^>\s]+))?)*)\s*(\/?)>/)) {
				data['content'] = content.html();	
			}else{
				data['content'] = content.text();			
			}
			
			//$('#content').val(data['content']);
			$('.jqte_editor').text(data['content']);
						
			//document.getElementById('content').innerHTML = data['content'];
			//console.log(data['content']);

			
			data['token'] = $(this).parents('tr').children('#content_token').text();
			$('#content_token').val(data['token']);
			
			//console.log(data);
			
			if(x === '0'){
				overlay.append(form);
				x++;
			}
	        
			e.preventDefault();
			
		});
		
		add_content.click(function(e){
			overlay.toggle();
			values = ['content_order','content','content_area','content_name','content_id'];
			update.val('add');
			
			data = new Object;
			
			for(var i = 0; i <values.length; i++) {
				$('#content_form '+'#'+values[i]).val('');

			}

			
			form.children('h1').text('Add Content');			
			data = new Object;
			
			
			data['token'] = $('table #content_token').first().text();
			$('#content_token').val(data['token']);
			
			//console.log(data);
			
			if(x === '0'){
				overlay.append(form);
				x++;
			}
	        
			e.preventDefault();

		});
		
		$(document).keyup(function(e) { //clicking escape will hide the overlay 
	        if (e.keyCode == KEYCODE_ESC) {
				overlay.hide();
				x = '0';
	        } 
		});
		

		
		//overlay.click(td);
	}
		

	function templates(){
		var template_edit = $('.edit_template');
		var overlay = $('#overlay');
		var add_template = $('.add_template');
		var KEYCODE_ESC = 27;     
		var x = '0'; 
		var update = $('#update_crud');
		var form = $('#template_form');

		overlay.on('click', '.form_close', function() { 
	        overlay.hide();
			x = '0';
        });      
        
		template_edit.click(function(e){
			overlay.toggle();
			form.children('h1').text('Edit Template');			
			values = ['template_name','id'];
			update.val('edit');
			
			data = new Object;
			
			for(var i = 0; i <values.length; i++) {
				data[values[i]] = $(this).parents('tr').children('.'+values[i]).text();
				$('#template_form '+'#'+values[i]).val(data[values[i]]);
			} 
			

			data['template_type'] = $(this).parents('tr').children('.template_type').text();
			
			var type = data['template_type'];
			if(type === 'page'){
				type = '0';
			}else{
				type = '1';
			}
			
			$('#template_form #template_type').val(type);
			
			//console.log(data['template_type']);
			
			data['token'] = $('p#token').text();
			$('#template_token').val(data['token']);
			
			//console.log(data);
			
			if(x === '0'){
				overlay.append(form);
				x++;
			}
	        
			e.preventDefault();
			
		});
		
		add_template.click(function(e){
			overlay.toggle();
			values = ['template_name' ,'id'];
			update.val('add');
			
			data = new Object;
			
			for(var i = 0; i <values.length; i++) {
				$('#template_form '+'#'+values[i]).val('');
			}

			
			form.children('h1').text('Add Template');			
			data = new Object;
			
			$('#template_form #template_type').val('0');
				
			data['token'] = $('p#token').text();
			$('#template_token').val(data['token']);
			
			//console.log(data);
			
			if(x === '0'){
				overlay.append(form);
				x++;
			}
	        
			e.preventDefault();

		});
		
		$(document).keyup(function(e) { //clicking escape will hide the overlay 
	        if (e.keyCode == KEYCODE_ESC) {
				overlay.hide();
				x = '0';
	        } 
		});
		

		
		
	}//templates

	function labels(){
		var label_edit = $('.edit_labels');
		var overlay = $('#overlay');
		var add_label = $('.add_labels');
		var KEYCODE_ESC = 27;     
		var x = '0'; 
		var update = $('#update_crud');
		var form = $('#label_form');

		overlay.on('click', '.form_close', function() { 
	        overlay.hide();
			x = '0';
        });      
        
		label_edit.click(function(e){ //=================== EDIT ===================
			overlay.toggle();
			form.children('h1').text('Edit Label');			
			values = ['label_name','id', 'label_content'];
			update.val('edit');
			
			data = new Object;
			
			for(var i = 0; i <values.length; i++) {
				data[values[i]] = $(this).parents('tr').children('.'+values[i]).text();
				$('#label_form '+'#'+values[i]).val(data[values[i]]);
			} 
			
			data['token'] = $('p#token').text();
			$('#label_token').val(data['token']);
			
			//console.log(data);
			
			if(x === '0'){
				overlay.append(form);
				x++;
			}
	        
			e.preventDefault();
			
		});
		
		add_label.click(function(e){ //=================== ADD ===================
			overlay.toggle();
			values = ['template_name' ,'template_content'];
			update.val('add');
			
			data = new Object;
			
			for(var i = 0; i <values.length; i++) {
				$('#template_form '+'#'+values[i]).val('');
			}

			
			form.children('h1').text('Add Label');			
			data = new Object;
							
			form.children('#label_name').val('');		
			form.children('#label_content').val('');		
					
							
			data['token'] = $('p#token').text();
			$('#label_token').val(data['token']);
			
			//console.log(data);
			
			if(x === '0'){
				overlay.append(form);
				x++;
			}
	        
			e.preventDefault();

		});
		
		$(document).keyup(function(e) { //clicking escape will hide the overlay 
	        if (e.keyCode == KEYCODE_ESC) {
				overlay.hide();
				x = '0';
	        } 
		});
		

		
		
	}//labels

	function regexSearch(v, s){
		$(s).keyup(function() {
			$rows = v;
		    var val =$.trim($(this).val()),
		        reg = RegExp(val, 'i'),
		        text;
		
		    $rows.show().filter(function() {
		        text = $(this).text().replace(/\s+/g, ' ');
		        return !reg.test(text);
		    }).hide();
		});
	}
	
	// inDomain & AddTarget = allows external links to automatically be opened in new windows, all self site links are opened in the same window
	function inDomain(url) {
	    var match = url.match(/^([^:\/?#]+:)?(?:\/\/([^\/?#]*))?([^?#]+)?(\?[^#]*)?(#.*)?/);
	    if (typeof match[2] === "string" && match[2].length > 0 && match[2].replace(new RegExp(":("+{"http:":80,"https:":443}[location.protocol]+")?$"), "") !== location.host) return false;
	    return true;
	}

	function AddTarget(){ // get each anchor check if it doesnt have a target and give it 

		$('a').each(function(i,a) {
			var target = $(a).attr('target');
			var $a = $(a);
			if(typeof target === 'undefined' || target === false){  
			    $a.attr('target', (inDomain( $a.attr('href') )) ? '_self' :'_blank');       			
			} 
		});


	}	
	
	(function($) {
	    $.QueryString = (function(a) {
	        if (a == "") return {};
	        var b = {};
	        for (var i = 0; i < a.length; ++i)
	        {
	            var p=a[i].split('=');
	            if (p.length != 2) continue;
	            b[p[0]] = decodeURIComponent(p[1].replace(/\+/g, " "));
	        }
	        return b;
	    })(window.location.search.substr(1).split('&'))
	})(jQuery);

		
	function init(){
		AddTarget();
		navdropdowns();
		content();
		templates();
		labels();
		
		//var tables = $('table').addClass('responsive'); // for responsive tables.. yay
		
		//$('#page_template').val($('.page_template').text());
		//$('#parent_page').val($('.sub_page').text());

		regexSearch($('.search_table .data'), $('.search'));

		
		if($.QueryString["type"] == 'edit_page' || $.QueryString["type"] == 'edit_user'){
			$('.html-code').jqte();
		}

	}
	
	init();
});