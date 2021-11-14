/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player
*/

#ifndef PLAYER_H_
#define PLAYER_H_

#include "display_player.h"
#include "dialog.h"

static const int MAX_INVENTORY = 4;

typedef struct skill_s {
    char name[13];
    int power;
    int aoe;
    int mana_cost;
} skill_t;

typedef struct save_s {
    int darkrai;
    int Dinogriffe;
    int grolem;
} save_t;

typedef struct player_s {
    char name[13];
    int level;
    int actual_level;
    int money;
    int xp;
    int health;
    int mana;
    int attack;
    int defense;
    char inventory[12];
    char armor[5];
    skill_t arr[4];
    save_t info;
} player_t;

typedef struct s_ply
{
    player_t player;
    disp_player_t disp;
} ply_t;

// proto
ply_t create_player(char *name, char *mode, window_t *window);
void parser_player(player_t *perso, char *path);
void save_player(player_t *perso, map_t *map, window_t *window);
void load_player(ply_t *perso, map_t *map_s, window_t *window);

skill_t player_use(int move, player_t *player);
int player_take(const char *name, int nbr, player_t *player);

void display_window(window_t *window, ply_t *player, map_t *map);
hash_t *create_dialogs(char *name);
int set_moov_croco(map_t *map, window_t *window, ply_t *p);
int set_moov_wolf(map_t *map, window_t *window, ply_t *p);
int set_moov_ghost(map_t *map, window_t *window, ply_t *p);
int set_moov_golem(map_t *map, window_t *window, ply_t *p);
int draw_mob(map_t *map, window_t *window, ply_t *disp_player);
void draw_view(window_t *w, ply_t *p, map_t *m);

#endif /* !PLAYER_H_ */
