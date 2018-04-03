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
			printf("数据库连接出错:%s",mysql_error(mysql));
			goto exit;//goto一般不推荐使用，但是在错误处理的时候，很好用
			//没有绝对好的东西，没有绝对坏的东西。就看用这个技术的人的水平怎么样
		}else
		{
			printf("连接数据库成功\n");
		}
		if(mysql_query(mysql,"set names gbk"))//插入成功返回0
		{
			printf("设定连接编码失败%s",mysql_error(mysql));
			goto exit;
		}
		goto success;
exit:
	printf("exit\n");
	mysql_close(mysql);//程序最后必须关闭连接，否则会有mysql服务器连接过多卡死的可能性    
success:
	;
}

void non_query_SQL(MYSQL* mysql, char *non_query_statements){
	if(mysql_query(mysql,non_query_statements)){
		printf("执行失败！:%s",mysql_error(mysql));
	}
}

MYSQL_RES* query_SQL(MYSQL* mysql, char *query_statements){
	MYSQL_RES *result;
	if(mysql_query(mysql,query_statements)){
		printf("执行失败！:%s",mysql_error(mysql));
	}
	result=mysql_store_result(mysql);
	return result;
}