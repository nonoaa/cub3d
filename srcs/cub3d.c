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

int name_check(char *str)
{
	int i;

	i = ft_strlen(str) - 1;
	if (str[i--] == 'b')
	{
		if (str[i--] == 'u')
		{
			if (str[i--] == 'c')
			{
				if (str[i] == '.')
					return (1);
			}
		}
	}
	return (0);
}

int arg_check(int argc, char **argv, t_map_info *map)
{
	if (argc != 2 || !name_check(argv[1]))
		return (0);
	map->map_fd = open(argv[1], O_RDONLY);
	if (map->map_fd < 0)
		return (0);
	return (1);
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

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (!arg_check(argc, argv, &game.map))
		err_exit("Wrong argument");
	init_game(&game);
}
