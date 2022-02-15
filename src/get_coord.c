/*
** EPITECH PROJECT, 2022
** get_coord.c
** File description:
** my_sokoban
*/

#include "../include/sokoban.h"

coord_t *check_p(char *buffer, char **map, coord_t *coord)
{
    int i = 0;

    check_nbr_p(buffer);
    while (buffer[i] != '\0') {
        if (buffer[i] == 'P') {
            coord = get_p(map, coord);
            return (coord);
        }
        i++;
    }
}

coord_t *get_p(char **map, coord_t *coord)
{
    int linum = 0;
    int cols = 0;

    while (map[linum][cols] != 'P') {
        if (cols == coord->col) {
            cols = 0;
            linum++;
        }
        cols++;
    }
    coord->p_line = linum;
    coord->p_col = cols;
    return (coord);
}

void check_nbr_xo(char *buffer)
{
    int x = 0;
    int o = 0;
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == 'X')
            x++;
        else if (buffer[i] == 'O')
            o++;
        i++;
    }
    if (x != o) {
        my_putstr("Invalid map: not the same number of 'X' and 'O'!\n");
        exit(84);
    }
}

void check_nbr_p(char *buffer)
{
    int p = 0;
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == 'P')
            p++;
        i++;
    }
    if (p != 1) {
        my_putstr("Invalid number of player!\n");
        exit(84);
    }
}