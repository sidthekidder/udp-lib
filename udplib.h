#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#ifndef _UDPLIB_H_
#define _UDPLIB_H_

int UDP_Open(int port);

int UDP_FillSockAddr(struct sockaddr_in *addr, char *hostName, int port);

int UDP_Write(int sd, struct sockaddr_in *addr, char *buffer, int n);

int UDP_Read(int sd, struct sockaddr_in *addr, char *buffer, int n);

#endif
