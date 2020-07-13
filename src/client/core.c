/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** core
*/

#include "jetpack_client.h"
#include "includes.h"

int errors(char **arg)
{
    return 0;
}

int core(char **arg)
{
    if (errors(arg) == 0)
        return 0;
    else
        return (errors(arg));
}