/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** commands
*/

#include "client.h"
#include <ctype.h>

void ready(__attribute__((unused)) char *lines, __attribute__((unused))  t_client *client, __attribute__((unused))  int socket)
{
    dprintf(socket, "READY\r\n");
}

void getID(__attribute__((unused)) char *lines, __attribute__((unused))  t_client *client, __attribute__((unused))  int socket)
{
    dprintf(socket, "ID\r\n");
}

void algeo(__attribute__((unused)) char *lines, __attribute__((unused))  t_client *server, __attribute__((unused)) int socket)
{
    printf("ok %s\r\n", server->id);
}

void player(__attribute__((unused)) char *lines, __attribute__((unused))  t_client *client, __attribute__((unused))  int socket)
{
    printf("PLAYER ok\r\n");
    char **thisline = my_str_to_word_array(lines, ' ');
    // printf("PLAY %s\n", thisline[1]);
    // client->px = thisline[2];
    // client->py = thisline[3];
    dprintf(socket, "PLAYER %s %s %s %d\r\n", client->id, thisline[2], thisline[3], 1);
    // dprintf(socket, "PLAYER %d %s %s\r\n", client->log, client->px, client->py);
    // dprintf(socket, "");
    free(thisline);
    // free_darray(thisline);
}

void coin(__attribute__((unused)) char *lines, __attribute__((unused))  t_client *client, __attribute__((unused))  int socket)
{
    printf("COIN %s %d %d\r\n", client->id, client->cx, client->cy);
}

void fire_dir(__attribute__((unused)) char *lines, __attribute__((unused))  t_client *client, __attribute__((unused))  int socket)
{
    dprintf(socket, "FIRE\r\n");
}

void start(__attribute__((unused)) char *lines, __attribute__((unused))  t_client *client, __attribute__((unused))  int socket)
{
    dprintf(socket, "START\r\n");
}