#ifndef _CLICNNECT_H
#define _CLICONNECT_H
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
 
/*
����������socket����
*/
void ClientConnect(const char *host, int port);
#endif // _CLICNNECT_H
