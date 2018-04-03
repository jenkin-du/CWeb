#include<stdio.h>
#include"cgic.h"
#include"ctemplate.h"
#include<string.h>
#include<stdlib.h>

int cgiMain(){
	int i1,i2,i3;
	char n1[256]={0};
	char n2[256]={0};
	char n3[256]={0};
	TMPL_varlist *varlist=0;
	cgiHeaderContentType("text/html;charset=gbk");
	if(cgiFormSubmitClicked("equal")==cgiFormSuccess){//点击了代码
		
		if(cgiFormString("n1",n1,sizeof(n1))!=cgiFormSuccess){
		    cgiFormString("n2",n2,sizeof(n2));
			varlist=TMPL_add_var(varlist,"n1",n1,"n2",n2,"n3","",0);
			varlist=TMPL_add_var(varlist,"errorMsg","第一个不能为空",0);
			TMPL_write("calculate.html",0,0,varlist,cgiOut,cgiOut);
			return 0;
		}
		if(cgiFormString("n2",n2,sizeof(n2))!=cgiFormSuccess){
		
			varlist=TMPL_add_var(varlist,"n1",n1,"n2",n2,"n3","",0);
			varlist=TMPL_add_var(varlist,"errorMsg","第二个不能为空",0);
			TMPL_write("calculate.html",0,0,varlist,cgiOut,cgiOut);
			return 0;
		}
		

		i1=atoi(n1);
		i2=atoi(n2);
		
		i3=i1+i2;
		_itoa(i3,n3,10);

		varlist=TMPL_add_var(varlist,"n1",n1,"n2",n2,"n3",n3,0);
		varlist=TMPL_add_var(varlist,"errorMsg","",0);
		TMPL_write("calculate.html",0,0,varlist,cgiOut,cgiOut);
			

	}else
	{
	//	TMPL_varlist *varlist=0;
		varlist=TMPL_add_var(varlist,"n1","","n2","","n3","",0);
		varlist=TMPL_add_var(varlist,"errorMsg","",0);
		TMPL_write("calculate.html",0,0,varlist,cgiOut,cgiOut);
	}
	return 0;
}