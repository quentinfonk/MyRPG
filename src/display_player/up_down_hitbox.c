/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** up_down_hitbox.c
*/

#include "window.h"
#include "display_player.h"

int can_player_go(disp_player_t *disp, st_map **map, int dir, sfVector2i n)
{
    sfVector2f oui = {REDIRECT_VALUE[dir][0], REDIRECT_VALUE[dir][1]};

    if (disp->movement_speed == 11) {
        if (oui.x != 0)
            oui.x = (oui.x / 7) * 11;
        if (oui.y != 0)
            oui.y = (oui.y / 7) * 11;
    }
    if (map[n.y][n.x].hit_box == 1)
        if (is_player_there((sfVector2f){disp->vect.x + oui.x, disp->vect.y +
            oui.y}, map[n.y][n.x].p_map) == 1)
            return (0);
    return (1);
}
