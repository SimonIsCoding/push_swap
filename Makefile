# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 20:04:24 by simarcha          #+#    #+#              #
#    Updated: 2024/03/17 16:25:35 by simarcha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

EXEC		= push_swap

CFLAGS		= -Wall -Wextra -Werror

SRCS_DIR	= srcs

SRCS		= $(SRCS_DIR)/main.c \
		  	$(SRCS_DIR)/list_utils.c \
			$(SRCS_DIR)/manage_errors.c \
			$(SRCS_DIR)/manage_errors2.c \
			$(SRCS_DIR)/push_swap_utils.c \
			$(SRCS_DIR)/movement_swap.c \
			$(SRCS_DIR)/movement_rotate.c \
			$(SRCS_DIR)/movement_reverse_rotate.c \
			$(SRCS_DIR)/movement_push.c \
			$(SRCS_DIR)/min_max.c \
			$(SRCS_DIR)/algorithm_utils.c \
			$(SRCS_DIR)/algorithm_utils2.c \
			$(SRCS_DIR)/algorithm.c \
			$(SRCS_DIR)/find_the_median.c \
			$(SRCS_DIR)/manage_errors_argc_is_2.c \
			$(SRCS_DIR)/ft_split.c \
			$(SRCS_DIR)/sort.c

INCLUDE		= ./inc/push_swap.h

RM			= rm -rf

OBJ			= $(SRCS:.c=.o)

all: 		$(EXEC)

%.o: 		%.c Makefile $(INCLUDE)
			$(CC) $(CFLAGS) -c $< -o $@

$(EXEC):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $@

clean:
			$(RM) $(OBJ)

fclean: 	clean
			$(RM) $(EXEC) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
