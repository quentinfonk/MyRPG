/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu_rpg.h
*/

#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Config.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "window.h"

#ifndef MENU_RPG_H
#define MENU_RPG_H

#include "player.h"
#include "map.h"

typedef struct button_menu_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f vect;
} button_menu_t;

typedef struct menu_s
{
    button_menu_t start;
    button_menu_t quit;
    sfTexture *bg_texture;
    sfSprite *bg_sprite;
    sfClock *clock;
} menu_t;

typedef struct home_menu_s
{
    button_menu_t start;
    button_menu_t quit;
    button_menu_t load;
    sfTexture *bg_texture;
    sfSprite *bg_sprite;
    sfClock *clock;
} home_menu_t;

void destroy_home_menu(home_menu_t *menu);
home_menu_t set_menu(window_t *window);
int scale_button_menu(button_menu_t *b, window_t *window, int size, int up);
void destroy_menu(menu_t *menu);
button_menu_t create_button_menu(char *str, sfVector2f vect);
int in_game_menu(window_t *window, ply_t *player, map_t *map);

#endif
