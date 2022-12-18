#ifndef __SERV_CLI_FIFO
#define __SERV_CLI_FIFO

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>
#include<math.h>    
#include <arpa/inet.h>
//#include <netinet/in.h>



// ***defining NBMAX and port***//
#define NBMAX 7
#define PORT 7000


// ***defining question struct ***//
struct Question {
int pid_client;
int n;
} ;


// ***defining response struct ***//
struct Reponse {
int pid_client;
int pid_serveur;
int tab [10];
} ;     





#endif