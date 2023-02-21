# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: terabu <terabu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 13:30:56 by terabu            #+#    #+#              #
#    Updated: 2023/02/21 13:52:56 by terabu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex

# DIR
l_DIR = lib/
I_DIR = include
LIBFTDIR = $(l_DIR)libft

# SRCS
l_SRCS = $(l_DIR)get_cmd_line.c \
		 $(l_DIR)do_system_call_fd.c \
		 $(l_DIR)do_system_call_pipe.c \
		 $(l_DIR)do_error.c \
		 $(l_DIR)do_dup_close.c \
		 $(l_DIR)do_libft.c \
		 $(l_DIR)initialize.c \
		 $(l_DIR)finalize.c
SRCS = pipex.c

# OBJS
l_OBJS = $(l_SRCS:.c=.o)
OBJS = $(SRCS:.c=.o)

INCLUDE = -I$(I_DIR)
LIBFT = -L$(LIBFTDIR) -lft

all: $(NAME)

$(NAME): $(OBJS) $(l_OBJS)
	$(MAKE) -C ${LIBFTDIR}
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(l_OBJS) $(INCLUDE) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

clean:
	rm -f $(OBJS) $(l_OBJS)
	$(MAKE) -C ${LIBFTDIR} clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ${LIBFTDIR} fclean

re: fclean all

.PHONY:	all clean fclean re bonus
