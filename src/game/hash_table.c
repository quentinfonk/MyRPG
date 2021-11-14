/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** hash_table.c
*/
#include "dialog.h"
#include "my.h"

hash_t *create_hash(void)
{
    hash_t *hash_table = NULL;

    hash_table = malloc(sizeof(*hash_table));
    if (hash_table == NULL)
        return (malloc_fail_null());
    hash_table->cells = NULL;
    hash_table->size = 0;
    return (hash_table);
}

void hash_add(hash_t *p_table, int chpt, int dia, char *data)
{
    cell_t *cells = NULL;

    if (p_table == NULL && data == NULL)
        return;
    p_table->size++;
    p_table->cells = my_realloc_struct(p_table->cells, p_table->size);
    if (p_table->cells == NULL)
        return (malloc_fail());
    cells = &p_table->cells[p_table->size - 1];
    cells->dia = dia;
    cells->chpt = chpt;
    cells->data = my_strdup(data);
}

void print_hash_table(hash_t tab)
{
    for (int i = 0; i != tab.size; i++) {
        my_printf("\n\t\t\tcell n%d\n", i);
        my_printf("chapter:\t%d\n", tab.cells[i].chpt);
        my_printf("dialog:\t%d\n", tab.cells[i].dia);
        my_printf("data:\t%s\n", tab.cells[i].data);
    }
}
