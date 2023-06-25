/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:02:37 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/05/03 11:42:53 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/bonus/cub3d.h"

static void	open_door(t_mlx *mlx)
{
	mlx->texture_door[0] = \
		mlx_load_png("rscs/textures/door/door1.png");
	mlx->texture_door[1] = \
		mlx_load_png("rscs/textures/door/door2.png");
	mlx->texture_door[2] = \
		mlx_load_png("rscs/textures/door/door3.png");
	mlx->texture_door[3] = \
		mlx_load_png("rscs/textures/door/door4.png");
	mlx->texture_door[4] = \
		mlx_load_png("rscs/textures/door/door5.png");
	mlx->texture_door[5] = \
		mlx_load_png("rscs/textures/door/door6.png");
}

static void	open_file(t_mlx *mlx)
{
	mlx->texture_animation[0] = \
		mlx_load_png("rscs/textures/wall_break/stone.png");
	mlx->texture_animation[1] = \
		mlx_load_png("rscs/textures/wall_break/stone1.png");
	mlx->texture_animation[2] = \
		mlx_load_png("rscs/textures/wall_break/stone2.png");
	mlx->texture_animation[3] = \
		mlx_load_png("rscs/textures/wall_break/stone3.png");
	mlx->texture_animation[4] = \
		mlx_load_png("rscs/textures/wall_break/stone4.png");
	mlx->texture_animation[5] = \
		mlx_load_png("rscs/textures/wall_break/stone5.png");
	mlx->texture_animation[6] = \
		mlx_load_png("rscs/textures/wall_break/stone6.png");
	mlx->texture_animation[7] = \
		mlx_load_png("rscs/textures/wall_break/stone7.png");
	mlx->texture_animation[8] = \
		mlx_load_png("rscs/textures/wall_break/stone8.png");
	mlx->texture_animation[9] = \
		mlx_load_png("rscs/textures/wall_break/stone9.png");
	mlx->texture_animation[10] = \
		mlx_load_png("rscs/textures/wall_break/stone10.png");
}

void	open_texture_animation(t_mlx *mlx)
{
	int		i;

	open_file(mlx);
	open_door(mlx);
	mlx->anim_door = 0;
	i = -1;
	while (++i < 11)
	{
		if (!mlx->texture_animation[i])
		{
			close_program(mlx);
		}
	}
	i = -1;
	while (++i < 6)
	{
		if (!mlx->texture_door[i])
		{
			close_program(mlx);
		}
	}
}
