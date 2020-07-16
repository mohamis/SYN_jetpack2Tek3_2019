/*
** EPITECH PROJECT, 2020
** do_func
** File description:
** do_func
*/

#include "../../include/old_jetpack_client.h"

int id_cmd(char *buffer, client_t *cli)
{
    char **array;
    int value;

    array = my_str_to_word_array(buffer, ' ');
    if (len_array(array) == 2 &&
        strncmp("ID", array[0], strlen("ID") == 0)) {
            cli->id = atoi(array[1]);
            value = 0;
        } else 
            value = 1;
        free_array(array);
        return (value);
}

int map_cmd(char *buffer, client_t *cli)
{
    char **array;
    int value;

    array = my_str_to_word_array(buffer, ' ');
    if (len_array(array) == 4 &&
        strncmp("MAP", array[0], strlen("MAP") == 0)) {
            cli->widht = atoi(array[1]);
            cli->height = atoi(array[2]);
            value = 0;
        } else
            value = 1;
        free_array(array);
        return (value);
}
        