NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEADER_PATH = includes/
SRCS_PATH = srcs/
OBJS_PATH = $(SRCS_PATH)objs/

SRCS = ft_printf.c \
	absolute.c \
	fmt_init.c \
	fmt_update.c \
	fmt_operation.c \
	fmt_update_flags.c \
	print_c.c \
	print_s.c \
	print_ptr.c \
	print_decimal.c \
	print_hexa.c \
	print_unsi.c \
	print_percent.c \
	print_space.c \
	print_prefix_nbr.c \
	print_prefix_unsi.c \

OBJS = $(patsubst %.c, %.o, $(SRCS))

SRCS_PREFIXED = $(addprefix $(SRCS_PATH), $(SRCS))
OBJS_PREFIXED = $(addprefix $(OBJS_PATH), $(OBJS))

LIBFT_DIR = ../
LIBFT_OBJS = $(LIBFT_DIR)objs/*.o
LIB = libft.a

#text color
COLOR_OFF =\033[0m
RED =\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
ORANGE=\033[38;5;214m
CYAN=\033[0;36m
MAGENTA=\033[35m

all : $(NAME)

$(NAME) : $(OBJS_PREFIXED)
	@ar rcs $(NAME) $(OBJS_PREFIXED) $(LIBFT_OBJS)
	@echo "$(GREEN)ft_printf Done!$(COLOR_OFF)"

# $(LIB) :
#	@make bonus -C $(LIBFT_DIR)

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	@echo "$(MAGENTA)Compiling: $<$(COLOR_OFF)"
	@$(CC) $(CFLAGS) -c -I$(HEADER_PATH) $< -o $@

bonus : $(NAME)

clean :
	@rm -rf $(OBJS_PATH)
	@echo "$(RED)Removed : obj files (ft_printf)$(COLOR_OFF)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(RED)Removed : $(NAME)$(COLOR_OFF)"
re : fclean all
