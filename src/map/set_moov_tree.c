/*
** EPITECH PROJECT, 2020
** test
** File description:
** *
*/

#include "map.h"
#include "window.h"
#include "my.h"

void set_moov_tree(map_t *map, window_t *window)
{
    if (my_strcmp(map->s_pos.actual_m, "map_4") == 0) {
        if (map->s_pnj.s_boss_2 == false || map->s_pnj.s_boss_1 == false) {
            map->map[5][15].hit_box = 1;
            map->map[6][15].hit_box = 1;
            sfRenderWindow_drawSprite(window->window,
            map->mob_tree.sprite, NULL);
        }
        else if (map->s_pnj.s_boss_2 == true && map->s_pnj.s_boss_1 == true) {
            sfRenderWindow_drawSprite(window->window,
            map->mob_tink.sprite, NULL);
            map->map[5][15].hit_box = 0;
            map->map[6][15].hit_box = 0;
        }
    }
    return;
}
