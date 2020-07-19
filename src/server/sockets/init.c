/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** init
*/

#include "jetpack.h"

struct sockaddr_in init_sockadrr(struct sockaddr_in to_fill, int port)
{
    to_fill.sin_addr.s_addr = htonl(INADDR_ANY);
    to_fill.sin_port = htons(port);
    to_fill.sin_family = PF_INET;
    return (to_fill);
}

int init_socket(int port)
{
    int sock = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sockaddr;

    if (sock == -1) {
        perror("socket()");
        return (84);
    }
    sockaddr = init_sockadrr(sockaddr, port);
    if (bind(sock, (struct sockaddr *) &sockaddr, sizeof(sockaddr)) == -1) {
        close(sock);
        perror("bind()");
        return (84);
    }
    if (listen(sock, MAX_CLIENT) == -1) {
        close(sock);
        perror("listen()");
        return (84);
    }
    return (sock);
}