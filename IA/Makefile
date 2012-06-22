##
## Makefile for the mini-Shell in /home/haulot_a//SystemeUnix/mysh/minishell1-2015-haulot_a
## 
## Made by alexandre haulotte
## Login   <haulot_a@epitech.net>
## 
## Started on  Thu Nov 10 09:53:25 2011 alexandre haulotte
## Last update Fri Jun 22 13:51:18 2012 alexandre haulotte
##

NAME= 		lola

SRC_DIR=	src

SRC=    	$(wildcard $(SRC_DIR)/*.cpp)

CFLAGS =	-I./include/

LDFLAGS =	-W -Wall -Wextra -std=c++0x

RM =	rm -f

OBJ =	$(SRC:.c=.o)

#all:	$(NAME)

$(NAME):	$(OBJ)
	@g++ $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

re:	fclean $(NAME) clean

clean:
	@$(RM) include/*~
	@$(RM) src/*~
	@$(RM) src/*.o

fclean:
	@$(RM) $(NAME)
	@$(RM) src/*.o
