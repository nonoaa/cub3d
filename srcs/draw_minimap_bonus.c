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
			*(int *)(img->addr + ((x + j) * img->size_line) + ((y + i) * (img->bpp / 8))) = color;
			i++;
		}
		j++;
	}
}

void    draw_ray_line(t_game *game, t_img_info *img)
{
    double    ray_x;
    double    ray_y;
    double    dx;
    double    dy;
    double    max_value;
    int i = 0;

    ray_x = game->player.pos.x;
    ray_y = game->player.pos.y;
    dx = game->dda_calc.side_dist.x;
    dy = game->dda_calc.side_dist.y;

    max_value = fmax(fabs(dx), fabs(dy));
    dx /= max_value;
    dy /= max_value;
    while (1)
    {
        if (game->map.map[(int)(ray_x)][(int)(ray_y)] == '0')
		{
			i = 0;
			while (i < MINIMAP_SIZE)
			{
				*(int *)(img->addr + (((int)(ray_x * MINIMAP_SIZE) + i) * img->size_line)
				+ ((int)(ray_y * MINIMAP_SIZE) + i) * (img->bpp / 8)) = 0xff0000;
				i++;
			}
		}
        else
            break;
        ray_x += dx;
        ray_y += dy;
    }
}

void	draw_ray(t_game *game, t_img_info *img)
{
	int		x;

	x = -1;
	while (++x < WIDTH)
	{
		init_view(game, &game->dda_calc, x);
		dda(game, &game->dda_calc);
		draw_ray_line(game, img);
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
				fill_squares(img, (int)(MINIMAP_SIZE * x), (int)(MINIMAP_SIZE * y), 0x0000ff);
			else if (game->map.map[x][y] == '0')
				fill_squares(img, (int)(MINIMAP_SIZE * x), (int)(MINIMAP_SIZE * y), 0xffffff);
			else
				fill_squares(img, (int)(MINIMAP_SIZE * x), (int)(MINIMAP_SIZE * y), 0x000000);
			y++;
		}
		x++;
	}
	draw_ray(game, img);
}