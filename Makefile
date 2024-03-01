# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 19:24:58 by simarcha          #+#    #+#              #
#    Updated: 2024/03/01 17:44:45 by simarcha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

SRCS		= main.c \
		  	list_utils.c \
			movements.c \
			push_swap_utils.c \
			reverse_mvt.c \
			rotate_mvt.c \
			swap_and_push_mvt.c \
			list_utils_2.c \
			manage_errors.c \
			manage_errors2.c

INCLUDE		= push_swap.h

NAME		= push_swap

RM			= rm -rf

OBJ			= $(SRCS:.c=.o)

MAKE		= ar rcs

all: 		$(NAME)

$(NAME): 	$(OBJ)
			$(MAKE) $(NAME) $(OBJ)

%.o: 		%.c $(INCLUDE) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJ)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
