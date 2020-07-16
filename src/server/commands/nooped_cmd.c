/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** pwd
*/

#include "jetpack.h"

void ready(__attribute__((unused)) char *lines, __attribute__((unused))  server_t *server)
{
    dprintf(tft_client, "READY\r\n");
}

void getID(__attribute__((unused)) char *lines, __attribute__((unused))  server_t *server)
{
    dprintf(tft_client, "ID %d\r\n", server->log);
}

void player(__attribute__((unused)) char *lines, __attribute__((unused))  server_t *server)
{
    char **thisline = my_str_to_word_array(lines, ' ');
    server->px = atoi(thisline[1]);
    server->py = atoi(thisline[2]);
    dprintf(tft_client, "PLAYER %d %d %d\r\n", server->log, server->px, server->py);
    free_darray(thisline);
}

void coin(__attribute__((unused)) char *lines, __attribute__((unused))  server_t *server)
{
    dprintf(tft_client, "COIN %d %d %d\r\n", server->log, server->cx, server->cy);
}

void fire_dir(__attribute__((unused)) char *lines, __attribute__((unused))  server_t *server)
{
    dprintf(tft_client, "FIRE\r\n");
}

void start(__attribute__((unused)) char *lines, __attribute__((unused))  server_t *server)
{
    dprintf(tft_client, "START\r\n");
}