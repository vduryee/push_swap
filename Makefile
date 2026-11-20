NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -MP -MMD -I$(LIBFT_DIR)

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS		= main.c ft_init.c ft_init_utils.c ft_normalize.c selector.c \
			  ops.c combined_ops.c butterfly_sort.c bench_helper.c \
			  ft_printf.c ft_printf_utils.c

HEAD		= structs.h helpers.h ops.h algo_sort.h ft_printf.h

OBJS		= $(SRCS:.c=.o)
DEPFILE		= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(DEPFILE)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(DEPFILE)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

FORCE:

.PHONY: all clean fclean re FORCE