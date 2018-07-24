//
// Created by xugaoxiang on 18-7-23.
// sudo apt-get install libmysqlclient-dev
//

#include "db.h"

/*
 * init mysql
 * */
 MYSQL* mysqldb_init() {
    return mysql_init(NULL);
 }

/*
 * connect db
 * */
int mysqldb_connect(MYSQL *mysql)
{
    if(!mysql_real_connect(mysql, "localhost", "root", "toor", "yolo", 0, NULL, 0)) {
        printf("Failed to connect db.\n");
        return -1;
    } else {
        return 0;
    }
}

/*
 * insert data
 * */
int mysqldb_insert(MYSQL *mysql, int total_person, char *image_addr)
{
    int t;
    char *head = "insert into ";
    char query[200];
    char table_name[20] = "meeting_room";

    // (id, total, image, date)
    char field[32] = "total, image";
    char *left = "(";
    char *right = ") ";
    char *values = " values";
    char message[100];

//    memset(field, '\0', sizeof(field));
//    memset(table_name, '\0', sizeof(table_name));
    memset(message, '\0', sizeof(message));

    sprintf(message, "%d, '%s'", total_person, image_addr);
    printf("\ninsert message: %s\n", message);

    sprintf(query, "%s%s %s%s%s%s%s%s%s", head, table_name, left, field, right, values, left, message, right);
    printf("\n%s\n", query);

    t = mysql_real_query(mysql, query, strlen(query));
    if (t != 0) {
        printf("\nFailed to query.\n");
        return -1;
    }

    return 0;
}

/*
 * close mysql
 * */
void mysqldb_close(MYSQL *mysql) {
    mysql_close(mysql);
}