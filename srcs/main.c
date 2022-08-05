/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:37:09 by junylee           #+#    #+#             */
/*   Updated: 2022/07/20 20:05:43 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (!arg_check(argc, argv, &game.map))
		err_exit("Wrong argument");
	init_game(&game);
	mlx_loop_hook (game.mlx_ptr, &main_loop, &game);
	mlx_hook(game.win_ptr, K_PRESS, 0, &key_press, &game);
	mlx_hook(game.win_ptr, K_RELEASE, 0, &key_release, &game);
	mlx_hook(game.win_ptr, E_EXIT, 0, &end_program, &game);
	mlx_loop(game.mlx_ptr);
}
