/*
** EPITECH PROJECT, 2020
** up
** File description:
** down
*/

#include "map.h"
#include "my.h"

void pnj_1_up(st_pnj *s_pnj)
{
    s_pnj->p_pnj[0].y += -8;
    s_pnj->r_pnj[0].left += 65;
    if (s_pnj->r_pnj[0].left > 130)
        s_pnj->r_pnj[0].left = 0;
    sfClock_restart(s_pnj->clock_walk);
}

void pnj_1_down(st_pnj *s_pnj, window_t *window)
{
    s_pnj->p_pnj[0].y += 8;
    s_pnj->r_pnj[0].left += 65;
    if (s_pnj->r_pnj[0].left > 130)
        s_pnj->r_pnj[0].left = 0;
    if (s_pnj->p_pnj[0].y > window->coll)
        window->is_cinematic = 0;
    sfClock_restart(s_pnj->clock_walk);
}
