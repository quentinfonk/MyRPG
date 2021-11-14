/*
** EPITECH PROJECT, 2020
** test
** File description:
** *
*/

#include "map.h"

char *get_info(char const *filepath)
{
    char *buff = malloc(sizeof(char) * (33 + 1));
    int opn = 0;

    if ((opn = open(filepath, O_RDONLY)) < 0) {
        free(buff);
        return NULL;
    }
    if (read(opn, buff, 34) < 0)
        return NULL;
    buff[33] = '\0';
    return buff;
}

char **set_map_to_info(char const *filepath)
{
    char *buff = get_info(filepath);
    char **map_tab = NULL;

    if (buff == NULL)
        return NULL;
    map_tab = my_str_to_word_array(buff);
    free(buff);
    return map_tab;
}
