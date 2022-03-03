# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mpeerdem <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/27 11:24:06 by mpeerdem      #+#    #+#                  #
#    Updated: 2020/11/21 09:18:52 by mpeerdem      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		polymorphism
CC =		clang++
CFLAGS =	-Wall -Werror -Wextra -std=c++98
OBJS =		main.o Sorcerer.o Victim.o Peon.o Grunt.o
INC =		Sorcerer.hpp Victim.hpp Peon.hpp Grunt.hpp

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
