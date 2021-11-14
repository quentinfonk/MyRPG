/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** dialog.c
*/

#include "lib_parser.h"
#include "monster.h"
#include "my.h"

static void fill_tables(hash_t *tables, char *buff)
{
    bool verif = false;
    int max = my_getnbr(buff);
    int end = 0;

    move_pointer(&buff, "\n");
    for (int i = 0, id = 1, chpt = 1; end != max; end++, id++, buff += i + 4) {
        for (i = 0; buff[i] != '\0'
            && (buff[i] != '#' && buff[i + 1] != '#'); i++)
            if ((buff[i] != '\0' && buff[i + 1] != '\0')
                && (buff[i + 2] == '#' && buff[i + 3] == '\\'))
                verif = true;
        buff[i] = '\0';
        hash_add(tables, chpt, id, buff);
        if (verif == true) {
            chpt++;
            id = 0;
            verif = false;
        }
    }
}

hash_t *create_dialogs(char *name)
{
    hash_t *arr_text = create_hash();
    char *path = my_strdup("./files/dialogs");
    char *text = NULL;

    path = find_file(path, name);
    text = read_save(path);
    fill_tables(arr_text, text);
    free(text);
    return (arr_text);
}
