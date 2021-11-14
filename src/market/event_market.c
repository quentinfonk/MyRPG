/*
** EPITECH PROJECT, 2020
** event
** File description:
** market
*/

#include "market.h"

int achat_pr_sequel(ply_t *player, int achat);

int check_key(window_t *window, int a, ply_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyM)) {
        if (a == 0) {
            market(window, player);
            return (0);
        }
        return (-1);
    }
    if (sfKeyboard_isKeyPressed(sfKeyM))
        return (-1);
    if (sfKeyboard_isKeyPressed(sfKeyI))
        inventory(window, player);
    return (42);
}

int achat_pr(ply_t *player, int achat)
{
    if (achat == 1) {
        if (player->player.money < 10)
            return (-1);
        else {
            player->player.money -= 10;
            return (0);
        }
    } else if (achat == 2) {
        if (player->player.money < 25)
            return (-1);
        else {
            player->player.money -= 25;
            return (0);
        }
    }
    return (achat_pr_sequel(player, achat));
}

void check_buy(window_t *window, int a, sfVector2f pos, ply_t *player)
{
    int achat = 0;
    int o = 0;

    if (pos.x > 545 && pos.x < 750 && pos.y > 660 && pos.y < 720)
        achat = 1;
    if (pos.x > 830 && pos.x < 1040 && pos.y > 660 && pos.y < 720)
        achat = 2;
    if (pos.x > 1110 && pos.x < 1320 && pos.y > 660 && pos.y < 720)
        achat = 3;
    for (o = 0; window->inv[o] != '\0' && window->inv[o] != '0'; o++);
    if (window->inv[o] == '\0')
        return;
    if (achat_pr(player, achat) == -1)
        return;
    achat = achat + (a-1) * 3;
    window->inv[o] = achat+48;
}

int check_pos(window_t *window, int a, ply_t *player)
{
    sfVector2f pos;

    pos.x = sfMouse_getPositionRenderWindow(window->window).x;
    pos.y = sfMouse_getPositionRenderWindow(window->window).y;
    if (pos.x > 496 && pos.x < 660 && pos.y > 240 && pos.y < 300)
        return (1);
    if (pos.x > 675 && pos.x < 840 && pos.y > 240 && pos.y < 300)
        return (2);
    if (pos.x > 860 && pos.x < 1020 && pos.y > 240 && pos.y < 300)
        return (3);
    if (pos.x > 1040 && pos.x < 1200 && pos.y > 240 && pos.y < 300)
        return (4);
    if (pos.x > 1220 && pos.x < 1375 && pos.y > 240 && pos.y < 300)
        return (5);
    check_buy(window, a, pos, player);
    return (a);
}

int ev_type(window_t *window, sfEvent ev_ty, int a, ply_t *player)
{
    while (sfRenderWindow_pollEvent(window->window, (&ev_ty))) {
        if (ev_ty.type == sfEvtClosed) {
            sfRenderWindow_close(window->window);
            return (-1);
        }
        if (ev_ty.type == sfEvtMouseButtonPressed)
            return (check_pos(window, a, player));
        if (ev_ty.type == sfEvtKeyPressed)
            return (check_key(window, 1, player));
    }
    return (a);
}
