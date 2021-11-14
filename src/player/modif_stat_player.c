/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** modif_stat_player.c
*/

#include "player.h"

void modif_stat_player(player_t *player)
{
    player->attack += player->attack / 3;
    player->defense += player->defense / 3;
    player->health += player->health / 4;
    player->mana += player->mana / 6;
}
