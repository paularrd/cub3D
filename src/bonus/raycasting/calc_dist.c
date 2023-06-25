/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:33:50 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/04/24 12:33:28 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/bonus/cub3d.h"

static void	get_ray_dir(t_raycast *ray, double x_pos, double y_pos)
{
	if (ray->x_raydir < 0)
	{
		ray->x_step = -1;
		ray->x_side_dist = (x_pos - ray->x_pos_map) * ray->x_delta;
	}
	else
	{
		ray->x_step = 1;
		ray->x_side_dist = (ray->x_pos_map + 1.0 - x_pos) * ray->x_delta;
	}
	if (ray->y_raydir < 0)
	{
		ray->y_step = -1;
		ray->y_side_dist = (y_pos - ray->y_pos_map) * ray->y_delta;
	}
	else
	{
		ray->y_step = 1;
		ray->y_side_dist = (ray->y_pos_map + 1.0 - y_pos) * ray->y_delta;
	}
}

static void	ft_calc_dist(t_raycast *ray, double x_pos, double y_pos)
{
	get_ray_dir(ray, x_pos, y_pos);
	while (ray->wall_hit == 0)
	{
		if (ray->x_side_dist < ray->y_side_dist)
		{
			ray->x_side_dist += ray->x_delta;
			ray->x_pos_map += ray->x_step;
			ray->side_hit = 0;
		}
		else
		{
			ray->y_side_dist += ray->y_delta;
			ray->y_pos_map += ray->y_step;
			ray->side_hit = 1;
		}
		if (ray->map[ray->x_pos_map][ray->y_pos_map] > 0)
			ray->wall_hit = 1;
	}
}

void	ft_raycast(t_raycast *ray, t_player *play, int x)
{
	ray->cam = 2 * x / (double)WIDTH - 1;
	ray->x_raydir = play->dir_x + play->plane_x * ray->cam;
	ray->y_raydir = play->dir_y + play->plane_y * ray->cam;
	ray->x_pos_map = (int)play->pos_x;
	ray->y_pos_map = (int)play->pos_y;
	ray->x_delta = fabs(1 / ray->x_raydir);
	ray->y_delta = fabs(1 / ray->y_raydir);
	ray->wall_hit = 0;
	ft_calc_dist(ray, play->pos_x, play->pos_y);
	if (ray->side_hit == 0)
	{
		ray->wall_dist = ray->x_pos_map - play->pos_x + (1 - ray->x_step) * 0.5;
		ray->wall_dist /= ray->x_raydir;
	}
	else
	{
		ray->wall_dist = ray->y_pos_map - play->pos_y + (1 - ray->y_step) * 0.5;
		ray->wall_dist /= ray->y_raydir;
	}
}
