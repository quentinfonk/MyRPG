/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** monster function
*/
#include "my.h"
#include "fight.h"

static const char *attack[9] = {
    "Fire Ball",
    "Paralyze",
    "Fire Tempest",
    "Thunder Ball",
    "Thunder Area",
    "Auto A",
    "Mega Blast",
    "Boost Attack",
    NULL
};

void parser_str_skill_monster(char *buffer, monster_t *perso, int i)
{
    int j = 0;

    for (j = 0; buffer[0] != '"'; buffer++, j++)
        perso->arr[i].name[j] = buffer[0];
    perso->arr[i].name[j] = '\0';
}

int monster_take(char *name, int nbr, monster_t *monster)
{
    for (int i = 0; attack[i]; i++)
        if (my_strcmp(name, attack[i]) == 0) {
            if (monster->health - nbr + monster->defense < 1) {
                monster->health = 0;
                return (print_lose(monster->name));
            } else
                monster->health -= nbr + monster->defense;
        }
    if (my_strcmp(name, "mana") == 0)
        monster->mana -= nbr;
    return (0);
}

static int mana_cost(monster_t *monster, int alea)
{
    int mana_cost = monster->mana - monster->arr[alea].mana_cost;

    if (mana_cost < 0) {
        my_printf("\n%s has not enough mana so he use aa\n",
            monster->name);
        return (1);
    }
    monster_take("mana", monster->arr[alea].mana_cost, monster);
    return (0);
}

skill_t monster_use(monster_t *monster)
{
    skill_t fight;
    char *str = malloc(69);
    int alea = 0;

    srand((intptr_t) str);
    for (int i = 0; i != MAX_INVENTORY; i++)
        if (my_strcmp(monster->arr[i].name, "NULL") == 0)
            alea++;
    alea = MAX_INVENTORY - alea;
    alea = rand() % alea;
    for (int i = 0; monster->arr[alea].name[i]; i++)
        fight.name[i] = monster->arr[alea].name[i];
    fight.name[my_strlen(monster->arr[alea].name)] = '\0';
    fight.power = monster->arr[alea].power + monster->attack;
    if (mana_cost(monster, alea) == 1)
        return ((skill_t) {"KO", 0, 0, 0});
    my_printf("\n%s use %s and deal %d damage !\n", monster->name,
            fight.name, fight.power);
    free(str);
    return (fight);
}
