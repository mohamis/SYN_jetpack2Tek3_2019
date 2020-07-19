/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** destroy
*/
#include "jetpack_graph.h"
#include <stdlib.h>

void destroy_window(window_t *window, message_t **message)
{
    sfFont_destroy(window->font);
    sfClock_destroy(window->clock);
    sfRenderWindow_destroy(window->window);
    sfRectangleShape_destroy(window->rectp1);
    sfRectangleShape_destroy(window->rectp2);
    for (int i = 0; i <= 5; i++) {
        sfText_destroy(message[i]->text);
        sfFont_destroy(message[i]->font);
    }
}