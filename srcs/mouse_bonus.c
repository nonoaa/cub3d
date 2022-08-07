#include "cub3d_bonus.h"

void	update_mouse(t_game *game)
{
	mlx_mouse_hide();
	mlx_mouse_get_pos(game->win_ptr, &game->mouse.x, &game->mouse.y);
	mlx_mouse_move(game->win_ptr, WIDTH / 2, HEIGHT / 2);
}