/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** func player
*/
#include "my.h"
#include "fight.h"

static const char *attack[25] = {
    "Fire Ball",
    "Paralyze",
    "Fire Tempest",
    "Thunder Ball",
    "Thunder Area",
    "Auto A",
    "Splash",
    "Mega Blast",
    "Boost Attack",
    "Crunch",
    "Earthquake",
    "Giga Impact",
    "Stone Edge",
    "Night Slash",
    "Foul Play",
    "Feint Attack",
    "Night Daze",
    "Rock Throw",
    "Dig",
    "Rollout",
    "Dark Pulse",
    "Nightmare",
    "Dream Eater",
    "Dark Void",
    NULL
};

int player_take(const char *name, const int nbr, player_t *player)
{
    for (int i = 0; attack[i]; i++)
        if (my_strcmp(name, attack[i]) == 0) {
            if (player->health - nbr + player->defense < 1) {
                player->health = 0;
                return (print_lose(player->name));
            } else
                player->health -= nbr + player->defense;
        }
    if (my_strcmp(name, "health") == 0)
        player->level -= nbr;
    if (my_strcmp(name, "level") == 0)
        player->level -= nbr;
    if (my_strcmp(name, "mana") == 0)
        player->mana -= nbr;
    if (my_strcmp(name, "attack") == 0)
        player->attack -= nbr;
    if (my_strcmp(name, "defense") == 0)
        player->defense -= nbr;
    return (0);
}

static int mana_cost(player_t *player, const int alea)
{
    int mana_cost = (int) player->mana - (int) player->arr[alea].mana_cost;

    if (mana_cost < 0) {
        my_printf("\nNot enough mana\n\nattack: ");
        return (1);
    }
    player_take("mana", player->arr[alea].mana_cost, player);
    return (0);
}

static void special_attack(player_t *player, skill_t *move)
{
    static int nbr_times = 1;

    nbr_times++;
    if (nbr_times == 0)
        player->attack -= player->attack / 2;
    else if (nbr_times == -1)
        move->power += player->attack * 2;
    if (my_strcmp(move->name, attack[7]) == 0) {
        player->health -= move->power / 2;
        if (player->health < 0)
            player->health = 0;
        return;
    } else if (my_strcmp(move->name, attack[8]) == 0) {
        move->power += player->attack * 2;
        nbr_times = -2;
    }
}

skill_t player_use(const int move, player_t *player)
{
    skill_t fight;

    fight.power = player->arr[move].power + player->attack;
    for (int i = 0; player->arr[move].name[i]; i++)
        fight.name[i] = player->arr[move].name[i];
    fight.name[my_strlen(player->arr[move].name)] = '\0';
    special_attack(player, &fight);
    if (mana_cost(player, move) == 1)
        return ((skill_t) {"KO", 0, 0, 0});
    my_printf("\n%s use %s and deal %d damage !\n", player->name,
        fight.name, fight.power);
    return (fight);
}

int next_level(player_t *player, int level_m)
{
    char *str = malloc(5);
    double next_lvl_p = round((4 * pow(player->level, 3)) / 5);
    double next_lvl_m = round((4 * pow(level_m, 3)) / 5);

    srand((intptr_t) str);
    player->money += (rand()
    % ((level_m * 5) + 1 - (level_m * 4))) + (level_m * 4);
    my_printf("money gained: %d\n", player->money);
    next_lvl_m /= 3;
    next_lvl_m = (next_lvl_m < 1) ? 1 : (int) next_lvl_m;
    free(str);
    if (next_lvl_p > player->actual_level + next_lvl_m) {
        player->actual_level += (int) next_lvl_m;
        return (1);
    }
    player->level++;
    player->actual_level = (player->actual_level + (int) next_lvl_m) -
    (int) next_lvl_p;
    modif_stat_player(player);
    return (0);
}
