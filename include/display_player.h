/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_player.h
*/

#ifndef DISPLAY_PLAYER_H
#define DISPLAY_PLAYER_H

//include

#include <stdbool.h>
#include "window.h"
#include "map.h"

//struct

static const int MV_RECT[] = {
    77,
    154,
    231,
    0
};

typedef struct disp_player_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f vect;
    bool is_walking;
    int movement_speed;
    sfClock *movement;
} disp_player_t;

static const int REDIRECT_VALUE[][2] = {
    {-7, 0},
    {7, 0},
    {0, -7},
    {0, 7},
    {-1, -1}
};

void draw_player(disp_player_t *disp_player, window_t *window, st_map ** map);
disp_player_t set_player(window_t *window, char *str);
void destroy_player(disp_player_t *disp_player);
int is_player_there(sfVector2f player, sfVector2f map);
sfVector2i get_map_of_player(disp_player_t *disp_player, st_map **map);
int get_direction_of_player(disp_player_t *disp_player);
sfVector2i get_next_mop(sfVector2i mop, int dir);
int border_map(sfVector2i mop, disp_player_t *disp_player, int direction);
int can_player_go(disp_player_t *disp, st_map **map, int dir, sfVector2i n);

int set_new_map_left(st_map **s_map, window_t *window, st_pos *s_pos,
    disp_player_t *disp_player);
int set_new_map_right(st_map **s_map, window_t *window, st_pos *s_pos,
    disp_player_t *disp_player);
int set_new_map_down(st_map **s_map, window_t *window, st_pos *s_pos,
    disp_player_t *disp_player);
int set_new_map_up(st_map **s_map, window_t *window, st_pos *s_pos,
    disp_player_t *disp_player);
void draw_pnj(map_t *map, window_t *window, disp_player_t *disp_player);
void check_map(st_map **s_map, window_t *w, disp_player_t *disp_player,
    st_pos *s_pos);
int good_pos_mob(sfVector2f player, sfVector2f p_mob);
sfVector2f set_moov_boss(sfVector2f mob, sfVector2f m, float speed, float i);

#endif
