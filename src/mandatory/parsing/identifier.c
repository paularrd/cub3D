/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:33:11 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/05/04 10:14:06 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/mandatory/cub3d.h"

static int	ft_is_a_wall(char *line)
{
	int		i;

	if (!line)
		return (1);
	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			i++;
		else if (line[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

static int	ft_test_orientation(char *line, t_parser **parser)
{
	if (line[0] == 'F' || line[0] == 'C')
	{
		ft_is_valid_color(line, parser);
		return (ft_strlen(line));
	}
	else if (line[0] == 'N' || line[0] == 'W'
		|| line[0] == 'S' || line[0] == 'E' )
	{
		ft_is_valid_texture(line, parser);
		return (ft_strlen(line));
	}
	else
	{
		free_parser(*parser, "Error\nNot a valid identifier\n");
		exit(1);
	}
}

static void	ft_test_line(char *line, t_parser **parser)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_is_identifier(line[i]) == 1)
			i += ft_test_orientation(&line[i], parser);
		else if (ft_is_identifier(line[i]) == 0 && line[i] != ' '
			&& line[i] != '\t' && line[i] != '\n')
		{
			free_parser(*parser, "Error\nNot a valid identifier\n");
			exit(1);
		}
		else
			i++;
	}
}

static int	ft_is_all_informations(t_parser **parser)
{
	if ((*parser)->no_texture != NULL && (*parser)->so_texture != NULL
		&& (*parser)->we_texture != NULL && (*parser)->ea_texture != NULL
		&& (*parser)->f_color != NULL && (*parser)->c_color != NULL)
		return (1);
	return (0);
}

char	**ft_test_identifier(char **map, t_parser **parser)
{
	int	i;

	i = 0;
	(*parser)->map = map;
	while (map[i])
	{
		ft_test_line(map[i], parser);
		i++;
		if (ft_is_all_informations(parser) == 1)
			break ;
		else if (ft_is_a_wall(map[i]) == 1)
		{
			free_parser(*parser, "Error\nNot enough identifier\n");
			exit(1);
		}
	}
	return (ft_only_map(map, i));
}
