/*
** EPITECH PROJECT, 2020
** jetpack2tek3
** File description:
** manage args of client
*/


#include <stdio.h>
#include "includes.h"
#include "jetpack_client.h"

void is_err(char *s, int value)
{
    if (s)
    printf("%s\n", s);
    exit(value ? 84 : 0);
}

void manage_args(client_t *cli, int ac, char **av)
{
    int j;

    j = 1;
    while (j < ac) {
        if (strcmp(av[j], "-h") == 0 && j + 1 < ac) {
	        cli->ip = av[++j];
            printf("%s\n", cli->ip);
        }
        else if (strcmp(av[j], "-p") == 0 && j + 1 < ac)
	        cli->port = atoi(av[++j]);
        else
            is_err("Bad or missing args.", 1);
        j++;
    }
    if (cli->port == -1 || cli->ip == NULL)
        is_err("bad format type -h for help", 1);
}

void *my_malloc(size_t size)
{
    void *stock;
    stock = malloc(size);
    if (!stock)
    is_err("Failed to malloc.", 1);
    return (stock);
}