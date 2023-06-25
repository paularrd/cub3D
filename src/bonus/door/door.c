/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:02:45 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/04/26 13:11:31 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/bonus/cub3d.h"

static int	door(int **map, int x, int y)
{
	if (map[x][y + 1] == 3)
		map[x][y + 1] = -2;
	else if (map[x][y + 1] == -2)
		map[x][y + 1] = 3;
	if (map[x][y - 1] == 3)
		map[x][y - 1] = -2;
	else if (map[x][y - 1] == -2)
		map[x][y - 1] = 3;
	if (map[x + 1][y] == 3)
		map[x + 1][y] = -2;
	else if (map[x + 1][y] == -2)
		map[x + 1][y] = 3;
	if (map[x - 1][y] == 3)
		map[x - 1][y] = -2;
	else if (map[x - 1][y] == -2)
		map[x - 1][y] = 3;
	return (1);
}

static int	check_is_block(int **map, int x, int y)
{
	if (map[x][y + 1] == 2)
		map[x][y + 1] = -1;
	if (map[x][y - 1] == 2)
		map[x][y - 1] = -1;
	if (map[x + 1][y] == 2)
		map[x + 1][y] = -1;
	if (map[x - 1][y] == 2)
		map[x - 1][y] = -1;
	return (1);
}

static int	check_is_block_to_open(int **map, int x, int y)
{
	if (map[x][y + 1] == 2)
		return (1);
	if (map[x][y - 1] == 2)
		return (1);
	if (map[x + 1][y] == 2)
		return (1);
	if (map[x - 1][y] == 2)
		return (1);
	return (0);
}

static void	block(t_mlx *mlx)
{
	if (mlx->anim == 10)
	{
		check_is_block(mlx->map, (int)mlx->player->pos_x, \
			(int)mlx->player->pos_y);
	}
	if (check_is_block_to_open(mlx->map, (int)mlx->player->pos_x, \
			(int)mlx->player->pos_y) == 1)
	mlx->anim++;
	if (mlx->anim >= 11)
		mlx->anim = 0;
}

void	key_event(mlx_key_data_t key, void *mlx)
{
	t_mlx	*game;

	game = mlx;
	if (key.key == MLX_KEY_E && key.action == MLX_PRESS)
		block(game);
	if (key.key == MLX_KEY_F && key.action == MLX_PRESS)
		door(game->map, (int)game->player->pos_x, \
			(int)game->player->pos_y);
}
