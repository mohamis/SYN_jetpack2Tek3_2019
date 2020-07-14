/*
** EPITECH PROJECT, 2020
** SYN_jetpack2Tek3_2019
** File description:
** manage
*/

#include "jetpack_graph.h"

button_t *init_a_button(sfVector2f pos, sfVector2f size)
{
    button_t *button = malloc(sizeof(button_t));

    if (button == NULL)
        return (NULL);
    button->rect = sfRectangleShape_create();
    if (button->rect == NULL)
        return (NULL);
    button->pos = pos;
    button->size = size;
    sfRectangleShape_setPosition(button->rect, button->pos);
    sfRectangleShape_setSize(button->rect, button->size);
    sfRectangleShape_setFillColor(button->rect, sfTransparent);
    return (button);
}

button_t **init_button(void)
{
    button_t **button = malloc(sizeof(button_t *) * 5);

    button[0] = init_a_button((sfVector2f) {870, 440}, (sfVector2f)
                                {180, 180});
    button[1] = init_a_button((sfVector2f) {1834, 44}, (sfVector2f)
                                {40, 40});
    button[2] = init_a_button((sfVector2f) {1790, 968}, (sfVector2f)
                                {70, 70});
    button[3] = init_a_button((sfVector2f) {1310, 368}, (sfVector2f)
                                {343, 108});
    button[4] = NULL;
    return (button);
}

int manage_tek3(window_t *window, char *t)
{
    window->font = sfFont_createFromFile("./font/arial.ttf");
    if (!window->font)
        return (84);
    window->text = sfText_create();
    sfText_setString(window->text, t);
    sfText_setFont(window->text, window->font);
    sfText_setCharacterSize(window->text, 50);
    sfRenderWindow_drawText(window->window, window->text, NULL);
    return (0);
}

int manage_infos(window_t *window)
{
    manage_tek3(window, "Legend");
}