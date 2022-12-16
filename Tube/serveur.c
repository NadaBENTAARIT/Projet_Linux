#include "serv_cli_fifo.h"
#include "Handlers_Serv.h"
int main()
{

    /*** Declaring variables ***/
    int i;
    // Question Structure object
    struct Question question;
    // Response Structure object
    struct Reponse reponse;

    /*** Unlinking pipes ***/
    // unlinking pipe fifo1
    unlink(fifo1);
    // unlinking pipe fifo1
    unlink(fifo2);

    /*** Creating pipes ***/
    if (mkfifo(fifo1, 0666) == -1 || mkfifo(fifo2, 0666) == -1)
    {
        perror("Impossible to create pipes");
        exit(0);
    }

    /*** Initializing generatar of random membres ***/
    srand(getpid());

    printf(" _______________Waiting for client _______________\n");

    /*** Opening pipes ***/
    int desc1 = open(fifo1, O_RDWR);
    int desc2 = open(fifo2, O_WRONLY);

    /*** Installing of Handlers ***/
    signal(SIGUSR1, hand_reveil);
    for (int sig = 1; sig < NSIG; sig++)
    {
        if (sig != SIGUSR1)
            signal(sig, fin_serveur);
    }

    while (1)
    {
        /*** Reading question from fifo1 ***/
        read(desc1, &question, sizeof(question));
        printf("Client PID = %d \n", question.pid_client);
        printf("Question content for client  %d  is  = %d \n", question.pid_client, question.n);

        /*** Constructing response ***/
        reponse.pid_serveur = getpid();
        reponse.pid_client = question.pid_client;
        // generating  n numberes
        for (i = 0; i < question.n; i++)
        {
            reponse.tab[i] = 1 + rand() % (NBMAX);
        }

        /*** Sending response ***/
        // write response in fifo2
        write(desc2, &reponse, sizeof(reponse));

        /*** Sending  SIGUSR1 to client ***/
        int test = kill(question.pid_client, SIGUSR1);
        // printf("Sending to client%d",test);
        printf(" _______________Waiting for another client _______________\n");
    } // end while

    close(desc2);
    close(desc1);

    return 0;
}
