/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_arrow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:34:10 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/04/24 12:33:30 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/bonus/cub3d.h"

void	key_right(t_mlx *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->player->dir_x;
	info->player->dir_x = info->player->dir_x * cos(-info->rotspeed) - \
		info->player->dir_y * sin(-info->rotspeed);
	info->player->dir_y = old_dir_x * sin(-info->rotspeed) + \
		info->player->dir_y * cos(-info->rotspeed);
	old_plane_x = info->player->plane_x;
	info->player->plane_x = info->player->plane_x * cos(-info->rotspeed) - \
		info->player->plane_y * sin(-info->rotspeed);
	info->player->plane_y = old_plane_x * sin(-info->rotspeed) + \
		info->player->plane_y * cos(-info->rotspeed);
}

void	key_left(t_mlx *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->player->dir_x;
	info->player->dir_x = info->player->dir_x * cos(info->rotspeed) - \
		info->player->dir_y * sin(info->rotspeed);
	info->player->dir_y = old_dir_x * sin(info->rotspeed) + \
		info->player->dir_y * cos(info->rotspeed);
	old_plane_x = info->player->plane_x;
	info->player->plane_x = info->player->plane_x * cos(info->rotspeed) - \
		info->player->plane_y * sin(info->rotspeed);
	info->player->plane_y = old_plane_x * sin(info->rotspeed) + \
		info->player->plane_y * cos(info->rotspeed);
}
