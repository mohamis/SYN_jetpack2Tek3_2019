/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** list
*/

#include "jetpack.h"

void loop_map(char **map)
{
    for (int x = 0; map[x] != NULL; x++) {
        for (int y = 0; map[x][y] != '\0'; y++) {
            // printf("%c", map[x][y]);
            dprintf(tft_client, "%c", map[x][y]);
        }
    }
}

int send_to(int sock, char *cmd)
{
    if (send(sock, cmd, strlen(cmd), 0) < 0) {
        perror("send()");
        return (84);
    }
    return (0);
}

int count_lines(char *filename, server_t *server)
{
    FILE *search = fopen(filename, "r");
    int size = 0;
    size_t len = 0;
    char *dat = NULL;
    ssize_t read;

    if (!search) {
        perror(filename);
        return (NULL);
    }
    fseek(search, 0, SEEK_END);
    size = ftell(search);
    fseek(search, 0, SEEK_SET);
    dat = malloc(size);
    for (server->cy; (read = getline(&dat, &len, search)) != -1; server->cy++) {
        server->cx = read - 1;
        // server->cy =+ 1;
        // printf("%s", data);
    }

    fclose(search);
}

char *cread_table(char *filename, server_t *server)
{
    FILE *search = fopen(filename, "r");
    int size = 0;
    size_t len = 0;
    char *data = NULL;

    if (!search) {
        perror(filename);
        return (NULL);
    }
    fseek(search, 0, SEEK_END);
    size = ftell(search);
    fseek(search, 0, SEEK_SET);
    data = malloc(size);

    fread(data, size, 1, search);
    fclose(search);
    return (data);
}

void list(char *filename, int socket, server_t *server)
{
    count_lines(filename, server);
    asprintf(&server->scy,  "%d", server->cy);
    asprintf(&server->scx,  "%d", server->cx);
    char *size = concat(server->scy, " ");
    char *size2 = concat(size, server->scx);
    char *size3 = concat(size2, " ");
    char *nfile1 = concat("MAP ", size3);
    char *nfile3 = concat(nfile1, cread_table(filename, server));
    // printf("%d\n", server->cy);
    // printf("%s\n", nfile3);

    send_to(socket, nfile3);
}

void map_files(__attribute__((unused)) char *lines, __attribute__((unused))  server_t *server)
{
    list(server->pathname, tft_client, server);
}