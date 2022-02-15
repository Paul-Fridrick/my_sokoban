##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## My_hunter
##

SRC = 	$(wildcard src/*c)

NAME = my_sokoban

OBJ = $(SRC:.c=.o)

FLAGS = -W -Wall -Wextra -lm -lncurses -L ./lib/my/ -lmy -g

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	cd lib/my && make re
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) 
	$(RM) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) a.out
	$(RM) *.o

re: fclean all
