/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:58:07 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/05/04 16:12:24 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/mandatory/cub3d.h"

void	load_texture(t_game *game)
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

	color = 0;
	pxl = 4 * (tex->height * (int)(y * step) + coord);
	color = (tex->pixels[pxl] << 24 | tex->pixels[pxl + 1] << 16 \
			| tex->pixels[pxl + 2] << 8 | tex->pixels[pxl + 3]);
	return (color);
}
