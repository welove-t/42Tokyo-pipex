# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: terabu <terabu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 13:30:56 by terabu            #+#    #+#              #
#    Updated: 2023/02/14 07:50:22 by terabu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
SRCS = pipex.c \
	   get_cmd_line.c \
	   do_system_call.c \
	   do_libft.c
OBJS = $(SRCS:.c=.o)

LIBFTDIR = ./libft
LIBFT =  -L$(LIBFTDIR) -lft

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ${LIBFTDIR}
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT)

clean:
	rm -f $(OBJS)
	$(MAKE) -C ${LIBFTDIR} clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ${LIBFTDIR} fclean

re: fclean all

.PHONY:	all clean fclean re
