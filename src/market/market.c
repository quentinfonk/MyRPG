/*
** EPITECH PROJECT, 2020
** market
** File description:
** market
*/

#include "market.h"

void pr_mark(market_t *my_m, window_t *window)
{
    sfIntRect rect = {0, 0, 975, 1000};
    sfVector2f pos = {450, 200};

    sfSprite_setTextureRect(my_m->sp_mark[0], rect);
    sfSprite_setPosition(my_m->sp_mark[0], pos);
    sfRenderWindow_drawSprite(window->window, my_m->sp_mark[0], NULL);
}

void pr_txt(char *str, window_t *window, market_t *my_m, sfVector2f pos_texte)
{
    sfText_setPosition(my_m->texte, pos_texte);
    sfText_setString(my_m->texte, str);
    sfRenderWindow_drawText(window->window, my_m->texte, NULL);
}

int check_a(int a, window_t *window, market_t *my_m)
{
    if (a == 1)
        a_1(window, my_m);
    if (a == 2)
        a_2(window, my_m);
    if (a == 3)
        a_3(window, my_m);
    if (a == 4)
        a_4(window, my_m);
    if (a == 5)
        a_5(window, my_m);
    return (a);
}

void market_pr(window_t *window, market_t *my_m, sfEvent ev_ty, ply_t *player)
{
    int a = 1;

    while (a != -1) {
        a = ev_type(window, ev_ty, a, player);
        pr_mark(my_m, window);
        if (check_a(a, window, my_m) == 42)
            a = -1;
        sfRenderWindow_display(window->window);
        sfRenderWindow_clear(window->window, sfBlack);
    }
}

void market(window_t *window, ply_t *player)
{
    sfEvent ev_ty;
    market_t my_m;

    create_mark(window, &my_m);
    market_pr(window, &my_m, ev_ty, player);
    return;
}
