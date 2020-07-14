/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019 NWP_myteams_2019
** File description:
** utilities
*/

#include <stdlib.h>

void free_darray(char **darray)
{
    for (int i = 0; darray[i] != NULL; i++)
        free(darray[i]);
    free(darray);
}

char **malloc_darray(char *str, char **d_str, char c)
{
    int nbr_line = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c || str[i] == '\n' || str[i] == '\r')
            nbr_line++;
    }
    d_str = malloc(sizeof(char *) * (nbr_line + 1));
    d_str[nbr_line] = NULL;
    return (d_str);
}

void malloc_lines(char *str, char **d_str, char c)
{
    int nbr_letter = 0;
    int y = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        while (str[i] != c && str[i] != '\n' && str[i] != '\r') {
            nbr_letter++;
            i++;
        }
        d_str[y] = malloc(sizeof(char) * (nbr_letter + 1));
        d_str[y][nbr_letter] = '\0';
        y++;
        nbr_letter = 0;
    }
}

void fill_lines(char *str, char **d_str, char c)
{
    int x = 0;
    int y = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != c && str[i] != '\n' && str[i] != '\r') {
            d_str[y][x] = str[i];
            x++;
        } else {
            y++;
            x = 0;
        }
    }
}

char **my_str_to_word_array(char *str, char c)
{
    char **d_str = NULL;

    d_str = malloc_darray(str, d_str, c);
    malloc_lines(str, d_str, c);
    fill_lines(str, d_str, c);
    return (d_str);
}