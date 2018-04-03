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
	while(row=mysql_fetch_row(result)){//只要还有数据那么while就一直执行
                                       //mysql_fetch_row是“箭头/游标”向下移动一行，并且获得这一行数据的MSQL_ROW对象
     char *id=row[0];                              //如果没有数据则返回0
	 char *name=row[1];
	 char *gender=row[2];
	 char *hobby=row[3];
	 printf("id=%s,name=%s,gender=%s,hobby=%s\n",id,name,gender,hobby);
	}
	mysql_free_result(result);//释放本地内存中的查询结果
	printf("exit\n");
	mysql_close(mysql);//程序最后必须关闭连接，否则会有mysql服务器连接过多卡死的可能性
	return 0;
}