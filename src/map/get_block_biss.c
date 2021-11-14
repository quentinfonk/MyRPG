/*
** EPITECH PROJECT, 2020
** test
** File description:
** *
*/

#include "map.h"

void get_block_1_2(sfVector2i va, st_map **s_map, char *map_tab)
{
    if (map_tab[0] == 'C' && map_tab[1] == 'T')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/c1.png", NULL);
    if (map_tab[0] == 'C' && map_tab[1] == 'S')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/c2.png", NULL);
    if (map_tab[0] == 'C' && map_tab[1] == 'C')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/c3.png", NULL);
    if (map_tab[0] == 'C' && map_tab[1] == 'F')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/c4.png", NULL);
    if (map_tab[0] == 'C' && map_tab[1] == 'R')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/c5.png", NULL);
}

void get_block_1(sfVector2i va, st_map **s_map, char *map_tab,
    sfClock *clock_rand)
{
    if (map_tab[0] == 'G' && map_tab[1] == 'N')
        get_rand_grass(va, s_map, clock_rand);
    if (map_tab[0] == 'B' && map_tab[1] == 'N')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a1.png", NULL);
    if (map_tab[0] == 'B' && map_tab[1] == 'U')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a2.png", NULL);
    if (map_tab[0] == 'B' && map_tab[1] == 'D')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a3.png", NULL);
    if (map_tab[0] == 'B' && map_tab[1] == 'T')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a4.png", NULL);
    get_block_1_2(va, s_map, map_tab);
}

void get_block_2_2(sfVector2i va, st_map **s_map, char *map_tab)
{
    if (map_tab[0] == 'C' && map_tab[1] == 'O')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/c6.png", NULL);
    if (map_tab[0] == 'C' && map_tab[1] == 'W')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/c7.png", NULL);
    if (map_tab[0] == 'C' && map_tab[1] == 'P')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/c8.png", NULL);
    if (map_tab[0] == 'F' && map_tab[1] == 'R')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a5.png", NULL);
    if (map_tab[0] == 'F' && map_tab[1] == 'L')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a6.png", NULL);
}

void get_block_2(sfVector2i va, st_map **s_map, char *map_tab)
{
    get_block_2_2(va, s_map, map_tab);
    if (map_tab[0] == 'F' && map_tab[1] == 'P')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a7.png", NULL);
    if (map_tab[0] == 'F' && map_tab[1] == 'C')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a8.png", NULL);
    if (map_tab[0] == 'R' && map_tab[1] == 'N')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/rock.png", NULL);
    if (map_tab[0] == 'W' && map_tab[1] == 'N')
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/a10.png", NULL);
    return;
}
