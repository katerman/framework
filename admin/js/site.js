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
	

	
	
	function init(){
		navdropdowns();
	}
	
	init();
});