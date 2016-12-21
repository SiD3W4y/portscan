#include <stdio.h>
#include "utils.h"

int main(){
	int i;

	for(i=0;i<1000;i++){
		if(check("192.168.1.31",i) > 0){
			printf("%d open\n",i);
		}
	}
}
