/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** sending
*/

#include "client.h"
#include <ctype.h>

int init_sock(char *ip, int port)
{
    int sock = socket(PF_INET, SOCK_STREAM, 0);
    struct hostent *hostinfo = NULL;

    if (sock == -1) {
        perror("socket()");
        return (84);
    }
    hostinfo = gethostbyname(ip);
    if (hostinfo == NULL) {
        fprintf (stderr, "Unknown host %s.\n", ip);
        return (84);
    }
    sockaddr = init_sockadrr(sockaddr, port, hostinfo);
    if (connect(sock, (struct sockaddr *) &sockaddr,
                sizeof(struct sockaddr)) == -1) {
        perror("connect()");
        return (84);
    }
    return (sock);
}

int send_to(int sock, char *cmd)
{
    if (send(sock, cmd, strlen(cmd), 0) < 0) {
        perror("send()");
        return (84);
    }
    return (0);
}