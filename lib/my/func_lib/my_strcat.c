/*
** EPITECH PROJECT, 2019
** my lib 2019
** File description:
** my strkat
*/
#include "my.h"

char *my_strcat_alloc(char *dest, char const *src)
{
    char *str = NULL;
    int i = my_strlen(dest);
    int j = my_strlen(src);

    str = malloc(sizeof(char) * (i + j + 1));
    if (str == NULL)
        return (NULL);
    for (i = 0; dest[i]; i++)
        str[i] = dest[i];
    for (j = 0; src[j]; j++)
        str[i] = src[j];
    str[i + j] = '\0';
    return (dest);
}

void my_strcat(char **dest, char const *src)
{
    int len = 0;
    int i = 0;
    int len2 = 0;

    if (src == NULL)
        return;
    else if ((*dest) == NULL) {
        (*dest) = malloc(sizeof(char) * (my_strlen(src) + 1));
        for (i = 0; src[i]; i++)
            (*dest)[i] = src[i];
        (*dest)[i] = '\0';
    }
    else {
        len = my_strlen(*dest);
        len2 = my_strlen(src);
        (*dest) = my_realloc((*dest), len + len2);
        for (int j = 0; src[j]; len++, j++)
            (*dest)[len] = src[j];
        (*dest)[len] = '\0';
    }
}
