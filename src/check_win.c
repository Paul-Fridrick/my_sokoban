/*
** EPITECH PROJECT, 2022
** check_win.c
** File description:
** my_sokoban
*/

#include "../include/sokoban.h"

int number_of_o(char *buffer)
{
    int o = 0;
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == 'O')
            o++;
        i++;
    }
    return (o);
}

void win_condition(char **map, char **init_map, char *buffer, coord_t *coord)
{
    int nb_o = number_of_o(buffer);
    int x = 0;
    int y = 0;

    while (y != coord->line) {
        if (x == coord->col) {
            x = 0;
            y++;
        }
        if (init_map[y][x] == 'O' && map[y][x] == 'X')
            nb_o--;
        else if (init_map[y][x] == 'O' && map[y][x] == ' ')
            map[y][x] = 'O';
        x++;
    }
    if (nb_o == 0) {
        endwin();
        my_putstr("You win!\n");
        exit(0);
    }
}