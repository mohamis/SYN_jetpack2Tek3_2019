/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** parsing
*/

#include "includes.h"
#include "jetpack.h"
#include "pipe.h"

char *init_buffer(char *lines)
{
    if (strlen(lines) > 0 && lines[strlen(lines) - 1] == '\n')
        lines[strlen(lines) - 1] = '\0';
    if (strlen(lines) > 0 && lines[strlen(lines) - 1] == '\r')
        lines[strlen(lines) - 1] = '\0';
    return (lines);
}

void remove_delim(char *buff)
{
    int i = 0;
    buff = init_buffer(buff);
    char *lines = strdup(buff);
    char *parse = strtok(buff, " ");
    bool is_valid = false;

    while (func[i].list) {
        if (parse != NULL && strcmp(parse, func[i].lines) == 0) {
            // if (func[i].log == 1 && usr != 2)
            //     dprintf(tft_client, "530 Error loging in.\r\n");
            // else
                func[i].list(lines);
            is_valid = true;
        }
        i++;
    }
    if (is_valid == false)
        is_valid = false;
    free(lines);
}