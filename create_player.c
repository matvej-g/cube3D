/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:42:04 by wdegraf           #+#    #+#             */
/*   Updated: 2025/02/17 15:01:00 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	init_angle(char view)
{
	if (view == 'N')
		return (1.5 * PI);
	if (view == 'S')
		return (0.5 * PI);
	if (view == 'W')
		return (0);
	if (view == 'E')
		return (PI);
	return (0);
}


void drawPlayer(t_c *cub)
{
    cub->player.player_img = mlx_new_image(cub->mlx, PLAYER_SIZE, PLAYER_SIZE);
    uint32_t y = 0;
	while (y < PLAYER_SIZE)
	{
		uint32_t x = 0;
		while (x < PLAYER_SIZE)
		{
			mlx_put_pixel(cub->player.player_img, x, y, 0xFF0000FF);
			x++;
		}
		y++;
	}	
}

void	create_player(t_c *cub, int x, int y)
{
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			if (ft_strchr("NSWE", cub->map[y][x]))
			{
				cub->player.pos = (t_vector){x, y};
				cub->player.angle = init_angle(cub->map[y][x]);
				cub->map[y][x] = '0';
				drawPlayer(cub);
				return ;
			}
			x++;
		}
		y++;
	}
	er_ex(*cub, "No player found in map\n");
}

bool	is_wall(t_c *cub, float px, float py)
{
	int	tx;
	int	ty;

	tx = (int)(px / TILE_SIZE);
	ty = (int)(py / TILE_SIZE);
	if (ty < 0 || ty >= cub->map_height
		|| tx < 0 || tx >= cub->map_width)
		return (true);
	return (cub->map[ty][tx] == '1');
}

bool	collision(t_c *cub, float x, float y)
{

	if (is_wall(cub, x, y))
		return (true);
	if (is_wall(cub, x, y + PLAYER_SIZE - 4))
		return (true);
	if (is_wall(cub, x + PLAYER_SIZE - 4, y))
		return (true);
	if (is_wall(cub, x + PLAYER_SIZE - 4, y + PLAYER_SIZE - 4))
		return (true);
	return (false);
}