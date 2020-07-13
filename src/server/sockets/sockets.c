/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** sockets
*/

#include "includes.h"
#include "jetpack.h"
#include "sockets.h"

int read_lines()
{
    dprintf(tft_client, "ALLO C LE SERVEUR.\r\n");
    FILE *file = fdopen(dup(tft_client), "r");
    char *lines = NULL;
    size_t i = 0;

    for (;42;) {
        if (getline(&lines, &i, file) == -1) {
            fclose(file);
            free(lines);
        }
        fprintf(stderr, "%s", lines);
        remove_delim(lines);
        if (strcmp(lines, "FINISH") == 0 )
            break;
    }
    free(lines);
    fclose(file);
    if (fcntl(tft_client, F_GETFD) != -1)
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
            sizeof(address)) < 0)
        exit(EXIT_FAILURE);
}

void listen_lines()
{
    if (listen(tft_server, 100) < 0)
        exit(EXIT_FAILURE);
}