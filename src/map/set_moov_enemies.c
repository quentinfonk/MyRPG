/*
** EPITECH PROJECT, 2020
** Mul_my_rpg_2019
** File description:
** set_moov_enemies.c
*/

#include "my.h"
#include "player.h"
#include "fight.h"

void set_t(sfTexture *rev, sfTexture *act, sfSprite *s, float i)
{
    if (i == 0)
        sfSprite_setTexture(s, rev, sfFalse);
    if (i == 1)
        sfSprite_setTexture(s, act, sfFalse);
}

int set_moov_croco(map_t *map, window_t *w, ply_t *p)
{
    static float i = 0;
    sfVector2f res;
    sfVector2f limit = (sfVector2f){(w->line / w->line), (w->line / 8)};
    sfTexture *rev = sfTexture_createFromFile("load/enemie/c_rev.png", NULL);

    if (my_strcmp(map->s_pos.actual_m, "map_4") == 0) {
        set_t(rev, map->mob_croco.texture, map->mob_croco.sprite, i);
        res = set_moov_boss(map->mob_croco.vect, limit, 1, i);
        i = res.x;
        map->mob_croco.vect.x = res.y;
        sfRenderWindow_drawSprite(w->window, map->mob_croco.sprite, NULL);
        sfSprite_setPosition(map->mob_croco.sprite, map->mob_croco.vect);
        if (good_pos_mob(p->disp.vect, map->mob_croco.vect) == 1) {
            map->s_pnj.s_boss_1 = true;
            return (fight_display(w, p, "DinoGriffe", "boss2.png"));
        }
    } sfTexture_destroy(rev);
    return (0);
}

int set_moov_wolf(map_t *map, window_t *w, ply_t *p)
{
    static float i = 0;
    sfVector2f res;
    sfVector2f limit = (sfVector2f){(w->line / 1.6), (w->line / 1.2)};
    sfTexture *rev = sfTexture_createFromFile("load/enemie/w_rev.png", NULL);

    if (my_strcmp(map->s_pos.actual_m, "map_4") == 0) {
        set_t(rev, map->mob_wolf.texture, map->mob_wolf.sprite, i);
        res = set_moov_boss(map->mob_wolf.vect, limit, 0.5, i);
        i = res.x;
        map->mob_wolf.vect.x = res.y;
        sfRenderWindow_drawSprite(w->window, map->mob_wolf.sprite, NULL);
        sfSprite_setPosition(map->mob_wolf.sprite, map->mob_wolf.vect);
        if (good_pos_mob(p->disp.vect, map->mob_wolf.vect) == 1) {
            map->s_pnj.final_boss = true;
            return (fight_display(w, p, "Zoroark", "boss4.png"));
        }
    }
    sfTexture_destroy(rev);
    return (0);
}

int set_moov_golem(map_t *map, window_t *w, ply_t *p)
{
    static float i = 0;
    sfVector2f res;
    sfVector2f limit = (sfVector2f){(w->line / w->line), (w->line / 8)};
    sfTexture *rev = sfTexture_createFromFile("load/enemie/o_rev.png", NULL);

    if (my_strcmp(map->s_pos.actual_m, "map_4") == 0) {
        set_t(rev, map->mob_golem.texture, map->mob_golem.sprite, i);
        res = set_moov_boss(map->mob_golem.vect, limit, 0.4, i);
        i = res.x;
        map->mob_golem.vect.x = res.y;
        sfRenderWindow_drawSprite(w->window, map->mob_golem.sprite, NULL);
        sfSprite_setPosition(map->mob_golem.sprite, map->mob_golem.vect);
        if (good_pos_mob(p->disp.vect, map->mob_golem.vect) == 1) {
            map->s_pnj.s_boss_2 = true;
            return (fight_display(w, p, "Grolem", "boss3.png"));
        }
    }
    sfTexture_destroy(rev);
    return (0);
}

int set_moov_ghost(map_t *map, window_t *w, ply_t *p)
{
    static float i = 0;
    sfVector2f res;
    sfVector2f limit = (sfVector2f){(w->line / 1.6), (w->line / 1.2)};
    sfTexture *rev = sfTexture_createFromFile("load/enemie/g_rev.png", NULL);

    if (my_strcmp(map->s_pos.actual_m, "map_3") == 0) {
        set_t(rev, map->mob_ghost.texture, map->mob_ghost.sprite, i);
        res = set_moov_boss(map->mob_ghost.vect, limit, 0.5, i);
        i = res.x;
        map->mob_ghost.vect.x = res.y;
        sfRenderWindow_drawSprite(w->window, map->mob_ghost.sprite, NULL);
        sfSprite_setPosition(map->mob_ghost.sprite, map->mob_ghost.vect);
        if (good_pos_mob(p->disp.vect, map->mob_ghost.vect) == 1) {
            map->s_pnj.boss_2 = true;
            map->s_pnj.key_south = true;
            return (fight_display(w, p, "Darkrai", "boss1.png"));
        }
    }
    sfTexture_destroy(rev);
    return (0);
}
