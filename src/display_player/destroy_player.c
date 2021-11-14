/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_player.c
*/

#include "display_player.h"

void destroy_player(disp_player_t *disp_player)
{
    sfTexture_destroy(disp_player->texture);
    sfSprite_destroy(disp_player->sprite);
    sfClock_destroy(disp_player->movement);
}
