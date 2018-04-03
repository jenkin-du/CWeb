#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cgi.h"
#include "cgic.h"
#include "ctemplate.h"
#include "sql.h"

#include<winsock.h>
#include<mysql.h>

void showError(char *error){
	TMPL_varlist *varlist=0;
	varlist=addVar(varlist,"msg",error);
	showWeb(varlist,"error.html");
}

int cgiMain(){
	MYSQL *mysql=mysql_init(0);

	TMPL_varlist *varlist=0;
	MYSQL_RES *result=0;
	TMPL_loop *loopTeacher=0;
	MYSQL_ROW row;

	char model[32]={0};
	char action[32]={0};//用model和action参数标示哪个模块以及操作
	char *name;
	char *phone;

	

	init_SQL(mysql,"localhost","root","root","study",0,0,0);

//	cgiHeaderContentType("text/html;charset=gbk");
	if (cgiFormString("model",model,sizeof(model))!=cgiFormSuccess)
	{
		showError("没有model参数");
		return 0;
	}
	if (cgiFormString("action",action,sizeof(action))!=cgiFormSuccess)
	{
		showError("没有action参数！");
		return 0;
	}



	if (strcmp(model,"teacher")==0)
	{
		if (strcmp(action,"list")==0)
		{
			
			result=query_SQL(mysql,"select * from t_teachers");
			row=mysql_fetch_row(result);
			while (!mysql_fetch_row(result))
			{
				row=mysql_fetch_row(result);
				name=row[1];
				phone=row[2];
			
				loopTeacher=TMPL_add_varlist(loopTeacher,
					TMPL_add_var(0,"name",name,"phone",phone,0));
				
			}
			varlist=TMPL_add_loop(varlist,"teachers",loopTeacher);   
			showWeb(varlist,"teachers.html");
			mysql_free_result(result);
		}else
		{
			showError("未知的action参数");
		}
		/*if (strcmp(action,"add")==0)
		{

		}
		if (strcmp(action,"delete")==0)
		{

		}
		if (strcmp(action,"change")==0)
		{

		}*/
	}
	else
	{
		showError("未知的model参数");
		return 0;
	}
	/*if (stricmp(model,"student")==0)
	{
	if (strcmp(action,"list")==0)
	{

	}
	if (strcmp(action,"add")==0)
	{

	}
	if (strcmp(action,"delete")==0)
	{

	}
	if (strcmp(action,"change")==0)
	{

	}
	}*/


	mysql_close(mysql);

	return 0;
}


int cgiMain1(){
	TMPL_varlist * varlist1=0;
	TMPL_loop * loopUsers=0;
	varlist1 = TMPL_add_var(varlist1,"Title","测试Loop",0);

	loopUsers = TMPL_add_varlist(loopUsers,TMPL_add_var(0,"Name","如鹏网","Age","8","Title","t1",0));
	loopUsers = TMPL_add_varlist(loopUsers,TMPL_add_var(0,"Name","淘宝","Age","15","Title","t2",0));
	loopUsers = TMPL_add_varlist(loopUsers,TMPL_add_var(0,"Name","京东","Age","10",0));

	varlist1 = TMPL_add_loop(varlist1,"users",loopUsers);
	cgiHeaderContentType("text/html;charset=gbk");
	TMPL_write("Users.htm",0,0,varlist1,cgiOut,cgiOut);
	return 0;
}