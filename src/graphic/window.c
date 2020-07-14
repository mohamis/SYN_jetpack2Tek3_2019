/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** window
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "jetpack_graph.h"

window_t *init_game(window_t *window)
{
    window->video_mode = (sfVideoMode) {1920, 1080, 30};
    window->window = sfRenderWindow_create(window->video_mode, "JetToPackTEK3",
                                            sfDefaultStyle, NULL);
    window->clock = sfClock_create();
    window->seconds = 0;
    window->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(window->rect, (sfVector2f) {0, 1010});
    if (window->rect == NULL)
        return (NULL);
    return (window);
}

void manage_event(window_t *window)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        if (window->event.type == sfEvtClosed)
            sfRenderWindow_close(window->window);
        if (window->event.type == sfEvtKeyPressed) {
            if (sfKeyboard_isKeyPressed(sfKeySpace) && window->fire == 0)
                window->fire = 1;
        }
    }
}

int create_window(void)
{
    window_t *window = malloc(sizeof(window_t));
    button_t **button = init_button();

    if (window == NULL)
        return (84);
    init_game(window);
    sfRenderWindow_setFramerateLimit(window->window, 60);
    while (sfRenderWindow_isOpen(window->window)) {
        manage_event(window);
        sfRenderWindow_clear(window->window, sfBlack);
        animation_manager(window);
        manage_infos(window);
        sfRenderWindow_drawRectangleShape(window->window, window->rect, NULL);
        sfRenderWindow_display(window->window);
    }
    destroy_window(window);
    free(window);
    return (0);
}

int main(void)
{
    return (create_window());
}