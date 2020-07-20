/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** errors
*/

#include "client.h"
#include <ctype.h>

int errors(int ac, char **av)
{
    if (ac == 5) {
        char *arg = av[2];
        for (int i = 0; arg[i]; i++) {
            if ((arg[i] >= '0' && arg[i] <= '9') || arg[i] == '.') {
                i++;
            }
        }
    } else {
        return (84);
    }
    return (0);
}