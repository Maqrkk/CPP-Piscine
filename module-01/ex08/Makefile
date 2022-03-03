# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mpeerdem <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/27 11:24:06 by mpeerdem      #+#    #+#                  #
#    Updated: 2020/11/16 08:54:51 by mpeerdem      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		attacks
CC =		clang++
CFLAGS =	-Wall -Werror -Wextra -std=c++98
OBJS =		main.o Human.o
INC =		Human.hpp

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
