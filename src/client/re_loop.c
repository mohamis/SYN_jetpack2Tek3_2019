/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** re_loop
*/

#include "client.h"
#include "jetpack_graph.h"
#include <ctype.h>

int init_loopback(int sock, char **lines, t_client *client)
{
    if (strcmp(lines[0], "ID") == 0) {
        printf("ID %s\n", lines[1]);
        client->status = 1;
    }  if (strcmp(lines[0], "MAP") == 0) {
        const char *separator = " ";
        char *b = strtok(client->desc, separator);
        while (b) {
            client->store = strdup(b);
            b = strtok(NULL, separator);
        }
        printf("MAP %s %s %s\n", lines[1], lines[2], client->store);
        client->status = 2;
    } if (strcmp(lines[0], "WAIT") == 0) {
        client->status = -1;
    } if (strcmp(lines[0], "START") == 0) {
        printf("STARTED!!!!\n");
        client->status = 3;
    }
}

char *init_loopfront(int sock, t_client *client)
{
    client->store = strdup("ID");
    // dprintf(sock, "ID\r\n");
    // int i = 100;
    // if (i > 0) {
    //     printf("stop");
    // } else {
    //     i = 120;
    // }
    // return (0);
    return (client->store);
}
