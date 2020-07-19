/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** main
*/

#include "client.h"
#include <ctype.h>

t_client *init_client(void)
{
    t_client *client = malloc(sizeof(t_client));

    client->py = 0;
    client->px = 0;
    client->id = 0;
    client->cx = 0;
    client->cy = 0;
    client->status = 0;
    client->fstatus = 0;
    client->buffer = NULL;
    return (client);
}

int main(int ac, char **av)
{
    t_client *client = init_client();;
    size_t bufsize = 0;
    size_t characters = 0;
    int port = 0;
    int socket = 0;

    if (errors(ac, av) != 84) {
        port = atoi(av[4]);
        socket = init_sock(av[2], port);
        if (socket == 84)
            return (84);
        if (loop_main(socket, client, bufsize, characters) == 84)
            return (84);
        free(client);
        close(socket);
        return (0);
    } else {
        return (84);
    }
}
