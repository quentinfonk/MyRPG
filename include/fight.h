/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight.h
*/

#ifndef MUL_MY_RPG_2019_FIGHT_H
#define MUL_MY_RPG_2019_FIGHT_H

#include <math.h>
#include "player.h"
#include "monster.h"

typedef struct s_load_btn
{
    sfSprite *sprite;
    sfTexture *texture;
} load_btn_t;

typedef struct s_button
{
    load_btn_t load;
    sfVector2f vect;
    char spell_name[20];
} button_t;

typedef struct s_buttons
{
    button_t one;
    button_t two;
    button_t three;
    button_t four;
} buttons_t;

typedef struct text_t
{
    sfText *text;
    sfColor color;
    sfFont *font;
} text_t;

typedef struct s_fight
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f save_pos_player;
    sfIntRect save_rect_player;
    text_t life;
    buttons_t buttons;
    int player_turn;
    int player_spell;
} fight_t;

int display_buttons(buttons_t *buttons, window_t *window, text_t *text);
buttons_t create_buttons(player_t *player);
char my_strcpy_btn(char *dest[13], char *str);
void draw_text_fight(text_t *display, window_t *window, char *str,
    sfVector2f pos);
void player_turn(ply_t *player, window_t *window, monster_t *monster,
    fight_t *bg);
void bot_turn(ply_t *player, window_t *window, monster_t *monster,
    fight_t *bg);
void draw_player_fight(ply_t *player, window_t *window, fight_t *bg);
void draw_monster_fight(monster_t *monster, window_t *window, fight_t *bg);
int when_no_mana_m(skill_t *fight, monster_t *monster);
int when_no_mana_p(skill_t *fight, player_t *player);
int next_level(player_t *player, int level_m);
void modif_stat_player(player_t *player);

int print_moves(player_t player);
int print_life_m(monster_t monster);
int print_life_p(player_t player);
int print_lose(char *name);
int fight_display(window_t *window, ply_t *player, char *nme, char *path);
void draw_element_in_fight(window_t *window, ply_t *player,
monster_t *monster, fight_t *fight);
int event_fight(window_t *window);
char *my_itoa_static(char str[20], int nbr);

#endif //MUL_MY_RPG_2019_FIGHT_H
