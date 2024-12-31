NAME = fractol
CC = cc 
CFLAGS = -Ilib

SRC = srcs/main.c srcs/drawing_mandelbrot.c srcs/tools.c
OBJS = $(SRC:.c=.o)

SRC_GNL = lib/get_next_line/get_next_line.c lib/get_next_line/get_next_line_utils.c 
OBJS_GNL = $(SRC_GNL:%.c=%.o)

PRINTF_DIR = lib/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

MINIMLX_DIR = lib/minilibx-linux
MINIMLX = $(MINIMLX_DIR)/libmlx.a

all: $(LIBFT) $(PRINTF) $(MINIMLX) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(OBJS_GNL)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -L$(MINIMLX_DIR) -lm -lmlx -lX11 -lGL -lXext $(OBJS_GNL)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MINIMLX):
	@$(MAKE) -C $(MINIMLX_DIR)

clean:
	rm -f $(OBJS) $(OBJS_GNL)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MINIMLX_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
