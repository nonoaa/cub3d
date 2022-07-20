NAME	= cub3D
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

LIB		= libft.a
LIBDIR	= -L ./libft
LIB_DIR = ./libft
LDLIBS	= ./libft/libft.a
INCDIR	= -I ./include \

MLX_PATH = opengl
MLXFLAGS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

SRC	= ./srcs
SOURCES = cub3d.c \

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
	make -C libft clean

fclean	: clean
	rm -rf $(NAME) 

re		: fclean all

.PHONY	: all clean fclean re
