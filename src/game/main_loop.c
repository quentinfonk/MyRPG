/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_loop.c
*/
#include "menu_rpg.h"
#include "particles.h"

void display_menu(home_menu_t *menu, window_t *window, node_t **node)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(menu->clock)) > 50) {
        if (window->is_cinematic < 10)
            sfRenderWindow_drawSprite(window->window, menu->bg_sprite, NULL);
        else
            sfRenderWindow_drawSprite(window->window, window->sprite, NULL);
        draw_particles(window, node);
        sfRenderWindow_drawSprite(window->window, menu->start.sprite, NULL);
        sfRenderWindow_drawSprite(window->window, menu->load.sprite, NULL);
        sfRenderWindow_drawSprite(window->window, menu->quit.sprite, NULL);
        sfRenderWindow_display(window->window);
        sfRenderWindow_clear(window->window, sfBlack);
        sfClock_restart(menu->clock);
    }
}

void redirect_main_loop(window_t *window, home_menu_t *menu, node_t **node)
{
    while (sfRenderWindow_pollEvent(window->window, (&window->event)))
        if (window->event.type == sfEvtClosed)
            sfRenderWindow_close(window->window);
    display_menu(menu, window, node);
}

void free_main_loop(home_menu_t *menu, node_t *node, window_t *window)
{
    free_node(node);
    destroy_home_menu(menu);
    sfSprite_destroy(window->sprite);
    sfTexture_destroy(window->texture);
}

int main_loop(void)
{
    window_t wind = create_window();
    home_menu_t menu = set_menu(&wind);
    node_t *node = NULL;

    setup_particles(&node);
    if (node == NULL || menu.bg_texture == NULL)
        return (84);
    sfRenderWindow_setFramerateLimit(wind.window, 60);
    while (sfRenderWindow_isOpen(wind.window)) {
        if (scale_button_menu(&menu.start, &wind, 483, 179) == 1) {
            window(&wind, "save");
            sfRenderWindow_waitEvent(wind.window, &wind.event);
        }
        if (scale_button_menu(&menu.quit, &wind, 410, 147) == 1)
            sfRenderWindow_close(wind.window);
        if (scale_button_menu(&menu.load, &wind, 409, 152) == 1)
            window(&wind, "load");
        redirect_main_loop(&wind, &menu, &node);
    } free_main_loop(&menu, node, &wind);
    return (0);
}
