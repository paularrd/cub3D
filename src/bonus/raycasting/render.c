/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:48:59 by mrudloff          #+#    #+#             */
/*   Updated: 2023/05/04 16:14:46 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/bonus/cub3d.h"

static void	get_texture(t_mlx *mlx, t_texture *tex, t_raycast *ray,
t_player *player)
{
	if (ray->side_hit == 0)
	{
		if (player->pos_x > ray->x_pos_map)
			tex->texture = mlx->texture_mlx[1];
		else
			tex->texture = mlx->texture_mlx[0];
		if (tex->num_texture == 2)
			tex->texture = mlx->texture_animation[mlx->anim];
		if (tex->num_texture == 3)
			tex->texture = get_door(mlx);
		tex->wall_x = player->pos_y + ray->wall_dist * ray->y_raydir;
	}
	else
	{
		if (player->pos_y > ray->y_pos_map)
			tex->texture = mlx->texture_mlx[2];
		else
			tex->texture = mlx->texture_mlx[3];
		if (tex->num_texture == 2)
			tex->texture = mlx->texture_animation[mlx->anim];
		if (tex->num_texture == 3)
			tex->texture = get_door(mlx);
		tex->wall_x = player->pos_x + ray->wall_dist * ray->x_raydir;
	}
}

static void	calc_render_2(t_texture *tex, t_raycast *ray)
{
	tex->wall_x -= floor(tex->wall_x);
	tex->x_texture = (int)(tex->wall_x * (double)tex->texture->height);
	if (ray->side_hit == 0 && ray->x_raydir > 0)
		tex->x_texture = tex->texture->height - tex->x_texture - 1;
	if (ray->side_hit == 1 && ray->y_raydir < 0)
		tex->x_texture = tex->texture->height - tex->x_texture - 1;
	if (tex->texture->height > tex->texture->width)
		tex->step = 1.0 * tex->texture->width / tex->line_height;
	else if (tex->texture->height < tex->texture->width)
		tex->step = 1.0 * tex->texture->width / tex->line_height;
	else
		tex->step = 1.0 * tex->texture->width / tex->line_height;
	tex->pos_texture = tex->begin_draw - HEIGHT * 0.5 + tex->line_height * 0.5;
	tex->pos_texture *= tex->step;
}

static void	calc_render(t_mlx *mlx, t_texture *tex, t_raycast *ray,
t_player *player)
{
	tex->line_height = (int)(HEIGHT / ray->wall_dist);
	tex->begin_draw = -tex->line_height * 0.5 + HEIGHT * 0.5;
	tex->end_draw = tex->line_height * 0.5 + HEIGHT * 0.5;
	if (tex->begin_draw < 0)
		tex->begin_draw = 0;
	if (tex->end_draw >= HEIGHT)
		tex->end_draw = HEIGHT - 1;
	tex->num_texture = ray->map[ray->x_pos_map][ray->y_pos_map];
	get_texture(mlx, tex, ray, player);
	calc_render_2(tex, ray);
}

static void	rendering_pixel(t_mlx *render, t_texture *tex, int x)
{
	int		y;
	int		i;

	y = tex->begin_draw;
	i = 0;
	while (i < y)
	{
		if (x > 925 && x < 975 && i > 25 && i < 75)
			mlx_put_pixel(render->img, x, i++, 4294902015);
		else
			mlx_put_pixel(render->img, x, i++, render->parser->c_color_uint);
	}
	while (y < tex->end_draw)
	{
		while (y < 0)
			y++;
		tex->begin_draw = -tex->line_height * 0.5 + HEIGHT * 0.5;
		mlx_put_pixel(render->img, x, y, get_color(tex->texture, \
			y - tex->begin_draw, tex->x_texture, tex->step));
		y++;
	}
	while (y < HEIGHT && tex->begin_draw > 0)
		mlx_put_pixel(render->img, x, y++, render->parser->f_color_uint);
}

void	rendering(t_mlx *render, t_raycast *ray, t_player *player)
{
	int			x;
	t_texture	*tex;

	tex = malloc(sizeof(t_texture));
	if (!tex)
		return ;
	x = 0;
	while (x < WIDTH)
	{
		ft_raycast(ray, player, x);
		calc_render(render, tex, ray, player);
		rendering_pixel(render, tex, x);
		x++;
	}
	free(tex);
}
