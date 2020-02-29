/*
聊天室客户端主程序*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "../Common/cJSON.h"
#include "../Service/ClientConnect.h"
#include "../View/MainUI.h"

int main()
{
	char host[50];
	char jsonBuf[1024];
	int port;
	int fd = open("../Config/config.json", O_RDONLY);
	if (fd == -1)
	{
		perror("open config.json");
		exit(1);
	}
	if (read(fd, jsonBuf, sizeof(jsonBuf)) == -1)
	{
		perror("read config.json");
		exit(1);
	}
	cJSON* jsonRoot = cJSON_Parse(jsonBuf);
	cJSON* jsonItem = cJSON_GetObjectItem(jsonRoot, "client_host");
	strcpy(host, jsonItem->valuestring);
	jsonItem = cJSON_GetObjectItem(jsonRoot, "port");
	port = jsonItem->valueint;
	//printf("%d%s\n", port, host);
	cJSON_Delete(jsonRoot);
	ClientConnect(host, port);
	//printf("jsonBuf:%s\n", jsonBuf);
	MainUI_Hello();
	close(fd);
	return 0;
}

