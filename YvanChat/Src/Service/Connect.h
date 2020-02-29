#ifndef _CONNECT_H
#define _CONNECT_H
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

/*
创建并保持socket连接
*/
void Connect(int port);

#endif
