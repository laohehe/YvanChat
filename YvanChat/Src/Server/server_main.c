/*
*	laohehe
*	聊天室服务端主程序
*/
#include <stdio.h>
#include <fcntl.h>  //open函数
#include <unistd.h> //read函数
#include <string.h>
#include <mysql/mysql.h>
#include "../Common/cJSON.h"   //非系统提供头文件
#include "../Service/Connect.h"


int main()
{
	char jsonBuf[1024];  //json配置文件字节流
	char host[50], username[50], password[50], database[50];
	int port; //开启端口
	int fd = open("../Config/config.json", O_RDONLY);
	if (fd == -1)
	{
		perror("open config.json");
		exit(0);
	}
	read(fd, jsonBuf, sizeof(jsonBuf));
	//printf("sizeof jsonBuf:%d", sizeof(jsonBuf));
	cJSON* jsonRoot = cJSON_Parse(jsonBuf);
	cJSON* jsonItem = cJSON_GetObjectItem(jsonRoot, "host");
	strcpy(host, jsonItem -> valuestring);   //主机名
	jsonItem = cJSON_GetObjectItem(jsonRoot, "username");
	strcpy(username, jsonItem -> valuestring);
	jsonItem = cJSON_GetObjectItem(jsonRoot, "password");
	strcpy(password, jsonItem->valuestring);
	jsonItem = cJSON_GetObjectItem(jsonRoot, "database");
	strcpy(database, jsonItem->valuestring);
	jsonItem = cJSON_GetObjectItem(jsonRoot, "port");
	port = jsonItem->valueint;
	printf("host:%s\nusername:%s\npassword:%s\ndatabase:%s\nport:%d\n", host, username, password, database, port);
	//printf("%s\nusername:%s\n", host, username);
	close(fd);
	cJSON_Delete(jsonRoot);

	//数据库连接
	MYSQL* mysql = mysql_init(NULL);
	if (mysql_real_connect(mysql, host, username, password,database, 0, NULL, 0) == 0)
	{
		printf("数据库连接失败\n");
		exit(0);
	}

	//创建并保持socket连接
	Connect(port);
	return 0;
}