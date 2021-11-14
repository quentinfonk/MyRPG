/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_click.c
*/

#include "menu_rpg.h"

int ismouse_there_2(sfVector2f vector, window_t *window, int size, int up)
{
    sfVector2i vect = sfMouse_getPositionRenderWindow(window->window);

    if (vect.x > vector.x && vect.x < vector.x + size && vect.y > vector.y &&
        vect.y < vector.y + up)
        return (1);
    return (0);
}

int scale_button_menu(button_menu_t *b, window_t *window, int size, int up)
{
    if (ismouse_there_2(b->vect, window, size, up) == 1) {
        sfSprite_setScale(b->sprite, (sfVector2f){1.2, 1.2});
        sfSprite_setColor(b->sprite, (sfColor){135, 150, 255, 255});
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            sfSprite_setScale(b->sprite, (sfVector2f){0.9, 0.9});
            sfSprite_setColor(b->sprite,
                (sfColor){255, 255, 255, 255});
            return (1);
        } else
            sfSprite_setScale(b->sprite, (sfVector2f){1.2, 1.2});
    } else {
        sfSprite_setScale(b->sprite, (sfVector2f){1, 1});
        sfSprite_setColor(b->sprite, (sfColor){255, 255, 255, 255});
    }
    return (0);
}
