/*
** EPITECH PROJECT, 2020
** inventory
** File description:
** inventory
*/

#ifndef INVENTORY_H
#define INVENTORY_H

#include "window.h"
#include "player.h"

typedef struct inventory {
    sfTexture **te_inv;
    sfSprite **sp_inv;
    sfFont *font;
    sfText *texte;
} inv_t;

void inventory(window_t *window, ply_t *player);
int check_po(window_t *window);
void create_inv(inv_t *inv);
int my_strlen(char const *str);
void my_putstr(char *str);
void pr_in(window_t *window, inv_t *inv, ply_t *player);
int event_ev(window_t *window, sfEvent ev_ent, int *choice);
void pr_stack(window_t *window, inv_t *inv);
int uti(window_t *window, ply_t *player, int choice);
int el_arm(window_t *window, int choice, ply_t *player);
int check_place(window_t *window);
void add_in(window_t *window, int a);
void change_pla(int i, ply_t *player);
void check_arm(ply_t *player, int choice);
void modif_stat_player(player_t *player);
char *print_stat(player_t player);

#endif
