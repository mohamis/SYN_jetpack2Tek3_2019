/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** main
*/

#include "jetpack.h"
#include "includes.h"

int errors(int ac, char **av)
{
    struct stat file_stat;

    if (ac == 7) {
        int n = strlen(av[2]);
        for (int i = 0; i < n; i++) {
            if (!isdigit(av[2][i])) {
                exit (84);
            }
        } if (stat(av[6], &file_stat) == -1) {
            exit (84);
        }
    } else {
        exit (84);
    }
    return (0);
}

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
        errors(ac, av);
    }
}

void init_struct(server_t *server, char *file)
{
    server->cx = 0;
    server->cy = 0;
    server->scy = NULL;
    server->scx = NULL;
    server->saved = 0;
    server->count = 0;
    server->coin = 0;
    server->px = NULL;
    server->py = NULL;
    server->pathname = file;
}

int main(int ac, char **av)
{
    help_errors(ac, av);
    server_t *server = malloc(sizeof(server_t));
    if (!server)
        exit (84);
    char *file = av[6];
    init_struct(server, file);
    core(atoi(av[2]), server);

    if (close(tft_server) == -1)
        perror("error");
    free(server);
    return 0;
}