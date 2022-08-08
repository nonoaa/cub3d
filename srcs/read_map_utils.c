/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:25:55 by byahn             #+#    #+#             */
/*   Updated: 2022/08/07 20:25:57 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_repeat(t_game *game, t_type type)
{
	if (type == E_NO && game->map.img[0].img_ptr)
		return (1);
	else if (type == E_EA && game->map.img[1].img_ptr)
		return (1);
	else if (type == E_WE && game->map.img[2].img_ptr)
		return (1);
	else if (type == E_SO && game->map.img[3].img_ptr)
		return (1);
	else if (type == E_FLOOR && game->map.floor_flag)
		return (1);
	else if (type == E_CEILING && game->map.ceiling_flag)
		return (1);
	return (0);
}

void	parse_info(char **line, t_type type)
{
	char	**split;
	int		len;

	if (type == E_MAP)
		return ;
	split = ft_split(*line, ' ');
	if (!split)
		err_exit("malloc error");
	len = arr_len(split);
	if (len != 2)
		err_exit("wrong amount of value");
	free(*line);
	*line = ft_strdup(split[1]);
	free_split(split);
}

t_img_info	load_img(void *mlx, char *path)
{
	t_img_info	img;
	void		*ptr;
	int			w;
	int			h;

	w = WALL_WIDTH;
	h = WALL_HEIGHT;
	ptr = mlx_xpm_file_to_image(mlx, path, &w, &h);
	if (!ptr)
		err_exit("Wrong file");
	img.img_ptr = ptr;
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp,
			&img.size_line, &img.endian);
	return (img);
}

void	handle_texture(t_game *game, char *path, t_type type)
{
	if (type == E_NO)
		game->map.img[0] = load_img(game->mlx_ptr, path);
	else if (type == E_EA)
		game->map.img[1] = load_img(game->mlx_ptr, path);
	else if (type == E_WE)
		game->map.img[2] = load_img(game->mlx_ptr, path);
	else if (type == E_SO)
		game->map.img[3] = load_img(game->mlx_ptr, path);
}

void	handle_color(t_map_info *map, char *colors, t_type type)
{
	char	**split;
	int		len;

	split = ft_split(colors, ',');
	if (!split)
		err_exit("malloc error");
	len = arr_len(split);
	if (len != 3)
		err_exit("wrong amount of value");
	if (type == E_FLOOR)
	{
		map->floor = ft_atoi_ad(split[0]) << 16
			| ft_atoi_ad(split[1]) << 8 | ft_atoi_ad(split[2]);
		map->floor_flag = 1;
	}
	else if (type == E_CEILING)
	{
		map->ceiling = ft_atoi_ad(split[0]) << 16
			| ft_atoi_ad(split[1]) << 8 | ft_atoi_ad(split[2]);
		map->ceiling_flag = 1;
	}
	free_split(split);
}
