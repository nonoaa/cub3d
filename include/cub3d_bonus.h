#ifndef CUB3D_H
# define CUB3D_H

# include "../opengl/mlx.h"
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "get_next_line.h"

# define HEIGHT 880
# define WIDTH 1320
# define WALL_WIDTH 64
# define WALL_HEIGHT 64
# define NORTH_RADIANS 0.01
# define SOUTH_RADIANS 3.14
# define EAST_RADIANS  4.71
# define WEST_RADIANS  1.58
# define MINIMAP_SIZE 7

enum e_event_index
{
	K_A = 0,
	K_S = 1,
	K_D = 2,
	K_PRESS = 2,
	K_RELEASE = 3,
	K_W = 13,
	E_EXIT = 17,
	K_ESC = 53,
	K_LEFT = 123,
	K_RIGHT = 124,
};

typedef struct s_key
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	l;
	bool	r;
}	t_key;

typedef struct s_coordinate_i
{
	int	x;
	int	y;
}	t_coordinate_i;

typedef struct s_coordinate_d
{
	double	x;
	double	y;
}	t_coordinate_d;

typedef struct s_player
{
	t_coordinate_d	pos;
	t_coordinate_d	dir;
	t_coordinate_d	plane;
	double			move_speed;
	double			rot_speed;
}	t_player;

typedef struct s_img_info
{
	char	*addr;
	void	*img_ptr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img_info;

typedef struct s_map_info
{
	int			map_width;
	int			map_height;
	int			floor;
	int			ceiling;
	t_img_info	img[4];
	char		**map;
	int			map_fd;
	t_list		*map_lst;
	int			ceiling_flag;
	int			floor_flag;
}	t_map_info;

typedef struct s_dda_calc
{
	double			camera_x;
	t_coordinate_d	ray_dir;
	t_coordinate_i	map;
	t_coordinate_d	side_dist;
	t_coordinate_d	delta_dist;
	double			per_dist;
	t_coordinate_i	step;
	int				hit;
	int				side;
}	t_dda_calc;

typedef struct s_dda_draw
{
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				wall_index;
	double			wall_x;
	t_coordinate_i	tex;
	double			step;
	double			tex_pos;
	int				color;
}	t_dda_draw;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_player		player;
	t_key			key_state;
	t_map_info		map;
	t_dda_calc		dda_calc;
	t_dda_draw		dda_draw;
	t_coordinate_i	mouse;
}	t_game;

typedef enum e_type
{
	E_ERROR = 0,
	E_NO,
	E_SO,
	E_WE,
	E_EA,
	E_FLOOR,
	E_CEILING,
	E_MAP
}	t_type;

/*
** =============================================================================
** arg_check.c
** =============================================================================
*/

int name_check(char *str);
int arg_check(int argc, char **argv, t_map_info *map);

/*
** =============================================================================
** check_map.c
** =============================================================================
*/

void	handle_character(t_game *game, char c, int row, int col);
int	count_source(t_game *game, char **map);
int	wall_surrounded(t_game *game, int row, int col);
int	wall_check(t_game *game, int i, int j, char **map);
void	check_map(t_game *game);

/*
** =============================================================================
** init_game.c
** =============================================================================
*/

void	init_key_state(t_key *key);
void	init_player(t_player *player);
void	init_game(t_game *game);

/*
** =============================================================================
** lst_to_arr.c
** =============================================================================
*/

void	free_node(void *content);
void	get_width_height(int *wid, int *hei, t_list *head);
void	fill_space(char **map, int wid, int hei);
char **lst_to_arr(t_game *game, t_list *head);

/*
** =============================================================================
** moving.c
** =============================================================================
*/

void	rotate(t_game *game, double rot);
void	moving(t_game *game);

/*
** =============================================================================
** read_map_utils.c
** =============================================================================
*/

int is_repeat(t_game *game, t_type type);
void    parse_info(char** line, t_type type);
t_img_info load_img(void *mlx, char *path);
void handle_texture(t_game *game, char *path, t_type type);
void handle_color(t_map_info *map, char *colors, t_type type);

/*
** =============================================================================
** read_map.c
** =============================================================================
*/

int	map_valid_check(char *str);
t_type type_info(char *str);
void handle_info(t_game *game, char *line, t_type type);
void    read_map(t_game *game);

/*
** =============================================================================
** utils.c
** =============================================================================
*/

void	err_exit(char *str);
void	free_split(char **split);
int		arr_len(char **arr);
int		ft_atoi_ad(const char *str);

/*
** =============================================================================
** mlx_bonus.c
** =============================================================================
*/

int		main_loop_bonus(t_game *game);
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
int		end_program(void);

/*
** =============================================================================
** draw_background.c
** =============================================================================
*/

void	draw_ceiling(t_img_info img, int ceiling);
void	draw_floor(t_img_info img, int floor);

/*
** =============================================================================
** draw_wall.c
** =============================================================================
*/

void	draw_wall(t_game *game, t_img_info *img);
void	init_view(t_game *game, t_dda_calc *v, int x);
void	dda(t_game *game, t_dda_calc *v);

/*
** =============================================================================
** draw_wall.c
** =============================================================================
*/

void	draw_line(int x, t_game *game, t_img_info *img);

/*
** =============================================================================
** draw_minimap.c
** =============================================================================
*/

void	draw_minimap(t_game *game, t_img_info *img);

/*
** =============================================================================
** draw_minimap.c
** =============================================================================
*/

void	update_mouse(t_game *game);

#endif
