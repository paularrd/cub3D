/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:38:28 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/05/04 10:21:55 by fle-tolg         ###   ########.fr       */
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

typedef struct s_mlx
{
	mlx_t			*mlx;
	int				**map;

	int				buff;
	int				**texture;

	double			rotspeed;
	double			movespeed;

	int				anim;
	int				anim_door;
	mlx_texture_t	*texture_animation[11];
	mlx_texture_t	*texture_door[7];
	mlx_texture_t	**texture_mlx;
	t_player		*player;
	mlx_image_t		*img;
	t_raycast		*ray;
	t_parser		*parser;
}				t_mlx;

/************************************PARSING********************************/

void			ft_test_wall(t_parser **parser);
void			initialise_parser(t_parser **parser);
void			ft_is_valid_color(char *line, t_parser **parser);
void			ft_is_valid_texture(char *line, t_parser **parser);
void			free_parser(t_parser *parser, char *error_message);
void			ft_test_multiples_comma(t_parser **parser, char *tmp);
void			ft_test_texture(char *line, t_parser **parser, int info);

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
int				close_program(t_mlx	*mlx);
void			open_texture_animation(t_mlx *mlx);

/************************************MINIMAP********************************/

void			minimap(t_mlx *mlx);
char			**cpy_minimap(t_mlx *mlx);

/**************************************MOVE**********************************/

void			key_press(void *mlx);
void			key_left(t_mlx *info);
void			key_right(t_mlx *info);
void			mouse_mouvements(void *ml);
void			key_event(mlx_key_data_t key, void *mlx);
void			get_orientation(t_mlx *game, t_parser *parser);

/***********************************RAYCASTING*********************************/

void			initialize_ray(t_parser *parser);
void			ft_raycast(t_raycast *ray, t_player *play, int x);
void			rendering(t_mlx *render, t_raycast *ray, t_player *player);

unsigned int	get_color(mlx_texture_t *tex, int y, int coord, double step);
mlx_texture_t	*get_door(t_mlx *mlx);

/***********************************TEXTURE*********************************/

void			load_texture(t_mlx *info);

#endif
