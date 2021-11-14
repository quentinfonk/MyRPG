/*
** EPITECH PROJECT, 2020
** print
** File description:
** print
*/

#include "inventory.h"

void pr_stat(window_t *window, ply_t *player)
{
    static sfFont *font;
    static sfText *texte;
    char *str = print_stat(player->player);
    sfVector2f pos_texte = {710, 540};
    sfVector2f pos_perso = {880, 360};

    if (font == NULL) {
        texte = sfText_create();
        font = sfFont_createFromFile("src/market/load/arial.ttf");
        sfText_setFont(texte, font);
        sfText_setCharacterSize(texte, 20);
        sfText_setPosition(texte, pos_texte);
    }
    sfText_setString(texte, str);
    sfRenderWindow_drawText(window->window, texte, NULL);
    sfSprite_setPosition(player->disp.sprite, pos_perso);
    sfRenderWindow_drawSprite(window->window, player->disp.sprite, NULL);
}

void pr_in(window_t *window, inv_t *inv, ply_t *player)
{
    sfVector2f pos_i = {1040, 320};

    sfRenderWindow_drawSprite(window->window, inv->sp_inv[0], NULL);
    for (int i = 0; window->inv[i] != '\0'; i++) {
        if (window->inv[i] != '0' && window->inv[i] < 59) {
            sfSprite_setPosition(inv->sp_inv[window->inv[i] - 48], pos_i);
            sfRenderWindow_drawSprite(window->window,
            inv->sp_inv[window->inv[i] - 48], NULL);
        }
        pos_i.x += 115;
        if (pos_i.x == 1385) {
            pos_i.x = 1040;
            pos_i.y += 110;
        }
    }
    pr_stat(window, player);
}

void pr_stack(window_t *window, inv_t *inv)
{
    sfVector2f pos_i = {600, 320};

    for (int i = 0; window->armor[i] != '\0'; i++) {
        if (window->armor[i] != '0' && window->armor[i] < 59) {
            sfSprite_setPosition(inv->sp_inv[window->armor[i] - 48], pos_i);
            sfRenderWindow_drawSprite(window->window,
            inv->sp_inv[window->armor[i] - 48], NULL);
        }
        pos_i.y += 115;
    }
}
