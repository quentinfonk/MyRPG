/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_buttons.c
*/

#include "window.h"
#include "fight.h"
#include "my.h"

load_btn_t load_button(char *str)
{
    load_btn_t load;

    load.sprite = sfSprite_create();
    load.texture = sfTexture_createFromFile(str, NULL);
    sfSprite_setTexture(load.sprite, load.texture, sfFalse);
    return (load);
}

button_t create_button(load_btn_t load, sfVector2f pos, char name[13])
{
    button_t button;
    button.load = load;
    button.vect = pos;
    my_strcpy(button.spell_name, name);
    return (button);
}

buttons_t create_buttons(player_t *player)
{
    buttons_t set;
    load_btn_t load = load_button("files/button.png");

    set.one = create_button(load, (sfVector2f){500, 740},
        player->arr[0].name);
    set.two = create_button(load, (sfVector2f){1000, 740},
        player->arr[1].name);
    set.three = create_button(load, (sfVector2f){500, 840},
        player->arr[2].name);
    set.four = create_button(load, (sfVector2f){1000, 840},
        player->arr[3].name);
    return (set);
}
