/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 09:59:56 by mrudloff          #+#    #+#             */
/*   Updated: 2023/04/24 11:47:05 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/mandatory/cub3d.h"

void	key_rotation(t_player *player, double rot)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = player->dir_x;
	player->dir_x = player->dir_x * cos(rot) - player->dir_y * sin(rot);
	player->dir_y = old_dirx * sin(rot) + player->dir_y * cos(rot);
	old_planex = player->plane_x;
	player->plane_x = player->plane_x * cos(rot) - player->plane_y * sin(rot);
	player->plane_y = old_planex * sin(rot) + player->plane_y * cos(rot);
}

void	move_left(t_game *game, t_player *player)
{
	if (!game->map[(int)(player->pos_x - player->plane_x * \
		game->movespeed)][(int)(player->pos_y)] \
		|| game->map[(int)(player->pos_x - player->plane_x * \
		game->movespeed)][(int)(player->pos_y)] == -1)
	{
		player->pos_x -= player->plane_x * game->movespeed;
	}
	if (!game->map[(int)(player->pos_x)][(int)(player->pos_y - \
		player->plane_y * game->movespeed)] \
		|| game->map[(int)(player->pos_x)][(int)(player->pos_y - \
	player->plane_y * game->movespeed)] == -1)
	{
		player->pos_y -= player->plane_y * game->movespeed;
	}
}

void	move_right(t_game *game, t_player *player)
{
	if (!game->map[(int)(player->pos_x + player->plane_x * \
		game->movespeed)][(int)(player->pos_y)] \
		|| game->map[(int)(player->pos_x + player->plane_x * \
		game->movespeed)][(int)(player->pos_y)] == -1)
	{
		player->pos_x += player->plane_x * game->movespeed;
	}
	if (!game->map[(int)(player->pos_x)][(int)(player->pos_y + \
		player->plane_y * game->movespeed)] \
		|| game->map[(int)(player->pos_x)][(int)(player->pos_y + \
		player->plane_y * game->movespeed)] == -1)
	{
		player->pos_y += player->plane_y * game->movespeed;
	}
}

void	move_forward(t_game	*game, t_player *player)
{
	if (!game->map[(int)(player->pos_x + player->dir_x * \
		game->movespeed)][(int)(player->pos_y)] \
		|| game->map[(int)(player->pos_x + player->dir_x * \
		game->movespeed)][(int)(player->pos_y)] == -1)
		player->pos_x += player->dir_x * game->movespeed;
	if (!game->map[(int)(player->pos_x)][(int)(player->pos_y + \
		player->dir_y * game->movespeed)] \
		|| game->map[(int)(player->pos_x)][(int)(player->pos_y + \
		player->dir_y * game->movespeed)] == -1)
		player->pos_y += player->dir_y * game->movespeed;
}

void	move_backward(t_game *game, t_player *player)
{
	if (!game->map[(int)(player->pos_x - player->dir_x * \
		game->movespeed)][(int)(player->pos_y)] \
		|| game->map[(int)(player->pos_x - player->dir_x * \
		game->movespeed)][(int)(player->pos_y)] == -1)
		player->pos_x -= player->dir_x * game->movespeed;
	if (!game->map[(int)(player->pos_x)][(int)(player->pos_y - \
		player->dir_y * game->movespeed)] \
		|| game->map[(int)(player->pos_x)][(int)(player->pos_y - \
		player->dir_y * game->movespeed)] == -1)
		player->pos_y -= player->dir_y * game->movespeed;
}
