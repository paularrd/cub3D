/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:53:44 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/05/04 10:53:16 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/mandatory/cub3d.h"

static void	ft_add_color(char *tmp, t_parser **parser, char c)
{
	if (c == 'F')
	{
		if ((*parser)->f_color)
		{
			free_parser(*parser, "Error\nTwo identifier F\n");
			free(tmp);
			exit(1);
		}
		(*parser)->f_color = ft_split(tmp, ',');
		(*parser)->f_color_uint = get_color_f_c((*parser)->f_color);
	}
	else if (c == 'C')
	{
		if ((*parser)->c_color)
		{
			free_parser(*parser, "Error\nTwo identifier C\n");
			free(tmp);
			exit(1);
		}
		(*parser)->c_color = ft_split(tmp, ',');
		(*parser)->c_color_uint = get_color_f_c((*parser)->c_color);
	}
}

static void	ft_test_color(char *line, t_parser **parser, char c)
{
	int		i;
	char	*tmp;
	char	**split;

	tmp = ft_strtrim(line, " \t\n");
	ft_test_multiples_comma(parser, tmp);
	split = ft_split(tmp, ',');
	i = 0;
	while (split && split[i])
	{
		if (ft_atoi(split[i]) < 0 || ft_atoi(split[i]) > 255 || i > 2)
		{
			free_parser(*parser, "Error\nRGB color no-valid\n");
			free_split(split);
			free(tmp);
			exit(1);
		}
		i++;
	}
	free_split(split);
	ft_add_color(tmp, parser, c);
	free(tmp);
}

void	ft_is_valid_color(char *line, t_parser **parser)
{
	int	i;

	i = 1;
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 1)
		{
			ft_test_color(&line[i], parser, line[0]);
			break ;
		}
		else if (line[i] == ' ' || line[i] == '\t')
			i++;
		else
		{
			free_parser(*parser, "Error\nInvalid identifier\n");
			exit(1);
		}
	}
}

char	**ft_only_map(char **map, int i)
{
	char	**only_map;
	char	*tmp;
	int		y;

	while (map[i][0] == '\n')
		i++;
	y = i;
	while (map[i])
		i++;
	only_map = malloc((i - y + 1) * sizeof(char *));
	if (!only_map)
		return (NULL);
	i = 0;
	while (map[y])
	{
		tmp = ft_strtrim(map[y], "\n");
		only_map[i] = ft_strdup(tmp);
		free(tmp);
		i++;
		y++;
	}
	only_map[i] = NULL;
	free_split(map);
	return (only_map);
}

t_parser	*ft_test_map(char **map)
{
	t_parser	*parser;

	parser = malloc(1 * sizeof(t_parser));
	if (!parser)
		return (NULL);
	initialise_parser(&parser);
	map = ft_test_identifier(map, &parser);
	parser->map = ft_add_spaces(map);
	if (!parser->map)
	{
		free_parser(parser, "Error\nOne line of map is invalid\n");
		free_split(map);
		exit(1);
	}
	ft_test_wall(&parser);
	parser->map = ft_add_8_lines(map);
	return (parser);
}
