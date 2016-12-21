#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "utils.h"

void print_error(char* msg)
{
	printf("\x1B[31mERROR : %s\x1B[0m\n",msg);
	exit(-1);
}

void print_port(int port)
{
	printf("\x1B[32m%d\x1B[0m : OPEN\n",port);
}

int check(char* ip,int port)
{
	int sock;
	int status;
	struct sockaddr_in target;
	
	// Creating socket
	sock = socket(AF_INET,SOCK_STREAM,0);

	if(sock == -1){
		print_error("Socket creation error");
	}
	
	target.sin_addr.s_addr = inet_addr(ip);
	
	if(target.sin_addr.s_addr == -1){
		print_error("Invalid ip");
	}

	target.sin_family = AF_INET;
	target.sin_port = htons(port);

	if(connect(sock,(struct sockaddr *)&target,sizeof(target)) < 0){
		status = 0;
	}else{
		status = 1;
	}

	close(sock);
	return status;
}
