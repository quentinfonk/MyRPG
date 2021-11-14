/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** parser_monster
*/
#include <lib_parser.h>
#include "my.h"
#include "monster.h"

static const int STAT_MONSTER = 5;

static void skill_monster(monster_t *perso, char *buffer)
{
    for (int i = 0; i != MAX_INVENTORY; i++) {
        for (; buffer[-1] != '\n'; buffer++);
        for (; buffer[-1] != '"'; buffer++);
        parser_str_skill_monster(buffer, perso, i);
        if (my_strcmp(perso->arr[i].name, "NULL") == 0) {
            perso->arr[i].power = 0;
            perso->arr[i].aoe = 0;
            perso->arr[i].mana_cost = 0;
            for (; buffer[-1] != '\n'; buffer++);
        } else {
            move_pointer(&buffer, ",");
            perso->arr[i].power = my_getnbr(buffer);
            move_pointer(&buffer, ",");
            perso->arr[i].aoe = my_getnbr(buffer);
            move_pointer(&buffer, ",");
            perso->arr[i].mana_cost = my_getnbr(buffer);
        }
    }
}

static void realize_monster(const int *data, monster_t *monster)
{
    for (int i = 0; monster->name[i]; i++)
        if (monster->name[i] == '_')
            monster->name[i] = ' ';
    monster->level = data[0];
    monster->health = data[1];
    monster->mana = data[2];
    monster->attack = data[3];
    monster->defense = data[4];
}

static int *parser_monster(char *path, monster_t *monster)
{
    int i = 0;
    int *nbr_stat = malloc(sizeof(int) * STAT_MONSTER);
    char *elem = read_save(path);
    char *buffer = elem;

    move_pointer(&buffer, ":");
    do {
        move_pointer(&buffer, ":");
        if (buffer[2] == '"')
            continue;
        nbr_stat[i++] = my_getnbr(buffer);
    } while (i != STAT_MONSTER);
    for (; buffer[0] != '\n'; buffer++);
    buffer++;
    skill_monster(monster, buffer);
    free(elem);
    return (nbr_stat);
}

monster_t create_monster(char *name, char *name_png)
{
    monster_t monster;
    int *res = 0;
    char *path = my_strdup("./files/monster");
    char *path2 = my_strdup(path);

    for (int i = 0; name[i]; i++)
        monster.name[i] = name[i];
    monster.name[my_strlen(name)] = '\0';
    path = find_file(path, name);
    path2 = find_file(path2, name_png);
    res = parser_monster(path, &monster);
    realize_monster(res, &monster);
    monster.disp = load_monster(path2);
    free(path2);
    free(res);
    return (monster);
}
