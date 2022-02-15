/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** sokoban
*/

#include "../include/sokoban.h"

static void help (void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tmap file representing the warehouse map, ");
    my_putstr("contaiging '#' for walls,\n");
    my_putstr("\t 'P' for the player, 'X' for boxes ");
    my_putstr("and '0' for storage locations.\n");
}

void print_tab(char **tab, coord_t *coord)
{
    int line = 0;

    clear();
    while (line != coord->line) {
        printw("%s\n", tab[line]);
        line++;
    }
}

char **reset_map(char **map, char **initial_map, coord_t *coord)
{
    int linum = 0;
    int cols = 0;

    while (linum != coord->line) {
        if (cols == coord->col) {
            cols = 0;
            linum++;
        }
        map[linum][cols] = initial_map[linum][cols];
        cols++;
    }
    coord = get_p(map, coord);
    return (map);
}


void my_sokoban(char **map, char *buffer, coord_t *coord)
{
    char **init_map = get_tab(buffer, init_map, coord);
    int nb = 0;

    check_nbr_xo(buffer);
    coord = check_p(buffer, map, coord);
    initscr();
    keypad(stdscr, true);
    while (1) {
        print_tab(map, coord);
        get_mvt_player(map, coord, init_map);
        win_condition(map, init_map, buffer, coord);
    }
}

int main (int argc, char **argv)
{
    char *buffer = NULL;
    char **map = NULL;
    coord_t *coord = NULL;

    coord = malloc(sizeof(coord_t));
    if (argc != 2)
        return (84);
    else {
        if (my_strcmp(argv[1], "-h") == 0)
            help();
        else {
            buffer = print_file(argv[1], buffer);
            coord->line = get_linum(buffer);
            coord->col = get_col(buffer);
            map = get_tab(buffer, map, coord);
            my_sokoban(map, buffer, coord);
        }
        return (0);
    }
}
