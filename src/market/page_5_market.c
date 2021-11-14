/*
** EPITECH PROJECT, 2020
** page 5
** File description:
** market
*/

#include "market.h"

void a_5_text(window_t *window, market_t *my_m)
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

void a_5(window_t *window, market_t *my_m)
{
    sfIntRect rect = {1000, 80, 200, 100};
    sfVector2f pos = {1205, 224};

    sfSprite_setTextureRect(my_m->sp_mark[0], rect);
    sfSprite_setPosition(my_m->sp_mark[0], pos);
    sfRenderWindow_drawSprite(window->window, my_m->sp_mark[0], NULL);
    a_5_text(window, my_m);
}
