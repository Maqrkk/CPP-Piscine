# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mpeerdem <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/27 09:48:54 by mpeerdem      #+#    #+#                  #
#    Updated: 2020/11/15 14:19:58 by mpeerdem      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		megaphone
CC =		clang++
CFLAGS =	-Wall -Werror -Wextra -std=c++98
OBJS =		megaphone.o

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
