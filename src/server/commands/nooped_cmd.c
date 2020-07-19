/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** pwd
*/

#include "jetpack.h"

void ready(__attribute__((unused)) char *lines, __attribute__((unused))  server_t *server)
{
    printf("READY\r\n");
    dprintf(tft_client, "OK %d\r\n", server->log);
}

void getID(__attribute__((unused)) char *lines, __attribute__((unused))  server_t *server)
{
    printf("readed\r\n");
    server->count = 1;
    dprintf(tft_client, "ID %d\r\n", server->log);
}

void player(__attribute__((unused)) char *lines, __attribute__((unused))  server_t *server)
{
    char **thisline = my_str_to_word_array(lines, ' ');
    // server->px = thisline[2];
    // server->py = thisline[3];
    printf("PLAYER %d %s %s\r\n", server->log, thisline[2], thisline[3]);
    dprintf(tft_client, "OK %d\r\n", server->log);
    free(thisline);
    // free_darray(thisline);
}

void coin(__attribute__((unused)) char *lines, __attribute__((unused))  server_t *server)
{
    dprintf(tft_client, "COIN %d %d %d\r\n", server->log, server->cx, server->cy);
}

void fire_dir(__attribute__((unused)) char *lines, __attribute__((unused))  server_t *server)
{
    printf("FIRE\r\n");
    dprintf(tft_client, "OK %d\r\n", server->log);
}

void start(__attribute__((unused)) char *lines, __attribute__((unused))  server_t *server)
{
    dprintf(tft_client, "START\r\n");
    dprintf(tft_client, "OK %d\r\n", server->log);
}