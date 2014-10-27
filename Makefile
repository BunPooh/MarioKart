##
## Makefile for MarioKart in /home/de-buy_i/rendu/ReRush1
## 
## Made by Ismael De Buyst
## Login   <de-buy_i@epitech.net>
## 
## Started on  Sun Oct 26 09:46:02 2014 Ismael De Buyst
## Last update Sun Oct 26 16:52:43 2014 Ismael De Buyst
##

SRC		= sources/main.c \
		  sources/random.c \
		  sources/start.c \
		  sources/my_nbr_func.c \
		  sources/my_printf.c \
		  sources/my_str_func.c \
		  sources/happy_wheel.c

OBJ		= $(SRC:.c=.o)

BIN		= bin/

NAME		= MarioKart

ICL		= includes/rush.h

CC		= gcc -W -Wall

RM		= rm

$(BIN)$(NAME)	:$(OBJ)
		mkdir -p $(BIN)
		$(CC) $(OBJ) -o $(BIN)$(NAME) -lncurses

all:		$(BIN)$(NAME)

clean:
		$(RM) -f $(OBJ)

fclean:		clean
		$(RM) -rf $(BIN)

re:		fclean all
