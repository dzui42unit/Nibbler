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

NAME = libsoundwrapper.so

CC = clang++ -std=c++14 -fPIC

# CFLAGS = -fPIC 
#-Wall -Wextra -Werror

#LIBS = -I ../sdl/sdl2_mixer/SDL2 -L ../sdl/sdl2_mixer/lib -l SDL2_mixer
#LIBS += -I ../sdl/sdl2/SDL2 -L ../sdl/sdl2/lib -l SDL2

LIBS = -I ../../InterfaceSoundLib

LIBS += -I ../sdl/sdl2/SDL2 -L ../sdl/sdl2/lib -l SDL2
# LIBS += -I ../sdl/sdl2_image/SDL2 -L ../sdl/sdl2_image/lib -l SDL2_image 
LIBS += -I ../sdl/sdl2_mixer/SDL2 -L ../sdl/sdl2_mixer/lib -l SDL2_mixer 
# LIBS += -I ../sdl/sdl2_ttf/SDL2 -L ../sdl/sdl2_ttf/lib -l SDL2_ttf
LISD += -framework OpenGL -framework AppKit


SRC = SoundWrapper.cpp

# OBJ = $(SRC:.cpp=.o)

all: $(OBJ) lib.so

lib.so:
	$(CC) -shared $(SRC) $(LIBS) -o $(NAME)

# %.o: %.cpp
# 	$(CC) $(CFLAGS) $(LIBS) -c  -o $@ $< 

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
