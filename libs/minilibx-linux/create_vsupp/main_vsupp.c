/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vsupp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:56:13 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/04/12 17:05:13 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./include/MLX42/MLX42.h"

int	main()
{
	mlx_t			*m = mlx_init(920, 920, "vsupp", 0);
	mlx_image_t		*i = mlx_new_image(m, 920, 920);
	mlx_texture_t	*t = mlx_load_png("textures/east.png");

	mlx_put_pixel(i, 50, 50, 6353643);
	mlx_delete_texture(t);
	mlx_delete_image(m, i);
	mlx_terminate(m);
}
