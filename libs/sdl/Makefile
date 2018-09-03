# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/22 21:10:53 by sprotsen          #+#    #+#              #
#    Updated: 2018/09/02 18:14:45 by dzui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libsdl2wrapper.so

CC = clang++ -std=c++14

# -Wall -Wextra -Werror

LIBS = -I ../../InterfaceLibrary
LIBS += -I sdl2/SDL2 -L sdl2/lib -l SDL2
LIBS += -I sdl2_image/SDL2 -L sdl2_image/lib -l SDL2_image 
LIBS += -I sdl2_mixer/SDL2 -L sdl2_mixer/lib -l SDL2_mixer 
LIBS += -I sdl2_ttf/SDL2 -L sdl2_ttf/lib -l SDL2_ttf
LISD += -framework OpenGL -framework AppKit

SRC = SdlLibraryWrap.cpp

# OBJ = $(SRC:.cpp=.o)

all: lib.so

lib.so:
	$(CC) -dynamiclib -flat_namespace $(SRC) $(LIBS) -o $(NAME)

# %.o: %.cpp
# 	$(CC) $(CFLAGS) $(LIBS) -c  -o $@ $< 

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
