/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_particles.c
*/

#include "particles.h"

void draw_particles(window_t *window, node_t **node)
{
    void *first = *node;

    while (*node != NULL) {
        (*node)->pos.x += (*node)->dir.x * (*node)->speed;
        (*node)->pos.y += (*node)->dir.y * (*node)->speed;
        if ((*node)->pos.y > 1080)
            (*node)->pos.y = 0;
        sfRectangleShape_setPosition((*node)->shape, (*node)->pos);
        sfRenderWindow_drawRectangleShape(window->window, (*node)->shape,
        NULL);
        *node = (*node)->next;
    }
    (*node) = first;
}
