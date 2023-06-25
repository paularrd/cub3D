/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:49:01 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/05/04 10:08:14 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/mandatory/cub3d.h"

void	key_press(void *mlx)
{
	t_game	*game;

	game = mlx;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_forward(game, game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_backward(game, game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_right(game, game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_left(game, game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		key_rotation(game->player, -game->rotspeed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		key_rotation(game->player, game->rotspeed);
	main_loop(game);
}
