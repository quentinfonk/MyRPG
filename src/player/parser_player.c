/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** parser_player
*/

#include <string.h>
#include "player.h"
#include "my.h"
#include "lib_parser.h"

static const int DATA_PLAYER = 8;

void move_pointer(char **buffer, char const *delim);

static void skill(player_t *perso, char *buffer)
{
    for (int i = 0; i != MAX_INVENTORY; i++) {
        for (; buffer[-1] != '\n'; buffer++);
        for (; buffer[-1] != '"'; buffer++);
        parser_str_skill(buffer, perso, i);
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

static void feature(player_t *perso, const int *data_player)
{
    perso->level = data_player[0];
    perso->actual_level = data_player[1];
    perso->money = data_player[2];
    perso->xp = data_player[3];
    perso->health = data_player[4];
    perso->mana = data_player[5];
    perso->attack = data_player[6];
    perso->defense = data_player[7];
}

void parser_player(player_t *perso, char *path)
{
    char *buffer = read_save(my_strdup(path));
    int *data_player = malloc(sizeof(int) * DATA_PLAYER);
    char *temp = buffer;

    perso = memset(perso, 0, sizeof(player_t));
    move_pointer(&temp, "\n");
    for (int i = 0; i != DATA_PLAYER; i++) {
        data_player[i] = my_getnbr(temp);
        move_pointer(&temp, "\n");
    }
    feature(perso, data_player);
    move_pointer(&temp, "\n");
    skill(perso, temp);
    free(data_player);
    free(buffer);
}

ply_t create_player(char *name, char *mode, window_t *window)
{
    ply_t perso;

    if (my_strcmp(mode, "save") == 0) {
        parser_player(&perso.player, "./files/player/player1.stat");
        save_player(&perso.player, NULL, NULL);
    }
    for (int i = 0; name[i]; i++)
        perso.player.name[i] = name[i];
    perso.player.name[my_strlen(name)] = '\0';
    perso.disp = set_player(window, "files/player/player.png");
    return (perso);
}
