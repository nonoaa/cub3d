NAME	= cub3D
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

LIB		= libft.a
LIBDIR	= -L ./libft
LIB_DIR = ./libft
LDLIBS	= ./libft/libft.a
INCDIR	= -I ./include

MLX		= libmlx.a
MLX_PATH = opengl
MLXDIR	= -L ./opengl
MLX_DIR = ./opengl
MLXLIBS	= ./opengl/libmlx.a
MLXFLAGS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

SRC	= ./srcs
SOURCES = main.c\
			arg_check.c\
			check_map.c\
			get_next_line.c\
			init_game.c\
			lst_to_arr.c\
			moving.c\
			read_map_utils.c\
			read_map.c\
			utils.c\
			mlx.c\
			draw_background.c\
			draw_wall.c\
			draw_wall2.c\
			
SOURCES_BONUS = main_bonus.c\
			arg_check.c\
			check_map.c\
			get_next_line.c\
			init_game.c\
			lst_to_arr.c\
			moving_bonus.c\
			read_map_utils.c\
			read_map.c\
			utils.c\
			mlx_bonus.c\
			draw_background.c\
			draw_wall.c\
			draw_wall2.c\
			draw_minimap_bonus.c\
			mouse_bonus.c\


SRCS	= $(addprefix $(SRC)/, $(SOURCES))
OBJS	= $(SRCS:.c=.o)

SRCS_BONUS = $(addprefix $(SRC)/, $(SOURCES_BONUS))
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

all		: $(LIB) $(MLX) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CLFAGS) $(OBJS) $(MLXFLAGS) $(LIBDIR) $(LDLIBS) $(MLXDIR) $(MLXLIBS) -o $(NAME)

$(LIB)	:
	make bonus -C libft

$(MLX)	:
	make -C opengl

clean	:
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)
	make clean -C $(LIB_DIR)/
	make clean -C $(MLX_PATH)/

fclean	: clean
	rm -rf $(NAME) $(LDLIBS) $(MLXLIBS)

re		: fclean all

bonus	: $(LIB) $(MLX) $(OBJS_BONUS)
	$(CC) $(CLFAGS) $(OBJS_BONUS) $(MLXFLAGS) $(LIBDIR) $(LDLIBS) $(MLXDIR) $(MLXLIBS) -o $(NAME)

.PHONY	: all clean fclean re bonus
