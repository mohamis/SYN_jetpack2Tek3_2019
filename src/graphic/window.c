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
    window->rectp1 = sfRectangleShape_create();
    window->rectp2 = sfRectangleShape_create();
    window->gravity = 12;
    window->s_fire = 0;
    window->x_move = 0.0;
    window->y_move = 0.0;
    sfRectangleShape_setPosition(window->rectp1, (sfVector2f) {0, 900});
    sfRectangleShape_setPosition(window->rectp2, (sfVector2f) {0, 900});
    if (window->rectp1 == NULL)
        return (NULL);
    if (window->rectp2 == NULL)
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
        } if (window->event.type == sfEvtKeyReleased) {
            if (sfKeySpace)
                window->fire = 0;
        }
        printf("%d", window->fire);
    }
}

char **init_manage(void)
{
    char **text = malloc(sizeof(char *) * 6);
    text[0] = "Legend";
    text[1] = "Coins";
    text[2] = "Fence";
    text[3] = "Player 1";
    text[4] = "Player 2";
    text[5] = "Space for Jetpack";
    text[6] = NULL;
    return (text);
}

int create_window(void)
{
    window_t *window = malloc(sizeof(window_t));
    if (window == NULL)
        return (84);
    init_game(window);
    message_t **message = init_text(init_manage());

    sfRenderWindow_setFramerateLimit(window->window, 60);
    while (sfRenderWindow_isOpen(window->window)) {
        manage_event(window);
        sfRenderWindow_clear(window->window, sfBlack);
        animation_manager(window);
        manage_infos(window, message);
        sfRenderWindow_drawRectangleShape(window->window, window->rectp1, NULL);
        sfRenderWindow_drawRectangleShape(window->window, window->rectp2, NULL);
        sfRenderWindow_display(window->window);
    }
    destroy_window(window, message);
    free(window);
    free(message);
    return (0);
}

int main(void)
{
    return (create_window());
}