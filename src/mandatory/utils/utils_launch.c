/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_launch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:38:04 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/05/04 10:14:18 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/mandatory/cub3d.h"

static int	**get_map_int(char **map)
{
	int		**map_int;
	int		x;
	int		y;

	map_int = malloc(ft_count_arg(map) * sizeof(int *));
	if (!map_int)
		return (NULL);
	x = -1;
	while (map[++x])
	{
		map_int[x] = malloc(ft_strlen(map[x]) * sizeof(int));
		if (!map_int[x])
			return (NULL);
		y = -1;
		while (map[x][++y])
		{
			if (map[x][y] == 'N' || map[x][y] == 'S' \
				|| map[x][y] == 'E' || map[x][y] == 'W' || map[x][y] == ' ')
				map_int[x][y] = 0;
			else
				map_int[x][y] = map[x][y] - '0';
		}
	}
	return (map_int);
}

static void	get_player_pos(t_game **game, char **map)
{
	int		x;
	int		y;

	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (map[x][y] == 'N' || map[x][y] == 'W' \
				|| map[x][y] == 'E' || map[x][y] == 'S')
			{
				(*game)->player->pos_x = (float)x + 0.49f;
				(*game)->player->pos_y = (float)y + 0.49f;
				return ;
			}
		}
	}
}

static t_game	*initialize_mlx(t_parser *parser)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->ray = NULL;
	game->parser = parser;
	game->map = NULL;
	game->map = get_map_int(parser->map);
	load_texture(game);
	game->player = ft_calloc(1, sizeof(t_player));
	if (!game->player)
		return (NULL);
	game->parser->player = game->player;
	get_orientation(game, parser);
	game->mlx = mlx_init(WIDTH, HEIGHT, "CreuseFabrik", 0);
	if (!game->mlx)
	{
		ft_fprintf(2, "Error\nNo graphic environment\n");
		close_program(game);
	}
	game->img = mlx_new_image(game->mlx, HEIGHT, WIDTH);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	return (game);
}

void	initialize_ray(t_parser *parser)
{
	t_game	*game;

	game = initialize_mlx(parser);
	get_player_pos(&game, parser->map);
	game->ray = ft_calloc(1, sizeof(t_raycast));
	if (!game->ray)
		return ;
	game->ray->map = game->map;
	game->movespeed = 0.1;
	game->rotspeed = 0.025;
	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_loop_hook(game->mlx, &key_press, game);
	mlx_loop(game->mlx);
	close_program(game);
}
