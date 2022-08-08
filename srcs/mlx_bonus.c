/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:24:02 by byahn             #+#    #+#             */
/*   Updated: 2022/08/07 20:24:03 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	main_loop_bonus(t_game *game)
{
	t_img_info	screen;

	update_mouse(game);
	moving(game);
	screen.img_ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	screen.addr = mlx_get_data_addr(screen.img_ptr, &screen.bpp,
			&screen.size_line, &screen.endian);
	draw_ceiling(screen, game->map.ceiling);
	draw_floor(screen, game->map.floor);
	draw_wall(game, &screen);
	draw_minimap(game, &screen);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, screen.img_ptr, 0, 0);
	mlx_destroy_image(game->mlx_ptr, screen.img_ptr);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == K_W)
		game->key_state.w = true;
	else if (keycode == K_S)
		game->key_state.s = true;
	else if (keycode == K_A)
		game->key_state.a = true;
	else if (keycode == K_D)
		game->key_state.d = true;
	else if (keycode == K_LEFT)
		game->key_state.l = true;
	else if (keycode == K_RIGHT)
		game->key_state.r = true;
	else if (keycode == K_ESC)
		end_program();
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == K_W)
		game->key_state.w = false;
	else if (keycode == K_S)
		game->key_state.s = false;
	else if (keycode == K_A)
		game->key_state.a = false;
	else if (keycode == K_D)
		game->key_state.d = false;
	else if (keycode == K_LEFT)
		game->key_state.l = false;
	else if (keycode == K_RIGHT)
		game->key_state.r = false;
	return (0);
}

int	end_program(void)
{
	exit(0);
	return (0);
}
