/*
** EPITECH PROJECT, 2022
** move.c
** File description:
** my_sokoban
*/

#include "../include/sokoban.h"

void moove_down(char **map, coord_t *coord)
{
    char cover = map[coord->p_line + 1][coord->p_col];
    char box = map[coord->p_line + 1][coord->p_col];
    int linum = coord->p_line + 1;

    if (linum < coord->line) {
        map[coord->p_line][coord->p_col] = ' ';
        coord->p_line += 1;
        map[coord->p_line][coord->p_col] = 'P';
        if (cover == '#') {
            map[coord->p_line][coord->p_col] = '#';
            coord->p_line -= 1;
            map[coord->p_line][coord->p_col] = 'P';
        }
        else
            check_box_down(map, coord, box);
    }
}

void moove_up(char **map, coord_t *coord)
{
    char cover = map[coord->p_line - 1][coord->p_col];
    char box = map[coord->p_line - 1][coord->p_col];
    int linum = coord->p_line - 1;

    if (linum > 0) {
        map[coord->p_line][coord->p_col] = ' ';
        coord->p_line -= 1;
        map[coord->p_line][coord->p_col] = 'P';
        if (cover == '#') {
            map[coord->p_line][coord->p_col] = '#';
            coord->p_line += 1;
            map[coord->p_line][coord->p_col] = 'P';
        }
        else
            check_box_up(map, coord, box);
    }
}

void moove_left(char **map, coord_t *coord)
{
    char cover = map[coord->p_line][coord->p_col - 1];
    char box = map[coord->p_line][coord->p_col - 1];
    int cols = coord->p_col - 1;

    if (cols > 0){
        map[coord->p_line][coord->p_col] = ' ';
        coord->p_col -= 1;
        map[coord->p_line][coord->p_col] = 'P';
        if (cover == '#') {
            map[coord->p_line][coord->p_col] = '#';
            coord->p_col += 1;
            map[coord->p_line][coord->p_col] = 'P';
        }
        else
            check_box_left(map, coord, box);
    }
}

void moove_right(char **map, coord_t *coord)
{
    char cover = map[coord->p_line][coord->p_col + 1];
    char box = map[coord->p_line][coord->p_col + 1];
    int cols = coord->p_col + 1;

    if (cols < coord->col) {
        map[coord->p_line][coord->p_col] = ' ';
        coord->p_col += 1;
        map[coord->p_line][coord->p_col] = 'P';
        if (cover == '#') {
            map[coord->p_line][coord->p_col] = '#';
            coord->p_col -= 1;
            map[coord->p_line][coord->p_col] = 'P';
        }
        else
            check_box_right(map, coord, box);
    }
}

void get_mvt_player(char **map, coord_t *coord, char **initial_map)
{
    int d = getch();

    switch(d) {
    case KEY_UP:
        moove_up(map, coord);
        break;
    case KEY_RIGHT:
        moove_right(map, coord);
        break;
    case KEY_DOWN:
        moove_down(map, coord);
        break;
    case KEY_LEFT:
        moove_left(map, coord);
        break;
    case ' ':
        map = reset_map(map, initial_map, coord);
        break;
    }
    refresh();
}