/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get pnj
*/

#include "map.h"
#include "my.h"

int change_pnj_1(st_pnj *s_pnj, int pos, window_t *window, float seconde)
{
    if (s_pnj->p_pnj[0].y <= window->coll / 2 && pos == 0) {
        print_histories_1(s_pnj, window, seconde);
        s_pnj->diag1 = 1;
        if (seconde > 10) {
            pos = 1;
            s_pnj->diag1 = 0;
            s_pnj->r_pnj[0].top = 0;
            sfClock_restart(s_pnj->clock_walk);
        }
    }
    return pos;
}

void use_pnj_1(st_pnj *s_pnj, window_t *window)
{
    sfTime time = sfClock_getElapsedTime(s_pnj->clock_walk);
    float seconde = sfTime_asSeconds(time);
    static int pos = 0;

    if (seconde > 0.09) {
        pos = change_pnj_1(s_pnj, pos, window, seconde);
        if (s_pnj->p_pnj[0].y > window->coll / 2 && pos == 0)
            pnj_1_up(s_pnj);
        if (s_pnj->p_pnj[0].y < window->coll && pos == 1)
            pnj_1_down(s_pnj, window);
        else if (s_pnj->p_pnj[0].y >= window->coll)
            s_pnj->pnj_nb[0] = 1;
        sfSprite_setPosition(s_pnj->s_pnj[0], s_pnj->p_pnj[0]);
        sfSprite_setTextureRect(s_pnj->s_pnj[0], s_pnj->r_pnj[0]);
    }
    return;
}

void check_bol(st_pnj *s_pnj, window_t *window)
{
    int i = 0;
    static int a = 0;

    if (a == 1 || s_pnj->boss_2 != true)
        return;
    a = 1;
    for (; window->inv[i] != '\0' && window->inv[i] != '\0'; i++);
    if (window->inv[i] == '\0')
        window->inv[0] = 10 + 48;
    else
        window->inv[i] = 10 + 48;
}

void change_pnj(map_t *map, window_t *window)
{
    if (my_strcmp(map->s_pos.actual_m, "map_1") == 0)
        use_pnj_1(&map->s_pnj, window);
    check_bol(&map->s_pnj, window);
    return;
}
