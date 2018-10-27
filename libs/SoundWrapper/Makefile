# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/22 21:10:53 by sprotsen          #+#    #+#              #
#    Updated: 2018/09/02 18:31:20 by dzui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libsoundwrapper.so

CC = clang++ -std=c++14 -Wall -Wextra -Werror

LIBS = -I ../../InterfaceSoundLib
LIBS += -I ~/.brew/include -L ~/.brew/lib
LIBS += -l SDL2_mixer 

SRC = SoundWrapper.cpp

all: lib.so

lib.so:
	$(CC) -dynamiclib -flat_namespace $(SRC) $(LIBS) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re: fclean all
