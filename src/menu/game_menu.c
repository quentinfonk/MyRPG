/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_menu.c
*/

#include "menu_rpg.h"

menu_t set_menu_in_game(window_t *window)
{
    menu_t load;

    load.start = create_button_menu("load/menu/save_button.png",
    (sfVector2f){(window->line / 3.3), (window->coll / 3)});
    load.quit = create_button_menu("load/menu/exit.png",
    (sfVector2f){(window->line / 3.3), (window->coll / 1.5)});
    load.bg_texture = sfTexture_createFromFile("load/menu/ig_menu.jpg", NULL);
    load.bg_sprite = sfSprite_create();
    sfSprite_setTexture(load.bg_sprite, load.bg_texture, sfFalse);
    load.clock = sfClock_create();
    return (load);
}

void display_ig_menu(menu_t *menu, window_t *window)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(menu->clock)) > 50) {
        sfRenderWindow_drawSprite(window->window, menu->bg_sprite, NULL);
        sfRenderWindow_drawSprite(window->window, menu->start.sprite, NULL);
        sfRenderWindow_drawSprite(window->window, menu->quit.sprite, NULL);
        sfRenderWindow_display(window->window);
        sfRenderWindow_clear(window->window, sfBlack);
        sfClock_restart(menu->clock);
    }
}

int event_ig(window_t *window)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        if (window->event.type == sfEvtClosed)
            sfRenderWindow_close(window->window);
        if (window->event.type == sfEvtKeyPressed &&
            sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            return (1);
    }
    return (0);
}

int in_game_menu(window_t *window, ply_t *player, map_t *map)
{
    menu_t menu = set_menu_in_game(window);

    while (sfRenderWindow_isOpen(window->window)) {
        if (scale_button_menu(&menu.start, window, 500, 179) == 1)
            save_player(&player->player, map, window);
        if (scale_button_menu(&menu.quit, window, 410, 147) == 1) {
            destroy_menu(&menu);
            return (1);
        }
        if (event_ig(window) == 1) {
            destroy_menu(&menu);
            return (0);
        }
        display_ig_menu(&menu, window);
    }
    destroy_menu(&menu);
    return (0);
}
