#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "serv_cli_socket.h"
#include <arpa/inet.h>
void main()
{
    int ret;
    int client_sock;
    struct sockaddr_in addr;
    int i; // compteur
    char buffer[1024];
    struct Question question; // variable question
    struct Reponse reponse;   // variable reponse

    // creating  socket
    client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock < 0)
    {
        printf("unable to create socket");
        
    }
        printf("Client socket create succcessfully");

    // Asking for connexion
    memset(&addr, '\n', sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    ret=connect(client_sock,(struct sockaddr *)&addr, sizeof(addr));



    if (ret< 0)
	{
		printf("Error in connection.\n");
		exit(1);
	}
    else{
    printf("\n Connect to server");

    // Transfering data
    int n = 1 + rand() % NBMAX;
    question.pid_client = getpid(); // pid de client courant
    question.n = n;
    send(client_sock, &question, sizeof(question), 0);

    // Receiving response
    read(client_sock, &reponse, sizeof(reponse));
    printf(" ena fl client noumrou serveur %d", reponse.pid_serveur);

    // ************* file

    FILE *fptr = NULL;

    // Open file in w (write) mode.

    fptr = fopen("Socket/data_file.txt", "w");

    /* fopen() return NULL if last operation was unsuccessful */
    if (fptr == NULL)
    {
        /* File not created hence exit */
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }

    /* Success message */
    printf(" Data File created and saved successfully. :) \n");

    /*** Treating response ***/
    printf("+=================================================+\n");
    printf("|from pid_server         |%d                   \n", reponse.pid_serveur);
    printf("|=================================================|\n");
    printf("|to pid_client           |%d                   \n", question.pid_client);
    printf("|=================================================\n");
    for (i = 0; i < n; i++)
    {
        // printf("|========================================|\n");
        printf("|number  %d               |%d              \n", i + 1, reponse.tab[i]);
        fprintf(fptr, "%d", reponse.tab[i]);
        fprintf(fptr, "%s", "\n");

        // putw(reponse.tab[i], fPtr);
    }
    printf("+=================================================+ \n");
    /* Close file to save file data */
    fclose(fptr);

    // Closing  socket
    close(client_sock);
    }
}