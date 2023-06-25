/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:39:54 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/04/24 11:46:36 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/mandatory/cub3d.h"

static char	**ft_add_line(char **map, char *line)
{
	int		i;
	char	**new_map;

	if (!map)
	{
		new_map = malloc(2 * sizeof(char *));
		if (!new_map)
			return (NULL);
		new_map[0] = ft_strdup(line);
		new_map[1] = NULL;
		return (new_map);
	}
	new_map = malloc((ft_count_arg(map) + 2) * sizeof(char *));
	if (!new_map)
		return (NULL);
	i = -1;
	while (map[++i])
		new_map[i] = ft_strdup(map[i]);
	new_map[i] = ft_strdup(line);
	new_map[i + 1] = NULL;
	free_split(map);
	return (new_map);
}

static char	**read_map(int fd_map)
{
	char	*line;
	char	**map;

	line = ft_strdup("");
	map = NULL;
	while (line)
	{
		free(line);
		line = get_next_line(fd_map);
		map = ft_add_line(map, line);
	}
	return (map);
}

char	**get_map(char *arg)
{
	char	**map;
	char	test[1];
	int		fd_map;

	fd_map = open(arg, O_RDONLY);
	if (fd_map < 0)
	{
		ft_fprintf(2, "Error\nFile do not open\n");
		exit(1);
	}
	else if (read(fd_map, test, 1) <= 0)
	{
		ft_fprintf(2, "Error\nFile is empty\n");
		close(fd_map);
		exit(1);
	}
	close(fd_map);
	fd_map = open(arg, O_RDONLY);
	map = read_map(fd_map);
	close(fd_map);
	return (map);
}
