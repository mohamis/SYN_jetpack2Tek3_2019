/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** destroy
*/
#include "jetpack_graph.h"
#include <stdlib.h>

void destroy_window(window_t *window)
{
    sfText_destroy(window->text);
    sfFont_destroy(window->font);
    sfClock_destroy(window->clock);
    sfRenderWindow_destroy(window->window);
}