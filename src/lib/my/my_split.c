/*
** EPITECH PROJECT, 2020
** split
** File description:
** split
*/

#include "../../../include/jetpack_client.h"

int find_size(char *str, char carac)
{
    int j = 0; 
    int i = 0;

    while (str[i]) {
        if (str[i] == carac)
            j++;
        i++;
    }
    return (j);
}

char **separate_str(char *str, char carac)
{
    char s[2];
    char **array;
    int i = 0;
    char *stock;

    s[0] = carac;
    s[1] = 0;
    array = my_malloc(sizeof(char *) * (find_size(str, carac) + 2));
    while (stock = strtok(i == 0 ? str : NULL, s)) {
        array[i] = stock;
        i++;
    }
    array[i] = 0;
    return (array);
}
