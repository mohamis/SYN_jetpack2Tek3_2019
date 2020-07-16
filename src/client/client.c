/*
** EPITECH PROJECT, 2020
** client
** File description:
** client
*/

#include "../../include/jetpack_client.h"

void send_data(int sock, char *buffer)
{
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("send()");
        exit(errno);
    }
}

int read_data(int sock, char *buffer)
{
    int i = 0;

    if ((i = recv(sock, buffer, sizeof(buffer - 1), 0)) < 0 ) {
        perror("recv()");
        exit(errno);
    }
    buffer[i] = 0;
    return (i);
}