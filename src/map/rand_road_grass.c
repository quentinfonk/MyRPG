/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rans_road_grass.c
*/

#include "map.h"

void chose_grass(sfVector2i va, st_map **s_map, int a)
{
    if (a == 1)
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/grass.png", NULL);
    if (a == 2)
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/grass_2.png", NULL);
    if (a == 3)
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/grass_3.png", NULL);
    if (a == 4)
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/grass_4.png", NULL);
    if (a == 5)
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/grass_5.png", NULL);
    if (a == 6)
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/grass_6.png", NULL);
    return;
}

void get_rand_road(sfVector2i va, st_map **s_map, sfClock *clock_rand)
{
    int a = 0;
    sfTime time = sfClock_getElapsedTime(clock_rand);
    float seconde = sfTime_asMicroseconds(time);

    srand(seconde);
    a = (rand()% (6) + 1);
    if (a == 1 || a == 6)
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/road_1.png", NULL);
    if (a == 2 || a == 5)
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/road_2.png", NULL);
    if (a == 3 || a == 4)
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/road_3.png", NULL);
    return;
}

void get_rand_grass(sfVector2i va, st_map **s_map, sfClock *clock_rand)
{
    int a = 0;
    sfTime time = sfClock_getElapsedTime(clock_rand);
    float seconde = sfTime_asMicroseconds(time);

    srand(seconde);
    a = (rand()% (6) + 1);
    chose_grass(va, s_map, a);
    return;

}

void get_rand_road_2(sfVector2i va, st_map **s_map, sfClock *clock_rand)
{
    int a = 0;
    sfTime time = sfClock_getElapsedTime(clock_rand);
    float seconde = sfTime_asMicroseconds(time);

    srand(seconde);
    a = (rand()% (6) + 1);
    if (a == 1 || a == 6)
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/road_4.png", NULL);
    if (a == 2 || a == 5)
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/road_5.png", NULL);
    if (a == 3 || a == 4)
        s_map[va.x][va.y].t_map =
        sfTexture_createFromFile("load/floor/road_6.png", NULL);
    return;
}

