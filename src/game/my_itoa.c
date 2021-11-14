/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_itoa.c
*/

#include "my.h"

char *my_itoa_static(char str[13], int nbr)
{
    int q = 0;

    if (nbr == 0) {
        str[0] = '0';
        str[1] = 0;
        return (str);
    }
    while (nbr != 0) {
        str[q] = nbr % 10 + '0';
        nbr /= 10;
        q++;
    }
    str[q] = '\0';
    my_revstr(str);
    return (str);
}
