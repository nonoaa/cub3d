/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:17:32 by junylee           #+#    #+#             */
/*   Updated: 2022/08/07 20:17:33 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	name_check(char *str)
{
	int	i;

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

int	arg_check(int argc, char **argv, t_map_info *map)
{
	if (argc != 2 || !name_check(argv[1]))
		return (0);
	map->map_fd = open(argv[1], O_RDONLY);
	if (map->map_fd < 0)
		return (0);
	return (1);
}
