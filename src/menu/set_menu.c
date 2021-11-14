/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_menu.c
*/

#include "menu_rpg.h"

button_menu_t create_button_menu(char *str, sfVector2f vect)
{
    button_menu_t load;

    load.texture = sfTexture_createFromFile(str, NULL);
    load.sprite = sfSprite_create();
    sfSprite_setTexture(load.sprite, load.texture, sfFalse);
    load.vect = vect;
    sfSprite_setPosition(load.sprite, vect);
    return (load);
}

home_menu_t set_menu(window_t *window)
{
    home_menu_t set;

    set.bg_texture = sfTexture_createFromFile("load/menu/D0wlF8.jpg", NULL);
    set.bg_sprite = sfSprite_create();
    sfSprite_setTexture(set.bg_sprite, set.bg_texture, sfTrue);
    set.start = create_button_menu("load/menu/button.png",
    (sfVector2f){(window->line / 3.3), (window->coll / 4)});
    set.quit = create_button_menu("load/menu/exit.png",
    (sfVector2f){(window->line / 3.3), (window->coll / 1.5)});
    set.load = create_button_menu("load/menu/load.png",
    (sfVector2f){(window->line / 3.3), (window->coll / 2)});
    set.clock = sfClock_create();
    return (set);
}

void destroy_home_menu(home_menu_t *menu)
{
    sfTexture_destroy(menu->bg_texture);
    sfTexture_destroy(menu->start.texture);
    sfTexture_destroy(menu->quit.texture);
    sfSprite_destroy(menu->start.sprite);
    sfSprite_destroy(menu->quit.sprite);
    sfSprite_destroy(menu->bg_sprite);
    sfTexture_destroy(menu->load.texture);
    sfSprite_destroy(menu->load.sprite);
    sfClock_destroy(menu->clock);
}

void destroy_menu(menu_t *menu)
{
    sfTexture_destroy(menu->bg_texture);
    sfTexture_destroy(menu->start.texture);
    sfTexture_destroy(menu->quit.texture);
    sfSprite_destroy(menu->start.sprite);
    sfSprite_destroy(menu->quit.sprite);
    sfSprite_destroy(menu->bg_sprite);
    sfClock_destroy(menu->clock);
}
