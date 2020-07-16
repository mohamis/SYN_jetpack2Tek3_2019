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
} t_client;
struct sockaddr_in sockaddr;

struct sockaddr_in init_sockadrr(struct sockaddr_in to_fill, int port,
                                    struct hostent *hostinfo);

#endif /* !CLIENT_H_ */
