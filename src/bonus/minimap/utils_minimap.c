/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:09:52 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/04/24 12:32:59 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/bonus/cub3d.h"

static char	**malloc_minimap(void)
{
	char	**minimap;
	int		i;

	minimap = malloc(10 * sizeof(char *));
	if (!minimap)
		return (NULL);
	minimap[9] = NULL;
	i = -1;
	while (++i < 9)
	{
		minimap[i] = malloc(10 * sizeof(char));
		if (!minimap[i])
			return (NULL);
		minimap[i][9] = '\0';
	}
	return (minimap);
}

char	**cpy_minimap(t_mlx *mlx)
{
	char	**minimap;
	int		x;
	int		y;
	int		x2;
	int		y2;

	minimap = malloc_minimap();
	y = -1;
	y2 = 4;
	while (++y < 9)
	{
		x = -1;
		x2 = 4;
		while (++x < 9)
		{
			minimap[y][x] = mlx->map[(int)mlx->player->pos_x - x2] \
				[(int)mlx->player->pos_y - y2] + '0';
			if (minimap[y][x] != '2' && minimap[y][x] != '1' && \
				minimap[y][x] != '0')
				minimap[y][x] = '0';
			x2--;
		}
		y2--;
	}
	return (minimap);
}
