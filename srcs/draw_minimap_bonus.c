/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:18:27 by junylee           #+#    #+#             */
/*   Updated: 2022/08/07 20:18:28 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	fill_squares(t_img_info *img, int x, int y, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < MINIMAP_SIZE)
	{
		i = 0;
		while (i < MINIMAP_SIZE)
		{
			*(int *)(img->addr + ((x + j) * img->size_line)
					+ ((y + i) * (img->bpp / 8))) = color;
			i++;
		}
		j++;
	}
}

void	draw_minimap(t_game *game, t_img_info *img)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.map_height)
	{
		y = 0;
		while (y < game->map.map_width)
		{
			if (x == (int)game->player.pos.x && y == (int)game->player.pos.y)
				fill_squares(img, (int)(MINIMAP_SIZE * x),
					(int)(MINIMAP_SIZE * y), 0xff0000);
			else if (game->map.map[x][y] == '0')
				fill_squares(img, (int)(MINIMAP_SIZE * x),
					(int)(MINIMAP_SIZE * y), 0xffffff);
			else
				fill_squares(img, (int)(MINIMAP_SIZE * x),
					(int)(MINIMAP_SIZE * y), 0x000000);
			y++;
		}
		x++;
	}
}
