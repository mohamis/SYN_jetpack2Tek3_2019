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
            printf("Arguments invalides\n");
            printf("%d",ac);
            exit(1);
        }
        if ((file = fopen(av[6],"r")) == NULL) {
            printf("Map invalide\n");
            fclose(file);
            exit(1);
        }
    }
}

int main(int ac, char **av)
{
    help_errors(ac, av);
    core(av);

    // if (close(tft_server) == -1)
    //     perror("error");
    return 0;
}