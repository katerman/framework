$(document).ready(function() {
	var body = $('body');
	var nav_tab = window.location.hash;
	var KEYCODE_ESC = 27;
	var index = null; //index for the Nav
	var window_width = $(window).width();
	$(window).resize(function() { // Generate accurate window size
		window_width = $(window).width();
	});
	$.fn.filterByData = function(prop, val) {
		return this.filter(

		function() {
			return $(this).data(prop) == val;
		});
	}
	
	function redirect(url) { //thanks mcpdesigns @stackoverflow
		var ua    = navigator.userAgent.toLowerCase(),
		isIE      = ua.indexOf('msie') !== -1,
		version   = parseInt(ua.substr(4, 2), 10);
		
		// IE8 and lower
		if (isIE && version < 9) {
			var link = document.createElement('a');
			link.href = url;
			document.body.appendChild(link);
			link.click();
		}
		
		// All other browsers
		else { window.location.replace(url); }
	}	
	

	function insertParam(key, value) {
		key = encodeURI(key);
		value = encodeURI(value);
		var kvp = document.location.search.substr(1).split('&');
		var i = kvp.length;
		var x;
		while (i--) {
			x = kvp[i].split('=');
			if (x[0] == key) {
				x[1] = value;
				kvp[i] = x.join('=');
				break;
			}
		}
		if (i < 0) {
			kvp[kvp.length] = [key, value].join('=');
		}
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

	function navdropdowns() {
		//#nav.nav-min > ul > li:last-child > ul.dropdown > li
		$('#nav > ul > li:first-child').on('click', function(e) { // Click on top level nav
			if ($(e.target).parents('#nav').hasClass('nav-min')) { //if its in Min nav mode
				var the_right_li = $(this).parent().children('li').last();
				if (index != $(e.target).parents('ul').index()) {
					$('.nav-spot').hide();
					$('.dropdown').hide();
					$('#nav > ul > li:last').hide();
					the_right_li.show();
					the_right_li.find('.dropdown').show();
					the_right_li.find('.nav-spot').css('display', 'block');
					e.preventDefault();
					index = $(e.target).parents('ul').index();
				} else {
					$('.nav-spot').hide();
					$('.dropdown').hide();
					//$('#nav > ul > li:last').hide();
					index = null;
				}
			} else { // Regular nav mode
				target = $(e.target);
				if (target.is('a') || target.is('.fa')) {
					target = $(e.target).parent('li');
				}
				target.next('li').stop().slideToggle('200');
				target.toggleClass('navBorderBottom');
				target.toggleClass('isSlide');
				//console.log(target);
				return false;
			}
		});
		$('.search_bg form').on('click', '.search_submit', function(e) {
			if ($(this).parents('#nav').hasClass('nav-min')) {
				//console.log($(this).prev('.search_field'));
				$('body .search_submit_min').toggle();
				if (window_width <= 767) {
					$(this).prev('.search_field').show();
					$(this).removeClass('nav-min-form-close');
				} else {
					$(this).prev('.search_field').toggle();
					$(this).toggleClass('nav-min-form-close');
				}
				e.preventDefault();
			}
		});
		$('nav-min-form-close').on('click', function(e) {
			$('#nav').find('.search_submit_min').hide();
		});
		$('.search_submit_min').on('click', function(e) {
			//ajax();
			e.preventDefault();
		});
	}

	function headerdropdown() {
		var header_bar = $('#header_ul > li'),
			index = null;
		header_bar.click(function() {
			if (index === $(this).index()) {
				header_bar.find('ul').hide();
				index = null;
			} else {
				header_bar.find('ul').hide();
				$(this).find('ul').show();
				index = $(this).index();
			}
		});
	}


	function slideable() {
		slideable = $('.slideable h1');
		slideable.click(function() {
			div = $(this).siblings('div');
			div.stop().animate({
				width: "toggle",
				height: "toggle"
			});
		});
	}

	function navbarmin() {
		nav = $('#nav');
		controller = $('#nav div.retract-nav .fa');
		controller.click(function() {
			nav.toggleClass('nav-min');
			if ($(this).parents('#nav').hasClass('nav-min')) { // if the navbar is in min mode
				nav.find('.search_field').hide();
				nav.find('.nav-min-form-close').removeClass('nav-min-form-close');
				//#nav.nav-min > ul > li > ul li:last-child:hover:after { border-bottom: none;} 	
				//$('#nav.nav-min > ul > li > .dropdown li:last-child').addClass('noBottomBorder');
				nav.find('a.nav-spot').hide();
				nav.find('.dropdown').hide();
				index = null;
				$.cookie('navmin', 'true');
			} else { // if the navbar is in normal mode
				nav.find('.search_field').show();
				nav.find('.search_submit_min').hide();
				nav.find('a.nav-spot').show();
				nav.find('.dropdown').show();
				$('#nav > ul > li:last-child').hide();
				$('#nav > ul > li:first-child').removeClass('navBorderBottom');
				$('#nav > ul > li:first-child').removeClass('isSlide');
				$.cookie('navmin', 'false');
			}
		});
	}
	//for searching filtering search field

	function regexSearch(v, s, m) {
		console.log('test');
		$(s).keyup(function(e) {
			$rows = v;
			var val = $.trim($(this).val()),
				reg = RegExp(val, 'i'),
				text;
			$rows.show().filter(function(evt) {
				text = $(this).text().replace(/\s+/g, ' ');
				return !reg.test(text);
			}).hide();
			if (m == true && val === '') {
				$('.child-node').hide();
				$('.child').hide();
			}
		});
	}

	function content() {
		'use strict'
	
		var content = $('.edit_content');
		var overlay = $('#overlay');
		var add_content = $('.add_content');
		var x = 0;
		var update = $('#update_crud');
		var form = $('#content_form');

		//if we close our content window and we are in the html view get out of it because this causes issues
		function exec_html_cmd(){	
			var elems = document.getElementsByClassName('fr-bttn');
			var length = elems.length
			for(var i = 0; i < length; i++){
				var _this = $(elems[i]);
				if(_this.data('cmd') === 'html' && _this.hasClass('active')){
					console.log('true');
					$(".html-code").editable("exec", "html");	
				}
			}		
		}

		overlay.on('click', '.form_close', function() {
			exec_html_cmd();
			overlay.hide();
			x = 0;
		});
		content.click(function(e) { //edit content
			overlay.toggle();
			form.children('h1').text('Edit Content');
			var values = ['content_order', 'content_area', 'content_name', 'content_id'];
			update.val('edit');
			var data = new Object;
			for (var i = 0; i < values.length; i++) {
				data[values[i]] = $(this).parents('tr').children('.' + values[i]).text();
				$('#content_form ' + '#' + values[i]).val(data[values[i]]);
			}
			var content = $(this).parents('tr').children('.content');
			
			if (content.html().match(/<(\w+)((?:\s+\w+(?:\s*=\s*(?:(?:"[^"]*")|(?:'[^']*')|[^>\s]+))?)*)\s*(\/?)>/)) {
				data['content'] = content.html();
			} else {
				data['content'] = content.text();
			}
				
			//wyswiyg
			var editor = $('.html-code');	
			editor.editable("setHTML", data['content'], true);			

			data['token'] = $(this).parents('tr').children('.token').text();
			$('.token').val(data['token']);
			if (x === 0) {
				overlay.append(form);
				x++;
			}
			e.preventDefault();
		});
		add_content.click(function(e) {
			overlay.toggle();
			var values = ['content_order', 'content', 'content_area', 'content_name', 'content_id'];
			update.val('add');
			var data = new Object;
			for (var i = 0; i < values.length; i++) {
				$('#content_form ' + '#' + values[i]).val('');
			}
			form.children('h1').text('Add Content');
			data = new Object;
			data['token'] = $('table .token').first().text();
			$('.token').val(data['token']);

			if (x === 0) {
				overlay.append(form);
				x++;
			}
			e.preventDefault();
		});
		$(document).keyup(function(e) { //clicking escape will hide the overlay 
			if (e.keyCode == KEYCODE_ESC) {
				exec_html_cmd();
				overlay.css({display:'none'});
				x = 0;
			}
		});
		//overlay.click(td);
	}

	function templates() {
		var template_edit = $('.edit_template');
		var overlay = $('#overlay');
		var add_template = $('.add_template');
		var KEYCODE_ESC = 27;
		var x = 0;
		var update = $('#update_crud');
		var form = $('#template_form');
		overlay.on('click', '.form_close', function() {
			overlay.hide();
			x = 0;
		});
		template_edit.click(function(e) {
			overlay.toggle();
			form.children('h1').text('Edit Template');
			var values = ['template_name', 'id'];
			update.val('edit');
			data = new Object;
			for (var i = 0; i < values.length; i++) {
				data[values[i]] = $(this).parents('tr').children('.' + values[i]).text();
				$('#template_form ' + '#' + values[i]).val(data[values[i]]);
			}
			data['template_type'] = $(this).parents('tr').children('.template_type').text();
			var type = data['template_type'];
			if (type === 'page') {
				type = 0;
			} else {
				type = 1;
			}
			$('#template_form #template_type').val(type);
			//console.log(data['template_type']);
			data['token'] = $('p#token').text();
			$('#template_token').val(data['token']);
			//console.log(data);
			if (x === 0) {
				overlay.append(form);
				x++;
			}
			e.preventDefault();
		});
		add_template.click(function(e) {
			overlay.toggle();
			var values = ['template_name', 'id'];
			update.val('add');
			var data = new Object;
			for (var i = 0; i < values.length; i++) {
				$('#template_form ' + '#' + values[i]).val('');
			}
			form.children('h1').text('Add Template');
			data = new Object;
			$('#template_form #template_type').val('0');
			data['token'] = $('p#token').text();
			$('#template_token').val(data['token']);

			if (x === 0) {
				overlay.append(form);
				x++;
			}
			e.preventDefault();
		});
		$(document).keyup(function(e) { //hitting escape will hide the overlay 
			if (e.keyCode == KEYCODE_ESC) {
				overlay.hide();
				x = 0;
			}
		});
	} //templates

	function labels() {
		var label_edit = $('.edit_labels');
		var overlay = $('#overlay');
		var add_label = $('.add_labels');
		var KEYCODE_ESC = 27;
		var x = 0;
		var update = $('#update_crud');
		var form = $('#label_form');
		overlay.on('click', '.form_close', function() {
			overlay.hide();
			x = 0;
		});
		label_edit.click(function(e) { //=================== EDIT ===================
			overlay.toggle();
			form.children('h1').text('Edit Label');
			var values = ['label_name', 'id', 'label_content'];
			update.val('edit');
			data = new Object;
			for (var i = 0; i < values.length; i++) {
				data[values[i]] = $(this).parents('tr').children('.' + values[i]).text();
				$('#label_form ' + '#' + values[i]).val(data[values[i]]);
			}
			data['token'] = $('#token').text();
			$('#label_token').val(data['token']);
			//console.log(data);
			if (x === 0) {
				overlay.append(form);
				x++;
			}
			e.preventDefault();
		});
		add_label.click(function(e) { //=================== ADD ===================
			overlay.toggle();
			values = ['template_name', 'template_content'];
			update.val('add');
			data = new Object;
			for (var i = 0; i < values.length; i++) {
				$('#label_form ' + '#' + values[i]).val('');
			}
			form.children('h1').text('Add Label');
			data = new Object;
			form.children('#label_name').val('');
			form.children('#label_content').val('');
			data['token'] = $('p#token').text();
			$('#token').val(data['token']);
			//console.log(data);
			if (x === 0) {
				overlay.append(form);
				x++;
			}
			e.preventDefault();
		});
		$(document).keyup(function(e) { //clicking escape will hide the overlay 
			if (e.keyCode == KEYCODE_ESC) {
				overlay.hide();
				x = 0;
			}
		});
	} //labels
	
	function scattershot() {
		var scattershot_edit = $('.edit_scattershot');
		var overlay = $('#overlay');
		var add_scattershot = $('.add_scattershot');
		var KEYCODE_ESC = 27;
		var x = 0;
		var update = $('#update_crud');
		var form = $('#scattershot_form');
		overlay.on('click', '.form_close', function() {
			overlay.hide();
			x = 0;
		});
		scattershot_edit.click(function(e) { //=================== EDIT ===================
			overlay.toggle();
			form.children('h1').text('Edit Scattershot');
			values = ['scattershot_id', 'scattershot_value', 'scattershot_name','scattershot_type','scattershot_anchor','scattershot_class','id'];
			update.val('edit');
			data = new Object;
			for (var i = 0; i < values.length; i++) {
				data[values[i]] = $(this).parents('tr').children('.' + values[i]).text();
				$('#scattershot_form ' + '#' + values[i]).val(data[values[i]]);
				//console.log($(this).parents('tr').children('.' + values[i]).text());
			}
			data['token'] = $('p#token').text();
			$('#token').val(data['token']);
			console.log(data);
			if (x === 0) {
				overlay.append(form);
				x++;
			}
			e.preventDefault();
		});
		add_scattershot.click(function(e) { //=================== ADD ===================
			overlay.toggle();
			values = ['value', 'name','type','anchor','class','id'];
			update.val('add');
			data = new Object;
			for (var i = 0; i < values.length; i++) {
				$('#scattershot_form ' + '#' + values[i]).val('');
			}
			form.children('h1').text('Add Label');
			data = new Object;
			
			//reset values
			form.children('#scattershot_name').val('');
			form.children('#scattershot_value').val('');
			form.children('#scattershot_type').val('');
			form.children('#scattershot_anchor').val('');
			form.children('#scattershot_class').val('');
			form.children('#scattershot_id').val('');
			
			data['token'] = $('p#token').text();
			$('#scattershot_token').val(data['token']);
			//console.log(data);
			if (x === 0) {
				overlay.append(form);
				x++;
			}
			e.preventDefault();
		});
		$(document).keyup(function(e) { //clicking escape will hide the overlay 
			if (e.keyCode == KEYCODE_ESC) {
				overlay.hide();
				x = 0;
			}
		});
	} //scattershot
	
	
	//for searching filtering search field
	function regexSearch(v, s) {
		$(s).keyup(function() {
			$rows = v;
			var val = $.trim($(this).val()),
				reg = RegExp(val, 'i'),
				text;
			$rows.show().filter(function() {
				text = $(this).text().replace(/\s+/g, ' ');
				return !reg.test(text);
			}).hide();
		});
	}
	
	//$.queryString jquery plugin, $.QueryString["string"] returns ?string=something
	(function($) {
		$.QueryString = (function(a) {
			if (a == "") return {};
			var b = {};
			for (var i = 0; i < a.length; ++i) {
				var p = a[i].split('=');
				if (p.length != 2) continue;
				b[p[0]] = decodeURIComponent(p[1].replace(/\+/g, " "));
			}
			return b;
		})(window.location.search.substr(1).split('&'))
	})(jQuery);
	
	//image chooser, div pops up choose and image, wah-lah.
	function image_chooser() {
		var overlay = $('#overlay');
		var ic = $('.image_chooser');
		var close = $('.image_chooser_close');
		var ifc = $('.images_for_chooser');
		var current_image = null;
		var images = $('.images_for_chooser .images');
		var picked = $('.picked');
		var submit = $('.image_chooser_submit');
		var value = $('.global_logo_value');
		ic.click(function(e) {
			openChooser();
			e.preventDefault();
			return false;
		});

		function openChooser() {
			ifc.show();
			overlay.show();
		}
		close.click(function() {
			closeChooser();
		});

		function closeChooser() {
			ifc.hide();
			overlay.hide();
		}
		$(document).keyup(function(e) { //clicking escape will hide the overlay 
			if (e.keyCode == KEYCODE_ESC) {
				closeChooser();
			}
		});
		images.click(function() {
			$('.images').removeClass('image-active');
			current_image = $(this).children('p').text();
			picked.text(current_image);
			$(this).addClass('image-active');
		});
		submit.click(function(e) {
			value.val(current_image);
			closeChooser();
			e.preventDefault();
		});
	}
	//create equal height of something

	function equalHeight(element) {
		var max = 0;
		element.css('height', 'auto');
		jQuery(element).each(function() {
			max = Math.max(jQuery(this).innerHeight(), max);
		}).css('min-height', max);
	}

	function perms_func() {
		$('.perms').click(function() {
			$(this).find('.checkbox_perms').click();
			if ($(this).find('.checkbox_perms').is(":checked")) {
				$(this).removeClass('checkbox_perms_bg_red');
				$(this).addClass('checkbox_perms_bg_green');
				$(this).find('label').text('Can Access');
			} else {
				$(this).find('label').text('Cannot Access');
				$(this).removeClass('checkbox_perms_bg_green');
				$(this).addClass('checkbox_perms_bg_red');
			}
		});
		$('.permission_div_header').click(function() {
			$('.permission_div_body').slideToggle();
		});
		$('.perms .checkbox_perms').click(function() {
			$(this).parent().click();
		});
		$('.perms label').click(function() {
			$(this).find('.checkbox_perms').parent().click();
		});
	}

	function pager(page_key,amt_key, id) {
		var amount = $('#pager-'+id+' .pager-amount').val();
		
		if(QueryString[page_key] === undefined){
			var page = 1;
		}else{
			var page = parseInt(QueryString[page_key]);
		}
		
		var max = $('#pager-'+id+' .pager-max').text();
				
		if(page > max){insertParam(page_key, max);} //check if user is above max pages
		
		$('#pager-'+id+' .pager-amount').change(function() {
			var amount = $(this).val();
			insertParam(amt_key, amount);
		}); //pager amount change - dropdown
		$('#pager-'+id+' .pager-forward').click(function(e) {
			if (page + 1 > parseInt(max)) {
				insertParam(page_key, 1);
			} else {
				insertParam(page_key, parseInt(page) + 1);
			}
		});
		$('#pager-'+id+' .pager-back').click(function(e) {
			if (page - 1 == 0) {
				insertParam(page_key, parseInt(max));
			} else {
				insertParam(page_key, parseInt(page) - 1);
			}
		});
		$('#pager-'+id+' .pager-input').keydown(function(e) {
			if (e.which == 13) { // fire on enter, then check if the value entered is higher than our max, if it is  bring them to the last page. If not bring them to the page they want
				if ($(this).val() > max) {
					insertParam(page_key, max);
				} else {
					insertParam(page_key, $(this).val());
				}
			}
		});
	} //pager 
	
	function search_nav(){
		var query;
		
		$('#nav .search_bg input').keyup(function(e) {
			query = $(this).val();
			
			if(e.which == 13 && query){//if keypress is enter "submit" the form.
				redirect('?filter=all&tpl=search&search='+query);
			}
		});		
		
		$('#nav button').on('click', function(e){
						
			var query = $(this).siblings('.search_field').val();
			
			if(query){
				redirect('?filter=all&tpl=search&search='+query);
				e.preventDefault();
			}else{
				e.preventDefault();
			}
		});
	}//Search nav	
	
	function search(){
		var select = $('.search_field .change_filter');
		var input = $('.search_field .search_query');
		var submit = $('.search_field button');
		
		select.change(function(){
			insertParam('filter', $(this).val());
		});		
		
		submit.click(function(e){
			if(input.val() != undefined){
				insertParam('search', input.val());
			}
			e.preventDefault();
		});
		
		input.keyup(function(e) {
			query = $(this).val();
			
			if(e.which == 13 && query){//if keypress is enter "submit" the form.
				insertParam('search', input.val());
			}
		});			
	}

	function init() { 
		content();
		templates();
		labels();
		image_chooser();
		perms_func();
		
		regexSearch($('.search_table .data'), $('.search')); //search field regex
		regexSearch($('.images'), $('.search')); //search field regex		

		headerdropdown();
		//slideable();
		navbarmin();
		navdropdowns();
		
		//close the nav if its in navmin
		if ($.cookie('navmin') == 'true') {
			controller.click();
		}
		
		$('.html-code').editable({
			inlineMode: false, 
			imageUploadURL: 'scripts/upload.php', 
			fileUploadURL: 'script/upload.php',
			imageUploadParams: {token: $('.token').first().text()},
			fileUploadParams: {token: $('.token').first().text()}
		});

		//pager JS
		function foreach_callback(element, index, array) {
			pager(element[0], element[1], element[0]);
		}
		pager_array.forEach(foreach_callback);
		
		search_nav();
		search();
		
		scattershot();
	}
	init();
});