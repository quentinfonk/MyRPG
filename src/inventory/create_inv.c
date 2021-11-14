/*
** EPITECH PROJECT, 2020
** create
** File description:
** inv
*/

#include "inventory.h"

void crea(int i, char *str, inv_t *inv)
{
    inv->te_inv[i] = sfTexture_createFromFile(str, NULL);
    inv->sp_inv[i] = sfSprite_create();
    sfSprite_setTexture(inv->sp_inv[i], inv->te_inv[i], sfTrue);
}

void create_inv(inv_t *inv)
{
    sfVector2f pos_inv = {450, 150};
    char *stack = "src/inventory/load/inv_a.png";
    char *str = malloc(sizeof(char) * (my_strlen(stack)));

    for (int i = 0; stack[i] != '\0'; i++)
        str[i] = stack[i];
    inv->te_inv = malloc(sizeof(sfTexture *) * 11);
    inv->sp_inv = malloc(sizeof(sfSprite *) * 11);
    inv->te_inv[0] = sfTexture_createFromFile
    ("src/inventory/load/inventory.png", NULL);
    inv->sp_inv[0] = sfSprite_create();
    sfSprite_setTexture(inv->sp_inv[0], inv->te_inv[0], sfTrue);
    sfSprite_setPosition(inv->sp_inv[0], pos_inv);
    for (int i = 1; i != 11; i++) {
        crea(i, str, inv);
        str[23] = str[23] + 1;
    }
}
