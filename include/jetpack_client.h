/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** jetpack_client
*/

#ifndef JETPACK_H_
#define JETPACK_H_

#define MAX_CMD 6

#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct cmd_s
{
    char *tmp;
    void (*func)(void *, int, char **);

} cmd_t;

typedef struct client_s
{
    char s;
    char rcv;
    int cli_sock;
    char *ip;
    int id;
    fd_set  fds;
    int port;
    fd_set  rdfds;
    pthread_t thread;
    cmd_t cmds[MAX_CMD];
} client_t;

void *my_malloc(size_t size);
void manage_args(client_t *cli, int ac, char **av);
void is_err(char *s, int value);
void start_client(client_t *cli);
void set_connection(client_t *cli);

#endif