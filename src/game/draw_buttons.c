/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_buttons.c
*/

#include "window.h"
#include "fight.h"

int ismouse_there(sfVector2f vector, window_t *window, int size)
{
    sfVector2i vect = sfMouse_getPositionRenderWindow(window->window);

    if (vect.x > vector.x && vect.x < vector.x + size && vect.y > vector.y &&
        vect.y < vector.y + 60)
        return (1);
    return (0);
}

int scale_button(button_t button, window_t *window, int size)
{
    if (ismouse_there(button.vect, window, size) == 1) {
        sfSprite_setScale(button.load.sprite, (sfVector2f){1.5, 1.5});
        sfSprite_setColor(button.load.sprite, (sfColor){135, 150, 255, 255});
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            sfSprite_setScale(button.load.sprite, (sfVector2f){1.20, 1.20});
            sfSprite_setColor(button.load.sprite,
                (sfColor){255, 255, 255, 255});
            return (1);
        } else
            sfSprite_setScale(button.load.sprite, (sfVector2f){1.5, 1.5});
    } else {
        sfSprite_setScale(button.load.sprite, (sfVector2f){1.3, 1.3});
        sfSprite_setColor(button.load.sprite, (sfColor){255, 255, 255, 255});
    }
    return (0);
}

void draw_button(button_t *button, window_t *window, text_t *text)
{
    sfSprite_setPosition(button->load.sprite, button->vect);
    sfRenderWindow_drawSprite(window->window, button->load.sprite, NULL);
    draw_text_fight(text, window, button->spell_name,
        (sfVector2f){button->vect.x + 40, button->vect.y + 20});
}

int display_buttons(buttons_t *buttons, window_t *window, text_t *text)
{
    int a = -1;

    if (scale_button(buttons->one, window, 250) == 1)
        a = 0;
    draw_button(&buttons->one, window, text);
    if (scale_button(buttons->two, window, 250) == 1)
        a = 1;
    draw_button(&buttons->two, window, text);
    if (scale_button(buttons->three, window, 250) == 1)
        a = 2;
    draw_button(&buttons->three, window, text);
    if (scale_button(buttons->four, window, 250) == 1)
        a = 3;
    draw_button(&buttons->four, window, text);
    return (a);
}
