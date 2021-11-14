/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** window.c
*/

#include "event.h"
#include "map.h"
#include "my.h"
#include "particles.h"

window_t create_window(void)
{
    window_t window;

    window.video = (sfVideoMode){1920, 1080, 32};
    window.line = 2000;
    window.coll	= 1100;
    window.is_cinematic = 0;
    window.window = sfRenderWindow_create(window.video, "my_rpg",
        sfDefaultStyle, NULL);
    window.inv = malloc(sizeof(char) * (12+1));
    for (int i = 0; i != 12; i++)
        window.inv[i] = '0';
    window.inv[13] = '\0';
    window.armor = malloc(sizeof(char) * (4+1));
    for (int i = 0; i != 4; i++)
        window.armor[i] = '0';
    window.armor[4] = '\0';
    window.texture = sfTexture_createFromFile("load/menu/game_over.jpg", NULL);
    window.sprite = sfSprite_create();
    sfSprite_setTexture(window.sprite, window.texture, sfFalse);
    return (window);
}

void display_window(window_t *window, ply_t *player, map_t *map)
{
    draw_floor(map->map, window);
    draw_asset(map->map, window);
    draw_player(&player->disp, window, map->map);
    draw_pnj(map, window, &player->disp);
    draw_mob(map, window, player);
    draw_view(window, player, map);
    map->s_pos.royal_key = map->s_pnj.key_south;
    sfRenderWindow_display(window->window);
    sfRenderWindow_clear(window->window, sfBlack);
    check_map(map->map, window, &player->disp, &map->s_pos);
}

st_map **set_tab(window_t *window)
{
    st_map **s_map;
    char **map_tab = set_map_to_int("map/map_1");
    int i = 0;

    s_map = malloc_tab();
    set_all_block(s_map, map_tab, window);
    set_all_asset(s_map, map_tab, window);
    for (i = 0; map_tab[i] != NULL; i++)
        free(map_tab[i]);
    free(map_tab);
    return s_map;
}

map_t create_map(window_t *window)
{
    map_t map;

    map.map = set_tab(window);
    map.s_pnj = set_pnj(window);
    map.s_pos = set_pos(window);
    map.s_view = set_view(window);
    map.mob_croco = create_mob("load/enemie/croco.png",
    (sfVector2f){window->line/ 12, window->coll / 16});
    map.mob_wolf = create_mob("load/enemie/wolf.png",
    (sfVector2f){window->line / 1.4, window->coll / 8});
    map.mob_ghost = create_mob("load/enemie/ghost.png",
    (sfVector2f){window->line / 1.3, window->coll / 6});
    map.mob_golem = create_mob("load/enemie/golem.png",
    (sfVector2f){window->line / 12, window->coll / 1.5});
    map.mob_tree = create_mob("load/enemie/tree_mob.png",
    (sfVector2f){window->line / 1.35, window->coll / 2.45});
    map.mob_tink = create_mob("load/enemie/bush.png",
    (sfVector2f){window->line / 1.4, window->coll / 2});
    return map;
}

int window(window_t *window, char *mode)
{
    ply_t player = create_player("Boby", mode, window);
    map_t map_s = create_map(window);

    if (my_strcmp(mode, "load") == 0)
        load_player(&player, &map_s, window);
    while (sfRenderWindow_isOpen(window->window) && player.player.health > 0
    && map_s.s_pnj.final_boss != true) {
        if (events(window, &player, &map_s) == 1)
            return (1);
        change_pnj(&map_s, window);
        display_window(window, &player, &map_s);
    }
    free_map(&map_s);
    destroy_player(&player.disp);

    return (0);
}
