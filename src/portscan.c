#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"


int main(int argc,char** argv)
{
	int i;
	int maxport = 1024;
	int openports = 0;
	float start = (float)clock()/CLOCKS_PER_SEC;
	float end;
	
	if(argc < 2){
		print_error("Not enough arguments");
		
	}

	if(argc > 2){
		maxport = atoi(argv[2]);
	}

	if(maxport < 0 || maxport > 65535){
		print_error("Port index out of range");
	}

	printf("Scanning host -> %s\n",argv[1]);

	for(i=0;i<maxport;i++){
		if(check(argv[1],i) > 0){
			print_port(i);
			openports++;
		}
	}
	
	// May not be the best way to time this
	end = (float)clock()/CLOCKS_PER_SEC;
	printf("Scanned %d ports in %f seconds\n",maxport,end-start);
	printf("Ports : %d open , %d closed\n",openports,maxport-openports);
}
