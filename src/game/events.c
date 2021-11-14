/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** events.c
*/

#include <SFML/Window/Keyboard.h>
#include "event.h"
#include "menu_rpg.h"

int events(window_t *window, ply_t *player, map_t *map)
{
    int rtrn_value = 0;

    while (sfRenderWindow_pollEvent(window->window, (&window->event))) {
        if (window->event.type == sfEvtClosed)
            sfRenderWindow_close(window->window);
        if (window->event.type == sfEvtKeyPressed &&
            sfKeyboard_isKeyPressed(sfKeyTab) == sfTrue) {
            use_view(window, player, map);
        }
        if (window->event.type == sfEvtKeyPressed)
            check_key(window, 0, player);
        if (window->event.type == sfEvtKeyPressed &&
            sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            rtrn_value = in_game_menu(window, player, map);
    }
    if (player->player.health == 0)
        window->is_cinematic = 10;
    return (rtrn_value);
}
