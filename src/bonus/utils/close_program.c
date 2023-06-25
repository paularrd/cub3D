/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:11:13 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/04/26 13:05:43 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/bonus/cub3d.h"

void	free_parser(t_parser *parser, char *error_message)
{
	if (error_message)
		ft_fprintf(2, "%s", error_message);
	if (parser->c_color != NULL)
		free_split(parser->c_color);
	if (parser->f_color != NULL)
		free_split(parser->f_color);
	if (parser->ea_texture != NULL)
		free(parser->ea_texture);
	if (parser->so_texture != NULL)
		free(parser->so_texture);
	if (parser->we_texture != NULL)
		free(parser->we_texture);
	if (parser->no_texture != NULL)
		free(parser->no_texture);
	if (parser->map != NULL)
		free_split(parser->map);
	if (parser->player != NULL)
		free(parser->player);
	free(parser);
}

static void	free_texture(t_mlx *game)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		if (game->texture_mlx[i])
			mlx_delete_texture(game->texture_mlx[i]);
	}
	free(game->texture_mlx);
}

static void	free_map_int(t_mlx *mlx)
{
	int		i;

	i = -1;
	while (mlx->parser->map[++i])
		free(mlx->map[i]);
	free(mlx->map);
}

static void	free_texture_anim(t_mlx *game)
{
	int		i;

	i = -1;
	while (++i < 11)
	{
		if (game->texture_animation[i])
			mlx_delete_texture(game->texture_animation[i]);
	}
	i = -1;
	while (++i < 6)
	{
		if (game->texture_door[i])
			mlx_delete_texture(game->texture_door[i]);
	}
}

int	close_program(t_mlx	*mlx)
{
	if (mlx->mlx)
	{
		mlx_delete_image(mlx->mlx, mlx->img);
		mlx_terminate(mlx->mlx);
	}
	if (mlx->map)
		free_map_int(mlx);
	if (mlx->ray)
		free(mlx->ray);
	free_texture(mlx);
	free_texture_anim(mlx);
	free_split(mlx->parser->old_map);
	free_parser(mlx->parser, NULL);
	free(mlx);
	exit(0);
}
