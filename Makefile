##
## Makefile for  in /home/rouane_q/projets/unix/my_script/my_script_FI
## 
## Made by quentin rouanet
## Login   <rouane_q@epitech.net>
## 
## Started on  Tue Feb 18 16:01:34 2014 quentin rouanet
## Last update Tue Feb 25 12:36:11 2014 quentin rouanet
##

NAME	= my_script

SRCS	= main.c \
	  select.c \
	  error.c \
	  my_tty.c

OBJ	= $(SRCS:.c=.o)

CC	= gcc

RM	= rm -f

ECHO	= @echo -e

CFLAGS	+= -W -Wall -Wextra
CFLAGS	+= -Werror
##CFLAGS	+= -ansi -pedantic
##CFLAGS	+= -I.

##LIBMATH	= -lm
##LIBTERM	= -ltermcap -lncurses
##LIBX	= -L/usr/lib64 -lmlx -L/usr/lib64/X11 -lXext -lX11
LIBTTY	= -lutil

all	: $(NAME)

$(NAME)	: $(OBJ)
	  $(CC) -o $(NAME) $(OBJ) $(LIBTTY)
	  $(ECHO) '\033[0;32m> Compiled\033[0m'

clean	:
	  $(RM) $(OBJ)
	  $(RM) *~
	  $(RM) \#*#
	  $(ECHO) '\033[0;31m> Directory cleaned\033[0m'

fclean	: clean
	  $(RM) $(NAME)
	  $(ECHO) '\033[0;31m> Remove executable\033[0m'

re	: fclean all

.PHONY	: all clean fclean re

