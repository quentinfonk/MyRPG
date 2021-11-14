/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** monster
*/

#include "player.h"

typedef struct s_disp_monster
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f vect;
} disp_monster_t;

typedef struct monster_s {
    char name[13];
    int level;
    int health;
    int mana;
    int attack;
    int defense;
    skill_t arr[4];
    disp_monster_t disp;
} monster_t;

// proto
monster_t create_monster(char *name, char *name_png);
char *find_file(char *path, char *name);
void move_pointer(char **buffer, char const *delim);
void parser_str_skill_monster(char *buffer, monster_t *perso, int i);
disp_monster_t load_monster(char *path);

void print_info_monster(monster_t monster);
skill_t monster_use(monster_t *monster);
int monster_take(char *name, int nbr, monster_t *monster);
