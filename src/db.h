#ifndef DB_H
#define DB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

MYSQL* mysqldb_init();
int mysqldb_connect(MYSQL *mysql);
int mysqldb_insert(MYSQL *mysql, int total_person, char *image_addr);
void mysqldb_close(MYSQL *mysql);

#endif
