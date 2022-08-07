/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:22:39 by byahn             #+#    #+#             */
/*   Updated: 2022/08/07 20:22:44 by byahn            ###   ########.fr       */
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
