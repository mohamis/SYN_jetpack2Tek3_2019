/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** utils
*/

#include "jetpack.h"

char *cut_buff(char *lines, char *delim)
{
    char *buff = strtok(lines, delim);
    buff = strtok(NULL, delim);

    return buff;
}