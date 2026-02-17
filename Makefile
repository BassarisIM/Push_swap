# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/09 14:51:09 by sohollar          #+#    #+#              #
#    Updated: 2026/02/17 22:23:15 by sohollar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
CC				= cc
CFLAGS			= -g3 -g -Wall -Wextra -Werror -I .
#INCLUDES		= push_swap.h

SRCS			= push_swap.c fillist.c push_swap_checks.c \
					pushes.c swaps.c rotate.c rrotate.c

OBJS			= $(SRCS:.c=.o)
LIBFT			= ./Libft00/libft.a
PRINTF_FD		= ./Printf_fd/libftprintf_fd.a

all : $(NAME)
re : fclean all
$(NAME) : $(OBJS) $(LIBFT) $(PRINTF_FD)
		$(CC) $(CFLAGS) -o $(NAME) $^

$(LIBFT) :
		make -C Libft00

$(PRINTF_FD) :
		make -C Printf_fd

%.o : %.c
		$(CC) $(CFLAGS) -o $@ -c $<

clean :
		make -C Libft00 clean
		make -C Printf_fd clean
		rm -rf $(OBJS)
fclean : clean
		make -C Libft00 fclean
		make -C Printf_fd fclean
		rm -rf $(NAME)

.PHONY : all clean fclean re
