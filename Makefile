NAME	=	push_swap

SRC		=	push_swap.c \
			operations.c \
			utils.c \
			free.c \
			checkers.c \
			sort.c \
			radix.c \
			sort_utils.c

OBJS	=	$(SRC:%.c=%.o)

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -g
# HEADERS	= -I $(LIBFT) -I $(PRINTF)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

# ft_printf library
PRINTF		= ./ft_printf
PRINTF_LIB	= $(PRINTF)/ft_printf.a

# libft library
LIBFT		= ./libft
LIBFT_LIB	= $(LIBFT)/libft.a

# instructions to compile $(NAME)
$(NAME): $(PRINTF_LIB) $(LIBFT_LIB) $(OBJS)
	@$(CC) $(OBJS) $(PRINTF_LIB) $(LIBFT_LIB) -o $(NAME)
	@echo "Program compiled"

# instructions to compile ft_printf (aka $(PRINTF_LIB))
$(PRINTF_LIB):
	@make -C $(PRINTF)
	@echo "ft_printf.a created"

# instructions to compile libft (aka $(LIBFT_LIB))
$(LIBFT_LIB):
	@make -C $(LIBFT)
	@echo "libft.a created"

PHONY: all clean fclean re

all: $(PRINTF_LIB) $(LIBFT_LIB) $(NAME)

clean:
	@rm -f $(OBJS)
	@make -C $(PRINTF) clean
	@make -C $(LIBFT) clean
	@echo "Objects files removed"

fclean: clean
	@rm -f $(NAME)
	@make -C $(PRINTF) fclean
	@make -C $(LIBFT) fclean
	@echo "Executable removed"

re: fclean all