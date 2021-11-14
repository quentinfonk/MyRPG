/*
** EPITECH PROJECT, 2020
** check_po
** File description:
** check_po
*/

#include "inventory.h"

int check_po4(sfVector2f pos)
{
    if (pos.x >= 1262 && pos.x <= 1353) {
        if (pos.y >= 315 && pos.y <= 405)
            return (3);
        if (pos.y >= 425 && pos.y <= 519)
            return (6);
        if (pos.y >= 539 && pos.y <= 632)
            return (9);
        if (pos.y >= 654 && pos.y <= 746)
            return (12);
    }
    return (-1);
}

int check_po3(sfVector2f pos)
{
    if (pos.x >= 585 && pos.x <= 685) {
        if (pos.y >= 315 && pos.y <= 405)
            return (-13);
        if (pos.y >= 425 && pos.y <= 519)
            return (-12);
        if (pos.y >= 539 && pos.y <= 632)
            return (-11);
        if (pos.y >= 654 && pos.y <= 746)
            return (-10);
    }
    return (check_po4(pos));
}

int check_po2(sfVector2f pos)
{
    if (pos.x >= 1150 && pos.x <= 1240) {
        if (pos.y >= 315 && pos.y <= 405)
            return (2);
        if (pos.y >= 425 && pos.y <= 519)
            return (5);
        if (pos.y >= 539 && pos.y <= 632)
            return (8);
        if (pos.y >= 654 && pos.y <= 746)
            return (11);
    }
    return (check_po3(pos));
}

int check_po(window_t *window)
{
    sfVector2f pos;

    pos.x = sfMouse_getPositionRenderWindow(window->window).x;
    pos.y = sfMouse_getPositionRenderWindow(window->window).y;
    if (pos.x >= 1035 && pos.x <= 1130) {
        if (pos.y >= 315 && pos.y <= 405)
            return (1);
        if (pos.y >= 425 && pos.y <= 519)
            return (4);
        if (pos.y >= 539 && pos.y <= 632)
            return (7);
        if (pos.y >= 654 && pos.y <= 746)
            return (10);
    }
    return (check_po2(pos));
}
