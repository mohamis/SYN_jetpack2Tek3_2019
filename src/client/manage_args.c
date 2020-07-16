/*
** EPITECH PROJECT, 2020
** manage_args
** File description:
** manage_args
*/

#include "../../include/jetpack_client.h"

int manage_args(int ac, char **av)
{
    int j = 3;
    int i = 1;
    
    if (ac != 5)
	    return (84);
    if ((strcmp(av[j], "-p")) != 0 && isdigit(av[j + 1] == 1))
	    return (84);
    if ((strcmp(av[i], "-h")) != 0 && av[i + 1] == NULL)
        return (84);
}
