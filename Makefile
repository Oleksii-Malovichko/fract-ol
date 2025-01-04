NAME = fractol
CC = cc 
CFLAGS = -fsanitize=address -g -Wall -Wextra -Werror -Ilib

SRC = srcs/main.c srcs/mandelbrot.c srcs/tools.c srcs/julia.c srcs/colors.c srcs/init.c
OBJS = $(SRC:.c=.o)

PRINTF_DIR = lib/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

MINIMLX_DIR = lib/minilibx-linux
MINIMLX = $(MINIMLX_DIR)/libmlx.a

all: $(PRINTF) $(MINIMLX) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(PRINTF_DIR) -lftprintf -L$(MINIMLX_DIR) -lm -lmlx -lX11 -lGL -lXext

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(MINIMLX):
	@$(MAKE) -C $(MINIMLX_DIR)

clean:
	@$(MAKE) -C $(MINIMLX_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
