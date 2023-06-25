/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:49:05 by mrudloff          #+#    #+#             */
/*   Updated: 2023/04/13 15:27:05 by mrudloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define WIDTH	1000
# define HEIGHT 1000

typedef struct s_raycast
{
	int		**map;

	double	x_raydir;
	double	y_raydir;
	double	x_side_dist;
	double	y_side_dist;

	double	x_delta;
	double	y_delta;
	double	wall_dist;

	int		x_step;
	int		y_step;

	int		x_pos_map;
	int		y_pos_map;

	int		wall_hit;
	int		side_hit;

	double	cam;
}				t_raycast;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;

	double	dir_x;
	double	dir_y;

	double	plane_x;
	double	plane_y;
}				t_player;

typedef struct s_texture
{
	mlx_texture_t	*texture;

	int				line_height;
	int				begin_draw;
	int				end_draw;
	int				num_texture;
	int				x_texture;
	int				y_texture;
	int				color;

	double			wall_x;
	double			step;
	double			pos_texture;
}				t_texture;

#endif
