/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** main
*/

#include "client.h"
#include <ctype.h>

int recv_from(int socket)
{
    char buffer[1024];
    int n = recv(socket, buffer, sizeof(buffer) - 1, 0);

    if (n < 0) {
        perror("recv()");
        return (84);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);
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

int init_sock(char *ip, int port)
{
    int sock = socket(PF_INET, SOCK_STREAM, 0);
    struct hostent *hostinfo = NULL;

    if (sock == -1) {
        perror("socket()");
        return (84);
    }
    hostinfo = gethostbyname(ip);
    if (hostinfo == NULL) {
        fprintf (stderr, "Unknown host %s.\n", ip);
        return (84);
    }
    sockaddr = init_sockadrr(sockaddr, port, hostinfo);
    if (connect(sock, (struct sockaddr *) &sockaddr,
                sizeof(struct sockaddr)) == -1) {
        perror("connect()");
        return (84);
    }
    return (sock);
}

int errors(int ac, char **av)
{
    if (ac == 5) {
        char *arg = av[2];
        for (int i = 0; arg[i]; i++) {
            if ((arg[i] >= '0' && arg[i] <= '9') || arg[i] == '.') {
                i++;
            }
        }
    } else {
        return (84);
    }
    return (0);
}

int send_to(int sock, char *cmd)
{
    if (send(sock, cmd, strlen(cmd), 0) < 0) {
        perror("send()");
        return (84);
    }
    return (0);
}

int main(int ac, char **av)
{
    t_client *client = malloc(sizeof(t_client));
    size_t bufsize = 0;
    size_t characters;
    int port = 0;
    int socket = 0;
    fd_set rdfs;

    if (errors(ac, av) != 84) {
        port = atoi(av[4]);
        socket = init_sock(av[2], port);
        if (socket == 84)
            return (84);
        while (1) {
            rdfs = init_select(socket);
            #ifdef __APPLE__
                if (rdfs.fds_bits[0] == 84)
                    return (84);
            #else
                if (rdfs.__fds_bits[0] == 84)
                    return (84);
            #endif
            if (FD_ISSET(STDIN_FILENO, &rdfs)) {
                    characters = getline(&client->buffer, &bufsize, stdin);
                    if (characters == (size_t) -1) {
                        perror("getline()");
                        close(socket);
                        return (84);
                    }
                    if (send_to(socket, client->buffer) == 84) {
                        close(socket);
                        return (84);
                    }
            } else if (FD_ISSET(socket, &rdfs)) {
                if (recv_from(socket) == 84)
                    return (84);
            }
        }
        close(socket);
        return (0);
    } else {
        return (84);
    }
}
