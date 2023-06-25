/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:09:00 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/04/25 15:44:34 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/mandatory/cub3d.h"

int	ft_is_identifier(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == 'F' || c == 'C')
		return (1);
	return (0);
}

void	ft_is_valid_texture(char *line, t_parser **parser)
{
	if (line[0] == 'N' && line[1] == 'O')
		ft_test_texture(&line[2], parser, 0);
	else if (line[0] == 'S' && line[1] == 'O')
		ft_test_texture(&line[2], parser, 1);
	else if (line[0] == 'E' && line[1] == 'A')
		ft_test_texture(&line[2], parser, 2);
	else if (line[0] == 'W' && line[1] == 'E')
		ft_test_texture(&line[2], parser, 3);
	else
	{
		free_parser(*parser, "Error\nNot a valid identifier\n");
		exit(1);
	}
}

void	initialise_parser(t_parser **parser)
{
	(*parser)->no_texture = NULL;
	(*parser)->so_texture = NULL;
	(*parser)->we_texture = NULL;
	(*parser)->ea_texture = NULL;
	(*parser)->f_color = NULL;
	(*parser)->c_color = NULL;
	(*parser)->map = NULL;
	(*parser)->player = NULL;
}

void	ft_test_multiples_comma(t_parser **parser, char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		while (tmp[i] && ft_isdigit(tmp[i]) == 1)
			i++;
		if ((tmp[i] && (tmp[i] != ',' || (tmp[i] == ',' && tmp[i + 1] \
			&& ft_isdigit(tmp[i + 1]) == 0))) || (tmp[i] && tmp[i] == ','
				&& !tmp[i + 1]))
		{
			free_parser(*parser, "Error\nRGB Color invalid\n");
			free(tmp);
			exit(1);
		}
		if (tmp[i])
			i++;
	}
}
