/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main.c
*/
#include "my.h"

int main_loop(void);

int check_env(char **env)
{
    char *str = "DISPLAY=:0.0";

    for (int i = 0; env[i] != NULL; i++)
        for (int o = 0; str[o] == env[i][o]; o++)
            if (o == 12 || o == 9)
                return (0);
    return (84);
}

void print_h(void)
{
    my_printf("HOW TO PLAY:\n");
    my_printf("use up left, right and down to move\n");
    my_printf("use m to open the shop\n");
    my_printf("use i to open the inventory\n");
    my_printf("fight begun when you touch an enemies\n");
}

int main(int ac, char **av, char **env)
{
    (void) ac;
    (void) av;
    if (check_env(env) == 84) {
        my_printf("%e", "No env\n");
        return (84);
    }
    if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h')) {
        print_h();
        return (0);
    }
    return (main_loop());
}
