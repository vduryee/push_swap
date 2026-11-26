# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/20 17:44:17 by alegaspa          #+#    #+#              #
#    Updated: 2026/11/26 16:55:49 by vduryee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC		= cc
CFLAGS		= -Wall -Wextra -Werror -g -MP -MMD -I$(LIBFT_DIR)

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS		= main.c\
		  better_init.c\
		  ft_init.c\
		  ft_init_utils.c\
		  ft_normalize.c\
		  selector.c\
		  ops.c\
		  combined_ops.c\
		  insert_sort.c\
		  butterfly_sort.c\
		  butterfly_utils.c\
		  adaptive_sort.c\
		  bench_helper.c\
		  ft_printf.c\
		  ft_printf_err_utils.c\
		  ft_printf_utils.c

HEAD		= structs.h\
		  helpers.h\
		  ops.h\
		  algo_sort.h\
		  butterfly_utils.h\
		  ft_printf.h\
		  ft_printf_err.h

OBJS		= $(SRCS:.c=.o)
DEPFILE		= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(DEPFILE)
	@echo "Tkt ça process $< → $@"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT): FORCE
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

%.o: %.c $(HEAD)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@rm -f $(OBJS) $(DEPFILE)
	@echo "Le bordel .o et .d  est nettoyé patron O7 !"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@rm -f $(NAME)
	@echo "Wallah c'est tout propre chef !"

re: fclean all
	@echo "Tié un tigre RAWR !"

FORCE:

.PHONY: all clean fclean re FORCE
