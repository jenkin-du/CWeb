#include<stdio.h>
#include<stdlib.h>
#include<winsock.h>
#include<mysql.h>
#include"sql.h"

int main(){
	

	MYSQL *mysql = mysql_init(0);
	MYSQL_RES* result;
	MYSQL_ROW row;


	init_SQL(mysql,"localhost","root","root","study",0,0,0);
	result=query_SQL(mysql,"select * from t_students ");
	while(row=mysql_fetch_row(result)){//ֻҪ����������ôwhile��һֱִ��
                                       //mysql_fetch_row�ǡ���ͷ/�αꡱ�����ƶ�һ�У����һ����һ�����ݵ�MSQL_ROW����
     char *id=row[0];                              //���û�������򷵻�0
	 char *name=row[1];
	 char *gender=row[2];
	 char *hobby=row[3];
	 printf("id=%s,name=%s,gender=%s,hobby=%s\n",id,name,gender,hobby);
	}
	mysql_free_result(result);//�ͷű����ڴ��еĲ�ѯ���
	printf("exit\n");
	mysql_close(mysql);//����������ر����ӣ��������mysql���������ӹ��࿨���Ŀ�����
	return 0;
}