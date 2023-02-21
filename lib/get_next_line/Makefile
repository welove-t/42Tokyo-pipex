# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: terabu <terabu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 17:43:10 by terabu            #+#    #+#              #
#    Updated: 2023/02/21 17:43:13 by terabu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libgnl.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= ./
SRCS		= get_next_line.c \
			get_next_line_utils.c
OBJS	= ${SRCS:.c=.o}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re
