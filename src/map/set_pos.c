/*
** EPITECH PROJECT, 2020
** tets
** File description:
** *
*/

#include "player.h"

static int my_strlen(char const *str)
{
    int f = 0;
    while (str[f] != '\0') {
        f++;
    }
    return (f);
}

static int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] > s2[i])
            return 1;
        if (s2[i] > s1[i])
            return -1;
        i++;
    }
    return 0;
}

static char *my_strcpy(char *dest, char const *src)
{
    int j;

    dest = malloc(sizeof(char) * my_strlen(src) + 1);
    for (j = 0; src[j] != '\0'; j++) {
        dest[j] = src[j];
    }
    dest[j] = '\0';
    return (dest);
}

void set_value(st_pos *s_pos, window_t *window, char **map_info)
{
    s_pos->l_map = window->line;
    s_pos->c_map = window->coll;
    s_pos->actual_m = my_strcpy(s_pos->actual_m, map_info[0]);
    s_pos->s_1 = 1;
    s_pos->s_2 = 1;
    s_pos->s_3 = 1;
    s_pos->s_4 = 1;
    s_pos->royal_key = 1;
    return;
}

st_pos set_pos(window_t *window)
{
    st_pos s_pos;
    char **map_info = set_map_to_info("map/pars/map_1");

    set_value(&s_pos, window, map_info);
    if (my_strcmp(map_info[2], "NULL") == 0)
        s_pos.s_1 = 0;
    if (my_strcmp(map_info[4], "NULL") == 0)
        s_pos.s_2 = 0;
    if (my_strcmp(map_info[6], "NULL") == 0)
        s_pos.s_3 = 0;
    if (my_strcmp(map_info[8], "NULL") == 0)
        s_pos.s_4 = 0;
    for (int i = 0; map_info[i] != NULL; i++)
        free(map_info[i]);
    free(map_info);
    return s_pos;
}
