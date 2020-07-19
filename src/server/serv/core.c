/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** core
*/

#include "jetpack.h"

int send_to(int sock, char *cmd)
{
    if (send(sock, cmd, strlen(cmd), 0) < 0) {
        perror("send()");
        return (84);
    }
    return (0);
}

int recv_from(int socket, char **buffer, client_t *tmp, client_t *client_llist)
{
    char buff[1024];
    int n = recv(socket, buff, sizeof(buff) - 1, 0);

    if (n < 0) {
        perror("recv()");
        return (84);
    }
    buff[n] = '\0';
    *buffer = strdup(buff);

    // tmp->database->desc = strdup(buffer);

    // free_darray(lines);
    return (0);
}

void check_client(int actual_client_nb, fd_set rdfs,
    client_t *client_llist)
{
    char *buffer = malloc(sizeof(char) * 1024);
    client_t *tmp = client_llist;
    char **lines = NULL;

    for (int i = 0; i != actual_client_nb; i++) {
        if (FD_ISSET(tmp->socket, &rdfs)) {
            if (actual_client_nb > 0)
                tmp->database->log = actual_client_nb;
            if (recv_from(tmp->socket, &buffer, tmp, client_llist) == 84)
                exit(84);
            printf("%s", buffer);
            lines = my_str_to_word_array(buffer, ' ');
            printf("received %s\n", lines[0]);
            check_what(lines, tmp->socket, tmp, client_llist);
            // dprintf(tmp->socket, "ID %d\r\n", actual_client_nb);
            // free_darray(lines);
            free(buffer);
        }
        tmp = tmp->next;
    }
}