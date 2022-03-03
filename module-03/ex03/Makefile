# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mpeerdem <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/27 11:24:06 by mpeerdem      #+#    #+#                  #
#    Updated: 2020/11/21 09:16:50 by mpeerdem      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		several_traps
CC =		clang++
CFLAGS =	-Wall -Werror -Wextra -std=c++98
OBJS =		main.o FragTrap.o ScavTrap.o ClapTrap.o NinjaTrap.o
INC =		FragTrap.hpp ScavTrap.hpp ClapTrap.hpp NinjaTrap.hpp

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
