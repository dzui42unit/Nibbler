# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/22 21:10:53 by sprotsen          #+#    #+#              #
#    Updated: 2018/08/22 21:10:54 by sprotsen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libsdl2wrapper.so

CC = clang++ -std=c++14

CFLAGS = -fPIC 
#-Wall -Wextra -Werror

LIBS = -I ../../InterfaceLibrary 

LIBS += -I SDL2 -L lib -l SDL2-2.0.0 -framework OpenGL -framework AppKit


SRC = SdlLibraryWrap.cpp

OBJ = $(SRC:.cpp=.o)

all: $(OBJ) lib.so

lib.so:
	$(CC) -shared $(OBJ) $(LIBS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(LIBS) -c  -o $@ $< 

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
