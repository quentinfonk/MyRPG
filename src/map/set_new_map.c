/*
** EPITECH PROJECT, 2020
** test
** File description:
** *
*/

#include "player.h"

static int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] > s2[i])
            return 1;
        if (s2[i] > s1[i])
            return -1;
        i++;
    }
    return 0;
}

int set_new_map_up(st_map **s_map, window_t *window, st_pos *s_pos,
    disp_player_t *disp_player)
{
    char **map_tab = NULL;
    char **map_info = NULL;

    if (my_strcmp(s_pos->actual_m, "map_2") == 0) {
        map_tab = set_map_to_int("map/map_1");
        map_info = set_map_to_info("map/pars/map_1");
    }
    if (my_strcmp(s_pos->actual_m, "map_4") == 0) {
        map_tab = set_map_to_int("map/map_2");
        map_info = set_map_to_info("map/pars/map_2");
    }
    disp_player->vect.x = ((s_pos->l_map / 2) - (s_pos->c_map) / 10);
    disp_player->vect.y = (s_pos->c_map - (s_pos->c_map / 6));
    set_new_pos(s_pos, map_info);
    set_all_block(s_map, map_tab, window);
    set_all_asset(s_map, map_tab, window);
    return 1;
}

int set_new_map_down(st_map **s_map, window_t *window, st_pos *s_pos,
    disp_player_t *disp_player)
{
    char **map_tab = NULL;
    char **map_info = NULL;

    if (my_strcmp(s_pos->actual_m, "map_1") == 0) {
        map_tab = set_map_to_int("map/map_2");
        map_info = set_map_to_info("map/pars/map_2");
    }
    if (my_strcmp(s_pos->actual_m, "map_2") == 0 && s_pos->royal_key == true) {
        map_tab = set_map_to_int("map/map_4");
        map_info = set_map_to_info("map/pars/map_4");
    }
    if (my_strcmp(s_pos->actual_m, "map_2") == 0 && s_pos->royal_key == false)
        return 0;
    disp_player->vect.x = ((s_pos->l_map / 2) - (s_pos->c_map) / 10);
    disp_player->vect.y = (s_pos->c_map / 24);
    set_new_pos(s_pos, map_info);
    set_all_block(s_map, map_tab, window);
    set_all_asset(s_map, map_tab, window);
    return 1;
}

int set_new_map_right(st_map **s_map, window_t *window, st_pos *s_pos,
    disp_player_t *disp_player)
{
    char **map_tab = NULL;
    char **map_info = NULL;

    if (my_strcmp(s_pos->actual_m, "map_2") == 0) {
        map_tab = set_map_to_int("map/map_3");
        map_info = set_map_to_info("map/pars/map_3");
    }
    disp_player->vect.x = ((s_pos->l_map / 20));
    disp_player->vect.y = ((s_pos->c_map / 2.2));
    set_new_pos(s_pos, map_info);
    set_all_block(s_map, map_tab, window);
    set_all_asset(s_map, map_tab, window);
    return 1;
}

int set_new_map_left(st_map **s_map, window_t *window, st_pos *s_pos,
    disp_player_t *disp_player)
{
    char **map_tab = NULL;
    char **map_info = NULL;

    if (my_strcmp(s_pos->actual_m, "map_3") == 0) {
        map_tab = set_map_to_int("map/map_2");
        map_info = set_map_to_info("map/pars/map_2");
    }
    disp_player->vect.x = (s_pos->l_map - (s_pos->l_map / 10));
    disp_player->vect.y = ((s_pos->c_map / 2.2));
    set_new_pos(s_pos, map_info);
    set_all_block(s_map, map_tab, window);
    set_all_asset(s_map, map_tab, window);
    return 1;
}
