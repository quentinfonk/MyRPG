/*
** EPITECH PROJECT, 2020
** page 3
** File description:
** market
*/

#include "market.h"

void a_3_text(window_t *window, market_t *my_m)
{
    sfVector2f pos_texte = {600, 585};

    pr_txt("strength", window, my_m, pos_texte);
    pos_texte.x += 300;
    pr_txt("  XP", window, my_m, pos_texte);
    pos_texte.x += 300;
    pr_txt("mana", window, my_m, pos_texte);
    pos_texte.x = 580;
    pos_texte.y += 80;
    pr_txt("10", window, my_m, pos_texte);
    pos_texte.x += 300;
    pr_txt("25", window, my_m, pos_texte);
    pos_texte.x += 300;
    pr_txt("50", window, my_m, pos_texte);
}

void a_3(window_t *window, market_t *my_m)
{
    sfIntRect rect = {1000, 80, 200, 100};
    sfVector2f pos = {845, 224};
    sfIntRect obj = {0, 300, 1000, 150};
    sfVector2f pos_obj = {450, 450};

    sfSprite_setTextureRect(my_m->sp_mark[0], rect);
    sfSprite_setPosition(my_m->sp_mark[0], pos);
    sfRenderWindow_drawSprite(window->window, my_m->sp_mark[0], NULL);
    sfSprite_setTextureRect(my_m->sp_mark[1], obj);
    sfSprite_setPosition(my_m->sp_mark[1], pos_obj);
    sfRenderWindow_drawSprite(window->window, my_m->sp_mark[1], NULL);
    a_3_text(window, my_m);
}
