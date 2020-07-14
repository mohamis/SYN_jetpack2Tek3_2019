/*
** EPITECH PROJECT, 2020
** jetpack2tek3
** File description:
** manage args of client
*/


#include <stdio.h>
#include "includes.h"

int manage_args(int ac, char **av)
{
    if (ac != 5) {
        printf("bad number of args");
        return (84);
    }
}