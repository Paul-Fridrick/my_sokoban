/*
** EPITECH PROJECT, 2022
** move_box.c
** File description:
** my_sokoban
*/

#include "../include/sokoban.h"

void check_box_up(char **map, coord_t *coord, char box)
{
    char cover = map[coord->p_line - 1][coord->p_col];

    if (box == 'X') {
        map[coord->p_line][coord->p_col] = ' ';
        map[coord->p_line][coord->p_col] = 'P';
        map[coord->p_line - 1][coord->p_col] = 'X';
    }
    if (cover == '#' && box == 'X') {
        map[coord->p_line - 1][coord->p_col] = '#';
        map[coord->p_line][coord->p_col] = 'X';
        coord->p_line += 1;
        map[coord->p_line][coord->p_col] = 'P';
    }
    if (cover == 'X' && box == 'X') {
        map[coord->p_line - 1][coord->p_col] = 'X';
        map[coord->p_line][coord->p_col] = 'X';
        coord->p_line += 1;
        map[coord->p_line][coord->p_col] = 'P';
    }
}

void check_box_down(char **map, coord_t *coord, char box)
{
    char cover = map[coord->p_line + 1][coord->p_col];

    if (box == 'X') {
        map[coord->p_line][coord->p_col] = ' ';
        map[coord->p_line][coord->p_col] = 'P';
        map[coord->p_line + 1][coord->p_col] = 'X';
    }
    if (cover == '#' && box == 'X') {
        map[coord->p_line + 1][coord->p_col] = '#';
        map[coord->p_line][coord->p_col] = 'X';
        coord->p_line -= 1;
        map[coord->p_line][coord->p_col] = 'P';
    }
    if (cover == 'X' && box == 'X') {
        map[coord->p_line + 1][coord->p_col] = 'X';
        map[coord->p_line][coord->p_col] = 'X';
        coord->p_line -= 1;
        map[coord->p_line][coord->p_col] = 'P';
    }
}

void check_box_right(char **map, coord_t *coord, char box)
{
    char cover = map[coord->p_line][coord->p_col + 1];

    if (box == 'X') {
        map[coord->p_line][coord->p_col] = ' ';
        map[coord->p_line][coord->p_col] = 'P';
        map[coord->p_line][coord->p_col + 1] = 'X';
    }
    if (cover == '#' && box == 'X') {
        map[coord->p_line][coord->p_col + 1] = '#';
        map[coord->p_line][coord->p_col] = 'X';
        coord->p_col -= 1;
        map[coord->p_line][coord->p_col] = 'P';
    }
    if (cover == 'X' && box == 'X') {
        map[coord->p_line][coord->p_col + 1] = 'X';
        map[coord->p_line][coord->p_col] = 'X';
        coord->p_col -= 1;
        map[coord->p_line][coord->p_col] = 'P';
    }
}

void check_box_left(char **map, coord_t *coord, char box)
{
    char cover = map[coord->p_line][coord->p_col - 1];

    if (box == 'X') {
        map[coord->p_line][coord->p_col] = ' ';
        map[coord->p_line][coord->p_col] = 'P';
        map[coord->p_line][coord->p_col - 1] = 'X';
    }
    if (cover == '#' && box == 'X') {
        map[coord->p_line][coord->p_col - 1] = '#';
        map[coord->p_line][coord->p_col] = 'X';
        coord->p_col += 1;
        map[coord->p_line][coord->p_col] = 'P';
    }
    if (cover == 'X' && box == 'X') {
        map[coord->p_line][coord->p_col - 1] = 'X';
        map[coord->p_line][coord->p_col] = 'X';
        coord->p_col += 1;
        map[coord->p_line][coord->p_col] = 'P';
    }
}