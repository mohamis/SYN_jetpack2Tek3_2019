/*
** EPITECH PROJECT, 2020
** jetpack2tek3
** File description:
** id cmd
*/

#include "../../../include/jetpack_client.h"

void id_cmd(client_t *cli, int ac, char **av)
{
    if (ac == 2) {
        cli->id = str_to_int(av[1]);
        cli->rcv |= 1;
        if (cli->rcv & 1 && cli->rcv & 2)
            dprintf(cli->cli_sock, "READY\n");
    } else
        return;
}
