/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** connect
*/

#include "jetpack.h"
#include "sockets.h"

void getLser(char *lines)
{
    char *buff = cut_buff(lines, " ");

    usr = 1;
    if (strcmp(buff, "Anonymous") == 0)
        usr = 0;
    dprintf(tft_client, "331 User name okay, need password.\r\n");
}
