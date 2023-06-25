/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:34:24 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/04/24 12:32:57 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/bonus/cub3d.h"

static void	put_block(t_mlx *mlx, int x, int y, char c)
{
	int		i;
	int		j;

	i = y - 1;
	while (++i < y + 20)
	{
		j = x - 1;
		while (++j < x + 20)
		{
			if (c == '2')
				mlx_put_pixel(mlx->img, j, i, 0x696969);
			else if (c == '1')
				mlx_put_pixel(mlx->img, j, i, 0);
			else
				mlx_put_pixel(mlx->img, j, i, 255);
		}
	}
}

static void	store_old_minimap(t_mlx *mlx, char **minimap)
{
	if (mlx->parser->old_map)
	{
		free_split(mlx->parser->old_map);
		mlx->parser->old_map = ft_strdup_split(minimap);
	}
	else
		mlx->parser->old_map = ft_strdup_split(minimap);
	free_split(minimap);
}

static void	put_minimap(t_mlx *mlx)
{
	char	**minimap;
	int		x;
	int		y;
	int		tmp1;
	int		tmp2;

	minimap = cpy_minimap(mlx);
	y = -1;
	while (minimap[++y])
	{
		x = -1;
		while (minimap[y][++x])
		{
			tmp1 = x + 20;
			if (x > 0)
				tmp1 += x * 18;
			tmp2 = y + 20;
			if (y > 0)
				tmp2 += y * 18;
			put_block(mlx, tmp1, tmp2, minimap[y][x]);
		}
	}
	store_old_minimap(mlx, minimap);
}

static void	put_outline(t_mlx *mlx)
{
	int		x;
	int		y;

	y = 18;
	x = 18;
	while (++x < 192)
		mlx_put_pixel(mlx->img, x, y, 0xFF0000FF);
	while (++y < 192)
		mlx_put_pixel(mlx->img, x, y, 0xFF0000FF);
	while (--x > 18)
		mlx_put_pixel(mlx->img, x, y, 0xFF0000FF);
	while (--y > 18)
		mlx_put_pixel(mlx->img, x, y, 0xFF0000FF);
}

void	minimap(t_mlx *mlx)
{
	int		x;
	int		y;

	put_outline(mlx);
	put_minimap(mlx);
	y = 102;
	while (++y < 108)
	{
		x = 102;
		while (++x < 108)
			mlx_put_pixel(mlx->img, x, y, 0xFF0000FF);
	}
}
