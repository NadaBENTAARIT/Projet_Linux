#ifndef __HANDLERS_SERV
#define __HANDLERS_SERV

/*** Notifying server when client receive response by SIGUSR1 sent from client to server ***/

void hand_reveil(int sig){

printf("\n  ________________ SIGNAL FROM CLIENT _______________\n" );  
printf ("__________'Thanks server!! I have received my response_______\n'") ;


}


/*** End server when it receives an outside signal ***/
void fin_serveur(int sig){
printf("\n                           ******* SIGNAL FROM OUTSIDE *******\n" );              
printf ("                   Receiving signal number %d   FIN SERVEUR!! I was killing ! \n",sig) ;
// unlinking pipes 
//unlinking pipe fifo1
unlink (fifo1);
//unlinking pipe fifo1
unlink (fifo2);

// quit server program
exit(0);

}   
#endif // MACRO
