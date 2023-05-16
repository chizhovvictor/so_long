#include "../include/so_long_bonus.h"

int update_animation_player(t_game *map)
{
	static int frame = 0;
	static int delay = 10;
	char *str;
	
	frame++;
	str = ft_itoa(map->step_count);
	if (frame == delay)
	{
		frame = 0;
		if (map->sprite_current_player == map->sprite_player1)
			map->sprite_current_player = map->sprite_player2;
		else if (map->sprite_current_player == map->sprite_player2)
			map->sprite_current_player = map->sprite_player3;
		else if (map->sprite_current_player == map->sprite_player3)
			map->sprite_current_player = map->sprite_player4;
		else if (map->sprite_current_player == map->sprite_player4)
			map->sprite_current_player = map->sprite_player1;
	}
	mlx_put_image_to_window(map->mlx, map->mlx_win, \
	map->sprite_current_player, 64 * map->position_player_x, 64 * map->position_player_y);
	mlx_string_put(map->mlx, map->mlx_win, 20, 20, 0xFFFFFF, "Moves:");
	mlx_string_put(map->mlx, map->mlx_win, 100, 20, 0xFFFFFF, str);
	free(str);
	//system("leaks so_long_bonus");
	return (0);
}


void init_animation_player(t_game *map)
{
	map->sprite_player2 = mlx_xpm_file_to_image(map->mlx, \
	"./sprites/player2.xpm", &map->width_sprite, &map->height_sprite);
	map->sprite_player3 = mlx_xpm_file_to_image(map->mlx, \
	"./sprites/player3.xpm", &map->width_sprite, &map->height_sprite);
	map->sprite_player4 = mlx_xpm_file_to_image(map->mlx, \
	"./sprites/player4.xpm", &map->width_sprite, &map->height_sprite);
	map->sprite_current_player = map->sprite_player1;
}

void   init_sprite_open_exit(t_game *map)
{
	map->sprite_exit = mlx_xpm_file_to_image(map->mlx, \
	"./sprites/exit.xpm", &map->width_sprite, &map->height_sprite);
}