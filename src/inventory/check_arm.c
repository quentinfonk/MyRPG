/*
** EPITECH PROJECT, 2020
** check_arm
** File description:
** check_arm
*/

#include "inventory.h"

void check_arm2(ply_t *player, int choice)
{
    if (choice == 55)
        player->player.attack += 10;
    if (choice == 56) {
        player->player.level += 1;
        modif_stat_player(&player->player);
    }
    if (choice == 57)
        player->player.mana += 200;
    if (player->player.mana > 400)
        player->player.mana = 400;
    if (player->player.health > 500)
        player->player.health = 500;
}

void check_arm(ply_t *player, int choice)
{
    if (choice == 49)
        player->player.defense += 10;
    if (choice == 50)
        player->player.attack += 10;
    if (choice == 51) {
        player->player.attack += 10;
        player->player.defense += 10;
    }
    if (choice == 52)
        player->player.health += 100;
    if (choice == 53)
        player->player.health += 250;
    if (choice == 54)
        player->player.health += 500;
    check_arm2(player, choice);
}

int el_arm2(window_t *window, int choice, ply_t *player)
{
    if (choice == -11)
        if (check_place(window) == 0) {
            add_in(window, 2);
            change_pla(window->armor[2], player);
            window->armor[2] = '0';
        }
    if (choice == -10)
        if (check_place(window) == 0) {
            add_in(window, 3);
            change_pla(window->armor[3], player);
            window->armor[3] = '0';
        }
    return (-1);
}

int el_arm(window_t *window, int choice, ply_t *player)
{
    if (choice >= -1)
        return (choice);
    if (choice == -13)
        if (check_place(window) == 0) {
            add_in(window, 0);
            change_pla(window->armor[0], player);
            window->armor[0] = '0';
        }
    if (choice == -12)
        if (check_place(window) == 0) {
            add_in(window, 1);
            change_pla(window->armor[1], player);
            window->armor[1] = '0';
        }
    return (el_arm2(window, choice, player));
}
