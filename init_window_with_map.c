#include "so_long.h"


void init_sprites(t_game *map)
{
	map->sprite_player = mlx_xpm_file_to_image(map->mlx, "./sprites/player.xpm", &map->width_sprite, &map->height_sprite);
	map->sprite_wall = mlx_xpm_file_to_image(map->mlx, "./sprites/wall.xpm", &map->width_sprite, &map->height_sprite);
	map->sprite_place = mlx_xpm_file_to_image(map->mlx, "./sprites/place.xpm", &map->width_sprite, &map->height_sprite);
	map->sprite_exit = mlx_xpm_file_to_image(map->mlx, "./sprites/exit.xpm", &map->width_sprite, &map->height_sprite);
	map->sprite_items = mlx_xpm_file_to_image(map->mlx, "./sprites/items.xpm", &map->width_sprite, &map->height_sprite);

}

void print_sprites(t_game *map, char c, int y, int x)
{
	if (c == '0')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->sprite_place, 64 * x, 64 * y);
	else if (c == '1')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->sprite_wall, 64 * x, 64 * y);
	else if (c == 'C')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->sprite_items, 64 * x, 64 * y);
	else if (c == 'E')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->sprite_exit, 64 * x, 64 * y);
	else if (c == 'P')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->sprite_player, 64 * x, 64 * y);
}

void render_map(t_game *map)
{
	int i;
	int j;

	i = 0;
	while(map->map[i])
	{
		j = 0;
		while(map->map[i][j])
		{
			print_sprites(map, map->map[i][j], i, j);
			j++;
		}
		i++;
	}
}


void init_window_with_map(t_game *map)
{
	map->mlx = mlx_init();
	//printf("map->width_map %d\nmap->height_map %d\n", map->width_map, map->height_map);
	map->mlx_win = mlx_new_window(map->mlx, 64 * map->width_map, 64 * map->height_map, "so_long");
	init_sprites(map);
	render_map(map);

	mlx_loop(map->mlx);
}