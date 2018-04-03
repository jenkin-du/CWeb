#include<winsock.h>
#include<mysql.h>
#ifndef _SQL_H_
#define _SQL_H_

extern void init_SQL(MYSQL* mysql,const char *host,
			const char *user,
			const char *passwd,
			const char *db,
			unsigned int port,
			const char *unix_socket,
			unsigned long clientflag);
extern void non_query_SQL(MYSQL* mysql, char *non_query_statements);
extern MYSQL_RES* query_SQL(MYSQL* mysql, char *query_statements);
#endif