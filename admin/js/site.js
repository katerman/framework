$(document).ready(function(){
	var body = $('body');
	
	
	function navdropdowns(){
		var fb = $('#nav > ul > li'); //parents
		var allBtns = $('#nav .dropdownBtn li').removeClass('bottomBtnBorder');
		var lastBtn = $('#nav .dropdownBtn:last li').last().addClass('bottomBtnBorder');
		
		
		fb.click(function(e){
			$(this).next('li').stop().slideToggle();
			e.preventDefault();
			
			allBtns;
			lastBtn;
		});
	}
	
	function init(){
		navdropdowns();
	}
	
	init();
});