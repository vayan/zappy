INC_DIR	=	include/
LIB_DIR	=	libs/
LIBS	=	m X11
SFML_LIB=	-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
LFLAGS	=	$(addprefix -l, $(LIBS)) $(addprefix -L, $(LIB_DIR)) \
		$(patsubst lib%.a, -l%, $(notdir $(wildcard $(LIB_DIR)*.a)))
IFLAGS	=	$(addprefix -I, $(INC_DIR))


all:
	clang++ src/*.cpp -W -Wall -Wextra -I./include/ $(SFML_LIB) $(LFLAGS) $(IFLAGS) -o b.out