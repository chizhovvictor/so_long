// #include "so_long.h"


// void init_sprites(t_game *map)
// {
// 	map->sprite_player = mlx_xpm_file_to_image(map->mlx, "./sprites/player.xpm", &map->width_sprite, &map->height_sprite);
// 	map->sprite_wall = mlx_xpm_file_to_image(map->mlx, "./sprites/wall.xpm", &map->width_sprite, &map->height_sprite);
// 	map->sprite_place = mlx_xpm_file_to_image(map->mlx, "./sprites/place.xpm", &map->width_sprite, &map->height_sprite);
// 	map->sprite_exit = mlx_xpm_file_to_image(map->mlx, "./sprites/exit.xpm", &map->width_sprite, &map->height_sprite);
// 	map->sprite_items = mlx_xpm_file_to_image(map->mlx, "./sprites/items.xpm", &map->width_sprite, &map->height_sprite);

// }

// void print_sprites(t_game *map, char c)
// {
// 	if (c == '0')
// 		mlx_put_image_to_window(map->mlx, map->window, map->sprite_place, map->width_sprite, map->height_sprite);
// 	else if (c == '1')
// 		mlx_put_image_to_window(map->mlx, map->window, map->sprite_wall, map->width_sprite, map->height_sprite);
// 	else if (c == 'C')
// 		mlx_put_image_to_window(map->mlx, map->window, map->sprite_items, map->width_sprite, map->height_sprite);
// 	else if (c == 'E')
// 		mlx_put_image_to_window(map->mlx, map->window, map->sprite_exit, map->width_sprite, map->height_sprite);
// 	else if (c == 'P')
// 		mlx_put_image_to_window(map->mlx, map->window, map->sprite_player, map->width_sprite, map->height_sprite);
// }

// void render_map(t_game *map)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while(map->map[i])
// 	{
// 		j = 0;
// 		while(map->map[i][j])
// 		{
// 			print_sprites(map, map->map[i][j]);
// 			j++;
// 		}
// 		i++;
// 	}
// }


// void init_window_with_map(t_game *map)
// {
// 	map->mlx = mlx_init();
// 	map->window = mlx_new_window(map->mlx, 64 * map->width_map, 64 * map->height_map, "so_long");
// 	//init_sprites(map);
// 	//render_map(map);

// 	mlx_loop(map->mlx);
// }