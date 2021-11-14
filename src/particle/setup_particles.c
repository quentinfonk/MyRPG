/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** setup_particles.c
*/

#include "particles.h"

void setup_rect_shape(node_t *new)
{
    sfRectangleShape_setOrigin(new->shape, (sfVector2f){0, 0});
    sfRectangleShape_setPosition(new->shape, new->pos);
    sfRectangleShape_setSize(new->shape,
    (sfVector2f){(rand() % (5 - 2 + 1)) - 2, (rand() % (20 - 10 + 1)) + 10});
    sfRectangleShape_setOutlineColor(new->shape, sfBlack);
    sfRectangleShape_setFillColor(new->shape, (sfColor){136, 150, 255, 255});
    sfRectangleShape_setOutlineThickness(new->shape, 1);
}

int create_particle(node_t **node, int pos)
{
    node_t *new = malloc(sizeof(node_t));

    if (new == NULL)
        return (84);
    if (*node != NULL)
        while ((*node)->next != NULL)
            *node = (*node)->next;
    new->shape = sfRectangleShape_create();
    new->dir.y = rand() % (30 - 10 + 1) + 10;
    new->dir.x = 0;
    new->pos.y = 0;
    new->pos.x = pos;
    new->speed = (rand() % (5 - 3 + 1)) + 3;
    new->next = NULL;
    if (*node == NULL)
        *node = new;
    else
        (*node)->next = new;
    setup_rect_shape(new);
    return (0);
}

int setup_particles(node_t **node)
{
    int pos = 0;
    void *first = NULL;

    for (int a = 0; a != 40; a++, pos += 50) {
        if (create_particle(node, pos) == 84)
            return (84);
        if (a == 0)
            first = (*node);
    }
    (*node) = first;
    return (0);
}

void free_node(node_t *node)
{
    node_t *freeable = node;

    while (node != NULL) {
        sfRectangleShape_destroy(node->shape);
        node = node->next;
        free(freeable);
        freeable = node;
    }
}
