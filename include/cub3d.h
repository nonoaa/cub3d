/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:35:47 by junylee           #+#    #+#             */
/*   Updated: 2022/07/20 20:04:49 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../opengl/mlx.h"
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>

typedef struct s_map_info
{
	int			map_width;
	int			map_height;
	int			floor;
	int			ceiling;
	t_img_info	img[4];
	char		**map;
	int			map_fd;
	t_list		*map_lst;
	int			ceiling_flag;
	int			floor_flag;
}	t_map_info;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
    t_map_info		map;
}	t_game;

#endif
