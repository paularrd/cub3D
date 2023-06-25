/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:21:03 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/04/26 13:54:29 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/mandatory/cub3d.h"

static int	is_char_player(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	return (1);
}

static void	ft_test_zero(t_parser **parser, char **map, int x, int y)
{
	int	test;

	test = 0;
	if (!map[x + 1] || !map[x + 1][y] || is_char_player(map[x + 1][y]) == 1)
		test = 1;
	if ((x - 1 < 0 || !map[x - 1] || !map[x - 1][y]
		|| is_char_player(map[x - 1][y]) == 1))
		test = 1;
	if (map[x][y + 1] == '\0' || is_char_player(map[x][y + 1]) == 1)
		test = 1;
	if ((y - 1 < 0 || map[x][y - 1] == '\0'
		|| is_char_player(map[x][y - 1]) == 1))
		test = 1;
	if (test == 1)
	{
		free_split(map);
		free_parser(*parser, "Error\nMap is no valid\n");
		exit (1);
	}
}

static void	test_multiples_start(t_parser **parser, int test)
{
	if (test > 1)
	{
		free_parser(*parser, "Error\nToo many start position\n");
		exit(1);
	}
	else if (test < 1)
	{
		free_parser(*parser, "Error\nNo start position\n");
		exit(1);
	}
}

void	ft_test_wall(t_parser **parser)
{
	int		x;
	int		y;
	int		test;
	char	**map;

	map = ft_strdup_split((*parser)->map);
	x = -1;
	test = 0;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (map[x][y] == '0')
				ft_test_zero(parser, map, x, y);
			else if (map[x][y] != '1' && is_char_player(map[x][y]) == 0)
			{
				ft_test_zero(parser, map, x, y);
				test++;
				(*parser)->direction = map[x][y];
			}
		}
	}
	free_split(map);
	test_multiples_start(parser, test);
}
