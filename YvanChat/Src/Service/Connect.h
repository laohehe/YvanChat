#ifndef _CONNECT_H
#define _CONNECT_H
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

/*
����������socket����
*/
void Connect(int port);

#endif
