/*
** EPITECH PROJECT, 2022
** check_error.c
** File description:
** my_sokoban
*/

#include "../include/sokoban.h"

void check_error(char *buffer)
{
    int i = 0;

    while (buffer[i] == '\n' || buffer[i] == ' ' || buffer[i] == 'P'
           || buffer[i] == 'X' || buffer[i] == '#' || buffer[i] == 'O') {
        i++;
    }
    if (i != my_strlen(buffer)) {
        my_putstr("A valid map can only contains the characters ");
        my_putstr("SPACE, '\\n', '#', 'X', 'O' and 'P'\n");
        exit(84);
    }
}