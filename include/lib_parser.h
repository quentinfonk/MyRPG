/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** lib_parser
*/

#ifndef LIB_PARSER_H_
#define LIB_PARSER_H_

#include <stdio.h>
#include "player.h"

char *read_save(char *path);
char *parser_str(char *buffer, player_t *perso);
void parser_str_skill(char *buffer, player_t *perso, int i);
void parser_str_object(char *buffer, player_t *perso, int i);

#endif /* !LIB_PARSER_H_ */
