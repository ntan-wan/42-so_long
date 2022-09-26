NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft/
LIBFT_LIB = libft.a

LIBMLX = -Lmlx_linux -lmlx_Linux -Imlx_linux
OTHER_LIBS = -lX11 -lXext -lm -lz
HEADER_DIR =  includes/
SRCS_DIR = srcs/
SRCS = $(shell find srcs/*.c)
OBJS_DIR = objs/
OBJS = $(notdir $(SRCS:.c=.o))
OBJS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

#text_color
COLOR_OFF =\033[0m
RED =\033[0;31m
GREEN =\033[0;32m
YELLOW =\033[0;33m
CYAN =\033[1;36m
MAGNETA =\033[95m 

#IP address
NAMESERVER = $(shell cat /etc/resolv.conf | grep nameserver)
IPV4 = $(filter-out nameserver, $(NAMESERVER))
IPV4_ADDRESS_SUFFIXED = $(addsuffix :0.0, $(IPV4))


all : $(LIBFT_LIB) $(NAME)


#pass the IP address to child process.
#the rule below only display the command needed to type in terminal.
#have to manually type in the command below into the terminal.
ip :
	export DISPLAY=$(IPV4_ADDRESS_SUFFIXED)

#Add norminette to PATH
norminette :
	PATH="$$PATH:/home/ntan-wan/.local/bin"

$(LIBFT_LIB) :
	make -C libft

$(OBJS_DIR)%.o : $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) -c $< -o $@ -I$(HEADER_DIR)
	@echo "$(GREEN)Compiling : $< $(COLOR_OFF)"

$(NAME) : $(OBJS_PREFIXED)
	@$(CC) $(OBJS_PREFIXED) $(LIBFT_DIR)$(LIBFT_LIB) $(LIBMLX) $(OTHER_LIBS) -o $(NAME)
	@echo "$(CYAN)$(NAME) done !$(COLOR_OFF)"

clean :
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)Removed : obj files ($(NAME))$(COLOR_OFF)"

fclean : clean
	@make fclean -C libft
	@rm -rf $(NAME)
	@echo "$(RED)Removed : $(NAME)$(COLOR_OFF)"

.PHONY : clean fclean all init norminette
