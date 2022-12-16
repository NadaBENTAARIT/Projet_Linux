#include "serv_cli_socket.h"
#include <string.h>
#include <time.h>

void main()
{
    int server_sock, sock_cl;
    struct sockaddr_in server_addr, addr_cl;
    char buffer[1024];
    int i;                    // compteur
    struct Question question; // variable question struct
    struct Reponse reponse;   // vraiable reponse struct

    // Creating  socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0)
    {
        printf("unable to create socket");
    }
    printf("Server socket create succcessfully");

    // Associating @ip+num port
    memset(&server_addr, '\n', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Binding
    int b = bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (b < 0)
    {
        perror("Bind error");
        exit(1);
    }

    // Listening
    listen(server_sock, 10);
    printf("\n I'm server %d Listening.........", getpid());

    reponse.pid_serveur = getpid(); // stock pid server

    // Accepting coonnexion
    while (1)
    {
        srand(time(NULL));
        socklen_t addrs_size = sizeof(addr_cl);
        sock_cl = accept(server_sock, (struct sockaddr *)&addr_cl, &addrs_size);

        // receive from clinet
        recv(sock_cl, &question, sizeof(question), 0);
        printf("\n client num %d connected successfully \n", question.pid_client);

        int pid = fork();

        if (pid < 0)
        {
            perror("ERROR on fork");
            exit(1);
        }
        if (pid == 0)
        {
            for (i = 0; i < question.n; i++) // create table by random numbers
            {
                reponse.tab[i] = 1 + rand() % NBMAX;
            }

            // Sending to client

            write(sock_cl, &reponse, sizeof(reponse));
            exit(0);
        }
        else
        {
            close(sock_cl);
        }
    }
    // Closing socket
    close(server_sock);
    close(sock_cl);
}