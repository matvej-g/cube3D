#include "cub3d.h"

float		distance(float x1, float y1, float x2, float y2);
float		fish_eye_fix(t_c *cub, float x1, float y1, float x2, float y2);
uint32_t	get_texture_pixel(t_texture *texture, int x, int y);

bool	is_wall(t_c *cub, float x, float y)
{
	int mapX = (int)(x / TILE_SIZE);
	int mapY = (int)(y / TILE_SIZE);
	printf("is_wall: mapX=%d, mapY=%d\n", mapX, mapY);
	// Validate map bounds to avoid segfault
	if (mapX < 0 || mapY < 0 ||
		mapX >= cub->map_width ||
		mapY >= cub->map_height)
	{
		return (true); // Out of bounds = treat as wall
	}

	return (cub->map[mapY][mapX] == '1');
}


float	draw_line(t_c *cub, float start_angle, int i)
{
	float	cos_angle = cos(start_angle);
	float	sin_angle = sin(start_angle);
	float	ray_x = cub->player.pos.x;
	float	ray_y = cub->player.pos.y;
	//int		hit_cell_x;
	//int		hit_cell_y;
	while (!is_wall(cub, ray_x, ray_y))
	{
		mlx_put_pixel(cub->ray_img, ray_x, ray_y, 0x00FF005E);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
	//hit_cell_x = (int)ray_x / TILE_SIZE;
	//hit_cell_y = (int)ray_y / TILE_SIZE;

	float ray_distance;
	ray_distance = fish_eye_fix(cub, cub->player.pos.x, cub->player.pos.y, ray_x, ray_y);
	float height = (TILE_SIZE / ray_distance) * (WIDTH / 2);
	int start_y = (HEIGHT - height) / 2;
	int end = start_y + height;

	mlx_image_t *texture = NULL;

	float	wallX;
	float	fx = fmod(ray_x, TILE_SIZE);
	float	fy = fmod(ray_y, TILE_SIZE);
	//0 is north texture, 1 SO, 2 WA, 3 EA
	if (fx < 1.0 || fx > (TILE_SIZE - 1.0))
	{
		if (cos_angle > 0)
			texture = cub->texture[3].img;//EAST
		else
			texture = cub->texture[2].img;//WEST
		wallX = fy / TILE_SIZE;
	}
	else
	{
		if (sin_angle > 0)
			texture = cub->texture[1].img;//SOUTH
		else
			texture = cub->texture[0].img;//NORTH
		wallX = fx / TILE_SIZE;
	}

	int tex_x = (int)(wallX * (float)texture->width);
	float	step = (float)texture->height / height;
	float	tex_pos = 0.0;
	int		y;
	y = start_y;
	while(y < end)
	{
		int tex_y = (int)tex_pos & (texture->height - 1);
		//int tex_y = (int)tex_pos % texture->height;

		tex_pos += step;
		int	pixel_index = tex_y * texture->width + tex_x;
		uint32_t color = ((uint32_t *)texture->pixels)[pixel_index];
		color = (color & 0xFFFFFF00) | 0x000000FF;
		mlx_put_pixel(cub->world_img, i, y, color);
		y++;
	}
	return(ray_distance);
}

int	fov_loop(t_c *cub)
{
	float	angle_step = PI / 3 / WIDTH;
	float	start_angle = cub->player.angle - PI / 6;
	int i = 0;
	while (i < WIDTH)
	{
		draw_line(cub, start_angle, i);
		start_angle += angle_step;
		i++;
	}
	return (0);
}

float	distance(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}


float	fish_eye_fix(t_c *cub, float x1, float y1, float x2, float y2)
{
	float	delta_x = x2 - x1;
	float	delta_y = y2 - y1;
	float	angle = atan2(delta_y, delta_x) - cub->player.angle;
	float	new_dist = distance(x1, y1, x2, y2) * cos(angle);
	return (new_dist);
}

bool	collision(t_c *cub, float x, float y)
{
	int mapX = (int)(x / TILE_SIZE);
	int mapY = (int)(y / TILE_SIZE);
	printf("Checking collision at: x=%f, y=%f\n", x, y);
	// Safety check for map boundaries
	if (mapX < 0 || mapY < 0 ||
		mapX >= cub->map_width ||
		mapY >= cub->map_height)
	{
		printf("Collision: Out of map bounds at (%d, %d)\n", mapX, mapY);
		return (true);
	}

	// Check four corners for wall collision
	if (is_wall(cub, x, y) ||
		is_wall(cub, x + PLAYER_SIZE - 4, y) ||
		is_wall(cub, x, y + PLAYER_SIZE - 4) ||
		is_wall(cub, x + PLAYER_SIZE - 4, y + PLAYER_SIZE - 4))
	{
		printf("Collision with wall detected!\n");
		return (true);
	}
	return (false);
}



/* void draw_line_dda(mlx_image_t *ray_img, float x0, float y0, float x1, float y1, uint32_t color)
{
    float dx = x1 - x0;
    float dy = y1 - y0;
    float steps;
    float x = x0;
    float y = y0;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
    float x_inc = dx / steps;
    float y_inc = dy / steps;
	int i = 0;
	while (i <= steps)
	{
		mlx_put_pixel(ray_img, (int)round(x), (int)round(y), color);
		x += x_inc;
		y += y_inc;
		i++;
	}
} */

// #include "cub3d.h"

// float	distance(float x1, float y1, float x2, float y2);
// float	fish_eye_fix(t_c *cub, float x1, float y1, float x2, float y2);

// bool	is_wall(float px, float py, t_c *cub)
// {
// 	int x = (int)px / TILE_SIZE;
// 	int y = (int)py / TILE_SIZE;
// 	return (cub->map[y][x] == '1' || cub->map[y][x] == ' ');
// }

// float	draw_line(t_c *cub, float start_angle, int i)
// {
// 	float	cos_angle = cos(start_angle);
// 	float	sin_angle = sin(start_angle);
// 	float	ray_x = cub->player.pos.x;
// 	float	ray_y = cub->player.pos.y;
// 	while (!is_wall(ray_x, ray_y, cub))
// 	{
// 		mlx_put_pixel(cub->ray_img, ray_x, ray_y, 0x00FF00FF);
// 		ray_x += cos_angle;
// 		ray_y += sin_angle;
// 	}
// 	float ray_distance;
// 	ray_distance = fish_eye_fix(cub, cub->player.pos.x, cub->player.pos.y, ray_x, ray_y);
// 	float height = (TILE_SIZE / ray_distance) * (WIDTH / 2);
// 	int start_y = (HEIGHT - height) / 2;
// 	int end = start_y + height;
// 	int texture_index;
// 	if (ray_x > 0)
// 		texture_index = 3; // East
// 	else
// 		texture_index = 2; // West
// 	if (ray_y > 0)
// 		texture_index = 1; // South
// 	else
// 		texture_index = 0; // North
// 	mlx_image_t *texture = cub->texture[texture_index].img;
// 	int texture_width = cub->texture[texture_index].width;
// 	int texture_height = cub->texture[texture_index].height;
// 	int y = start_y;
// 	while(y < end)
// 	{
// 		int tex_y = (int)(((y - start_y) / (double)(end - start_y)) * texture_height);
// 		int tex_x = (int)(i * texture_width);
// 		uint32_t color = ((uint32_t *)texture->pixels)[tex_y * texture_width + tex_x];
// 		mlx_put_pixel(cub->world_img, i, y, color);
// 		y++;
// 	}
// 	return(ray_distance);
// }

// int	fov_loop(t_c *cub)
// {
// 	float	angle_step = PI / 3 / WIDTH;
// 	float	start_angle = cub->player.angle - PI / 6;
// 	int i = 0;
// 	while (i < WIDTH)
// 	{
// 		draw_line(cub, start_angle, i);
// 		start_angle += angle_step;
// 		i++;
// 	}
// 	return (0);
// }

// float	distance(float x1, float y1, float x2, float y2)
// {
// 	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
// }


// float	fish_eye_fix(t_c *cub, float x1, float y1, float x2, float y2)
// {
// 	float	delta_x = x2 - x1;
// 	float	delta_y = y2 - y1;
// 	float	angle = atan2(delta_y, delta_x) - cub->player.angle;
// 	float	new_dist = distance(x1, y1, x2, y2) * cos(angle);
// 	return (new_dist);
// }
