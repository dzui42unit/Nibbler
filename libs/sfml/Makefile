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

CC = clang++ -std=c++14 -Wall -Wextra -Werror

LIBS = -I ../../InterfaceLibrary -I.
LIBS += -I SFML -L lib/  -lsfml-window -lsfml-graphics -Wl,-rpath, ~/.brew/Cellar/sfml/2.4.2_1/lib/
LISD += -framework OpenGL -framework AppKit

SRC = SfmlWrapper.cpp

# OBJ = $(SRC:.cpp=.o)

all: lib.so 

lib.so:
	$(CC) -dynamiclib -flat_namespace  $(SRC) $(LIBS) -o $(NAME)


#-Wl,rpath, ~/.brew/Cellar/sfml/2.4.2_1/lib/

# %.o: %.cpp
# 	$(CC) $(CFLAGS) $(LIBS) -c  -o $@ $< 


clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
