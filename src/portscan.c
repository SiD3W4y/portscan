#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(int argc,char** argv)
{
	int i;
	int maxport = 1024;
	
	if(argc < 2){
		perror("Not enough arguments");
		exit(-1);
	}

	if(argc > 2){
		maxport = atoi(argv[2]);
	}

	for(i=0;i<maxport;i++){
		if(check(argv[1],i) > 0){
			printf("%d open\n",i);
		}
	}
}
