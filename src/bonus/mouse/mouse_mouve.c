/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_mouve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:30:53 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/05/04 10:39:16 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/bonus/cub3d.h"

static void	change_angle(t_mlx *mlx, int x)
{
	if (x < 920 / 2)
	{
		while (x < 920 / 2)
		{
			key_left(mlx);
			x += 70;
		}
	}
	else if (x > 920 / 2)
	{
		while (x > 920 / 2)
		{
			key_right(mlx);
			x -= 70;
		}
	}
}

void	mouse_mouvements(void *ml)
{
	int		x;
	int		y;
	t_mlx	*mlx;

	mlx = ml;
	mlx_get_mouse_pos(mlx->mlx, &x, &y);
	if (x != 920 && y != 540)
	{
		change_angle(mlx, x);
		mlx_set_mouse_pos(mlx->mlx, 920 / 2, 540 / 2);
		main_loop(mlx);
	}
}
