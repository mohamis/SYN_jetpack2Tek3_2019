/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** client
*/

#include "jetpack.h"

client_t *add_head(client_t *list, int sock)
{
    client_t *head_node = malloc(sizeof(client_t));

    if (head_node == NULL)
        return (NULL);
    head_node->database = malloc(sizeof(server_t) * 1);
    if (head_node->database == NULL)
        return (NULL);
    head_node->database->cx = 0;
    head_node->database->cy = 0;
    head_node->database->scy = NULL;
    head_node->database->scx = NULL;
    head_node->database->saved = 0;
    head_node->database->count = 0;
    head_node->database->pathname = file;
    head_node->database->px = NULL;
    head_node->database->py = NULL;
    head_node->socket = sock;
    head_node->next = list;
    head_node->prev = NULL;
    return (head_node);
}

client_t *add_last(client_t *list, int sock)
{
    client_t *last_node = malloc(sizeof(client_t));
    client_t *tmp = NULL;

    if (last_node == NULL)
        return (NULL);
    last_node->database = malloc(sizeof(server_t) * 1);
    if (last_node->database == NULL)
        return (NULL);
    last_node->database->cx = 0;
    last_node->database->cy = 0;
    last_node->database->scy = NULL;
    last_node->database->scx = NULL;
    last_node->database->saved = 0;
    last_node->database->count = 0;
    last_node->database->pathname = file;
    last_node->database->px = NULL;
    last_node->database->py = NULL;
    last_node->socket = sock;
    last_node->prev = list;
    last_node->next = NULL;
    if (list == NULL)
        return (last_node);
    else {
        tmp = list;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = last_node;
        return (list);
    }
}

client_t *find_data(client_t *list, int sock)
{
    client_t *tmp = list;

    while (tmp != NULL) {
        if (tmp->socket == sock)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

void remove_node(client_t *list, int sock)
{
    client_t *tmp = list;
    client_t *previous = NULL;

    if (tmp != NULL && tmp->socket == sock) {
        tmp = tmp->next;
        free(tmp);
        return;
    }
    while (tmp != NULL && tmp->socket == sock) {
        previous = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return;
    previous->next = tmp->next;
    free(tmp);
    return;
}

void free_linked_list(client_t *linked_list)
{
    client_t *tmp = linked_list;

    while (tmp != NULL) {
        linked_list = linked_list->next;
        free(tmp);
        tmp = linked_list;
    }
}