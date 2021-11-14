/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_mob.c
*/

#include "player.h"
#include "my.h"

int good_pos_mob(sfVector2f player, sfVector2f p_mob)
{
    if ((player.y < (p_mob.y + 250))
        && (player.y > (p_mob.y - 50))
        && (player.x < (p_mob.x + 250))
        && (player.x > p_mob.x - 50))
        return 1;
    return 0;
}

sfVector2f set_moov_boss(sfVector2f mob, sfVector2f m, float speed, float i)
{
    sfVector2f res;

    if (mob.x < m.y && i == 0) {
        mob.x = mob.x + speed;
        if (mob.x >= m.y)
            i = 1;
    }
    if (mob.x > m.x && i == 1) {
        mob.x = mob.x - speed;
        if (mob.x <= m.x)
            i = 0;
    }
    res.x = i;
    res.y = mob.x;
    return res;
}

int draw_mob(map_t *map, window_t *window, ply_t *p)
{
    if (map->s_pnj.s_boss_1 != true)
        if (set_moov_croco(map, window, p) == 1)
            return (1);
    if (map->s_pnj.final_boss != true)
        if (set_moov_wolf(map, window, p) == 1)
            return (1);
    if (map->s_pnj.s_boss_2 != true)
        if (set_moov_golem(map, window, p) == 1)
            return (1);
    if (map->s_pnj.boss_2 != true)
        if (set_moov_ghost(map, window, p) == 1)
            return (1);
    set_moov_tree(map, window);
    return (0);
}

st_mob create_mob(char *str, sfVector2f pos)
{
    st_mob load;

    load.texture = sfTexture_createFromFile(str, NULL);
    load.sprite = sfSprite_create();
    sfSprite_setTexture(load.sprite, load.texture, sfFalse);
    load.vect = pos;
    sfSprite_setPosition(load.sprite, load.vect);
    return load;
}
