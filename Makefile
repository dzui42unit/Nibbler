# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/01 09:29:35 by sprotsen          #+#    #+#              #
#    Updated: 2018/08/26 19:31:36 by dzui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Nibbler

SRC = main.cpp \
	Game/Game.cpp \
	Snake/Snake.cpp \
	Fruit/Fruit.cpp


#SdlLibraryWrap/SdlLibraryWrap.cpp
OBJ = $(SRC:.cpp=.o)

# CFLAGS = -std=c++14 -I libs/sdl/sdl2/SDL2 -L libs/sdl/sdl2/lib -l SDL2-2.0.0 \
		  -I libs/sdl/sdl2_image/SDL2 -L libs/sdl/sdl2_image/lib -l SDL2_image -L libs/sdl/sdl2_ttf/lib -l SDL2_ttf -L libs/sdl/sdl2_mixer/lib -l SDL2_mixer


CFLAGS = -std=c++14
		 

CC = clang++

all: $(NAME)
	# g++ $(SRC) -o play -I libs/sdl/SDL2 -L libs/sdl/lib -l SDL2-2.0.0


$(NAME): $(OBJ)
	clang++ $(OBJ) -L. -lsdl2wrapper -Wl,-rpath,. -L. -lsoundwrapper -Wl,-rpath,.


	#$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c  -o $@ $< 

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
