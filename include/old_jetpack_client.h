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
#include <sys/time.h>
#include <sys/select.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

typedef struct client_s
{
    int id;
    char *map;
    int widht;
    int height;
    char player;
    int state_fire;
    int finish;
} client_t;
#endif

int my_isnum(char *str);
int manage_args(int ac, char **av);
void free_array(char **array);