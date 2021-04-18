# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/03 15:37:37 by user42            #+#    #+#              #
#    Updated: 2021/04/18 12:11:09 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serialize
HUMAN = human_readable

CC = clang++
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3 -fno-omit-frame-pointer -std=c++98

SRCS = serializer.cpp
OBJS = ${SRCS:.cpp=.o}

SRCS2 = human_readable_serializer.cpp
OBJS2 = ${SRCS2:.cpp=.o}

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(HUMAN):	$(OBJS2)
			$(CC) $(CFLAGS) -o $(HUMAN) $(OBJS2)

%.o:%.cpp
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS)
			rm -f $(OBJS2)

fclean:		clean
			rm -f $(NAME)
			rm -f $(HUMAN)

re:			fclean all
