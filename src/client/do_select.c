/*
** EPITECH PROJECT, 2020
** do_select
** File description:
** do_select
*/

#include "../../include/jetpack_client.h"

void check_cmd(client_t *cli, char *cmd)
{
    int count = 0; 
    int j = 0;
    char **array;

    array = separate_str(cmd, ' ');
    while (array && array[j])
        j++;
    if (j == 0) {
        free_array(array);
        return ;
    }
    while (count < MAX_CMD) {
        if (strcmp(cli->cmds[count].tmp, array[0])){
            cli->cmds[count].func(cli, j, array);
            free_array(array);
            return ;
        }
        count++;
    }
}

void rd_cmd(client_t *cli, int socket)
{
    int size_stock;
    char *buff;

    if (!(buff = my_gnl(socket)) || feof(fdopen(socket, "r"))){
        close(socket);
        exit(0);
    }
    size_stock = strlen(buff);
    buff[size_stock] = 0;
    if (buff[size_stock - 1] == '\n')
        buff[size_stock - 1] = 0;
    if (size_stock > 1 && buff[size_stock - 2] == '\r')
        buff[size_stock - 2] = 0;
    check_cmd(cli, buff);
}

void do_select(client_t *cli)
{
    int size_stock;

    FD_ZERO(&cli->fds);
    FD_SET(cli->cli_sock, &cli->fds);
    while(1) {
        cli->rdfds = cli->fds;
        if ((size_stock = select(FD_SETSIZE, &cli->rdfds, NULL, NULL, NULL)) < 0)
            is_err(NULL, 1);
        if (size_stock > 0 && FD_ISSET(cli->cli_sock, &cli->rdfds))
            rd_cmd(cli, cli->cli_sock);
    }
}