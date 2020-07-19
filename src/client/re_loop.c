/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** re_loop
*/

#include "client.h"
#include "jetpack_graph.h"
#include <ctype.h>

int init_loopback(int sock, char **lines, t_client *client)
{
    // char *parse = strtok(cmd, " \n\r\0");
    // char **lines = my_str_to_word_array(cmd, ' ');
    // printf("parse : %s %s %s\n", parse, cmd, lines);
    // printf("p->%s\n", parse);
    if (strcmp(lines[0], "ID") == 0) {
        printf("ID %s\n", lines[1]);
        client->status = 1;
    } if (strcmp(lines[0], "OK") == 0) {
        printf("OK %s\n", lines[1]);
        client->status = 2;
    } if (strcmp(lines[0], "MAP") == 0) {
        const char *separator = " ";
        char *b = strtok(client->desc, separator);
        while (b) {
            // printf("element: %s\n", b);
            client->store = strdup(b);
            b = strtok(NULL, separator);
        }
        printf("MAP %s %s %s\n", lines[1], lines[2], client->store);
        // printf("saved: %s\n", client->store);

        // for (char *p = strtok(client->desc, " "); client->desc != '\0'; client->desc = strtok(NULL, " ")) {
        //     // printf("MAP %s\n", p);
        //     // strdup(p);
        // }
        // printf("MAP ", lines[0]);
        // for (int x = 1; lines[x] != '\0'; x++) {
        //     for (int y = 0; lines[x][y] != '\0'; y++) {
        //         // printf("%c", map[x][y]);
        //         printf("%c", lines[x][y]);
        //     }
        // }
        // printf("OK %s\n", lines[1]);
        client->status = 42;
    }
}

char *init_loopfront(int sock, t_client *client)
{
    client->store = strdup("ID");
    // dprintf(sock, "ID\r\n");
    // int i = 100;
    // if (i > 0) {
    //     printf("stop");
    // } else {
    //     i = 120;
    // }
    // return (0);
    return (client->store);
}
