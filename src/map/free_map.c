/*
** EPITECH PROJECT, 2020
** test
** File description:
** free.c
*/

#include "map.h"

void free_mob(sfTexture *t, sfSprite *s)
{
    sfTexture_destroy(t);
    sfSprite_destroy(s);
    return;
}

void free_map(map_t *map)
{
    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 20; j++) {
            sfTexture_destroy(map->map[i][j].t_map);
            sfSprite_destroy(map->map[i][j].s_map);
            sfTexture_destroy(map->map[i][j].t_obj);
            sfSprite_destroy(map->map[i][j].s_obj);
        }
    return;
}
