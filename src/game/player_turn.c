/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_turn.c
*/

#include "window.h"
#include "fight.h"
#include "my.h"

static const int delay = 1000;
static const int disp_x = 700;
static const int disp_y = 200;
static const int clock_time = 75;

static int player_turn_bis(ply_t *player, window_t *window, sfClock *clock)
{
    player->disp.vect.x += 10;
    sfClock_restart(clock);
    sfSprite_setPosition(player->disp.sprite, player->disp.vect);
    sfRenderWindow_drawSprite(window->window, player->disp.sprite, NULL);
    sfRenderWindow_display(window->window);
    return (1);
}

void player_turn(ply_t *player, window_t *window, monster_t *monster,
    fight_t *bg)
{
    skill_t fight = player_use(bg->player_spell, &player->player);
    sfClock *clock = NULL;
    char *str = my_strdup(player->player.name);

    my_strcat(&str, " use ");
    my_strcat(&str, fight.name);
    if (when_no_mana_p(&fight, &player->player) == 0)
        return;
    clock = sfClock_create();
    if (monster_take(fight.name, fight.power, monster) == 1)
        next_level(&player->player, monster->level);
    draw_text_fight(&bg->life, window, str, (sfVector2f){disp_x, disp_y});
    sfRenderWindow_display(window->window);
    for (int waiter = 0; waiter != 20;)
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > clock_time)
            waiter += player_turn_bis(player, window, clock);
    player->disp.vect.x -= disp_y;
    bg->player_turn = 0;
    sfClock_destroy(clock);
    free(str);
}

static int bot_turn_bis(monster_t *monster, window_t *window, sfClock *clock)
{
    monster->disp.vect.x -= 10;
    sfClock_restart(clock);
    sfSprite_setPosition(monster->disp.sprite, monster->disp.vect);
    sfRenderWindow_drawSprite(window->window, monster->disp.sprite, NULL);
    sfRenderWindow_display(window->window);
    return (1);
}

void bot_turn(ply_t *player, window_t *window, monster_t *monster,
    fight_t *bg)
{
    skill_t fight = monster_use(monster);
    sfClock *clock = sfClock_create();
    char *str = my_strdup(monster->name);

    my_strcat(&str, " use ");
    my_strcat(&str, fight.name);
    while (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) < delay);
    sfClock_restart(clock);
    when_no_mana_m(&fight, monster);
    player_take(fight.name, fight.power, &player->player);
    draw_text_fight(&bg->life, window, str, (sfVector2f){disp_x, disp_y});
    sfRenderWindow_display(window->window);
    for (int waiter = 0; waiter != 20;)
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > clock_time)
            waiter += bot_turn_bis(monster, window, clock);
    monster->disp.vect.x += disp_y;
    bg->player_turn = 1;
    sfClock_destroy(clock);
    free(str);
}
