/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_player
*/
#include "player.h"
#include <stddef.h>
#include <stdio.h>

void load_player(ply_t *perso, map_t *map_s, window_t *window)
{
    FILE *file = fopen("./files/player/player1_struct.stat", "rb");

    if (file == NULL)
        return;
    fread(&perso->player, sizeof(player_t), 1, file);
    fclose(file);
    map_s->s_pnj.boss_2 = perso->player.info.darkrai;
    map_s->s_pnj.s_boss_2 = perso->player.info.grolem;
    map_s->s_pnj.s_boss_1 = perso->player.info.Dinogriffe;
    for (int i = 0; perso->player.inventory[i]; i++)
        window->inv[i] = perso->player.inventory[i];
    window->inv[11] = '\0';
    for (int i = 0; perso->player.armor[i]; i++)
        window->armor[i] = perso->player.armor[i];
    window->armor[MAX_INVENTORY] = '\0';
}
