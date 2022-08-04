#include "cub3d.h"

void	rotate(t_game *game, double rot)
{
	double	tmp;

	tmp = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * cos(rot)
		- game->player.dir.y * sin(rot);
	game->player.dir.y = game->player.dir.y * cos(rot)
		+ tmp * sin(rot);
	tmp = game->player.plane.x;
	game->player.plane.x = game->player.plane.x * cos(rot)
		- game->player.plane.y * sin(rot);
	game->player.plane.y = game->player.plane.y * cos(rot)
		+ tmp * sin(rot);
}