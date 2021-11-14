/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** move_player.c
*/

#include "display_player.h"
#include <stdio.h>

void move_left(disp_player_t *disp_player)
{
    disp_player->rect.top = 77;
    disp_player->is_walking = true;
}

void move_right(disp_player_t *disp_player)
{
    disp_player->rect.top = 154;
    disp_player->is_walking = true;
}

void move_up(disp_player_t *disp_player)
{
    disp_player->rect.top = 231;
    disp_player->is_walking = true;
}

void move_down(disp_player_t *disp_player)
{
    disp_player->rect.top = 0;
    disp_player->is_walking = true;
}
