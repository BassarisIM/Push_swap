# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 18:53:22 by sohollar          #+#    #+#              #
#    Updated: 2026/02/17 22:06:58 by sohollar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf_fd.a

SRCS = ft_printf_fd.c ft_putstr_r_fd.c ft_putnbr_r_fd.c ft_isinset.c ft_puthl_fd.c ft_puthh_fd.c ft_putptr_fd.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

.PHONY : all clean fclean re
