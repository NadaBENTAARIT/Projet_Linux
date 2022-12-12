#ifndef __HANDLERS_CLI
#define __HANDLERS_ CLI
//  Waking upclient when it receives response by sending SIGUSR1 from server to client

void hand_reveil(int sig)
{
printf("\n                        ******* SIGNAL FROM SERVER *********\n" );  
printf ("                  Our client wake up you received your question !! \n") ;

}



#endif // MACRO
