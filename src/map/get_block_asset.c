/*
** EPITECH PROJECT, 2020
** get block
** File description:
** *
*/

#include "map.h"

void set_all_block(st_map **s_map, char **map_tab, window_t *wind)
{
    int v = 0;
    sfVector2i va = {0, 0};
    sfClock *clock_rand = sfClock_create();

    for (int i = 0, line = 0; i < 11; i++, line += (wind->coll / 11)) {
        for (int j = 0, coll = 0; j < 20; j++, v++, coll += (wind->line / 20)) {
            va.x = i;
            va.y = j;
            get_block(va, s_map, map_tab[v], clock_rand);
            s_map[i][j].s_map = sfSprite_create();
            sfSprite_setTexture(s_map[i][j].s_map, s_map[i][j].t_map, sfTrue);
            s_map[i][j].p_map.x = coll;
            s_map[i][j].p_map.y = line;
            sfSprite_setPosition(s_map[i][j].s_map, s_map[i][j].p_map);
        }
    }
    sfClock_destroy(clock_rand);
    return;
}

void set_all_asset(st_map **s_map, char **map_tab, window_t *wind)
{
    int v = 0;
    sfVector2i va;

    for (int i = 0, line = 0; i < 11; i++, line += (wind->coll / 11)) {
        for (int j = 0, coll = 0; j < 20; j++, v++, coll += (wind->line / 20)) {
            va.x = i;
            va.y = j;
            get_asset(va, s_map, map_tab[v]);
            s_map[i][j].s_obj = sfSprite_create();
            sfSprite_setTexture(s_map[i][j].s_obj, s_map[i][j].t_obj, sfTrue);
            s_map[i][j].p_obj.x = coll;
            s_map[i][j].p_obj.y = line;
            s_map[i][j].hit_box = NBR(map_tab[v][3]);
            sfSprite_setPosition(s_map[i][j].s_obj, s_map[i][j].p_obj);
        }
    }
    return;
}
