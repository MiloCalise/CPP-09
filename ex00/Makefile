# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/10 13:22:45 by miltavar          #+#    #+#              #
#    Updated: 2026/02/10 14:45:14 by miltavar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= btc
CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -Iincludes -g3

SRCS		= srcs/main.cpp srcs/BitcoinExchange.cpp

OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp includes/BitcoinExchange.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
