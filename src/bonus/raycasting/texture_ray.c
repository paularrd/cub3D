/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:58:07 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/05/04 16:13:53 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/bonus/cub3d.h"

mlx_texture_t	*get_door(t_mlx *mlx)
{
	mlx->anim_door++;
	if (mlx->anim_door < 10000)
		return (mlx->texture_door[0]);
	if (mlx->anim_door < 20000)
		return (mlx->texture_door[1]);
	if (mlx->anim_door < 30000)
		return (mlx->texture_door[2]);
	if (mlx->anim_door < 40000)
		return (mlx->texture_door[3]);
	if (mlx->anim_door < 50000)
		return (mlx->texture_door[4]);
	if (mlx->anim_door < 60000)
		return (mlx->texture_door[5]);
	else
		mlx->anim_door = 0;
	return (mlx->texture_door[0]);
}

void	load_texture(t_mlx *game)
{
	game->texture_mlx = ft_calloc(4, sizeof(mlx_texture_t));
	if (!game->texture_mlx)
		return ;
	game->texture_mlx[0] = mlx_load_png(game->parser->no_texture);
	if (!game->texture_mlx[0])
		close_program(game);
	game->texture_mlx[1] = mlx_load_png(game->parser->so_texture);
	if (!game->texture_mlx[1])
		close_program(game);
	game->texture_mlx[2] = mlx_load_png(game->parser->ea_texture);
	if (!game->texture_mlx[2])
		close_program(game);
	game->texture_mlx[3] = mlx_load_png(game->parser->we_texture);
	if (!game->texture_mlx[3])
		close_program(game);
}

unsigned int	get_color(mlx_texture_t *tex, int y, int coord, double step)
{
	unsigned int	color;
	int				pxl;

	(void)step;
	color = 0;
	pxl = 4 * (tex->height * (int)(y * step) + coord);
	color = (tex->pixels[pxl] << 24 | tex->pixels[pxl + 1] << 16 \
		| tex->pixels[pxl + 2] << 8 | tex->pixels[pxl + 3]);
	return (color);
}
