/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:06:02 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/04/24 12:33:15 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/bonus/cub3d.h"

static void	ft_test_extension(char *arg)
{
	int	size;

	size = (int)ft_strlen(arg);
	if (size < 5 || arg[size - 1] != 'b' || arg[size - 2] != 'u'
		|| arg[size - 3] != 'c' || arg[size - 4] != '.'
		|| arg[size - 5] == '/')
	{
		ft_fprintf(2, "Error\nFile do not end by .cub\n");
		exit(1);
	}
}

t_parser	*ft_test_arg(char *arg)
{
	char		**map;
	t_parser	*parser;

	ft_test_extension(arg);
	map = get_map(arg);
	parser = ft_test_map(map);
	return (parser);
}
