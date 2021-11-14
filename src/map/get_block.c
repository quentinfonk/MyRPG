/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_block.c
*/

#include "map.h"

void get_block_3_2(sfVector2i va, st_map **s_map, char *map_tab)
{
    if (map_tab[0] == 'W' && map_tab[1] == 'U')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a11.png", NULL);
    if (map_tab[0] == 'W' && map_tab[1] == 'D')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a12.png", NULL);
    if (map_tab[0] == 'W' && map_tab[1] == 'R')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a13.png", NULL);
    if (map_tab[0] == 'W' && map_tab[1] == 'L')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a14.png", NULL);
    if (map_tab[0] == 'W' && map_tab[1] == 'I')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a15.png", NULL);
}

void get_block_3(sfVector2i va, st_map **s_map, char *map_tab)
{
    get_block_3_2(va, s_map, map_tab);
    if (map_tab[0] == 'S' && map_tab[1] == 'N')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a16.png", NULL);
    if (map_tab[0] == 'S' && map_tab[1] == 'T')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a17.png", NULL);
    if (map_tab[0] == 'S' && map_tab[1] == 'U')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a18.png", NULL);
    if (map_tab[0] == 'S' && map_tab[1] == 'D')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a19.png", NULL);
    if (map_tab[0] == 'S' && map_tab[1] == 'N')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a20.png", NULL);
}

void get_block_4_2(sfVector2i va, st_map **s_map, char *map_tab,
    sfClock *clock_rand)
{
    if (map_tab[0] == 'R' && map_tab[1] == '1')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a21.png", NULL);
    if (map_tab[0] == 'R' && map_tab[1] == '2')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a22.png", NULL);
    if (map_tab[0] == 'R' && map_tab[1] == '3')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a23.png", NULL);
    if (map_tab[0] == 'R' && map_tab[1] == '4')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a24.png", NULL);
    if (map_tab[0] == 'R' && map_tab[1] == 'R')
        get_rand_road(va, s_map, clock_rand);
    if (map_tab[0] == 'R' && map_tab[1] == 'U')
        get_rand_road_2(va, s_map, clock_rand);
}

void get_block_4(sfVector2i va, st_map **s_map, char *map_tab,
    sfClock *clock_rand)
{
    get_block_4_2(va, s_map, map_tab, clock_rand);
    if (map_tab[0] == 'M' && map_tab[1] == 'U')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a25.png", NULL);
    if (map_tab[0] == 'M' && map_tab[1] == 'L')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a26.png", NULL);
    if (map_tab[0] == 'D' && map_tab[1] == 'N')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a27.png", NULL);
    if (map_tab[0] == 'F' && map_tab[1] == 'S')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a28.png", NULL);
}

void get_block(sfVector2i va, st_map **s_map, char *map_tab,
    sfClock *clock_rand)
{
    get_block_1(va, s_map, map_tab, clock_rand);
    get_block_2(va, s_map, map_tab);
    get_block_3(va, s_map, map_tab);
    get_block_4(va, s_map, map_tab, clock_rand);
}
