/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:20:02 by junylee           #+#    #+#             */
/*   Updated: 2022/08/07 20:20:02 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	player->rot_speed = 0.05;
}

void	init_game(t_game *game)
{
	init_player(&game->player);
	init_key_state(&game->key_state);
	game->mlx_ptr = mlx_init();
	read_map(game);
	check_map(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "cub3D");
}
