/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** window.h
*/

#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.h>
#include <SFML/Window/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/Window/Mouse.h>
#include <stdlib.h>

typedef struct s_window {
    sfRenderWindow *window;
    sfVideoMode video;
    sfEvent event;
    int line;
    int coll;
    char *inv;
    char *armor;
    int is_cinematic;
    sfTexture *texture;
    sfSprite *sprite;
} window_t;

int window(window_t *window, char *mode);
window_t create_window(void);

#endif
