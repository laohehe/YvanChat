#include "./Connect.h"
#define BACKLOG 12 //连接请求队列长度
#define MSG_LEN 1024 //数据长度

void *create(void *arg)
{
	char buf[MSG_LEN];
	int ret, recv_len;
	int client_fd = (int)(long)arg;
	ret = recv(client_fd, buf, MSG_LEN - recv_len, 0);
	if (ret <= 0 )
	{
		perror("recv");
		return NULL;
	}
	printf("buf:%s\n");
	//while (1)
	//{
	//	recv_len = 0;//初始接收长度为0
	//	while (recv_len < MSG_LEN)
	//	{
	//		ret = recv(client_fd, buf, MSG_LEN - recv_len, 0);
	//		if (ret <= 0 )
	//		{
	//			perror("recv");
	//			return NULL;
	//		}
	//		recv_len += ret;
	//	}
	//	printf("buf:%s\n");
	//}
	//printf("a  new thread! client_fd = %d\n", (int)(long)arg);

	return NULL;
}

void Connect(int port)
{
	int sock_fd, client_fd;
	int yes = 1;
	int len = sizeof(struct sockaddr_in);
	struct sockaddr_in sockaddr_server, sockaddr_client;
	sockaddr_server.sin_family = AF_INET;
	sockaddr_server.sin_port = htons(port);
	sockaddr_server.sin_addr.s_addr = INADDR_ANY;
	memset(sockaddr_server.sin_zero, 0, sizeof(sockaddr_server.sin_zero));

	//创建socket
	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (sock_fd < 0)
	{
		perror("socket create");
		exit(1);
	}
	//设置socket的属性，socket关闭后立即收回 用以加强程序的健壮性
	if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)  
	{
		perror("setsockopt error!");
		exit(1);
	}

	if (bind(sock_fd, (struct sockaddr *)&sockaddr_server, sizeof(sockaddr_server)) <0 )
	{
		perror("bind error!");
		exit(1);
	}

	if (listen(sock_fd, BACKLOG) < 0)
	{
		perror("listen error!");
		exit(1);
	}
	while (1)
	{
		client_fd = accept(sock_fd, (struct sockaddr *)&sockaddr_client, (socklen_t *)&len);
		if (client_fd < 0)
		{
			perror("accept error!");
			exit(1);
		}
		else
		{
			printf("accept from :%d,socket:%d\n", client_fd, ntohs(sockaddr_client.sin_port));
		}
		pthread_t thid;
		pthread_create(&thid, NULL, create, (void *)(long)client_fd);

	}
}

