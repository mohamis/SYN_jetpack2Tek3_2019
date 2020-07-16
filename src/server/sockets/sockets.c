/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** sockets
*/

#include "includes.h"
#include "jetpack.h"
#include "sockets.h"

int read_lines(server_t *server)
{
    dprintf(tft_client, "ALLO C LE SERVEUR.\r\n");
    FILE *file = fdopen(dup(tft_client), "r");
    char *lines = NULL;
    size_t i = 0;

    for (;42;) {
        if (getline(&lines, &i, file) == -1) {
            fclose(file);
        } else {
            remove_delim(lines, server);
            if (strcmp(lines, "FINISH") == 0 )
                break;
            free(lines);
        }
        // fprintf(stderr, "%d", server->log);
        //ici ajouter un concat des donnees log et lines pour send to other client
    }
    free(lines);
    fclose(file);
    close(tft_client);
    exit (0);
}

void sockets_init(int port)
{
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = ntohs(port);

    if (bind(tft_server, (const struct sockaddr *)&address,
            sizeof(address)) < 0) {
            close(tft_server); 
            exit(EXIT_FAILURE);
    }
}

void listen_lines()
{
    if (listen(tft_server, MAX_CLIENT) == -1) {
        close(tft_server);
        perror("listen()");
    }   
}