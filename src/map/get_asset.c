/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_asset.c
*/

#include "map.h"

void get_asset_5(sfVector2i va, st_map **s_map, char *map_tab)
{
    if (map_tab[2] == '4')
        s_map[va.x][va.y].t_obj =
        sfTexture_createFromFile("load/obj/a12.png", NULL);
    if (map_tab[2] == '3')
        s_map[va.x][va.y].t_obj =
        sfTexture_createFromFile("load/obj/a13.png", NULL);
    if (map_tab[2] == '2')
        s_map[va.x][va.y].t_obj =
        sfTexture_createFromFile("load/obj/a14.png", NULL);
    if (map_tab[2] == '1')
        s_map[va.x][va.y].t_obj =
        sfTexture_createFromFile("load/obj/a15.png", NULL);
    if (map_tab[2] == 'g')
        s_map[va.x][va.y].t_obj =
        sfTexture_createFromFile("load/obj/a16.png", NULL);
    if (map_tab[2] == 'r')
        s_map[va.x][va.y].t_obj =
        sfTexture_createFromFile("load/obj/a17.png", NULL);
}

void get_asset_2(sfVector2i va, st_map **s_map, char *map_tab)
{
    get_asset_5(va, s_map, map_tab);
    if (map_tab[2] == 'b')
        s_map[va.x][va.y].t_obj =
        sfTexture_createFromFile("load/obj/a18.png", NULL);
    if (map_tab[2] == '9')
        s_map[va.x][va.y].t_obj =
        sfTexture_createFromFile("load/obj/a19.png", NULL);
    if (map_tab[2] == '8')
        s_map[va.x][va.y].t_obj =
        sfTexture_createFromFile("load/obj/a20.png", NULL);
    if (map_tab[2] == '7')
        s_map[va.x][va.y].t_obj =
        sfTexture_createFromFile("load/obj/a21.png", NULL);
}

void get_asset_4(sfVector2i va, st_map **s_map, char *map_tab)
{
    if (map_tab[2] == 'E')
        s_map[va.x][va.y].t_obj =
        sfTexture_createFromFile("load/obj/a1.png", NULL);
    if (map_tab[2] == 'H')
        s_map[va.x][va.y].t_obj =
        sfTexture_createFromFile("load/obj/a2.png", NULL);
    if (map_tab[2] == 'N')
        s_map[va.x][va.y].t_obj =
        sfTexture_createFromFile("load/obj/a3.png", NULL);
    if (map_tab[2] == 'B')
        s_map[va.x][va.y].t_obj =
        sfTexture_createFromFile("load/obj/a4.png", NULL);
    if (map_tab[2] == 'F')
        s_map[va.x][va.y].t_obj =
        sfTexture_createFromFile("load/obj/a5.png", NULL);
}

void get_asset_3(sfVector2i va, st_map **s_map, char *map_tab)
{
    get_asset_4(va, s_map, map_tab);
    if (map_tab[2] == 'S')
        s_map[va.x][va.y].t_obj =
        sfTexture_createFromFile("load/obj/a6.png", NULL);
    if (map_tab[2] == 'P')
        s_map[va.x][va.y].t_obj =
        sfTexture_createFromFile("load/obj/a7.png", NULL);
    if (map_tab[2] == 'G')
        s_map[va.x][va.y].t_obj =
        sfTexture_createFromFile("load/a8.png", NULL);
    if (map_tab[2] == 'p')
        s_map[va.x][va.y].t_obj =
        sfTexture_createFromFile("load/a9.png", NULL);
    if (map_tab[2] == 'f')
        s_map[va.x][va.y].t_obj =
        sfTexture_createFromFile("load/obj/a10.png", NULL);
}

void get_asset(sfVector2i va, st_map **s_map, char *map_tab)
{
    get_asset_2(va, s_map, map_tab);
    get_asset_3(va, s_map, map_tab);
}
