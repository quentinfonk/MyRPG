/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** graphic_fight.c
*/

#include "window.h"
#include "fight.h"
#include "my.h"

fight_t load_fight(ply_t *player)
{
    fight_t load;

    load.texture = sfTexture_createFromFile("load/fight_map.png", NULL);
    load.sprite = sfSprite_create();
    sfSprite_setTexture(load.sprite, load.texture, sfTrue);
    load.save_pos_player = player->disp.vect;
    load.save_rect_player = player->disp.rect;
    load.life.text = sfText_create();
    load.life.color = sfBlack;
    load.buttons = create_buttons(&player->player);
    load.life.font = sfFont_createFromFile("load/anime_ace.bold.ttf");
    sfText_setFont(load.life.text, load.life.font);
    sfText_setColor(load.life.text, load.life.color);
    sfText_setStyle(load.life.text, sfTextStrikeThrough);
    sfText_setCharacterSize(load.life.text, (20));
    load.player_turn = 1;
    load.player_spell = -1;
    return (load);
}

void end_fight(disp_monster_t *monster, fight_t *fight, ply_t *player)
{
    player->disp.vect = fight->save_pos_player;
    player->disp.rect = fight->save_rect_player;
    sfSprite_setScale(player->disp.sprite, (sfVector2f){1, 1});
    sfFont_destroy(fight->life.font);
    sfText_destroy(fight->life.text);
    sfSprite_destroy(fight->sprite);
    sfTexture_destroy(fight->texture);
    sfSprite_destroy(monster->sprite);
    sfTexture_destroy(monster->texture);
    sfTexture_destroy(fight->buttons.one.load.texture);
    sfSprite_destroy(fight->buttons.one.load.sprite);
}

void change_sprite_player(ply_t *player)
{
    player->disp.rect.top = 154;
    player->disp.rect.left = 77;
    player->disp.vect.x = 300;
    player->disp.vect.y = 500;
    sfSprite_setScale(player->disp.sprite, (sfVector2f){2, 2});
}

void draw_win_lose(ply_t *player, monster_t *monster, window_t *window,
    fight_t *fight)
{
    char *str = NULL;
    sfClock *clock = sfClock_create();

    sfRenderWindow_drawSprite(window->window, fight->sprite, NULL);
    draw_player_fight(player, window, fight);
    draw_monster_fight(monster, window, fight);
    if (player->player.health == 0)
        str = my_strdup(monster->name);
    else
        str = my_strdup(player->player.name);
    if (window->is_cinematic == 10)
        sfRenderWindow_drawSprite(window->window, window->sprite, NULL);
    my_strcat(&str, " won the fight !");
    draw_text_fight(&fight->life, window, str, (sfVector2f){700, 200});
    sfRenderWindow_display(window->window);
    while (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) < 3000);
    sfClock_destroy(clock);
    free(str);
}

int fight_display(window_t *window, ply_t *player, char *name, char *path)
{
    fight_t fight = load_fight(player);
    monster_t monster = create_monster(name, path);
    int retrn_event = 0;

    change_sprite_player(player);
    while (player->player.health > 0 && monster.health > 0) {
        retrn_event = event_fight(window);
        if (retrn_event == 1) {
            end_fight(&monster.disp, &fight, player);
            return (1);
        }
        draw_element_in_fight(window, player, &monster, &fight);
        if (player->player.health == 0)
            window->is_cinematic = 10;
        if (player->player.health == 0 || monster.health == 0)
            draw_win_lose(player, &monster, window, &fight);
    }
    end_fight(&monster.disp, &fight, player);
    return (0);
}
