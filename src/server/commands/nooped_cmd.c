/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** pwd
*/

#include "jetpack.h"

void ready(__attribute__((unused)) char *lines, __attribute__((unused))  client_t *server, __attribute__((unused)) int socket)
{
    if (server->database->log == 2) {
        dprintf(socket, "START\r\n");
    } else {
        printf("READY\r\n");
        dprintf(socket, "NOK\r\n");
    }
}

void getID(__attribute__((unused)) char *lines, __attribute__((unused))  client_t *server, __attribute__((unused)) int socket)
{
    printf("%d\r\n", server->database->log);
    dprintf(socket, "ID %d\r\n", server->database->log);
}

void player(__attribute__((unused)) char *lines, __attribute__((unused))  client_t *server, __attribute__((unused)) int socket)
{
    char **thisline = my_str_to_word_array(lines, ' ');
    // server->px = thisline[2];
    // server->py = thisline[3];
    printf("PLAYER %d %s %s\r\n", server->database->log, thisline[2], thisline[3]);
    free(thisline);
    // free_darray(thisline);
}

void coin(__attribute__((unused)) char *lines, __attribute__((unused))  client_t *server, __attribute__((unused)) int socket)
{
    dprintf(socket, "COIN %d %d %d\r\n", server->database->log, server->database->cx, server->database->cy);
}

void fire_dir(__attribute__((unused)) char *lines, __attribute__((unused))  client_t *server, __attribute__((unused)) int socket)
{
    printf("FIRE\r\n");
}

void start(__attribute__((unused)) char *lines, __attribute__((unused))  client_t *server, __attribute__((unused)) int socket)
{
    if (server->database->log == 2) {
        dprintf(socket, "START\r\n");
    } else
        dprintf(socket, "NOK\r\n");
}