/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvej <matvej@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:40:57 by matvej            #+#    #+#             */
/*   Updated: 2025/01/08 16:42:17 by matvej           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define imageWIDTH 512
#define imageHEIGHT 512
#define TILE_SIZE 64
#define SQUARE_SIZE 64
#define mapHeight 8
#define mapWidth 8

int map[]=
{
    1,1,1,1,1,1,1,1,
    1,0,1,0,0,0,0,1,
    1,0,1,0,0,0,0,1,
    1,0,1,1,1,0,1,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,1,0,1,
    1,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,
};


void draw_map2D(mlx_image_t *map_image)
{
    uint32_t x;
    uint32_t y;
    uint32_t tx;
    uint32_t ty;
    uint32_t color;

    x = 0;
    y = 0;
    
    ty = 0;

    while (y < mapHeight)
    {
        x = 0;
        while (x < mapWidth)
        {
            //Set Color
            if (map[y * mapWidth + x] == 1)
                color = 0xFFFFFFFF;
            else
                color = 0xFF000000;
            //Draw map
            tx = 0;
            while (tx < TILE_SIZE)
            {
                ty = 0;
                while (ty < TILE_SIZE)
                {
                    mlx_put_pixel(map_image, x * TILE_SIZE + tx, y * TILE_SIZE + ty, color);
                    ty++;
                }
                tx++;
            }
            x++;
        }
        y++;
    }
}

bool check_collision(int x, int y)
{
    int map_x1 = x / TILE_SIZE;
    int map_y1 = y / TILE_SIZE;
    int map_x2 = (x + TILE_SIZE / 2 - 1) / TILE_SIZE;
    int map_y2 = (y + TILE_SIZE / 2 - 1) / TILE_SIZE;

    if (map_x1 < 0 || map_x2 >= mapWidth || map_y1 < 0 || map_y2 >= mapHeight)
        return true;

    return (map[map_y1 * mapWidth + map_x1] == 1 || 
            map[map_y1 * mapWidth + map_x2] == 1 || 
            map[map_y2 * mapWidth + map_x1] == 1 || 
            map[map_y2 * mapWidth + map_x2] == 1);
}
