#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include "udplib.h"

int BUFFER_SIZE = 50;

int main (int argc, char *argv[])
{
	int sd = UDP_Open(20000);
	struct sockaddr_in addrSnd, addrRcv;
	int rc = UDP_FillSockAddr(&addrSnd, "127.0.0.1", 10000);

	char message[BUFFER_SIZE];
	sprintf(message, "Test Ping");

	rc = UDP_Write(sd, &addrSnd, message, BUFFER_SIZE);
	printf("Wrote no of bytes: %d\n", rc);
	if (rc > 0) {
		int rc = UDP_Read(sd, &addrRcv, message, BUFFER_SIZE);
		printf("Received msg = %s\n", message);
	}
	return 0;
}