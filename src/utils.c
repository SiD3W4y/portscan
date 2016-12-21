#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "utils.h"

void print_error(char* msg){

}

void print_port(int port){

}

int check(char* ip,int port)
{
	int sock;
	int status;
	struct sockaddr_in target;
	
	// Creating socket
	sock = socket(AF_INET,SOCK_STREAM,0);

	if(sock == -1){
		perror("Error creating socket");
		exit(-1);
	}
	
	target.sin_addr.s_addr = inet_addr(ip);
	
	if(target.sin_addr.s_addr == -1){
		perror("Invalid ip");
		exit(-1);
	}
	target.sin_family = AF_INET;
	target.sin_port = htons(port);

	if(target.sin_port < 0 || target.sin_port > 65536){
		perror("Port index out of range");
		exit(-1);
	}

	if(connect(sock,(struct sockaddr *)&target,sizeof(target)) < 0){
		status = 0;
	}else{
		status = 1;
	}

	close(sock);
	return status;
}
