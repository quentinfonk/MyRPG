/*
** EPITECH PROJECT, 2020
** page 4
** File description:
** market
*/

#include "market.h"

void a_4_text(window_t *window, market_t *my_m)
{
    sfVector2f pos_texte = {580, 585};

    pr_txt("...", window, my_m, pos_texte);
    pos_texte.x += 300;
    pr_txt("...", window, my_m, pos_texte);
    pos_texte.x += 300;
    pr_txt("...", window, my_m, pos_texte);
    pos_texte.x = 580;
    pos_texte.y += 80;
    pr_txt("...", window, my_m, pos_texte);
    pos_texte.x += 300;
    pr_txt("...", window, my_m, pos_texte);
    pos_texte.x += 300;
    pr_txt("...", window, my_m, pos_texte);
}

void a_4(window_t *window, market_t *my_m)
{
    sfIntRect rect = {1000, 80, 200, 100};
    sfVector2f pos = {1025, 224};

    sfSprite_setTextureRect(my_m->sp_mark[0], rect);
    sfSprite_setPosition(my_m->sp_mark[0], pos);
    sfRenderWindow_drawSprite(window->window, my_m->sp_mark[0], NULL);
    a_4_text(window, my_m);
}
