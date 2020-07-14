/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** jetpack
*/

#include "includes.h"
#include "utils.h"

#ifndef JETPACK_H_
#define JETPACK_H_

typedef struct server_s
{
    char *lines;
    void (*list)(char *lines);
    int log;
    int saved;
    int cx;
    int cy;
    int px;
    int py;
}   server_t;

typedef struct jetpack
{
    char *lines;
    void (*list)(char *lines, server_t *server);
    int log;
} func_t;

// utils/utilities.c
char **my_str_to_word_array(char *, char);
void free_darray(char **);

// server

void getID(char *lines, server_t *server);
void quit_finish(char *lines, server_t *server);
void pwd(char *lines, server_t *server);
void help_command(char *lines, server_t *server);
void map_files(char *lines, server_t *server);
void fire_dir(char *lines, server_t *server);
void coin(char *lines, server_t *server);
void start(char *lines, server_t *server);
void player(char *lines, server_t *server);
void ready(char *lines, server_t *server);
int read_lines(server_t *server);

char *init_buffer(char *lines);
void check_if_valid(char *lines, bool valid);
void remove_delim(char *lines, server_t *server);
void core(int port, server_t *server);
#endif /* !JETPACK_H_ */