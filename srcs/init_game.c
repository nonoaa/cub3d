#include "cub3d.h"

void	init_key_state(t_key *key)
{
	key->w = false;
	key->a = false;
	key->s = false;
	key->d = false;
	key->l = false;
	key->r = false;
}

void	init_player(t_player *player)
{
	player->dir.x = -1;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = 0.66;
	player->move_speed = 0.1;
	player->rot_speed = 0.1;
}

void	init_game(t_game *game)
{
	init_player(&game->player);
	init_key_state(&game->key_state);
	game->mlx_ptr = mlx_init();
	read_map(game);
	// for (int i = 0; i < game->map.map_height; i++)
	// {
	// 	for (int j = 0; j < game->map.map_width; j++)
	// 	{
	// 		printf("%c ", game->map.map[i][j]);
	// 	}
	// 	printf("\n");
	// }
	check_map(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "cub3D");
}