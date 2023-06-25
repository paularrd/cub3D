/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_spaces_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:25:29 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/05/04 10:13:51 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/mandatory/cub3d.h"

char	*ft_strdup_spaces(char *line)
{
	char	*new_line;
	int		i;
	int		y;

	new_line = malloc((ft_strlen(line) + 9) * sizeof(char));
	if (!new_line)
		return (NULL);
	i = -1;
	while (++i < 4)
		new_line[i] = ' ';
	y = -1;
	while (++y < (int)ft_strlen(line))
	{
		new_line[i] = line[y];
		i++;
	}
	y = i + 4;
	while (i < y)
	{
		new_line[i] = ' ';
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

int	test_last_line(char **map, int i)
{
	while (map[i] && ft_strlen(map[i]) == 0)
		i++;
	if (!map[i])
		return (0);
	return (1);
}
