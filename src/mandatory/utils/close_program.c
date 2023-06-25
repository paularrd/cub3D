/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:11:13 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/04/24 11:46:07 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/mandatory/cub3d.h"

static void	free_texture(t_game *game)
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

static void	free_map_int(t_game *mlx)
{
	int		i;

	i = -1;
	while (mlx->parser->map[++i])
		free(mlx->map[i]);
	free(mlx->map);
}

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

int	close_program(t_game	*mlx)
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
	free_parser(mlx->parser, NULL);
	free(mlx);
	exit(0);
}
