/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvej <matvej@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:31:32 by wdegraf           #+#    #+#             */
/*   Updated: 2025/01/08 16:20:18 by matvej           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libft/libft.h>

# include <MLX42/include/MLX42/MLX42.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define WIDTH 512
# define HEIGHT 512
# define TILE_SIZE 64
# define SQUARE_SIZE 64

typedef struct s_texture
{
	mlx_image_t		*img;
	int				width;
	int				height;
}					t_texture;

typedef struct s_vector
{
	double			x;
	double			y;
}					t_vector;

typedef struct s_char
{
	t_vector		pos;
	t_vector		dir;
	t_vector		plane;
}					t_char;

typedef struct s_cub3d
{
	mlx_t			*mlx;
	mlx_image_t		*img;

}					t_c;

//draw_map.c
void draw_map2D(mlx_image_t *map_image);
bool check_collision(int x, int y);

#endif