/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight
*/
#include "fight.h"
#include "my.h"

int when_no_mana_p(skill_t *fight, player_t *player)
{
    if (fight->power != 0)
        return (1);
    fight->power = player->attack;
    return (0);
}

int when_no_mana_m(skill_t *fight, monster_t *monster)
{
    char *attack = "Auto A";

    if (fight->power != 0)
        return (1);
    fight->power = monster->attack;
    for (int i = 0; attack[i]; i++)
        fight->name[i] = attack[i];
    fight->name[my_strlen(attack)] = '\0';
    return (0);
}