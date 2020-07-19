/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** jetpack
*/

#ifndef JETPACK_H_
#define JETPACK_H_

#include "includes.h"
#include "utils.h"
#define MAX_CLIENT 2

char *file;
// structures
typedef struct server_s
{
    int count;
    char *desc;
    int log;
    char *id;
    int saved;
    int cx;
    int cy;
    char *scy;
    char *scx;
    int coin;
    char *px;
    char *py;
    char *pathname;
}   server_t;

typedef struct client_s {
    struct client_s *prev;
    struct client_s *next;
    server_t *database;
    int socket;
} client_t;

typedef struct jetpack
{
    char *lines;
    void (*list)(char *lines, client_t *server, int socket);
    int log;
} func_t;


// utils/utilities.c
char **my_str_to_word_array(char *, char);
void free_darray(char **);

// server

void getID(char *lines, client_t *server, int socket);
void quit_finish(char *lines, client_t *server, int socket);
void map_files(char *lines, client_t *server, int socket);
void fire_dir(char *lines, client_t *server, int socket);
void coin(char *lines, client_t *server, int socket);
void start(char *lines, client_t *server, int socket);
void player(char *lines, client_t *server, int socket);
void ready(char *lines, client_t *server, int socket);
void quit_finish(char *lines, client_t *server, int socket);
void map_files(char *lines, client_t *server, int socket);
// int read_lines(server_t *server);


void check_what(char **buffer, int socket, client_t *client, 
    client_t *client_llist);
void database(char *buffer, int socket, client_t *client, 
    client_t *client_llist);
// utilities/tab.c
char **my_str_to_word_array(char *, char);
void free_darray(char **);

// server functions
void sigint_handler(int sig);
int send_to(int sock, char *cmd);
int recv_from(int socket, char **buffer, client_t *tmp, client_t *client_llist);
void check_client(int actual_client_nb, fd_set rdfs, client_t *client_llist);
int server(int);

// init functions
int init_socket(int);

// linked list functions
client_t *add_head(client_t *list, int sock);
client_t *add_last(client_t *list, int sock);
client_t *find_data(client_t *list, int sock);
void remove_node(client_t *list, int sock);
void free_linked_list(client_t *linked_list);

// char *init_buffer(char *lines);
// void check_if_valid(char *lines, bool valid);
void remove_delim(char *lines, client_t *list, int socket);
int core(int port);
char *concat(const char *s1, const char *s2);
// void sigint_handler(int sig);

#endif /* !JETPACK_H_ */