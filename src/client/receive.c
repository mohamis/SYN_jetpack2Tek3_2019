/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** receive
*/

#include "client.h"
#include "c_pipe.h"
#include <ctype.h>

char *init_buffer(char *lines)
{
    if (strlen(lines) > 0 && lines[strlen(lines) - 1] == '\n')
        lines[strlen(lines) - 1] = '\0';
    if (strlen(lines) > 0 && lines[strlen(lines) - 1] == '\r')
        lines[strlen(lines) - 1] = '\0';
    return (lines);
}

void remove_delim(int socket, char *buff, t_client *server)
{
    int i = 0;
    buff = init_buffer(buff);
    char *lines = strdup(buff);
    char *parse = strtok(buff, " ");
    bool is_valid = false;

    while (c_func[i].list) {
        if (parse != NULL && strcmp(parse, c_func[i].lines) == 0) {
                c_func[i].list(lines, server, socket);
            is_valid = true;
        }
        i++;
    }
    if (is_valid == false)
        is_valid = false;
    free(lines);
}

int recv_from(int socket, t_client *client)
{
    char buffer[5000];
    memset(buffer ,0 , 5000);
    int n = recv(socket, buffer, 5000, 0);
    char **lines = NULL;

    if (n < 0) {
        perror("recv()");
        return (84);
    }
    buffer[n] = '\0';
    client->desc = strdup(buffer);
    // printf("from : %s\n", buffer);
    // printf("dest : %s\n", client->desc);
    lines = my_str_to_word_array(client->desc, ' ');
    // printf("lines : %s\n", lines[1]);
    // printf("lines2 : %s\n", lines[10]);
    init_loopback(socket, lines, client);
    // client->store = strdup(buffer);
    // free(lines);
    free_darray(lines);
    return (0);
}

fd_set init_select(int sock)
{
    fd_set rdfs;
    fd_set err;

    #ifdef __APPLE__
        err.fds_bits[0] = 84;
    #else
        err.__fds_bits[0] = 84;
    #endif
    FD_ZERO(&rdfs);
    FD_SET(STDIN_FILENO, &rdfs);
    FD_SET(sock, &rdfs);
    if (select(sock + 1, &rdfs, NULL, NULL, NULL) == -1) {
        perror("select()");
        close(sock);
        return (err);
    }
    return (rdfs);
}

struct sockaddr_in init_sockadrr(struct sockaddr_in to_fill, int port,
                                    struct hostent *hostinfo)
{
    to_fill.sin_addr = *(struct in_addr *) hostinfo->h_addr_list[0];
    to_fill.sin_port = htons(port);
    to_fill.sin_family = PF_INET;
    return (to_fill);
}