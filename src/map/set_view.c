/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_view.c
*/

#include "player.h"

st_view set_view(window_t *w)
{
    st_view s_view;

    s_view.cent = sfClock_create();
    s_view.size_1 = (sfVector2f){w->line / 4, w->coll / 4};
    s_view.cent_2 = (sfVector2f){w->line / 2 - (w->line / 50),
        w->coll / 2 - (w->coll / 50)};
    s_view.size_2 = (sfVector2f){w->line - (w->line / 15),
        w->coll - (w->coll / 15)};
    s_view.click = 0;
    s_view.views = sfView_create();
    return s_view;
}

void draw_view(window_t *w, ply_t *p, map_t *m)
{
    sfTime time = sfClock_getElapsedTime(m->s_view.cent);
    float seconde = sfTime_asSeconds(time);

    sfVector2f cent_1 = (sfVector2f){p->disp.vect.x, p->disp.vect.y};

    if (m->s_view.click == 1 && seconde >= 0.001) {
        sfView_setCenter(m->s_view.views, cent_1);
        sfRenderWindow_setView(w->window, m->s_view.views);
        sfClock_restart(m->s_view.cent);
    }
    return;
}

void use_view(window_t *w, ply_t *p, map_t *m)
{
    sfVector2f cent_1 = (sfVector2f){p->disp.vect.x, p->disp.vect.y};

    if (m->s_view.click == 0) {
        sfView_setCenter(m->s_view.views, cent_1);
        sfView_setSize(m->s_view.views, m->s_view.size_1);
        m->s_view.click = 1;
        sfRenderWindow_setView(w->window, m->s_view.views);
        return;
    }
    if (m->s_view.click == 1) {
        sfView_setCenter(m->s_view.views, m->s_view.cent_2);
        sfView_setSize(m->s_view.views, m->s_view.size_2);
        m->s_view.click = 0;
        sfRenderWindow_setView(w->window, m->s_view.views);
    }
}
