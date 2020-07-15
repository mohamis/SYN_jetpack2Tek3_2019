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
#include <stdlib.h>
/* Structures */
typedef struct window {
    sfVideoMode video_mode;
    sfRenderWindow *window;
    sfRectangleShape *rectp1;
    sfRectangleShape *rectp2;
    sfRectangleShape *map;
    sfClock *clock;
    float seconds;
    sfEvent event;
    int s_gravity;
    sfFont *font;
    sfText *text;
    float x_move;
    float y_move;
    sfTime time;
    int gravity;
    int s_fire;
    int fire;
} window_t;

typedef struct message {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    sfVector2f size;
} message_t;

/* Functions */
int create_window(void);
void destroy_window(window_t *window, message_t **message);
window_t *init_game2(window_t *window);
void animation_manager(window_t *window);
void move_player(window_t *window, sfRectangleShape *rect, int fire);
int manage_infos(window_t *window, message_t **message);
message_t *init_a_text(sfVector2f pos, char *t, sfColor color);
message_t **init_text(char **t);

#endif /* !JETPACK_GRAPH_H_ */
