# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 19:24:58 by simarcha          #+#    #+#              #
#    Updated: 2024/03/05 18:53:11 by simarcha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

SRCS		= main.c \
		  	list_utils.c \
			manage_errors.c \
			manage_errors2.c \
			push_swap_utils.c \
			movement_swap.c \
			movement_rotate.c \
			movement_reverse_rotate.c \
			movement_push.c \
			min_max.c \
			algorithm_utils.c

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
