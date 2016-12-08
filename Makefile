##
## Makefile for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint
##
## Made by Jamy Bailly
## Login   <bailly_j@epitech.net>
##
## Started on  Thu Jan 14 22:54:21 2016 Jamy Bailly
## Last update Sat Jan 30 19:01:40 2016 David Zeng
##

SRCS	= main.c \
	  src/tekpixel.c \
	  src/tekline.c \
	  src/set_background.c \
	  src/create_window.c \
	  src/set_color.c \
	  src/toolbar.c \
	  src/paintbar.c \
	  src/load_cat_buttons_paintbar.c \
	  src/img.c \
	  src/load_button.c \
	  src/bool/bool.c \
	  src/bool/brush.c \
	  src/destroy.c \
	  src/create_event_mouse.c \
	  src/event/init_event_paintbar.c \
	  src/event/init_event_toolbar.c \
	  src/mouse.c \
	  src/event/event_boot.c \
	  src/event/event_newfile.c \
	  src/event/event_folder.c \
	  src/event/event_save.c \
	  src/event/event_exit.c \
	  src/event/event_trans.c \
	  src/event/event_img.c \
	  src/tools/tekblackwhite.c \
	  src/tools/tekbucket.c \
	  src/tools/tekreverse.c \
	  src/tools/tekpinceaux.c \
	  src/file/get_nbr.c \
	  src/file/load.c \
	  src/file/my_load_bmp.c \
	  src/file/read.c \
	  src/file/safe.c \
	  src/file/save_bmp.c \
	  src/my_blit_pixel.c \
	  src/get_next_line.c

SRCS_MY	= src/libmy/my_putchar.c \
	  src/libmy/my_putcharerr.c \
	  src/libmy/my_putstr.c \
	  src/libmy/my_puterr.c \
	  src/libmy/my_putnbr_rec.c \

LIBS	= -L/home/${USER}/.froot/lib/ \
	  -llapin \
	  -lsfml-audio \
	  -lsfml-graphics \
	  -lsfml-window \
	  -lsfml-system \
	  -lstdc++ \
	  -ldl \
	  -lm \

NAME	= tekpaint

CC	= gcc

CFLAGS	+= -g -W -Wall -Werror -ansi -pedantic

CFLAGS	+= -I./include/ -I/home/${USER}/.froot/include/

RM	= rm -f

OBJS	= $(SRCS:.c=.o)

OBJS_MY	= $(SRCS_MY:.c=.o)

all:	 $(NAME)

$(NAME): $(OBJS) $(OBJS_MY)
	$(CC) $(OBJS) $(OBJS_MY) $(LIBS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_MY)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

yo: all clean

.PHONY:	all clean fclean re
