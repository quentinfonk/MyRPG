/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** function market
*/
#include "player.h"

int achat_pr_sequel(ply_t *player, int achat)
{
    if (achat == 3) {
        if (player->player.money < 50)
            return (-1);
        else {
            player->player.money -= 50;
            return (0);
        }
    }
    return (-1);
}