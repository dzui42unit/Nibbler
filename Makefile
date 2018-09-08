# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/01 09:29:35 by sprotsen          #+#    #+#              #
#    Updated: 2018/09/05 20:40:18 by dzui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Nibbler

SRC = main.cpp \
	Game/Game.cpp \
	Snake/Snake.cpp \
	Fruit/Fruit.cpp

OBJ = $(SRC:.cpp=.o)

CFLAGS = -std=c++14 -Wall -Wextra -Werror
		 

CC = clang++

all: lib $(NAME)

lib:
	make re -C libs/sdl
	make re -C libs/SoundWrapper
	make re -C libs/glfw3

$(NAME): $(OBJ)
	clang++ -o $(NAME) $(OBJ) 

%.o: %.cpp
	$(CC) $(CFLAGS) -c  -o $@ $< 

clean:
	rm -f $(OBJ)
	make clean -C libs/sdl
	make clean -C libs/SoundWrapper
	make clean -C libs/glfw3

fclean:	clean
	rm -f $(NAME)
	make fclean -C libs/sdl
	make fclean -C libs/SoundWrapper
	make fclean -C libs/glfw3

re: fclean all
