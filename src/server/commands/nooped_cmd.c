/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** pwd
*/

#include "jetpack.h"

void ready(__attribute__((unused)) char *lines,
    __attribute__((unused))  server_t *server)
{
    if (strcmp("2", file_stat("./.jetpack.log")) == 0) {
        dprintf(tft_client, "START\r\n");
    } else {
        printf("WAITING\r\n");
        dprintf(tft_client, "WAIT\r\n");
    }
}

void waiting(__attribute__((unused)) char *lines,
    __attribute__((unused))  server_t *server)
{
    if (strcmp("2", file_stat("./.jetpack.log")) == 0) {
        dprintf(tft_client, "START\r\n");
    } else {
        printf("WAITING\r\n");
        dprintf(tft_client, "WAIT\r\n");
    }
}

void getID(__attribute__((unused)) char *lines,
    __attribute__((unused))  server_t *server)
{
    printf("%d\r\n", server->log);
    dprintf(tft_client, "ID %d\r\n", server->log);
}

void player(__attribute__((unused)) char *lines,
    __attribute__((unused))  server_t *server)
{
    char **thisline = my_str_to_word_array(lines, ' ');
    printf("PLAYER %d %s %s\r\n", server->log, thisline[2], thisline[3]);
    dprintf(tft_client, "PLAYER\r\n");
    free(thisline);
}

void coin(__attribute__((unused)) char *lines,
    __attribute__((unused))  server_t *server)
{
    dprintf(tft_client, "COIN %d %d %d\r\n", server->log,
        server->cx, server->cy);
}