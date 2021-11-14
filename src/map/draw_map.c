/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_map.c
*/

#include "display_player.h"
#include "window.h"
#include "my.h"

int good_pos(disp_player_t *disp_player, sfVector2f p_pnj)
{
    if ((disp_player->vect.y < (p_pnj.y + 150))
        && (disp_player->vect.y > (p_pnj.y - 150))
        && (disp_player->vect.x < (p_pnj.x + 150))
        && (disp_player->vect.x > p_pnj.x - 150)) {
        return 1;
    }
    return 0;
}

int get_nb_text(int i)
{
    i += 1;
    if (i == 4)
        i = 0;
    return i;
}

void draw_text_biss(map_t *map, window_t *window)
{
    if (map->s_pnj.diag1 == 1 && my_strcmp(map->s_pnj.nb_map[0],
        map->s_pos.actual_m) == 0) {
        sfRenderWindow_drawSprite(window->window, map->s_pnj.text[0] , NULL);
        sfRenderWindow_drawText(window->window, map->s_pnj.text_1, NULL);
    }
}

void draw_text(map_t *map, window_t *window, disp_player_t *disp_player)
{
    static int i = 0, z = 0;

    draw_text_biss(map, window);
    if (good_pos(disp_player, map->s_pnj.p_pnj[1]) == 1
        && my_strcmp(map->s_pnj.nb_map[1] , map->s_pos.actual_m) == 0) {
        print_histories_2(&map->s_pnj, window, i);
        sfRenderWindow_drawSprite(window->window, map->s_pnj.text[1] , NULL);
        sfRenderWindow_drawText(window->window, map->s_pnj.text_2, NULL);
        i = 1;
        return;
    } if (good_pos(disp_player, map->s_pnj.p_pnj[3]) == 1
        && my_strcmp(map->s_pnj.nb_map[2] , map->s_pos.actual_m) == 0) {
        print_histories_3(&map->s_pnj, window, z);
        sfRenderWindow_drawSprite(window->window, map->s_pnj.text[2], NULL);
        sfRenderWindow_drawText(window->window, map->s_pnj.text_3, NULL);
        z = 1;
        return;
    } z = 0;
    i = 0;
}

void draw_pnj(map_t *map, window_t *window, disp_player_t *disp_player)
{
    if (map->s_pnj.pnj_nb[0] == 0 && my_strcmp(map->s_pnj.nb_map[0] ,
        map->s_pos.actual_m) == 0)
        sfRenderWindow_drawSprite(window->window, map->s_pnj.s_pnj[0], NULL);
    if (map->s_pnj.pnj_nb[1] == 0 && my_strcmp(map->s_pnj.nb_map[1] ,
        map->s_pos.actual_m) == 0)
        sfRenderWindow_drawSprite(window->window, map->s_pnj.s_pnj[1], NULL);
    if (my_strcmp(map->s_pnj.nb_map[2], map->s_pos.actual_m) == 0) {
        sfRenderWindow_drawSprite(window->window, map->s_pnj.s_pnj[2], NULL);
        sfRenderWindow_drawSprite(window->window, map->s_pnj.s_pnj[3], NULL);
    }
    draw_text(map, window, disp_player);
}
