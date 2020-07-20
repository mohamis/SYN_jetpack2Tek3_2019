/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** re_loop
*/

#include "client.h"
#include "jetpack_graph.h"
#include <ctype.h>

void init_loopback(char **lines, t_client *client)
{
    if (strcmp(lines[0], "ID") == 0) {
        printf("ID %s\n", lines[1]);
        client->id = strdup(lines[1]);
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
    } if (strcmp(lines[0], "NOK") == 0) {
        printf("OTHER OPPONENT NOT CONNECTED\n");
        client->status = 42;
    } if (strcmp(lines[0], "WAIT") == 0) {
        printf("OTHER OPPONENT NOT CONNECTED\n");
        client->status = 42;
    } if (strcmp(lines[0], "START") == 0) {
        printf("STARTED!!!!\n");
        client->status = 3;
    } if (strcmp(lines[0], "PLAYER") == 0) {
        client->status = 3;
    }
}
