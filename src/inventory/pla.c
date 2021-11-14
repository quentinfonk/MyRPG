/*
** EPITECH PROJECT, 2020
** place
** File description:
** place
*/

#include "inventory.h"

int check_place(window_t *window)
{
    int i = 0;

    for (; window->inv[i] != '\0' && window->inv[i] != '0'; i++);
    if (window->inv[i] == '\0')
        return (-1);
    return (0);
}

void add_in(window_t *window, int a)
{
    int i = 0;

    for (i = 0; window->inv[i] != '0'; i++);
    window->inv[i] = window->armor[a];
}

void change_pla(int i, ply_t *player)
{
    if (i == 49)
        player->player.defense -= 10;
    if (i == 50)
        player->player.attack -= 10;
    if (i == 51) {
        player->player.attack -= 10;
        player->player.defense -= 10;
    }
}
