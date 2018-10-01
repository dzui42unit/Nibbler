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

NAME = libsfmlwrapper.so

CC = clang++ -g -std=c++14 -Wall -Wextra -Werror

LIBS = -I ../../InterfaceLibrary
LIBS += -I ~/.brew/include -L ~/.brew/lib
LIBS += -lsfml-system
LIBS += -lsfml-window
LIBS += -lsfml-graphics
LIBS += -Wl,-rpath, ~/.brew/lib
#LIBS += -framework OpenGL -framework AppKit

SRC = SfmlWrapper.cpp

# OBJ = $(SRC:.cpp=.o)

all: lib.so 

lib.so:
	$(CC) -dynamiclib -flat_namespace  $(SRC) $(LIBS) -o $(NAME)


# %.o: %.cpp
# 	$(CC) $(CFLAGS) $(LIBS) -c  -o $@ $< 


clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re: fclean all
