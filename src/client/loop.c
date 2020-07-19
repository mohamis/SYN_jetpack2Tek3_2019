/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** loop
*/

#include "client.h"
#include <ctype.h>

fd_set read_main(fd_set rdfs, int socket)
{
                rdfs = init_select(socket);
            #ifdef __APPLE__
                if (rdfs.fds_bits[0] == 84)
                    exit (84);
            #else
                if (rdfs.__fds_bits[0] == 84)
                    exit (84);
            #endif
            return (rdfs);
}

int loop_main(int socket, t_client *client)
{
        while (1) {
            if (client->status == 0)
                dprintf(socket, "ID\r\n");
            if (client->status == 1)
                dprintf(socket, "MAP\r\n");
            if (client->status == 2)
                dprintf(socket, "READY\r\n");
            if (client->status == 42)
                dprintf(socket, "WAITING\r\n");
            if (client->status == 3)
                dprintf(socket, "PLAYER %s 1 1 1\r\n", client->id);
            if (recv_from(socket, client) == 84)
                return (84);
        }
}