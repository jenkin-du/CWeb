#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <mysql.h>
#include "sql.h"
#include "cgic.h"
#include "ctemplate.h"
#include "cgi.h"

//int cgiMain(){
//	MYSQL  *mysql=mysql_init(0);
//	MYSQL_RES* result;
//	MYSQL_ROW row;
//	char *name;
//	char *gender;
//	char *hobby;
//	cgiHeaderContentType("text/html;charset=gbk");
//	init_SQL(mysql,"localhost","root","root","study",0,0,0);
//	fprintf(cgiOut,"<html><head></head><body>");
//	fprintf(cgiOut,"<table><thead><tr><td>姓名</td><td>性别</td><td>爱好</td></tr></thead>");
//	fprintf(cgiOut,"<tbody>");
//	{
//		result=query_SQL(mysql,"select * from T_Students");
//		while(row=mysql_fetch_row(result)){
//			name=row[1];
//			gender=row[2];
//			hobby=row[3];
//			fprintf(cgiOut,"<tr><td>%s</td><td>%s</td><td>%s</td></tr>",name,gender,hobby);
//		}
//		mysql_free_result(result);
//	}
//	
//	fprintf(cgiOut,"</tbody>");
//	fprintf(cgiOut,"</table>");
//	fprintf(cgiOut,"</body></html>");
//	
//
//
//
//	mysql_close(mysql);
//	return 0;
//}


int cgiMain(){
	MYSQL* mysql=mysql_init(0);
	char name[256]={0};
	char gender[256]={0};
	char hobby[256]={0};
	
	char statement[1024];
	int i=0;
	TMPL_varlist* varlist=0;
	cgiHeaderContentType("text/html;charset=gbk");
	init_SQL(mysql,"localhost","root","root","study",0,0,0);
	if (cgiFormSubmitClicked("btninsert")==cgiFormSuccess)
	{
		
		cgiFormString("name",name,sizeof(name));
		cgiFormString("gender",gender,sizeof(gender));
		cgiFormString("hobby",hobby,sizeof(hobby));
		
		varlist=cgiWriteStrToVar(varlist,"name",name);
		varlist=cgiWriteStrToVar(varlist,"gender",gender);
		varlist=cgiWriteStrToVar(varlist,"hobby",hobby);
		TMPL_write("insert.html",0,0,varlist,cgiOut,cgiOut);
		i=atoi(gender);
		sprintf(statement,"insert into T_Students(name,gender,hobby) values('%s','%d','%s')",name,i,hobby);
		non_query_SQL(mysql,statement);

	}else
	{
		varlist=cgiWriteStrToVar(varlist,"name","");
		varlist=cgiWriteStrToVar(varlist,"gender","");
		varlist=cgiWriteStrToVar(varlist,"hobby","");
		TMPL_write("insert.html",0,0,varlist,cgiOut,cgiOut);

	}

	mysql_close(mysql);
	return 0;
}