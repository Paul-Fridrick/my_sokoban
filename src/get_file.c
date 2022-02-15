/*
** EPITECH PROJECT, 2022
** get_file.c
** File description:
** my_sokoban
*/

#include "../include/sokoban.h"

int open_file(char const *filepath)
{
    int fd = 0;
    char *str = "Failure open or invalid arguments\n";

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        write(2, str , my_strlen(str));
        return (84);
    }
    return (fd);
}

char *print_file (char const *filepath, char *buffer)
{
    int fd = open_file(filepath);
    struct stat sb;

    if (stat(filepath, &sb) == -1)
        return (84);
    else {
        buffer = malloc(sizeof(char) * (sb.st_size + 2));
        if (buffer == NULL)
            return (84);
        if (sb.st_size == 0)
            return (84);
        read(fd, buffer, sb.st_size);
    }
    buffer[sb.st_size] = '\0';
    return (buffer);
}

int get_linum(char *buffer)
{
    int i = 0;
    int line = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            line++;
        i++;
    }
    line++;
    return (line);
}

int get_col(char *buffer)
{
    int i = 0;
    int col = 0;
    int j = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            (j > col) ? col = j : 0;
            j = -1;
        }
        j++;
        i++;
    }
    return (col);
}

char **get_tab(char *buffer, char **tab, coord_t *coord)
{
    int line = 0;
    int col = 0;
    int cpt = 0;

    tab = malloc (sizeof(char *) * (coord->line * (coord->col + 2)));
    for (int j = 0; j < coord->line + 1; j++) {
        tab[j] = malloc(sizeof(char) * (coord->col + 2));
        tab[j][coord->col] = '\0';
    }
    while (buffer[cpt] != '\0') {
        if (buffer[cpt] == '\n') {
            col = 0;
            line++;
            cpt++;
        }
        tab[line][col] = buffer[cpt];
        col++;
        cpt++;
    }
    return (tab);
}