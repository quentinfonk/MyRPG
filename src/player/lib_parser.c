/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** lib_parser
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include "player.h"
#include "my.h"

char *read_save(char *path)
{
    FILE *yes = fopen(path, "r");
    char *line = NULL;
    char *buff = NULL;
    int fs = open(path, O_RDONLY);
    size_t len = 0;
    ssize_t rd = 0;
    ssize_t le = 0;

    for (int i = 0; (rd = getline(&line, &len, yes)) != -1; i++)
        le += rd;
    buff = malloc(le + 1);
    buff[read(fs, buff, le)] = '\0';
    close(fs);
    fclose(yes);
    free(line);
    free(path);
    return buff;
}

char *find_file(char *path, char *name)
{
    DIR *rep = opendir(path);
    struct dirent *file = NULL;

    if (rep == NULL)
        return (NULL);
    while ((file = readdir(rep)) != NULL) {
        if (file->d_name[0] != '.')
            if (my_strncmp(name, file->d_name, my_strlen(name)) == 0)
                break;
    }
    my_strcat(&path, "/");
    my_strcat(&path, file->d_name);
    closedir(rep);
    return (path);
}

void parser_str_skill(char *buffer, player_t *perso, int i)
{
    int j = 0;

    for (j = 0; buffer[0] != '"'; buffer++, j++)
        perso->arr[i].name[j] = buffer[0];
    perso->arr[i].name[j] = '\0';
}

void move_pointer(char **buffer, char const *delim)
{
    for (; (*buffer)[0]; (*buffer)++)
        for (int i = 0; delim[i]; i++)
            if ((*buffer)[0] == delim[i]) {
                (*buffer)++;
                return;
            }
}

char *print_stat(player_t player)
{
    char *str = NULL;

    str = my_strdup(player.name);
    my_strcat(&str, "\nlevel: ");
    my_strcat(&str, my_itoa(player.level));
    my_strcat(&str, "\nexperience: ");
    my_strcat(&str, my_itoa(player.actual_level));
    my_strcat(&str, "\nmoney: ");
    my_strcat(&str, my_itoa(player.money));
    my_strcat(&str, "\nhealth: ");
    my_strcat(&str, my_itoa(player.health));
    my_strcat(&str, "\nmana: ");
    my_strcat(&str, my_itoa(player.mana));
    my_strcat(&str, "\nattack: ");
    my_strcat(&str, my_itoa(player.attack));
    my_strcat(&str, "\ndefense: ");
    my_strcat(&str, my_itoa(player.defense));
    return (str);
}
