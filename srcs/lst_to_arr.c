/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:20:11 by junylee           #+#    #+#             */
/*   Updated: 2022/08/07 20:20:12 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_node(void *content)
{
	free(content);
	content = 0;
}

void	get_width_height(int *wid, int *hei, t_list *head)
{
	int				size;
	unsigned int	longest_width;
	t_list			*curr;

	size = 0;
	curr = head;
	longest_width = ft_strlen(head->content);
	while (curr)
	{
		if (longest_width < ft_strlen(curr->content))
			longest_width = ft_strlen(curr->content);
		size++;
		curr = curr->next;
	}
	*wid = longest_width;
	*hei = size;
}

void	fill_space(char **map, int wid, int hei)
{
	int	i;

	i = 0;
	while (i < hei)
	{
		map[i] = (char *)malloc(sizeof(char) * (wid + 1));
		if (!map[i])
			err_exit("malloc error");
		ft_memset(map[i], ' ', wid);
		map[i][wid] = '\0';
		i++;
	}
}

char	**lst_to_arr(t_game *game, t_list *head)
{
	int		i;
	char	**map;
	t_list	*curr;

	i = 0;
	curr = head;
	get_width_height(&game->map.map_width, &game->map.map_height, head);
	map = (char **)malloc(sizeof(char *) * (game->map.map_height + 1));
	if (!map)
		err_exit("malloc error");
	fill_space(map, game->map.map_width, game->map.map_height);
	while (i < game->map.map_height)
	{
		ft_strncpy(map[i], curr->content, ft_strlen(curr->content));
		curr = curr->next;
		i++;
	}
	ft_lstclear(&head, free_node);
	return (map);
}
