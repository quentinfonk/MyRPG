/*
** EPITECH PROJECT, 2020
** test
** File description:
** get_the_pnj.c
*/

#include "player.h"

st_pnj set_text_2(st_pnj s_pos, window_t *window)
{
    sfTexture *text = sfTexture_createFromFile("load/pnj/texte_2.png", NULL);
    sfVector2f rct = (sfVector2f){(window->line / 2), (window->coll / 1.6)};

    s_pos.key_south = false;
    s_pos.boss_2 = false;
    s_pos.s_boss_1 = false;
    s_pos.s_boss_2 = false;
    s_pos.final_boss = false;
    s_pos.text[2] = sfSprite_create();
    sfSprite_setTexture(s_pos.text[2] , text, false);
    sfSprite_setPosition(s_pos.text[2] , rct);
    return s_pos;
}

st_pnj set_text_1(st_pnj s_pos, window_t *window)
{
    sfTexture *text = sfTexture_createFromFile("load/pnj/texte_2.png", NULL);
    sfVector2f rct = (sfVector2f){(window->line / 3.8), (window->coll / 12)};

    s_pos.text[1] = sfSprite_create();
    sfSprite_setTexture(s_pos.text[1] , text, false);
    sfSprite_setPosition(s_pos.text[1] , rct);
    return s_pos;
}

st_pnj set_position(st_pnj s_pos, window_t *window)
{
    s_pos.p_pnj = malloc(sizeof(sfVector2f) * (s_pos.nb_pnj + 1));
    s_pos.p_pnj[0].x = ((window->line / 2) -
    (window->line / (window->line / 100)));
    s_pos.p_pnj[0].y = window->coll - (window->coll / 6);
    s_pos.p_pnj[1].x = (window->line / 4);
    s_pos.p_pnj[1].y = (window->coll / 4);
    s_pos.p_pnj[2].x = (window->line / 2.4);
    s_pos.p_pnj[2].y = (window->coll / 1.2);
    s_pos.p_pnj[3].x = (window->line / 2);
    s_pos.p_pnj[3].y = (window->coll / 1.2);
    sfSprite_setPosition(s_pos.s_pnj[0], s_pos.p_pnj[0]);
    sfSprite_setPosition(s_pos.s_pnj[1], s_pos.p_pnj[1]);
    sfSprite_setPosition(s_pos.s_pnj[2], s_pos.p_pnj[2]);
    sfSprite_setPosition(s_pos.s_pnj[3], s_pos.p_pnj[3]);
    s_pos.pnj_nb = malloc(sizeof(int) * (s_pos.nb_pnj + 1));
    s_pos.pnj_nb[0] = 0;
    s_pos.pnj_nb[1] = 0;
    s_pos.pnj_nb[2] = 0;
    s_pos.pnj_nb[3] = 0;
    return s_pos;
}

st_pnj set_t_s(st_pnj s_pos)
{
    s_pos.r_pnj[2] = (sfIntRect){65, 285, 65, 85};
    s_pos.r_pnj[3] = (sfIntRect){65, 285, 65, 85};
    s_pos.t_pnj = malloc(sizeof(sfTexture*) * (s_pos.nb_pnj + 1));
    s_pos.t_pnj[0] = sfTexture_createFromFile("load/pnj/farmer.png", NULL);
    s_pos.t_pnj[1] = sfTexture_createFromFile("load/pnj/king.png", NULL);
    s_pos.t_pnj[2] = sfTexture_createFromFile("load/pnj/knigh.png", NULL);
    s_pos.t_pnj[3] = sfTexture_createFromFile("load/pnj/knigh.png", NULL);
    s_pos.s_pnj = malloc(sizeof(sfSprite*) * (s_pos.nb_pnj + 1));
    s_pos.s_pnj[0] = sfSprite_create();
    s_pos.s_pnj[1] = sfSprite_create();
    s_pos.s_pnj[2] = sfSprite_create();
    s_pos.s_pnj[3] = sfSprite_create();
    sfSprite_setTexture(s_pos.s_pnj[0], s_pos.t_pnj[0], sfFalse);
    sfSprite_setTexture(s_pos.s_pnj[1], s_pos.t_pnj[1], sfFalse);
    sfSprite_setTexture(s_pos.s_pnj[2], s_pos.t_pnj[2], sfFalse);
    sfSprite_setTexture(s_pos.s_pnj[3], s_pos.t_pnj[3], sfFalse);
    sfSprite_setTextureRect(s_pos.s_pnj[0], s_pos.r_pnj[0]);
    sfSprite_setTextureRect(s_pos.s_pnj[2], s_pos.r_pnj[2]);
    sfSprite_setTextureRect(s_pos.s_pnj[3], s_pos.r_pnj[3]);
    return s_pos;
}

st_pnj set_pnj(window_t *window)
{
    st_pnj s_pos;

    s_pos.nb_pnj = 4;
    s_pos.text = malloc(sizeof(sfSprite*) * (s_pos.nb_pnj + 1));
    s_pos.nb_map = malloc(sizeof(char *) * (s_pos.nb_pnj + 1));
    s_pos.nb_map[0] = "map_1";
    s_pos.nb_map[1] = "map_3";
    s_pos.nb_map[2] = "map_2";
    s_pos.nb_map[3] = "map_2";
    s_pos.r_pnj = malloc(sizeof(sfIntRect) * (s_pos.nb_pnj + 1));
    s_pos.r_pnj[0] = (sfIntRect){0, 82, 75, 85};
    s_pos.r_pnj[1] = (sfIntRect){0, 0, 0, 0};
    s_pos = set_t_s(s_pos);
    s_pos = set_position(s_pos, window);
    s_pos.clock_walk = sfClock_create();
    s_pos.clock_rand = sfClock_create();
    s_pos = set_text_1(s_pos, window);
    s_pos = set_text_2(s_pos, window);
    s_pos.diag1 = 0;
    return s_pos;
}
