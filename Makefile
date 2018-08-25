# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/01 09:29:35 by sprotsen          #+#    #+#              #
#    Updated: 2017/11/01 09:29:40 by sprotsen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Nibbler

SRC = main.cpp \
	Game/Game.cpp \
	Snake/Snake.cpp \
	SdlLibraryWrap/SdlLibraryWrap.cpp \
	Fruit/Fruit.cpp

OBJ = $(SRC:.cpp=.o)

CFLAGS = -std=c++14 -I libs/sdl/sdl2/SDL2 -L libs/sdl/sdl2/lib -l SDL2-2.0.0 \
			-I libs/sdl/sdl2_image/SDL2 -L libs/sdl/sdl2_image/lib -l SDL2_image  

CC = clang++

all: $(NAME)
	# g++ $(SRC) -o play -I libs/sdl/SDL2 -L libs/sdl/lib -l SDL2-2.0.0


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c  -o $@ $< 

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
