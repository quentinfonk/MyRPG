/*
** EPITECH PROJECT, 2020
** test
** File description:
** *
*/

#include "map.h"
#include "window.h"

void draw_floor(st_map **s_map, window_t *window)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < 11; i++)
        for (j = 0; j < 20; j++)
            sfRenderWindow_drawSprite(window->window, s_map[i][j].s_map, NULL);
    return;
}

void draw_asset(st_map **s_map, window_t *window)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < 11; i++)
        for (j = 0; j < 20; j++)
            sfRenderWindow_drawSprite(window->window, s_map[i][j].s_obj, NULL);
    return;
}
