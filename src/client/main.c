/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** main
*/

#include "jetpack_client.h"
#include "includes.h"

void help_errors(int ac, char **av)
{
    if (av[1] != NULL && strcmp(av[1], "-help") == 0) {
        printf("USAGE:\t./clientJ2T3 ip port\n");
        printf("\t-h <ip> used to set <ip> as the IP");
        printf("\n");
        printf("\t-p <port> is the port number \
        on which the server socket listens");
        printf("\n");
        exit(0);
    } else {
        if (ac != 6) {
            perror("Arguments invalides\n");
            exit(1);
        }
    }
}

int main(int ac, char **av)
{
    help_errors(ac, av);
    core();

    // if (close(tft_server) == -1)
    //     perror("error");
    return 0;
}