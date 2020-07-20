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
#include <stdbool.h>
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
    char *id;
    char *px;
    char *py;
    int status;
    int fstatus;
    int cx;
    int cy;
    fd_set rdfs;
} t_client;
struct sockaddr_in sockaddr;

typedef struct jetpack
{
    char *lines;
    void (*list)(char *lines, t_client *client, int socket);
    int log;
} jet_t;

// utils/utilities.c
char **my_str_to_word_array(char *, char);
void free_darray(char **);

struct sockaddr_in init_sockadrr(struct sockaddr_in to_fill, int port,
                                    struct hostent *hostinfo);
int recv_from(int socket, t_client *client);
fd_set init_select(int sock);
int init_sock(char *ip, int port);
void remove_delim(int socket, char *buff, t_client *server);
int send_to(int sock, char *cmd);
int loop_main(int socket, t_client *client);
fd_set read_main(fd_set rdfs, int socket);
int errors(int ac, char **av);

void ready(__attribute__((unused)) char *lines,
            __attribute__((unused))  t_client *client, int socket);
void algeo(__attribute__((unused)) char *lines,
            __attribute__((unused))  t_client *client, int socket);
void getID(__attribute__((unused)) char *lines,
            __attribute__((unused))  t_client *client, int socket);
void player(__attribute__((unused)) char *lines,
            __attribute__((unused))  t_client *client, int socket);
void coin(__attribute__((unused)) char *lines,
            __attribute__((unused))  t_client *client, int socket);
void fire_dir(__attribute__((unused)) char *lines,
            __attribute__((unused))  t_client *client, int socket);
void start(__attribute__((unused)) char *lines,
            __attribute__((unused))  t_client *client, int socket);
void init_loopback(char **lines, t_client *client);
char *concat(const char *s1, const char *s2);

#endif /* !CLIENT_H_ */
