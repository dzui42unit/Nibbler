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

NAME = libglfw3wrapper.so

CC = clang++ -std=c++14

# -Wall -Wextra -Werror

LIBS = -I ../../InterfaceLibrary
LIBS += -I GLFW/ -L lib/
LIBS += -lglfw -framework OpenGL -framework AppKit

SRC = Glfw3Wrapper.cpp

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
