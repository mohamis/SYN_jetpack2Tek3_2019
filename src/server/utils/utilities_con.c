/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** utilities_con
*/

#include "includes.h"

char *concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1);

    if (!result)
        return (NULL);
    strcpy(result, s1);
    strcat(result, s2);
    return (result);
}

void sigint_handler(int sig)
{
    signal(sig, SIG_IGN);
}