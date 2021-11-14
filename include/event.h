/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event.h
*/

#ifndef EVENT_H
#define EVENT_H

//includes

#include "window.h"
#include "market.h"
#include "player.h"

//proto

int events(window_t *window, ply_t *player, map_t *map);
void use_view(window_t *w, ply_t *p, map_t *map);
st_view set_view(window_t *w);

#endif
