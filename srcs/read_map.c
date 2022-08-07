/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:27:28 by byahn             #+#    #+#             */
/*   Updated: 2022/08/07 20:27:30 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_valid_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("01NSEW ", str[i]))
			return (0);
		i++;
	}
	return (1);
}

t_type	type_info(char *str)
{
	if (str[0] == 'N' && str[1] == 'O')
		return (E_NO);
	else if (str[0] == 'S' && str[1] == 'O')
		return (E_SO);
	else if (str[0] == 'W' && str[1] == 'E')
		return (E_WE);
	else if (str[0] == 'E' && str[1] == 'A')
		return (E_EA);
	else if (str[0] == 'F' && str[1] == ' ')
		return (E_FLOOR);
	else if (str[0] == 'C' && str[1] == ' ')
		return (E_CEILING);
	else if (map_valid_check(str))
		return (E_MAP);
	else
		return (E_ERROR);
}

void	handle_info(t_game *game, char *line, t_type type)
{
	if (is_repeat(game, type))
		err_exit("info repeated");
	parse_info(&line, type);
	if (type == E_NO || type == E_SO || type == E_WE || type == E_EA)
		handle_texture(game, line, type);
	else if (type == E_FLOOR || type == E_CEILING)
		handle_color(&game->map, line, type);
	else
		ft_lstadd_back(&game->map.map_lst, ft_lstnew(ft_strdup(line)));
	free(line);
}

int	map_info_check(t_map_info *info)
{
	if (!info->img[0].img_ptr)
		return (0);
	if (!info->img[1].img_ptr)
		return (0);
	if (!info->img[2].img_ptr)
		return (0);
	if (!info->img[3].img_ptr)
		return (0);
	if (!info->floor_flag)
		return (0);
	if (!info->ceiling_flag)
		return (0);
	return (1);
}

void	read_map(t_game *game)
{
	char	*line;
	t_type	type;
	int		read_size;

	while (1)
	{
		read_size = get_next_line(game->map.map_fd, &line);
		if (read_size < 0)
			err_exit("read error");
		else if (read_size == 0)
		{
			free(line);
			break ;
		}
		type = type_info(line);
		if (type == E_ERROR)
			err_exit("Wrong map information");
		handle_info(game, line, type);
	}
	if (!map_info_check(&game->map))
		err_exit("Missing source");
	game->map.map = lst_to_arr(game, game->map.map_lst);
}
