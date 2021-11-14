/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** dialog.h
*/

#ifndef MUL_MY_RPG_2019_DIALOG_H
#define MUL_MY_RPG_2019_DIALOG_H

typedef struct cell_s {
    int chpt;
    int dia;
    char *data;
} cell_t;

typedef struct hash_s {
    cell_t *cells;
    int size;
} hash_t;

hash_t *create_hash(void);
void hash_add(hash_t *p_table, int chpt, int key, char *data);

void malloc_fail(void);
void *malloc_fail_null(void);
cell_t *my_realloc_struct(cell_t *cells, int size);
void print_hash_table(hash_t tab);
void free_dialogs(hash_t *arr);

#endif //MUL_MY_RPG_2019_DIALOG_H
