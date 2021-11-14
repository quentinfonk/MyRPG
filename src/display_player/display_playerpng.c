/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_playerpng.c
*/

#include "window.h"
#include "display_player.h"

static const sfKeyCode KEYCODE[] = {
    sfKeyLeft,
    sfKeyRight,
    sfKeyUp,
    sfKeyDown,
    -1
};

disp_player_t set_player(window_t *window, char *str)
{
    disp_player_t set;
    sfVector2u win_size = sfRenderWindow_getSize(window->window);

    set.texture = sfTexture_createFromFile(str, NULL);
    set.sprite = sfSprite_create();
    set.rect.top = 0;
    set.rect.left = 0;
    set.rect.width = 77;
    set.rect.height = 77;
    set.vect.x = win_size.x / 2 - 77 / 2;
    set.vect.y = win_size.y / 2 - 77 / 2;
    set.is_walking = false;
    set.movement_speed = 7;
    set.movement = sfClock_create();
    return (set);
}

static int can_player_move(disp_player_t *disp_player, st_map **map)
{
    sfVector2i mop = get_map_of_player(disp_player, map);
    int direction = get_direction_of_player(disp_player);
    sfVector2i next_mop = get_next_mop(mop, direction);

    if (border_map(mop, disp_player, direction) == 0)
        return (0);
    if (next_mop.x < 0 || next_mop.y < 0 || next_mop.y > 10)
        return (1);
    if (map[next_mop.y][next_mop.x].hit_box == 1)
        if (can_player_go(disp_player, map, direction, next_mop) == 0)
            return (0);
    if (direction == 2 || direction == 3) {
        next_mop.x += 1;
        if (can_player_go(disp_player, map, direction, next_mop) == 0)
            return (0);
    }
    return (1);
}

void move_player_on_map(disp_player_t *disp_player, st_map **map)
{
    if (can_player_move(disp_player, map) == 0)
        return;
    switch (disp_player->rect.top) {
    case 0:
        disp_player->vect.y += disp_player->movement_speed;
        break;
    case 231:
        disp_player->vect.y -= disp_player->movement_speed;
        break;
    case 154:
        disp_player->vect.x += disp_player->movement_speed;
        break;
    case 77:
        disp_player->vect.x -= disp_player->movement_speed;
        break;
    default:
        break;
    }
}

static void manage_player_movements(disp_player_t *disp_player,
    window_t *window)
{
    if (window->is_cinematic == 1) {
        disp_player->is_walking = false;
        return;
    }
    for (int i = 0; KEYCODE[i] != -1; i++) {
        if (sfKeyboard_isKeyPressed(KEYCODE[i])) {
            disp_player->is_walking = true;
            disp_player->rect.top = MV_RECT[i];
            break;
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyLShift) == sfTrue)
        disp_player->movement_speed = 11;
    else
        disp_player->movement_speed = 7;
}

void draw_player(disp_player_t *disp_player, window_t *window, st_map **map)
{
    manage_player_movements(disp_player, window);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(disp_player->movement))
        >= 50 && disp_player->is_walking == true) {
        move_player_on_map(disp_player, map);
        disp_player->rect.left += 77;
        if (disp_player->rect.left >= 539)
            disp_player->rect.left = 0;
        sfClock_restart(disp_player->movement);
        disp_player->is_walking = false;
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(disp_player->movement))
        >= 100 && disp_player->is_walking == false) {
        disp_player->rect.left = 0;
        if (disp_player->rect.top == 154 || disp_player->rect.top == 77)
            disp_player->rect.left = 77;
    }
    sfSprite_setTexture(disp_player->sprite, disp_player->texture, sfFalse);
    sfSprite_setPosition(disp_player->sprite, disp_player->vect);
    sfSprite_setTextureRect(disp_player->sprite, disp_player->rect);
    sfRenderWindow_drawSprite(window->window, disp_player->sprite, NULL);
}
