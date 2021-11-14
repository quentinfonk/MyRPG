/*
** EPITECH PROJECT, 2020
** get_map
** File description:
** *
*/

#include "map.h"

char *get_map(char const *filepath)
{
    char *buff = malloc(sizeof(char) * (1100 + 1));
    int opn = open(filepath, O_RDONLY);

    if (opn < 0) {
        free(buff);
        return NULL;
    }
    if (read(opn, buff, 1101) < 0)
        return NULL;
    buff[1100] = '\0';
    return buff;
}

char **set_map_to_int(char const *filepath)
{
    char *buff = get_map(filepath);
    char **map_tab = NULL;

    if (buff == NULL)
        return NULL;
    map_tab = my_str_to_word_array(buff);
    free(buff);
    return map_tab;
}

st_map **malloc_tab(void)
{
    int line = 11;
    int coll = 20;
    st_map **s_map = malloc(sizeof(st_map *) * (line + 1));

    if (s_map == NULL)
        return (NULL);
    for (int i = 0; i < line; i++)
        s_map[i] = malloc(sizeof(st_map) * (coll + 1));
    return s_map;
}

void free_all(st_map **s_map, char **map_tab)
{
    for (int i = 0; map_tab[i] != NULL; i++)
        free(map_tab[i]);
    free(map_tab);
    for (int i = 0; i < 11; i++) {
        sfTexture_destroy(s_map[i]->t_map);
        sfSprite_destroy(s_map[i]->s_map);
        sfTexture_destroy(s_map[i]->t_obj);
        sfSprite_destroy(s_map[i]->s_obj);
        free(s_map[i]);
    }
    free(s_map);
}
