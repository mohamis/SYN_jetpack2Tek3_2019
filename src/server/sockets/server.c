/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** server
*/

#include "sockets.h"
#include "jetpack.h"

void check_protocol(int port, proto_t *proto)
{
    int opt = 1;

    (tft_server = socket(AF_INET, SOCK_STREAM, proto->p_proto));
    if (tft_server == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(tft_server, SOL_SOCKET, SO_REUSEADDR,
                &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    sockets_init(port);
    listen_lines();
} 

void fork_iter(server_t *server)
{
    int pid = fork();
    if (pid < 0)
        exit(84);

    if (pid == 0) {
        read_lines(server);
    }
    else if (close(tft_client) == -1)
        perror("forked close");
}

void core(int port, server_t *server)
{
    socklen_t len;
    struct sockaddr_in cli;
    proto_t *proto;

    (proto = getprotobyname("TCP"));
    if (proto == NULL) {
        perror("getprotobyname");
        exit(84);
    }
    check_protocol(port, proto);
    while (84) {
        if ((tft_client = accept(tft_server,
                                (struct sockaddr *)&cli, &len)) < 0) {
            close(tft_server);
            exit(EXIT_FAILURE);
        } else {
            if (server->log <= 2)
                server->log += 1;
            fork_iter(server);
        }
    }
}