/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:17:40 by junylee           #+#    #+#             */
/*   Updated: 2022/08/07 20:17:41 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling(t_img_info img, int ceiling)
{
	int		x;
	int		y;

	y = -1;
	while (++y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
			*(int *)(img.addr + (y * img.size_line
						+ x * (img.bpp / 8))) = ceiling;
	}
}

void	draw_floor(t_img_info img, int floor)
{
	int		x;
	int		y;

	y = HEIGHT / 2 - 1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			*(int *)(img.addr + (y * img.size_line
						+ x * (img.bpp / 8))) = floor;
	}
}
