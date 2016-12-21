#ifndef UTILS_H
#define UTILS_H

// Function returning:
//	 0 : on port closed
//	 1 : on port open
int check(char* addr,int port);

// Prints error in red
void print_error(char* msg);

// Prints port in green
void print_port(int port);


#endif
