NAME	= cub3D
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

LIB		= libft.a
LIBDIR	= -L ./libft
LIB_DIR = ./libft
LDLIBS	= ./libft/libft.a
INCDIR	= -I ./include

MLX_PATH = opengl
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
			


SRCS	= $(addprefix $(SRC)/, $(SOURCES))
OBJS	= $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

all		: $(LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CLFAGS) $(OBJS) $(MLXFLAGS) $(LIBDIR) $(LDLIBS) -o $(NAME)

$(LIB)	:
	make bonus -C libft

clean	:
	rm -rf $(OBJS)
	make clean -C $(LIB_DIR)/
	make clean -C $(MLX_PATH)/

fclean	: clean
	rm -rf $(NAME) $(LDLIBS)

re		: fclean all

.PHONY	: all clean fclean re
