/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** print data
*/
#include "monster.h"
#include "player.h"
#include "my.h"

int print_moves(player_t player)
{
    my_printf("\n");
    for (int i = 0; i != MAX_INVENTORY; i++)
        my_printf("%d: %s, %d, %d, %d\n", i, player.arr[i].name,
            player.arr[i].power, player.arr[i].aoe,
            player.arr[i].mana_cost);
    my_printf("\nattack: ");
    return (0);
}

int print_life_m(monster_t monster)
{
    my_printf("\n%s has %d pv and %d mana\n",
        monster.name, monster.health, monster.mana);
    return (0);
}

int print_life_p(player_t player)
{
    my_printf("\n%s has %d pv and %d mana\n",
        player.name, player.health, player.mana);
    return (0);
}

int print_lose(char *name)
{
    my_printf("\n%s has been slayed\n%s lose !\n", name, name);
    return (1);
}