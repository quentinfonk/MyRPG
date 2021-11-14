/*
** EPITECH PROJECT, 2019
** function.c
** File description:
** local lib
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

void my_swap(char *a, char *b)
{
    char a3 = *a;

    *a = *b;
    *b = a3;
}

int change(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char *my_revstr(char *str)
{
    int decount = 0;
    int count = change(str) - 1;
    while (count >= decount) {
        my_swap(&str[count], &str[decount]);
        decount++;
        count--;
    }
    return (str);
}
