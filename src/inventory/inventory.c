/*
** EPITECH PROJECT, 2020
** inventory
** File description:
** inventory
*/

#include "inventory.h"

void inven(window_t *window, inv_t *inv, ply_t *player)
{
    sfEvent ev_ent;
    int a = 0;
    int choice = -1;

    create_inv(inv);
    while (a != -1) {
        a = event_ev(window, ev_ent, &choice);
        pr_in(window, inv, player);
        pr_stack(window, inv);
        choice = uti(window, player, choice);
        choice = el_arm(window, choice, player);
        sfRenderWindow_display(window->window);
        sfRenderWindow_clear(window->window, sfBlack);
    }
}

void inventory(window_t *window, ply_t *player)
{
    inv_t inv;

    inven(window, &inv, player);
}
