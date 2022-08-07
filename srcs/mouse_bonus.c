/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:24:54 by byahn             #+#    #+#             */
/*   Updated: 2022/08/07 20:24:58 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	update_mouse(t_game *game)
{
	mlx_mouse_hide();
	mlx_mouse_get_pos(game->win_ptr, &game->mouse.x, &game->mouse.y);
	mlx_mouse_move(game->win_ptr, WIDTH / 2, HEIGHT / 2);
}
