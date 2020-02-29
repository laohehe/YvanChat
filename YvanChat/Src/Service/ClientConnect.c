#include "ClientConnect.h"
int sock_fd;

void ClientConnect(const char * host, int port)
{
	struct sockaddr_in sockaddr_client;
	sockaddr_client.sin_addr.s_addr = inet_addr(host);
	sockaddr_client.sin_family = AF_INET;
	sockaddr_client.sin_port = htons(port);
	memset(&sockaddr_client.sin_zero, 0, sizeof(sockaddr_client.sin_zero));
	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (sock_fd < 0)
	{
		perror("client socket error");
		exit(1);
	}
	if (connect(sock_fd, (struct sockaddr *)&sockaddr_client, sizeof(sockaddr_client)) < 0)
	{
		perror("client connect error");
		exit(1);
	}

}
