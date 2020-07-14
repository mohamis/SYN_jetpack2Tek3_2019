/*
** EPITECH PROJECT, 2020
** jetpack
** File description:
** create client in list
*/

#include "../../include/includes.h"
#include "../../include/jetpack_client.h"

void	start_client(client_t *cli)
{
    cli->rcv = 0;
    cli->s = 0;
    cli->cli_sock = -1;
    cli->id = -1;
    cli->ip = NULL;
}

void set_connection(client_t *cli)
{
    struct sockaddr_in server;

    cli->cli_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (cli->cli_sock == -1)
        is_err("Error on creating socket", 1);
    if (strcmp(cli->ip, "localhost") == 0)
        cli->ip = "127.0.0.1";
    server.sin_addr.s_addr = inet_addr(cli->ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(cli->port);
    if (connect(cli->cli_sock, (struct sockaddr *)&server, 
                sizeof(server)) < 0)
        is_err("connection failed", 1);
}

