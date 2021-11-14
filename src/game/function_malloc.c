/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** function_malloc.c
*/
#include "dialog.h"
#include "my.h"

void malloc_fail(void)
{
    my_printf("%e", "Malloc failed\n");
}

void *malloc_fail_null(void)
{
    my_printf("%e", "Malloc failed\n");
    return (NULL);
}

void free_dialogs(hash_t *arr)
{
    for (int i = 0; i != arr->size; i++)
        free(arr->cells[i].data);
    free(arr->cells);
    free(arr);
}

cell_t *my_realloc_struct(cell_t *cells, int size)
{
    cell_t *new_cells = malloc(sizeof(cell_t) * size);

    for (int i = 0; i != size-1; i++) {
        new_cells[i].data = my_strdup(cells[i].data);
        new_cells[i].dia = cells[i].dia;
        new_cells[i].chpt = cells[i].chpt;
        free(cells[i].data);
    }
    free(cells);
    return (new_cells);
}