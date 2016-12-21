#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "utils.h"

int check(char* ip,int port)
{
	int sock;
	struct sockaddr_in target;
	
	// Creating socket
	sock = socket(AF_INET,SOCK_STREAM,0);

	if(sock == -1){
		perror("Error creating socket");
		exit(-1);
	}

	target.sin_addr.s_addr = inet_addr(ip);
	target.sin_family = AF_INET;
	target.sin_port = htons(port);

	if(connect(sock,(struct sockaddr *)&target,sizeof(target)) < 0){
		return 0;
	}

	return 1;
}
