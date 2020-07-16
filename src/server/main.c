/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** main
*/

#include "jetpack.h"
#include "includes.h"

void help_errors(int ac, char **av)
{
    if (av[1] != NULL && strcmp(av[1], "-help") == 0) {
        printf("USAGE:\t./serverJ2T3 port gravity map\n");
        printf("\t-p <port> port is the port number \
        on which the server socket listens");
        printf("\n");
        printf("\t-g <gravity> is the gravity for all players");
        printf("\n");
                printf("\n");
        printf("\t-m <map-file> file set for all players");
        printf("\n");
        exit(0);
    } else {
        FILE *file;
        if (ac != 7) {
            exit(84);
        }
        if ((file = fopen(av[6],"r")) == NULL) {
            fclose(file);
            exit(84);
        }
    }
}

void init_struct(server_t *server)
{
    server->cx = 0;
    server->cy = 0;
    server->saved = 0;
    server->px = 0;
    server->py = 0;
}

int main(int ac, char **av)
{
    help_errors(ac, av);
    server_t *server = malloc(sizeof(server_t));
    if (!server)
        exit (84);
    init_struct(server);
    core(atoi(av[2]), server);

    if (close(tft_server) == -1)
        perror("error");
    return 0;
}