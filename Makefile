# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: terabu <terabu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 13:30:56 by terabu            #+#    #+#              #
#    Updated: 2023/02/15 14:06:45 by terabu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex

# DIR
C_DIR = common/
I_DIR = include
LIBFTDIR = $(C_DIR)libft

# SRCS
C_SRCS = $(C_DIR)get_cmd_line.c \
		 $(C_DIR)do_system_call_fd.c \
		 $(C_DIR)do_system_call_pipe.c \
		 $(C_DIR)do_error.c \
		 $(C_DIR)do_libft.c
M_SRCS = pipex.c

C_OBJS = $(C_SRCS:.c=.o)
M_OBJS = $(M_SRCS:.c=.o)

INCLUDE = -I$(I_DIR)
LIBFT = -L$(LIBFTDIR) -lft

all: $(NAME)

$(NAME): $(M_OBJS) $(C_OBJS)
	$(MAKE) -C ${LIBFTDIR}
	$(CC) $(CFLAGS) -o $@ $(M_OBJS) $(C_OBJS) $(INCLUDE) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

# $(C_OBJS): $(C_SRCS)
# 	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

# $(M_OBJS): $(M_SRCS)
# 	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

clean:
	rm -f $(C_OBJS) $(M_OBJS)
	$(MAKE) -C ${LIBFTDIR} clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ${LIBFTDIR} fclean

re: fclean all

.PHONY:	all clean fclean re
