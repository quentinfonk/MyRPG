/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** save_player
*/
#include "player.h"
#include <stddef.h>
#include <stdio.h>

void save_player(player_t *perso, map_t *map, window_t *window)
{
    int nbr = 0;
    FILE *file = fopen("./files/player/player1_struct.stat", "wb");

    if (file == NULL)
        return;
    if (map) {
        perso->info.darkrai = (int) map->s_pnj.boss_2;
        perso->info.grolem = (int) map->s_pnj.s_boss_2;
        perso->info.Dinogriffe = (int) map->s_pnj.s_boss_1;
    }
    if (window) {
        for (nbr = 0; window->inv[nbr]; nbr++)
            perso->inventory[nbr] = window->inv[nbr];
        perso->inventory[11] = '\0';
        for (nbr = 0; window->armor[nbr]; nbr++)
            perso->armor[nbr] = window->armor[nbr];
        perso->armor[MAX_INVENTORY] = '\0';
    }
    fwrite(perso, sizeof(player_t), 1, file);
    fclose(file);
}
