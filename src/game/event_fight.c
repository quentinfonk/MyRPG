/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_fight.c
*/

#include "window.h"
#include "fight.h"

int event_fight(window_t *window)
{
    while (sfRenderWindow_pollEvent(window->window, (&window->event))) {
        if (window->event.type == sfEvtClosed) {
            sfRenderWindow_close(window->window);
            return (1);
        }
    }
    return (0);
}
