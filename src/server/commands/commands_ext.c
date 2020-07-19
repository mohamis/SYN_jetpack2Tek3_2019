/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** commands_ext
*/

#include "jetpack.h"

void fire_dir(__attribute__((unused)) char *lines,
    __attribute__((unused))  server_t *server)
{
    printf("FIRE\r\n");
}

void start(__attribute__((unused)) char *lines,
    __attribute__((unused))  server_t *server)
{
    if (strcmp("2", file_stat("./.jetpack.log")) == 0) {
        dprintf(tft_client, "START\r\n");
    } else
        dprintf(tft_client, "NOK\r\n");
}