/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:05:35 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/04/26 13:44:28 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/bonus/cub3d.h"

void	main_loop(void *mlx)
{
	t_mlx	*render;

	render = mlx;
	rendering(render, render->ray, render->player);
	minimap(render);
}

int	main(int argc, char **argv)
{
	t_parser	*parser;

	if (argc != 2)
	{
		ft_fprintf(2, "Error\nInvalid argument\n");
		return (1);
	}
	parser = ft_test_arg(argv[1]);
	parser->old_map = NULL;
	initialize_ray(parser);
}
