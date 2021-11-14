/*
** EPITECH PROJECT, 2020
** create
** File description:
** market
*/

#include "market.h"

int create_mark(window_t *window, market_t *my_m)
{
    (void)window;
    my_m->te_mark = malloc(sizeof(sfTexture *) * 2);
    my_m->sp_mark = malloc(sizeof(sfSprite *) * 2);
    my_m->te_mark[0] = sfTexture_createFromFile
    ("src/market/load/Market.png", NULL);
    my_m->sp_mark[0] = sfSprite_create();
    sfSprite_setTexture(my_m->sp_mark[0], my_m->te_mark[0], sfTrue);
    my_m->te_mark[1] = sfTexture_createFromFile
    ("src/market/load/all_mark.png", NULL);
    my_m->sp_mark[1] = sfSprite_create();
    sfSprite_setTexture(my_m->sp_mark[1], my_m->te_mark[1], sfTrue);
    my_m->texte = sfText_create();
    my_m->font = sfFont_createFromFile("src/market/load/arial.ttf");
    sfText_setFont(my_m->texte, my_m->font);
    sfText_setCharacterSize(my_m->texte, 40);
    my_m->buy = 0;
    return (1);
}
