##
## Makefile for  in /home/vailla_y/Projet/myirc/svn_my_irc/server
## 
## Made by yann vaillant
## Login   <vailla_y@epitech.net>
## 
## Started on  Thu Apr 19 11:59:27 2012 yann vaillant
## Last update Thu Jun 14 12:48:09 2012 randy lyvet
##

CC=gcc
NAME=serveur
SRC=$(wildcard src/*.c)
SUBDIR=$(wildcard src/*/*.c)
OBJ=$(SRC:.c=.o)
SUBOBJ=$(SUBDIR:.c=.o)
CFLAGS= -W -Wall -Wextra -g -Iinclude

all : $(NAME)

$(NAME) : $(OBJ) $(SUBOBJ)
	$(CC) -o $(NAME) $(OBJ) $(SUBDIR) -lrt

clean:
	rm -f *~
	rm -f *# 
	rm -f $(OBJ) 
	rm -f src/*~
	rm -f src/*# 
	rm -f src/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)