/*
** EPITECH PROJECT, 2020
** map
** File description:
** map.h
*/

#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Config.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

#include "window.h"

#ifndef MAP_H
#define MAP_H
#define NBR(a) (a - '0')

typedef struct map_block_asset
{
    sfClock *clock_map;
    sfTexture *t_map;
    sfSprite *s_map;
    sfVector2f p_map;
    sfTexture *t_obj;
    sfSprite *s_obj;
    sfVector2f p_obj;
    int hit_box;
    int mob;
} st_map;

typedef struct map_pnj
{
    int *pnj_nb;
    int nb_pnj;
    char **nb_map;
    sfClock *clock_walk;
    sfTexture **t_pnj;
    sfSprite **s_pnj;
    sfVector2f *p_pnj;
    sfIntRect *r_pnj;
    sfSprite **text;
    sfText *text_1;
    sfText *text_2;
    sfText *text_3;
    int diag1;
    sfClock *clock_rand;
    bool key_south;
    bool boss_2;
    bool s_boss_1;
    bool s_boss_2;
    bool final_boss;
} st_pnj;

typedef struct map_change
{
    int royal_key;
    char *actual_m;
    int s_1;
    int s_2;
    int s_3;
    int s_4;
    int l_map;
    int c_map;
} st_pos;

typedef struct ma_mob
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f vect;
} st_mob;

typedef struct ma_view
{
    sfView *views;
    sfVector2f cent_1;
    sfVector2f size_1;
    sfVector2f cent_2;
    sfVector2f size_2;
    int click;
    sfClock *cent;
} st_view;

typedef struct map_all
{
    st_pos s_pos;
    st_pnj s_pnj;
    st_mob mob_tink;
    st_mob mob_ghost;
    st_mob mob_wolf;
    st_mob mob_golem;
    st_mob mob_croco;
    st_mob mob_tree;
    st_map **map;
    st_view s_view;
} map_t;

char **my_str_to_word_array(char *str);
char **set_map_to_int(char const *filepath);
char **set_map_to_info(char const *filepath);
void free_all(st_map **s_map, char **map_tab);
char *get_map(char const *filepath);
char *get_info(char const *filepath);
void draw_floor(st_map **s_map, window_t *window);
void draw_asset(st_map **s_map, window_t *window);
void get_rand_road(sfVector2i va, st_map **s_map, sfClock *clock_rand);
void get_rand_road_2(sfVector2i va, st_map **s_map, sfClock *clock_rand);
void get_rand_grass(sfVector2i va, st_map **s_map, sfClock *clock_rand);
void set_all_block(st_map **s_map, char **map_tab, window_t *wind);
void set_all_asset(st_map **s_map, char **map_tab, window_t *wind);
void get_block(sfVector2i va, st_map **s_map, char *map_tab,
    sfClock *clock_rand);
void get_asset(sfVector2i va, st_map **s_map, char *map_tab);
void set_new_pos(st_pos *s_pos, char **map_info);
void change_pnj(map_t *map, window_t *window);
void print_histories_1(st_pnj *s_pnj, window_t *window, float seconde);
void print_histories_2(st_pnj *s_pnj, window_t *window, int i);
void print_histories_3(st_pnj *s_pnj, window_t *window, int i);
void get_str_hist_1(char **str, int i, st_pnj *s_pnj);
void get_str_hist_2(char **str, int i, st_pnj *s_pnj);
st_pnj set_pnj(window_t *window);
st_pos set_pos(window_t *window);
st_map **malloc_tab(void);
st_map **set_tab(window_t *window);
st_mob create_mob(char *str, sfVector2f pos);
void get_block_1_2(sfVector2i va, st_map **s_map, char *map_tab);
void get_block_1(sfVector2i va, st_map **s_map, char *map_tab,
    sfClock *clock_rand);
void get_block_2_2(sfVector2i va, st_map **s_map, char *map_tab);
void get_block_2(sfVector2i va, st_map **s_map, char *map_tab);
void set_moov_tree(map_t *map, window_t *window);
void pnj_1_up(st_pnj *s_pnj);
void pnj_1_down(st_pnj *s_pnj, window_t *window);
void free_map(map_t *map);

#endif
