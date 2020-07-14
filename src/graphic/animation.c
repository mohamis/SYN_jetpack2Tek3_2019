/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** animation
*/

#include "jetpack_graph.h"
#include <SFML/Graphics/Transform.h>

void move_player(window_t *game)
{
    float x_move = 0.0;
    float y_move = 0.0;
    sfVector2f sprite_pos = sfRectangleShape_getPosition(game->rect);
    sfVector2f movement;

    if (sprite_pos.x >= 500.0 && sprite_pos.x <= 525.0) {
        y_move = (-5.0 * game->seconds);
        if (sprite_pos.y >= 750.0)
            x_move = (5.0 * game->seconds);
    } else if (sprite_pos.x >= 1320.0 && sprite_pos.x <= 1340.0) {
        y_move = (5.0 * game->seconds);
        if (sprite_pos.y >= 150.0 && sprite_pos.y <= 180.0)
            x_move = (-5.0 * game->seconds);
    } else {
        x_move = (5.0 * game->seconds);
            if (sprite_pos.x >= 1790.0)
                printf("ok");
    }
    movement = (sfVector2f) {x_move, y_move};
    sfRectangleShape_move(game->rect, movement);
}

void animation_manager(window_t *window)
{
    window->time = sfClock_getElapsedTime(window->clock);
    window->seconds = window->time.microseconds / 100000.0;
    if (window->seconds > 1.5) {
        move_player(window);
        sfRectangleShape_setFillColor(window->rect, sfBlue);
        sfRectangleShape_setSize(window->rect, (sfVector2f){10,10});
        sfClock_restart(window->clock);
    }
}