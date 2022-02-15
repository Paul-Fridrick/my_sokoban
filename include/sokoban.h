/*
** EPITECH PROJECT, 2022
** sokoban.h
** File description:
** my_sokoban
*/

#ifndef sokoban
    #define sokoban
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <time.h>
    #include "../include/my.h"
    #include <stdbool.h>
    #include <ncurses.h>

typedef struct coord_s
{
    int line;
    int col;
    int p_line;
    int p_col;
}coord_t;


//check_win
coord_t *check_p(char *buffer, char **map, coord_t *coord);
coord_t *get_p(char **map, coord_t *coord);
void check_nbr_xo(char *buffer);
void check_nbr_p(char *buffer);
int number_of_o(char *buffer);
void win_condition(char **map, char **init_map, char *buffer, coord_t *coord);


//check_file
int open_file(char const *filepath);
char *print_file (char const *filepath, char *buffer);
int get_linum(char *buffer);
int get_col(char *buffer);
char **get_tab(char *buffer, char **tab, coord_t *coord);

//move
void moove_down(char **map, coord_t *coord);
void moove_up(char **map, coord_t *coord);
void moove_left(char **map, coord_t *coord);
void moove_right(char **map, coord_t *coord);
void get_mvt_player(char **map, coord_t *coord, char **initial_map);
void check_box_up(char **map, coord_t *coord, char box);
void check_box_down(char **map, coord_t *coord, char box);
void check_box_right(char **map, coord_t *coord, char box);
void check_box_left(char **map, coord_t *coord, char box);


//bases
static void help (void);
void print_tab(char **tab, coord_t *coord);
void my_sokoban(char **map, char *buffer, coord_t *coord);
int main (int argc, char **argv);
#endif
