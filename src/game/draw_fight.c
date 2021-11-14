/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_fight.c
*/

#include "window.h"
#include "fight.h"

void draw_text_fight(text_t *display, window_t *window, char *str,
    sfVector2f pos)
{
    sfText_setPosition(display->text, pos);
    sfText_setString(display->text, str);
    sfRenderWindow_drawText(window->window, display->text, NULL);
}

void draw_player_fight(ply_t *player, window_t *window, fight_t *bg)
{
    char life[10] = {0};
    char mana[10] = {0};

    my_itoa_static(life, player->player.health);
    my_itoa_static(mana, player->player.mana);
    draw_text_fight(&bg->life, window, life, (sfVector2f){160, 120});
    draw_text_fight(&bg->life, window, mana, (sfVector2f){160, 212});
    sfSprite_setTexture(player->disp.sprite, player->disp.texture, sfFalse);
    sfSprite_setPosition(player->disp.sprite, player->disp.vect);
    sfSprite_setTextureRect(player->disp.sprite, player->disp.rect);
    sfRenderWindow_drawSprite(window->window, player->disp.sprite, NULL);
}

void draw_monster_fight(monster_t *monster, window_t *window, fight_t *bg)
{
    char life[10] = {0};
    char mana[10] = {0};

    my_itoa_static(life, monster->health);
    my_itoa_static(mana, monster->mana);
    draw_text_fight(&bg->life, window, life, (sfVector2f){1620, 120});
    draw_text_fight(&bg->life, window, mana, (sfVector2f){1620, 212});
    sfSprite_setTexture(monster->disp.sprite, monster->disp.texture, sfFalse);
    sfSprite_setPosition(monster->disp.sprite, monster->disp.vect);
    sfRenderWindow_drawSprite(window->window, monster->disp.sprite, NULL);
}

void player_bot_turns(ply_t *player, window_t *window, monster_t *monster,
    fight_t *bg)
{
    player_turn(player, window, monster, bg);
    if (monster->health <= 0) {
        monster->health = 0;
        return;
    }
    if (player->player.health == 0)
        return;
    sfRenderWindow_clear(window->window, sfBlack);
    sfRenderWindow_drawSprite(window->window, bg->sprite, NULL);
    draw_player_fight(player, window, bg);
    draw_monster_fight(monster, window, bg);
    bot_turn(player, window, monster, bg);
}

void draw_element_in_fight(window_t *window, ply_t *player, monster_t *monster,
    fight_t *bg)
{
    bg->player_spell = -1;
    sfRenderWindow_drawSprite(window->window, bg->sprite, NULL);
    draw_player_fight(player, window, bg);
    draw_monster_fight(monster, window, bg);
    if (bg->player_turn == 1)
        bg->player_spell = display_buttons(&bg->buttons, window, &bg->life);
    if (bg->player_spell != -1)
        player_bot_turns(player, window, monster, bg);
    sfRenderWindow_display(window->window);
    sfRenderWindow_clear(window->window, sfBlack);
}
