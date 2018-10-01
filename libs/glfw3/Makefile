# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/22 21:10:53 by sprotsen          #+#    #+#              #
#    Updated: 2018/09/12 20:10:07 by dzui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libglfw3wrapper.so

CC = clang++ -g -std=c++14 -Wall -Wextra -Werror

LIBS = -I ../../InterfaceLibrary
LIBS += -I ~/.brew/include/freetype2
LIBS += -I ~/.brew/include -L ~/.brew/lib -lglfw
LIBS += -lftgl
#LIBS += -framework OpenGL -framework AppKit


SRC = Glfw3Wrapper.cpp

# OBJ = $(SRC:.cpp=.o)

all: lib.so

lib.so:
	$(CC) -dynamiclib -flat_namespace $(SRC) $(LIBS) -o $(NAME)

# %.o: %.cpp
# 	$(CC) $(CFLAGS) $(LIBS) -c  -o $@ $< 

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re: fclean all
