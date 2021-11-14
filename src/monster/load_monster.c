/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_monster.c
*/

#include "monster.h"

disp_monster_t load_monster(char *path)
{
    disp_monster_t load;

    load.texture = sfTexture_createFromFile(path, NULL);
    load.sprite = sfSprite_create();
    load.vect.x = 1500;
    load.vect.y = 500;
    return (load);
}
