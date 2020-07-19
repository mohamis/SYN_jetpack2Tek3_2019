/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** server
*/

#include "jetpack.h"

int add_client_or_not(int sock, int *actual_client_nb,
    client_t **client_llist, int *max)
{
    struct sockaddr_in accept_sockaddr;
    unsigned int size = sizeof(accept_sockaddr);
    int user_socket = accept(sock, (struct sockaddr *) &accept_sockaddr, &size);

    if (user_socket == -1) {
        perror("accept()");
        close(sock);
        return (84);
    }
    if (*actual_client_nb != MAX_CLIENT) {
        if (*actual_client_nb == 0)
            *client_llist = add_head(*client_llist, user_socket);
        else
            *client_llist = add_last(*client_llist, user_socket);
        *actual_client_nb += 1;
        return (user_socket > *max ? user_socket : *max);
    } else {
        if (send_to(user_socket, 
            "too many client connected, closing connection\r\n"))
            return (84);
        close(user_socket);
    }
    return (0);
}

fd_set init_select(int sock, int actual_client_nb, int max, 
    client_t *client_llist)
{
    fd_set rdfs;
    fd_set err;
    client_t *tmp = client_llist;

    #ifdef __APPLE__
        err.fds_bits[0] = 84;
    #else
        err.__fds_bits[0] = 84;
    #endif
    FD_ZERO(&rdfs);
    FD_SET(STDIN_FILENO, &rdfs);
    FD_SET(sock, &rdfs);
    for (int i = 0; i < actual_client_nb; i++) {
        FD_SET(tmp->socket, &rdfs);
        tmp = tmp->next;
    }
    if (select(max + 1, &rdfs, NULL, NULL, NULL) == -1) {
        perror("select()");
        close(sock);
        return (err);
    }
    return (rdfs);
}

int main_loop(int sock, int *actual_client_nb, int *max, 
    client_t **client_llist)
{
    fd_set rdfs;

    rdfs = init_select(sock, *actual_client_nb, *max, *client_llist);
    #ifdef __APPLE__
        if (rdfs.fds_bits[0] == 84)
            return (84);
    #else
        if (rdfs.__fds_bits[0] == 84)
            return (84);
    #endif
    if (FD_ISSET(STDIN_FILENO, &rdfs)) {
        return (84);
    }
    else if (FD_ISSET(sock, &rdfs)) {
        *max = add_client_or_not(sock, actual_client_nb, client_llist, max);
        if (*max == 84)
            return (84);
    } else
        check_client(*actual_client_nb, rdfs, *client_llist);
    return (0);
}

int core(int port)
{
    int sock = init_socket(port);
    client_t *client_llist = NULL;
    int actual_client_nb = 0;
    int max = sock;
    proto_t *proto;

    if (sock == 84)
        return (84);
    signal(SIGINT, sigint_handler);
    (proto = getprotobyname("TCP"));
    if (proto == NULL) {
        perror("getprotobyname");
        exit(84);
    }
    while (1) {
        if (main_loop(sock, &actual_client_nb, &max, &client_llist) == 84)
            return (84);
    }
    close(sock);
    return (0);
}
