/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_orientation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:25:45 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/04/24 12:33:46 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/bonus/cub3d.h"

static void	orientation_east_south(t_mlx *game, t_parser *parser)
{
	if (parser->direction == 'E')
	{
		game->player->dir_x = 0.0;
		game->player->dir_y = 1.0;
		game->player->plane_x = 0.66;
		game->player->plane_y = 0.0;
	}
	if (parser->direction == 'S')
	{
		game->player->dir_x = 1.0;
		game->player->dir_y = 0.0;
		game->player->plane_x = 0.00;
		game->player->plane_y = -0.66;
	}
}

void	get_orientation(t_mlx *game, t_parser *parser)
{
	if (parser->direction == 'N')
	{
		game->player->dir_x = -1.0;
		game->player->dir_y = 0.0;
		game->player->plane_x = 0.00;
		game->player->plane_y = 0.66;
	}
	if (parser->direction == 'W')
	{
		game->player->dir_x = 0.0;
		game->player->dir_y = -1.0;
		game->player->plane_x = -0.66;
		game->player->plane_y = 0.0;
	}
	orientation_east_south(game, parser);
	game->buff = 0;
}
