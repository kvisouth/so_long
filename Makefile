SRC		=	src/parsing_args.c \
			src/main.c \
			src/parsing_utils.c \
			src/parsing_walls.c \
			src/parsing_elem.c \
			src/parsing_path.c \
			src/init_var.c \
			src/init_textures.c \
			src/init_textures_mlx.c \
			src/init_textures_player.c \
			src/init_textures_coins.c \
			src/event_move.c \
			src/event_utils.c \

SRC_B	=	src_bonus/parsing_args_bonus.c \
			src_bonus/main_bonus.c \
			src_bonus/parsing_utils_bonus.c \
			src_bonus/parsing_walls_bonus.c \
			src_bonus/parsing_elem_bonus.c \
			src_bonus/parsing_path_bonus.c \
			src_bonus/init_var_bonus.c \
			src_bonus/init_textures_bonus.c \
			src_bonus/init_textures_mlx_bonus.c \
			src_bonus/init_textures_player_bonus.c \
			src_bonus/init_textures_coins_bonus.c \
			src_bonus/event_move_bonus.c \
			src_bonus/event_utils_bonus.c \

NAME	= so_long
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf
AR		= ar rcs

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a


OBJ		= $(SRC:.c=.o)
OBJ_B	= $(SRC_B:.c=.o)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(LIBFT) $(MLX) $(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft $(MLX) -lXext -lX11

$(LIBFT):
			$(MAKE) -C $(LIBFT_DIR)

$(MLX):
			$(MAKE) -C $(MLX_DIR)

all:		$(NAME)

bonus:		$(LIBFT) $(MLX) $(OBJ_B)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ_B) -L$(LIBFT_DIR) -lft $(MLX) -lXext -lX11

clean:
			$(RM) $(OBJ) $(OBJ_B)
			$(MAKE) -C $(LIBFT_DIR) clean
			$(MAKE) -C $(MLX_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re
