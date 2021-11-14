/*
** EPITECH PROJECT, 2020
** test
** File description:
** print_histories.c
*/

#include "dialog.h"
#include "player.h"

void print_histories_3(st_pnj *s_pnj, window_t *window, int i)
{
    sfVector2f pos = (sfVector2f){(window->line / 1.9), (window->coll / 1.5)};
    sfFont* font = sfFont_createFromFile("src/market/load/arial.ttf");
    static char *str = NULL;

    s_pnj->text_3 = NULL;
    s_pnj->text_3 = sfText_create();
    sfText_setPosition(s_pnj->text_3, pos);
    sfText_setFont(s_pnj->text_3, font);
    get_str_hist_2(&str, i, s_pnj);
    sfText_setString(s_pnj->text_3, str);
    sfText_setColor (s_pnj->text_3, sfBlack);
    sfText_setCharacterSize(s_pnj->text_3, 30);
}

void print_histories_2(st_pnj *s_pnj, window_t *window, int i)
{
    sfVector2f pos = (sfVector2f){(window->line / 3.5), (window->coll / 7.2)};
    sfFont* font = sfFont_createFromFile("src/market/load/arial.ttf");
    static char *str = NULL;

    s_pnj->text_2 = NULL;
    s_pnj->text_2 = sfText_create();
    sfText_setPosition(s_pnj->text_2, pos);
    sfText_setFont(s_pnj->text_2, font);
    get_str_hist_1(&str, i, s_pnj);
    sfText_setString(s_pnj->text_2, str);
    sfText_setColor (s_pnj->text_2, sfBlack);
    sfText_setCharacterSize(s_pnj->text_2, 30);
}

char *set_diag_1(float seconde)
{
    static int dia = 0;
    hash_t *dialogs = create_dialogs("main_pnj");

    if (seconde > 0 && seconde < 2)
        return (dialogs->cells[dia].data);
    if (seconde > 2 && seconde < 4)
        return (dialogs->cells[dia+1].data);
    if (seconde > 4 && seconde < 6)
        return (dialogs->cells[dia+2].data);
    if (seconde > 6 && seconde < 8)
        return (dialogs->cells[dia+3].data);
    if (seconde > 8 && seconde < 10)
        return (dialogs->cells[dia+4].data);
    return (NULL);
}

void print_histories_1(st_pnj *s_pnj, window_t *window, float seconde)
{
    sfTexture *text = sfTexture_createFromFile("load/pnj/texte_1.png", NULL);
    sfVector2f rct = (sfVector2f){(window->line / 2.2), (window->coll / 5)};
    sfVector2f pos = (sfVector2f){(window->line / 2), (window->coll / 3.7)};
    sfFont* font = sfFont_createFromFile("src/market/load/arial.ttf");
    char *str = NULL;

    s_pnj->text_1 = NULL;
    s_pnj->text_1 = sfText_create();
    sfText_setPosition(s_pnj->text_1, pos);
    sfText_setFont(s_pnj->text_1, font);
    str = set_diag_1(seconde);
    sfText_setString(s_pnj->text_1, str);
    sfText_setColor (s_pnj->text_1, sfBlack);
    sfText_setCharacterSize(s_pnj->text_1, 30);
    s_pnj->text[0] = sfSprite_create();
    sfSprite_setTexture(s_pnj->text[0] , text, false);
    sfSprite_setPosition(s_pnj->text[0] , rct);
    return;
}
