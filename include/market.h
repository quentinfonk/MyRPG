/*
** EPITECH PROJECT, 2020
** market
** File description:
** market
*/

#ifndef MARKET_H
#define MARKET_H

#include "window.h"
#include "player.h"

typedef struct market {
    sfTexture **te_mark;
    sfSprite **sp_mark;
    sfFont *font;
    sfText *texte;
    int buy;
} market_t;

int create_mark(window_t *window, market_t *my_m);
int ev_type(window_t *window, sfEvent ev_ty, int a, ply_t *player);
void a_1_text(window_t *window, market_t *my_m);
void a_2_text(window_t *window, market_t *my_m);
void a_3_text(window_t *window, market_t *my_m);
void a_4_text(window_t *window, market_t *my_m);
void a_5_text(window_t *window, market_t *my_m);
void a_1(window_t *window, market_t *my_m);
void a_2(window_t *window, market_t *my_m);
void a_3(window_t *window, market_t *my_m);
void a_4(window_t *window, market_t *my_m);
void a_5(window_t *window, market_t *my_m);
void pr_txt(char *str, window_t *window, market_t *my_m, sfVector2f pos_texte);
int check_key(window_t *window, int a, ply_t *player);
void market(window_t *window, ply_t *player);
void inventory(window_t *window, ply_t *player);
void my_putstr(char *str);

#endif
