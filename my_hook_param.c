#include "so_long.h"

void deleted_sprites(t_game *map)
{
	mlx_destroy_image(map->mlx, map->sprite_player);
	mlx_destroy_image(map->mlx, map->sprite_exit);
	mlx_destroy_image(map->mlx, map->sprite_items);
	mlx_destroy_image(map->mlx, map->sprite_place);
	mlx_destroy_image(map->mlx, map->sprite_wall);
}

int exit_game(t_game *map)
{
	deleted_sprites(map);
	mlx_destroy_window(map->mlx, map->mlx_win);
	//mlx_destroy_display(map->mlx);
	// free_arr(map->map);
	// free(map);
	exit(0);
}


int my_keypress_hook(int keycode, t_game *map)
{
	if (keycode == 13 || keycode == 12)
		move_player_up(map);
    else if (keycode == 0 || keycode == 6)
		move_player_down(map);
    else if (keycode == 1)
		move_player_left(map);
    else if (keycode == 2)
		move_player_right(map);
	else if (keycode == 53)
		exit_game(map);
	render_map(map);
    return (keycode);
}
