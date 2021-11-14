/*
** EPITECH PROJECT, 2020
** event
** File description:
** inv
*/

#include "inventory.h"

int event_ev(window_t *window, sfEvent ev_ent, int *choice)
{
    while (sfRenderWindow_pollEvent(window->window, (&ev_ent))) {
        if (ev_ent.type == sfEvtClosed) {
            sfRenderWindow_close(window->window);
            return (-1);
        }
        if (ev_ent.type == sfEvtKeyPressed)
            if (sfKeyboard_isKeyPressed(sfKeyI))
                return (-1);
        if (ev_ent.type == sfEvtMouseButtonPressed)
            (*choice) = check_po(window);
    }
    return (0);
}

int uti(window_t *window, ply_t *player, int choice)
{
    int i = 0;

    if (choice <= -1)
        return (choice);
    if (window->inv[choice-1] != '0') {
        if (window->inv[choice-1] > '0' && window->inv[choice-1] < '4') {
            while (window->armor[i] != '0' && window->armor[i] != '\0')
                i++;
            if (window->armor[i] == '\0')
                return (-1);
            window->armor[i] = window->inv[choice-1];
            check_arm(player, window->inv[choice-1]);
            window->inv[choice-1] = '0';
        }
        if (window->inv[choice-1] != 58 && window->inv[choice-1] > '0') {
            check_arm(player, window->inv[choice-1]);
            window->inv[choice-1] = '0';
        }
    }
    return (-1);
}

