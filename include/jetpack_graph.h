/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** jetpack_graph
*/
#include <SFML/Graphics.h>
#include <SFML/Window/Event.h>
#include <SFML/Audio.h>

#ifndef JETPACK_GRAPH_H_
#define JETPACK_GRAPH_H_

/* Structures */

typedef struct window {
    sfVideoMode video_mode;
    sfRenderWindow *window;
    sfRectangleShape *rect;
    sfClock *clock;
    float seconds;
    sfEvent event;
    sfFont *font;
    sfText *text;
    sfTime time;
    int fire;
} window_t;

typedef struct message {
    sfText *text;
    sfVector2f pos;
    sfVector2f size;
} message_t;

/* Functions */
int create_window(void);
void destroy_window(window_t *window);
window_t *init_game2(window_t *window);
void animation_manager(window_t *window);
void move_player(window_t *window);
int manage_infos(window_t *window);

#endif /* !JETPACK_GRAPH_H_ */
