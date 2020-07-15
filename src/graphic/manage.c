/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** manage
*/

#include "jetpack_graph.h"

message_t *init_a_text(sfVector2f pos, char *t, sfColor color)
{
    message_t *button = malloc(sizeof(message_t));
    if (button == NULL)
        return (NULL);

    button->font = sfFont_createFromFile("./font/arial.ttf");
    if (!button->font)
        exit (84);
    button->text = sfText_create();
    sfText_setString(button->text, t);
    sfText_setFont(button->text, button->font);
    sfText_setCharacterSize(button->text, 20);
    sfText_setPosition(button->text, pos);
    sfText_setFillColor(button->text, color);
    return (button);
}

message_t **init_text(char **t)
{
    message_t **button = malloc(sizeof(message_t *) * 7);

    button[0] = init_a_text((sfVector2f) {0, 0}, t[0], sfWhite);
    button[1] = init_a_text((sfVector2f) {0, 20}, t[1], sfYellow);
    button[2] = init_a_text((sfVector2f) {0, 40}, t[2], sfCyan);
    button[3] = init_a_text((sfVector2f) {0, 60}, t[3], sfGreen);
    button[4] = init_a_text((sfVector2f) {0, 80}, t[4], sfMagenta);
    button[5] = init_a_text((sfVector2f) {0, 100}, t[5], sfWhite);
    button[6] = NULL;
    return (button);
}

int manage_infos(window_t *window, message_t **message)
{
    for (int i = 0; i <= 5; i++)
        sfRenderWindow_drawText(window->window, message[i]->text, NULL);
    return (0);
}