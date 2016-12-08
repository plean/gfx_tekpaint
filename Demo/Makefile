##
## Makefile for Makefile in /home/zeng_d/test/10/test
##
## Made by David Zeng
## Login   <zeng_d@epitech.net>
##
## Started on  Mon Oct 12 13:31:18 2015 David Zeng
## Last update Wed Jan 27 08:49:16 2016 David Zeng
##

SRC	= main.c \
	  load.c \
	  read.c \
	  save_bmp.c \
	  get_nbr.c \
	  my_load_bmp.c \
	  safe.c \

NAME	= bmp

CC	= gcc

OBJ	= $(SRC:.c=.o)

CFLAGS	=  -W -Werror -Wall \
	   -L /home/${USER}/.froot/include -llapin \
	   -L /home/${USER}/.froot/lib -lsfml-audio -lsfml-graphics \
	   -lsfml-window -lsfml-system -lstdc++ -ldl -lm

all: 	  $(NAME)

$(NAME):  $(OBJ)
	  @$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	  @rm -f $(OBJ)

fclean:	  clean
	  @rm -f $(NAME)

re:	  fclean all

.PHONY:	  all clean fclean re

yo:	  all clean

.c.o:
	  @gcc -c $< -o $@ $(CFLAGS)
