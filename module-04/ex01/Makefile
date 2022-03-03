# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mpeerdem <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/27 11:24:06 by mpeerdem      #+#    #+#                  #
#    Updated: 2020/11/22 11:27:58 by mpeerdem      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		wasteland
CC =		clang++
CFLAGS =	-Wall -Werror -Wextra -std=c++98
OBJS =		main.o AWeapon.o PlasmaRifle.o PowerFist.o Enemy.o SuperMutant.o \
			RadScorpion.o Character.o ShieldKnight.o Boomerang.o
INC =		AWeapon.hpp PlasmaRifle.hpp PowerFist.hpp Enemy.hpp \
			SuperMutant.hpp RadScorpion.hpp Character.hpp ShieldKnight.hpp \
			Boomerang.hpp

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.cpp $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
