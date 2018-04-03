#include<stdio.h>
#include<stdlib.h>
#include<winsock.h>
#include<mysql.h>

void init_SQL(MYSQL* mysql,const char *host,
			const char *user,
			const char *passwd,
			const char *db,
			unsigned int port,
			const char *unix_socket,
			unsigned long clientflag){
//		MYSQL *mysql=mysql_init(0);

	    if(!mysql_real_connect(mysql,"localhost","root","root","study",0,0,0)){
			printf("���ݿ����ӳ���:%s",mysql_error(mysql));
			goto exit;//gotoһ�㲻�Ƽ�ʹ�ã������ڴ������ʱ�򣬺ܺ���
			//û�о��ԺõĶ�����û�о��Ի��Ķ������Ϳ�������������˵�ˮƽ��ô��
		}else
		{
			printf("�������ݿ�ɹ�\n");
		}
		if(mysql_query(mysql,"set names gbk"))//����ɹ�����0
		{
			printf("�趨���ӱ���ʧ��%s",mysql_error(mysql));
			goto exit;
		}
		goto success;
exit:
	printf("exit\n");
	mysql_close(mysql);//����������ر����ӣ��������mysql���������ӹ��࿨���Ŀ�����    
success:
	;
}

void non_query_SQL(MYSQL* mysql, char *non_query_statements){
	if(mysql_query(mysql,non_query_statements)){
		printf("ִ��ʧ�ܣ�:%s",mysql_error(mysql));
	}
}

MYSQL_RES* query_SQL(MYSQL* mysql, char *query_statements){
	MYSQL_RES *result;
	if(mysql_query(mysql,query_statements)){
		printf("ִ��ʧ�ܣ�:%s",mysql_error(mysql));
	}
	result=mysql_store_result(mysql);
	return result;
}