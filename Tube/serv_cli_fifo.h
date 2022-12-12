#ifndef __SERV_CLI_FIFO
#define __SERV_CLI_FIFO

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>
#include <math.h>    

// ***defining NBMAX and pipes ***//
#define NBMAX 7
#define fifo1 "/home/nada/Bureau/Projetlinux/Tube/fifo1"
#define fifo2 "/home/nada/Bureau/Projetlinux/Tube/fifo2"

// ***defining question struct ***//
struct Question {
int pid_client;
int n;
} ;
// ***defining response struct ***//
struct Reponse {
int pid_client;
int pid_serveur;
int tab [NBMAX];
} ;     


                             
int mkfifo (const char* ref, mode_t mode);
int kill(pid_t pid, int sig);
int unlink (const char *ref);
int close(int fd);  
int remove(const char * filename);
    
    
#endif // MACRO
