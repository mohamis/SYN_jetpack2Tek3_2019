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
typedef struct func_s
{
    char *lines;
    void (*list)(char *lines);
    int log;

}   func_t;

void getLser(char *lines);
void quit_finish(char *lines);
void pwd(char *lines);
void help_command(char *lines);
void map_files(char *lines);
void fire_dir(char *lines);
void coin(char *lines);
void start(char *lines);
void player(char *lines);
void ready(char *lines);

char *init_buffer(char *lines);
void check_if_valid(char *lines, bool valid);
void remove_delim(char *lines);
void core(int port);
#endif /* !JETPACK_H_ */