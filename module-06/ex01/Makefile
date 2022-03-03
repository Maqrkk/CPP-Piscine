# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mpeerdem <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/27 11:24:06 by mpeerdem      #+#    #+#                  #
#    Updated: 2021/03/01 13:16:23 by mpeerdem      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = 			serialize
CC = 			clang++
CFLAGS = 		-Wall -Werror -Wextra -std=c++98
CLASSES =
INTERFACES =
_OBJS = 		main $(CLASSES)
OBJS =			$(addsuffix .o, $(_OBJS))
_INC = 			$(CLASSES) $(INTERFACES)
INC =			$(addsuffix .hpp, $(_INC))

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
