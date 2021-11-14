/*
** EPITECH PROJECT, 2020
** change_map
** File description:
** *
*/

#include "display_player.h"
#include "my.h"

int go_up(disp_player_t *disp_player, st_pos *s_pos, int old_place_y)
{
    if ((disp_player->vect.x > ((s_pos->l_map / 2) - (s_pos->c_map) / 9)
        && disp_player->vect.x < ((s_pos->l_map / 2) + (s_pos->c_map) / 9))
        && (disp_player->vect.y < 50)
        && (old_place_y > disp_player->vect.y)
        && s_pos->s_1 == 1)
        return 1;
    return 0;
}

int go_down(disp_player_t *disp_player, st_pos *s_pos, int old_place_y)
{
    if ((disp_player->vect.x > ((s_pos->l_map / 2) - (s_pos->c_map) / 9))
        && disp_player->vect.x < ((s_pos->l_map / 2) + (s_pos->c_map) / 9)
        && (disp_player->vect.y > (s_pos->c_map - (s_pos->c_map) / 7))
        && (old_place_y < disp_player->vect.y)
        && s_pos->s_4 == 1)
        return 1;
    return 0;
}

int go_left(disp_player_t *disp_player, st_pos *s_pos, int old_place_x)
{
    if ((disp_player->vect.x < ((s_pos->c_map) / 40))
        && (disp_player->vect.y > ((s_pos->c_map / 2) - (s_pos->c_map) / 9))
        && (disp_player->vect.y < ((s_pos->c_map / 2) + (s_pos->c_map) / 20))
        && (old_place_x > disp_player->vect.x)
        && s_pos->s_2 == 1)
        return 1;
    return 0;
}

int go_right(disp_player_t *disp_player, st_pos *s_pos, int old_place_x)
{
    if ((disp_player->vect.x > (s_pos->l_map - (s_pos->l_map / 10)))
        && (disp_player->vect.y > ((s_pos->c_map / 2) - (s_pos->c_map) / 9))
        && (disp_player->vect.y < ((s_pos->c_map / 2) + (s_pos->c_map) / 9))
        && (old_place_x < disp_player->vect.x)
        && s_pos->s_3 == 1)
        return 1;
    return 0;
}

void check_map(st_map **s_map, window_t *w, disp_player_t *disp_player,
    st_pos *s_pos)
{
    static int old_place_y = 0;
    static int old_place_x = 0;
    static int save = 0;
    int temp = 0;

    if (go_down(disp_player, s_pos, old_place_y) == 1)
        temp = set_new_map_down(s_map, w, s_pos, disp_player);
    if (go_up(disp_player, s_pos, old_place_y) == 1 && temp == 0)
        temp = set_new_map_up(s_map, w, s_pos, disp_player);
    if (go_left(disp_player, s_pos, old_place_x) == 1 && temp == 0)
        temp = set_new_map_left(s_map, w, s_pos, disp_player);
    if (go_right(disp_player, s_pos, old_place_x) == 1 && temp == 0)
        temp = set_new_map_right(s_map, w, s_pos, disp_player);
    save += 1;
    if (save == 1) {
        old_place_y = disp_player->vect.y;
        old_place_x = disp_player->vect.x;
    } if (save == 2)
        save = 0;
}
