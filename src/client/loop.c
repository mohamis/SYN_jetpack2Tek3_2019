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

int loop_main(int socket, t_client *client, size_t bufsize, size_t characters)
{
        while (1) {
            if (client->status == 0)
                send_to(socket, "ID\r\n", client);
            if (client->status == 1)
                send_to(socket, "MAP\r\n", client);
            if (client->status == 2)
                send_to(socket, "READY\r\n", client);
            if (client->status == 3)
                send_to(socket, "PLAYER 1 1 1 1\r\n", client);
            if (client->status == -1)
                send_to(socket, "WAIT\r\n", client);
            if (recv_from(socket, client) == 84)
                return (84);
            // client->rdfs = read_main(client->rdfs, socket);
            // if (FD_ISSET(socket, &client->rdfs)) {
            //     if (client->status == 0)
            //         dprintf(socket, "ID\r\n");
            //     if (recv_from(socket, client) == 84)
            //         return (84);
            //     // if (recv_from(socket, client) == 84)
            //     //     return (84);
            // } if (FD_ISSET(STDIN_FILENO, &client->rdfs)) {
            //         if (client->status == 0)
            //             dprintf(socket, "ID\r\n");
            //         if (recv_from(socket, client) == 84)
            //             return (84);
            //         // client->buffer = init_loopfront(socket, client);
            //         // characters = getline(&client->buffer, &bufsize, socket);
            //         // if (characters == (size_t) -1) {
            //         //     perror("getline()");
            //         //     close(socket);
            //         //     return (84);
            //         // }
            //         // if (send_to(socket, client->buffer, client) == 84) {
            //         //     close(socket);
            //         //     return (84);
            //         // }
            // }
        }
}