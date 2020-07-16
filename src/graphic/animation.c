/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** animation
*/

#include "jetpack_graph.h"
#include <SFML/Graphics/Transform.h>

void movem(window_t *game, sfRectangleShape *rect, int fire, sfVector2f sprite_pos)
{
    if (fire == 1) {
        game->y_move = (-5.0 * game->seconds);
        if (sprite_pos.y > 1001.000000)
            game->s_gravity = 2;
        else
            game->s_gravity = 1;
        game->x_move = (5.0 * game->seconds);
    } else if (fire == 0) {
        if (game->s_gravity == 1) {
            if (sprite_pos.y > 1000.000000)
                sfRectangleShape_setPosition(rect, (sfVector2f) {sprite_pos.x, 1000});
            else
                game->y_move = (game->gravity * game->seconds);
        } else if (game->s_gravity == 2 || sprite_pos.y > 1001.000000) {
            sfRectangleShape_setPosition(rect, (sfVector2f) {sprite_pos.x, 1000});
            game->x_move = (5.0 * game->seconds);
        }
        game->x_move = (5.0 * game->seconds);
    }
}

void move_player(window_t *game, sfRectangleShape *rect, int fire)
{
    sfVector2f sprite_pos = sfRectangleShape_getPosition(rect);
    sfVector2f movement;

    movem(game, rect, fire, sprite_pos);
    movement = (sfVector2f) {game->x_move, game->y_move};
    sfRectangleShape_move(rect, movement);
}

void animation_manager(window_t *window)
{
    window->time = sfClock_getElapsedTime(window->clock);
    window->seconds = window->time.microseconds / 100000.0;

    if (window->seconds > 0.0000001) {
        move_player(window, window->rectp1, window->fire);
        move_player(window, window->rectp2, window->s_fire);
        sfRectangleShape_setFillColor(window->rectp1, sfGreen);
        sfRectangleShape_setFillColor(window->rectp2, sfMagenta);
        sfRectangleShape_setSize(window->rectp1, (sfVector2f){10,10});
        sfRectangleShape_setSize(window->rectp2, (sfVector2f){10,10});
        sfClock_restart(window->clock);
    }
}