/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** hitbox.c
*/

#include "window.h"
#include "display_player.h"

int is_player_there(sfVector2f player, sfVector2f map)
{
    if (((player.x + 60 >= map.x && player.x + 60 <= map.x + 100)) ||
        (player.x + 17 >= map.x && player.x + 17 <= map.x + 100))
        if (player.y + 70 >= map.y && player.y + 70 <= map.y + 100)
            return (1);
    return (0);
}

sfVector2i get_map_of_player(disp_player_t *disp_player, st_map **map)
{
    int a = 0, b = 0;

    while (a < 11) {
        if (b == 20) {
            a += 1;
            b = 0;
        }
        if (is_player_there(disp_player->vect, map[a][b].p_map) == 1)
            break;
        b += 1;
    }
    if (b == 20 || a == 11) {
        b = (b == 20 ? b - 1 : b);
        a = (a == 11 ? a - 1 : a);
    }
    return ((sfVector2i){b, a});
}

int get_direction_of_player(disp_player_t *disp_player)
{
    for (int a = 0; a != 4; a++)
        if (MV_RECT[a] == disp_player->rect.top)
            return (a);
    return (4);
}

sfVector2i get_next_mop(sfVector2i mop, int dir)
{
    sfVector2i next = mop;

    switch (dir) {
    case 0:
        next.x -= 1;
        break;
    case 1:
        next.x += 1;
        break;
    case 2:
        next.y -= 1;
        break;
    case 3:
        next.y += 1;
        break;
    default:
        next.y = -1;
        next.x = -1;
        break;
    } return (next);
}

int border_map(sfVector2i mop, disp_player_t *disp_player, int direction)
{
    if (direction == 4)
        return (0);
    if (mop.x == 0 && direction == 0 && disp_player->vect.x - 7 + 17 < 0)
        return (0);
    if (mop.y == 0 && direction == 2 && disp_player->vect.y - 7 < 0)
        return (0);
    if (mop.y == 10 && direction == 3 && disp_player->vect.y + 7 > 950)
        return (0);
    if (mop.x == 18 && direction == 1 && disp_player->vect.x + 7 > 1850)
        return (0);
    return (1);
}
