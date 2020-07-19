/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** data
*/

#include "jetpack.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>


void check_what(char **buffer, int socket, client_t *client, client_t *client_llist)
{
    if (strcmp(buffer[0], "ID") == 0) {
        char id[20];
        sprintf(id, "%d", client->database->log);
        client->database->desc = concat("ID ", id);
        printf("%s\n", client->database->desc);
        send_to(socket, client->database->desc);
    }  if (strcmp(buffer[0], "MAP") == 0) {
        map_files(buffer, client, socket);
    } if (strcmp(buffer[0], "READY") == 0) {
        if (client->database->log == 2) {
            while (client_llist != NULL) {
                send_to(client_llist->socket, "START");
                client_llist = client_llist->next;
            }
        } else 
            send_to(socket, "WAIT");
        // printf("OTHER OPPONENT NOT CONNECTED\n");
    } if (strcmp(buffer[0], "PLAYER") == 0) {
        // send_to(socket, "OK");
        printf("OTHER OPPONENT CONNECTED\n");
    } if (strcmp(buffer[0], "WAIT") == 0) {
        if (client->database->log == 2) {
            while (client_llist != NULL) {
                send_to(client_llist->socket, "START");
                client_llist = client_llist->next;
            }
        } else 
            send_to(socket, "WAIT");
    }
    // if (strcmp("ID", buffer) == 0) {
    //     while (client_llist != NULL) {
    //         send_to(client_llist->socket, "yes");
    //         client_llist = client_llist->next;
    //     }
    // }
}

void database(char *buffer, int socket, client_t *client,
                client_t *client_llist)
{
    check_what(buffer, socket, client, client_llist);
}