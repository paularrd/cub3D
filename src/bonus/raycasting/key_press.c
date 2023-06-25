/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:49:01 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/05/04 10:22:38 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/bonus/cub3d.h"

static void	key_w(t_mlx	*info)
{
	if (!info->map[(int)(info->player->pos_x + info->player->dir_x * \
		info->movespeed)][(int)(info->player->pos_y)] \
		|| info->map[(int)(info->player->pos_x + info->player->dir_x * \
		info->movespeed)][(int)(info->player->pos_y)] < 0)
		info->player->pos_x += info->player->dir_x * info->movespeed;
	if (!info->map[(int)(info->player->pos_x)][(int)(info->player->pos_y + \
		info->player->dir_y * info->movespeed)] \
		|| info->map[(int)(info->player->pos_x)][(int)(info->player->pos_y + \
		info->player->dir_y * info->movespeed)] < 0)
		info->player->pos_y += info->player->dir_y * info->movespeed;
}

static void	key_s(t_mlx	*info)
{
	if (!info->map[(int)(info->player->pos_x - info->player->dir_x * \
		info->movespeed)][(int)(info->player->pos_y)] \
		|| info->map[(int)(info->player->pos_x - info->player->dir_x * \
		info->movespeed)][(int)(info->player->pos_y)] < 0)
		info->player->pos_x -= info->player->dir_x * info->movespeed;
	if (!info->map[(int)(info->player->pos_x)][(int)(info->player->pos_y - \
		info->player->dir_y * info->movespeed)] \
		|| info->map[(int)(info->player->pos_x)][(int)(info->player->pos_y - \
		info->player->dir_y * info->movespeed)] < 0)
		info->player->pos_y -= info->player->dir_y * info->movespeed;
}

static void	move_right(t_mlx *info, t_player *player)
{
	if (!info->map[(int)(player->pos_x + player->plane_x * \
		info->movespeed)][(int)(player->pos_y)] \
		|| info->map[(int)(player->pos_x + player->plane_x * \
		info->movespeed)][(int)(player->pos_y)] < 0)
	{
		player->pos_x += player->plane_x * info->movespeed;
	}
	if (!info->map[(int)(player->pos_x)][(int)(player->pos_y + \
		player->plane_y * info->movespeed)] \
		|| info->map[(int)(player->pos_x)][(int)(player->pos_y + \
		player->plane_y * info->movespeed)] < 0)
	{
		player->pos_y += player->plane_y * info->movespeed;
	}
}

static void	move_left(t_mlx *info, t_player *player)
{
	if (!info->map[(int)(player->pos_x - player->plane_x * \
		info->movespeed)][(int)(player->pos_y)] \
		|| info->map[(int)(player->pos_x - player->plane_x * \
		info->movespeed)][(int)(player->pos_y)] < 0)
	{
		player->pos_x -= player->plane_x * info->movespeed;
	}
	if (!info->map[(int)(player->pos_x)][(int)(player->pos_y - \
		player->plane_y * info->movespeed)] \
		|| info->map[(int)(player->pos_x)][(int)(player->pos_y - \
	player->plane_y * info->movespeed)] < 0)
	{
		player->pos_y -= player->plane_y * info->movespeed;
	}
}

void	key_press(void *mlx)
{
	t_mlx	*info;

	info = mlx;
	if (mlx_is_key_down(info->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(info->mlx);
	if (mlx_is_key_down(info->mlx, MLX_KEY_W))
		key_w(info);
	if (mlx_is_key_down(info->mlx, MLX_KEY_S))
		key_s(info);
	if (mlx_is_key_down(info->mlx, MLX_KEY_D))
		move_right(info, info->player);
	if (mlx_is_key_down(info->mlx, MLX_KEY_A))
		move_left(info, info->player);
	if (mlx_is_key_down(info->mlx, MLX_KEY_RIGHT))
		key_right(info);
	if (mlx_is_key_down(info->mlx, MLX_KEY_LEFT))
		key_left(info);
	main_loop(info);
}
