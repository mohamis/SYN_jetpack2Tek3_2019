/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** commands_ext
*/

#include "client.h"
#include <ctype.h>

void coin(__attribute__((unused)) char *lines,
    __attribute__((unused))  t_client *client,
    __attribute__((unused))  int socket)
{
    printf("COIN %s %d %d\r\n", client->id, client->cx, client->cy);
}

void fire_dir(__attribute__((unused)) char *lines,
    __attribute__((unused))  t_client *client,
    __attribute__((unused))  int socket)
{
    dprintf(socket, "FIRE\r\n");
}

void start(__attribute__((unused)) char *lines,
    __attribute__((unused))  t_client *client,
    __attribute__((unused))  int socket)
{
    dprintf(socket, "START\r\n");
}