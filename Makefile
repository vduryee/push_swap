# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alegaspa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/20 15:00:07 by alegaspa          #+#    #+#              #
#    Updated: 2026/11/20 16:53:13 by alegaspa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap

CC	:= cc
CFLAGS	:= -Wall -Wextra -Werror -g -MP -MMD -I$(LIBFT_DIR)

SRCS	:= bench_helper.c\
	   butterfly_sort.c\
	   combined_ops.c\
	   ft_init.c\
	   ft_init_utils.c\
	   ft_normalize.c\
	   ft_printf.c\
	   ft_printf_utils.c\
	   main.c\
	   ops.c\
	   selector.c

OBJS	= $(SRCS:.c=.o)
DEPFILE = $(OBJS:.o=.d)

LIBFT_DIR = libft/
LIBFT	= $(LIBFT_DIR)libft.a

all: $(NAME)

$(NAME): $(OBJS) $(DEPFILE) $(LIBFT)
	 $(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c algo_sort.h\
	ft_printf.h\
	helpers.h\
	ops.h\
	structs.h
	@$(CC) $(CFLAGS) $(LIBFT) -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPFILE)

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re
