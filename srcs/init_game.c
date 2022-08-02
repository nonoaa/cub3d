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
