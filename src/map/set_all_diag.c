/*
** EPITECH PROJECT, 2020
** test
** File description:
** set_all_diag.c
*/
#include "my.h"
#include "player.h"

void get_hist_1_biss(char **str, int i, st_pnj *s_pnj, int seconde)
{
    hash_t *dia = create_dialogs("king");
    int a = 0;

    if (i == 0 && s_pnj->boss_2 == true) {
        srand(seconde);
        a = (rand() % (5 + 1 - 3)) + 3;
        *str = dia->cells[a].data;
    }
}

void get_str_hist_1(char **str, int i, st_pnj *s_pnj)
{
    sfTime time = sfClock_getElapsedTime(s_pnj->clock_rand);
    float seconde = sfTime_asMicroseconds(time);
    hash_t *dia = create_dialogs("king");
    int a = 0;

    if (i == 0 && s_pnj->boss_2 == false) {
        srand(seconde);
        a = rand() % 3;
        *str = dia->cells[a].data;
    }
    get_hist_1_biss(str, i, s_pnj, seconde);
}

void get_hist_2_biss(char **str, int i, st_pnj *s_pnj, int seconde)
{
    int a = 0;
    hash_t *dia = create_dialogs("guard");

    if (i == 0 && s_pnj->boss_2 == true) {
        srand(seconde);
        a = (rand() % (4 + 1 - 3)) + 3;
        *str = dia->cells[a].data;
    }
}

void get_str_hist_2(char **str, int i, st_pnj *s_pnj)
{
    hash_t *dia = create_dialogs("guard");
    sfTime time = sfClock_getElapsedTime(s_pnj->clock_rand);
    float seconde = sfTime_asMicroseconds(time);
    int a = 0;

    srand(seconde);
    if (i == 0 && s_pnj->boss_2 == false) {
        a = rand() % 3;
        *str = dia->cells[a].data;
    }
    get_hist_2_biss(str, i, s_pnj, seconde);
}
