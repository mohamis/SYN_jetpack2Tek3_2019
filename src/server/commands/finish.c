/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** quit
*/

#include "jetpack.h"
#include "sockets.h"

void quit_finish(__attribute__((unused)) char *lines)
{
    dprintf(tft_client, "FINISH <COIN>\r\n");
}