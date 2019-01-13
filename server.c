#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include "udplib.h"

int BUFFER_SIZE = 50;

int main(int argc, char *argv[])
{
	int sd = UDP_Open(10000);

	while (1)
	{
		struct sockaddr_in addr;
		char message[BUFFER_SIZE];
		int rc = UDP_Read(sd, &addr, message, BUFFER_SIZE);
		if (rc > 0)
		{
			char reply[BUFFER_SIZE];
			sprintf(reply, "Acknowledged your message");
			rc = UDP_Write(sd, &addr, reply, BUFFER_SIZE);
		}
	}
	return 0;
}