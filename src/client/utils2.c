/*
** EPITECH PROJECT, 2020
** utils2
** File description:
** utils2
*/

#include "../../include/old_jetpack_client.h"

int len_array(char **array)
{
    int count;

    count = 0;
    while (array[count])
        ++count;
    return (count);
}

void free_array(char **array)
{
    int j = 0;

    while (array[j] != NULL) {
        free(array[j]);
        j++;
    }
    free(array);
}