#include "serv_cli_fifo.h"
#include "Handlers_Cli.h"

int main(){

/*** Declaring variables ***/
int n,i;
int pid_client=getpid();
// Question Structure object
struct Question question; 
// Response Structure object 
struct Reponse reponse;    



/*** Opening pipes ***/
int desc1 =open(fifo1,O_WRONLY);
int desc2=open(fifo2,O_RDONLY);
//test of open
//printf("desc 1 = %d   et desc 2 =  %d",desc1,desc2);
if (desc1 == -1  && desc2 == -1) {
      perror("you are not connected to server !! \n") ;
      exit(2);
   }



/*** Initializing generatar of random membres ***/
srand(getpid());



/*** Installing of Handlers ***/
signal(SIGUSR1,hand_reveil);



/*** Constructing and sending question ***/
printf("I'm client with pid_client = %d ****** \n",getpid());
//generating the n number
n = 1+rand() % (NBMAX );
printf("number = %d",n);
// filling columns of question
question.n=n;
question.pid_client= pid_client;
//printf("************* %d \n ",question.pid_client);
//write question in pipe fifo1
write(desc1,&question,sizeof(question));




/*** Waiting response ***/
printf(" I'm  wating for my response  \n");
pause();



/*** Reading response ***/
read(desc2,&reponse,sizeof(reponse));

/*** Creating file to insert result in ***/

FILE *fp;
char file_name [20];
//file_name=question.n;
fp = fopen("/home/nada/Bureau/Projetlinux/Tube/test.txt","r+");

/*** Sending  SIGUSR1 to server ***/
int test=kill(reponse.pid_serveur,SIGUSR1);



/*** Treating response ***/
printf("+=================================================+\n");
printf("|from pid_server         |%d                   \n",reponse.pid_serveur);
printf("|=================================================|\n");
printf("|to pid_client           |%d                   \n",reponse.pid_client);
printf("|=================================================\n");
for(i=0;i<n;i++)
{
//printf("|========================================|\n");
printf("|number  %d               |%d              \n",i+1,reponse.tab[i]);
}
printf("+=================================================+ \n");


fputs("Salut les développeurs\nBienvenue sur OpenClassrooms !", fp);
close(desc2);
close(desc1);



} //end main
