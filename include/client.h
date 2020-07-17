/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <errno.h>
#include <dirent.h>
#include <stdio.h>
#include <signal.h>
#include <limits.h>

typedef struct s_client {
    char *store;
    char *desc;
    char *buffer;
    char **tab;
    fd_set rdfs;
} t_client;
struct sockaddr_in sockaddr;

struct sockaddr_in init_sockadrr(struct sockaddr_in to_fill, int port,
                                    struct hostent *hostinfo);
int recv_from(int socket);
fd_set init_select(int sock);
int init_sock(char *ip, int port);
int send_to(int sock, char *cmd);
int loop_main(int socket, t_client *client, size_t bufsize, size_t characters);
fd_set read_main(fd_set rdfs, int socket);
int errors(int ac, char **av);

#endif /* !CLIENT_H_ */
