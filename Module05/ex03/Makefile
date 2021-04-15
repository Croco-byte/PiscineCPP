# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/03 15:37:37 by user42            #+#    #+#              #
#    Updated: 2021/04/14 15:34:20 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CC = clang++
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3 -fno-omit-frame-pointer -std=c++98

SRCS = Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp main.cpp
OBJS = ${SRCS:.cpp=.o}

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o:%.cpp
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)
			rm -f "SweetHome_shrubbery"

re:			fclean all
