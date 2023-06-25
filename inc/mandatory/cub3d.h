/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:38:28 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/05/04 09:57:53 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/includes/libft.h"
# include "../libs/minilibx-linux/include/MLX42/MLX42.h"
# include "./player.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

/************************************STRUCT*********************************/

struct	s_mlx;

typedef struct s_parser
{
	char			direction;
	char			*no_texture;
	char			*so_texture;
	char			*we_texture;
	char			*ea_texture;
	char			**f_color;
	char			**c_color;
	unsigned int	f_color_uint;
	unsigned int	c_color_uint;
	char			**map;
	char			**old_map;
	t_player		*player;
}				t_parser;

typedef struct s_game
{
	mlx_t			*mlx;
	int				**map;

	int				buff;
	int				**texture;

	double			rotspeed;
	double			movespeed;

	mlx_texture_t	**texture_mlx;
	t_player		*player;
	mlx_image_t		*img;
	t_raycast		*ray;
	t_parser		*parser;
}				t_game;

/************************************PARSING********************************/

void			ft_test_wall(t_parser **parser);
void			initialise_parser(t_parser **parser);
void			ft_is_valid_color(char *line, t_parser **parser);
void			ft_is_valid_texture(char *line, t_parser **parser);
void			free_parser(t_parser *parser, char *error_message);
void			ft_test_multiples_comma(t_parser **parser, char *tmp);
void			ft_test_texture(char *line, t_parser **parser, int game);

int				ft_is_identifier(char c);
int				test_last_line(char **map, int i);

uint32_t		get_color_f_c(char **color);

char			**get_map(char *arg);
char			**ft_add_spaces(char **map);
char			**ft_add_8_lines(char **map);
char			*ft_strdup_spaces(char *line);
char			**ft_only_map(char **map, int i);
char			**ft_test_identifier(char **map, t_parser **parser);

t_parser		*ft_test_arg(char *arg);
t_parser		*ft_test_map(char **map);

/************************************WINDOWS********************************/

void			main_loop(void *render);
int				close_program(t_game *game);

/**************************************MOVE**********************************/

void			key_press(void *mlx);
void			key_left(t_game *game);
void			key_right(t_game *game);
void			get_orientation(t_game *game, t_parser *parser);
void			key_rotation(t_player *player, double rot);
void			move_left(t_game *game, t_player *player);
void			move_right(t_game *game, t_player *player);
void			move_forward(t_game *game, t_player *player);
void			move_backward(t_game *game, t_player *player);

/***********************************RAYCASTING*********************************/

void			initialize_ray(t_parser *parser);
void			ft_calc_dist(t_raycast *ray, double x_pos, double y_pos);
void			rendering(t_game *render, t_raycast *ray, t_player *player);

unsigned int	get_color(mlx_texture_t *tex, int y, int coord, double step);

/***********************************TEXTURE*********************************/

void			load_texture(t_game *game);

#endif
