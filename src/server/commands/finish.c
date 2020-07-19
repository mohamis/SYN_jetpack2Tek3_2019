/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** quit
*/

#include "jetpack.h"
#include "sockets.h"

void quit_finish(__attribute__((unused)) char *lines, __attribute__((unused))  client_t *server, int socket)
{
    dprintf(socket, "FINISH %d\r\n", server->database->coin);
}