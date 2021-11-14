/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** particles.h
*/

#ifndef PARTICLES_H
#define PARTICLE_H

#include <stdlib.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>
#include "window.h"

typedef struct s_node
{
    struct s_node *next;
    sfRectangleShape *shape;
    sfVector2f dir;
    sfVector2f pos;
    float speed;
} node_t;

int setup_particles(node_t **node);
void draw_particles(window_t *window, node_t **node);
void free_node(node_t *node);

#endif
