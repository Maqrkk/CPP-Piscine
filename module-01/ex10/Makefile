# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mpeerdem <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/27 11:24:06 by mpeerdem      #+#    #+#                  #
#    Updated: 2020/11/16 08:55:28 by mpeerdem      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		cato9tails
CC =		clang++
CFLAGS =	-Wall -Werror -Wextra -std=c++98
OBJS =		main.o

.PHONY: all clean fclean re

all: $(NAME)
	@echo "This is a line you should never get to see,\nUnless you chmoded me." > error.txt
	@chmod 000 error.txt

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	chmod 777 error.txt && rm error.txt

re: fclean all
