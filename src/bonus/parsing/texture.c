/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:47:52 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/04/24 13:01:35 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/bonus/cub3d.h"

static void	invalid_texture(char *msg, char *tmp, t_parser **parser)
{
	free_parser(*parser, msg);
	free(tmp);
	exit(1);
}

static void	ft_test_ea_we(char *line, t_parser **parser, int info)
{
	if (info == 2)
	{
		if ((*parser)->ea_texture)
			invalid_texture("Error\nTwo identifier EA\n", line, parser);
		(*parser)->ea_texture = ft_strdup(line);
	}
	else if (info == 3)
	{
		if ((*parser)->we_texture)
			invalid_texture("Error\nTwo identifier WE\n", line, parser);
		(*parser)->we_texture = ft_strdup(line);
	}
}

static void	is_a_texture(char *tmp, t_parser **parser)
{
	if (!tmp[0] || !tmp[1])
	{
		free_parser(*parser, "Error\nNot a valid texture\n");
		free(tmp);
		exit(1);
	}
}

void	ft_test_texture(char *line, t_parser **parser, int info)
{
	char	*tmp;

	tmp = ft_strtrim(line, " \n\t");
	is_a_texture(tmp, parser);
	if (info == 0)
	{
		if ((*parser)->no_texture)
			invalid_texture("Error\nTwo identifier NO\n", tmp, parser);
		(*parser)->no_texture = ft_strdup(tmp);
	}
	else if (info == 1)
	{
		if ((*parser)->so_texture)
			invalid_texture("Error\nTwo identifier SO\n", tmp, parser);
		(*parser)->so_texture = ft_strdup(tmp);
	}
	else
		ft_test_ea_we(tmp, parser, info);
	free(tmp);
}

uint32_t	get_color_f_c(char **color)
{
	unsigned int	c;

	c = (ft_atoi(color[0]) << 24 | ft_atoi(color[1]) << 16 \
		| ft_atoi(color[2]) << 8 | 255);
	return (c);
}
