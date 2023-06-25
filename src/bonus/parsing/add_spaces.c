/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_spaces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:36:01 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/05/04 10:13:22 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/bonus/cub3d.h"

static int	find_longest_line(char **map)
{
	int	i;
	int	pos;
	int	tmp;

	i = 0;
	tmp = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) > tmp)
		{
			tmp = (int)ft_strlen(map[i]);
			pos = i;
		}
		i++;
	}
	return (pos);
}

static char	*add_blank(char *line, int max)
{
	char	*new_line;
	int		i;

	new_line = malloc((max + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	i = 0;
	while (line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	while (i < max)
	{
		new_line[i] = ' ';
		i++;
	}
	new_line[i] = '\0';
	free(line);
	return (new_line);
}

char	**ft_add_spaces(char **map)
{
	int	i;
	int	max;

	max = (int)ft_strlen(map[find_longest_line(map)]);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) == 0 && test_last_line(map, i) == 1)
			return (NULL);
		if ((int)ft_strlen(map[i]) < max)
			map[i] = add_blank(map[i], max);
		i++;
	}
	return (map);
}

static char	**ft_add_8_lines_end(char **map, char **new_map, int i)
{
	int		y;
	int		x;

	y = -1;
	while (map[++y])
	{
		new_map[i] = ft_strdup_spaces(map[y]);
		i++;
	}
	x = i + 4;
	while (i < x)
	{
		new_map[i] = ft_calloc(ft_strlen(map[0]) + 9, sizeof(char));
		if (!new_map[i])
			return (NULL);
		y = -1;
		while (++y < ((int)ft_strlen(map[0]) + 8))
			new_map[i][y] = ' ';
		new_map[i][y] = '\0';
		i++;
	}
	return (new_map);
}

char	**ft_add_8_lines(char **map)
{
	char	**new_map;
	int		i;
	int		y;

	new_map = malloc((ft_count_arg(map) + 9) * sizeof(char *));
	if (!new_map)
		return (NULL);
	new_map[ft_count_arg(map) + 8] = NULL;
	i = -1;
	while (++i < 4)
	{
		new_map[i] = ft_calloc(ft_strlen(map[0]) + 9, sizeof(char));
		if (!new_map[i])
			return (NULL);
		y = -1;
		while (++y < (int)ft_strlen(map[0]) + 8)
			new_map[i][y] = ' ';
	}
	new_map = ft_add_8_lines_end(map, new_map, i);
	free_split(map);
	return (new_map);
}
