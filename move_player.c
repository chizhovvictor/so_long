#include "so_long.h"


int check_move_place(char place, t_game *map)
{
	if (place == '1')
		return 1;
	if (place == 'C')
		map->items--;
	if (place == 'E' && map->items == 0)
	{
		ft_putstr_fd("YOU WIN\n", 1);
		exit_game(map);
	}
	else if (place == 'E')
		return 1;
	map->step_count++;
	ft_putnbr_fd(map->step_count, 1);
	write(1, "\n", 1);
	return 0;
}

void move_player(char place, t_game *map, int keycode)
{
	if (check_move_place(place, map))
		return ;
	if (keycode == 13 || keycode == 12)
	{
		map->position_player_y--;
		map->map[map->position_player_y][map->position_player_x] = 'P';
		map->map[map->position_player_y + 1][map->position_player_x] = '0';
	}
	else if (keycode == 0 || keycode == 6)
	{
		map->position_player_y++;
		map->map[map->position_player_y][map->position_player_x] = 'P';
		map->map[map->position_player_y - 1][map->position_player_x] = '0';
	}
	else if (keycode == 1)
	{
		map->position_player_x--;
		map->map[map->position_player_y][map->position_player_x] = 'P';
		map->map[map->position_player_y][map->position_player_x + 1] = '0';
	}
	else if (keycode == 2)
	{
		map->position_player_x++;
		map->map[map->position_player_y][map->position_player_x] = 'P';
		map->map[map->position_player_y][map->position_player_x - 1] = '0';
	}
}


void move_player_up(t_game *map)
{
	// if (map->map[map->position_player_y - 1][map->position_player_x] == '1')
	// 	return ;
	// if (map->map[map->position_player_y - 1][map->position_player_x] == 'C')
	// 	map->items--;
	// if (map->map[map->position_player_y - 1][map->position_player_x] == 'E' && map->items == 0)
	// 	exit_game(map);
	// else if (map->map[map->position_player_y - 1][map->position_player_x] == 'E')
	// 	return ;
	if (check_move_place(map->map[map->position_player_y - 1][map->position_player_x], map))
		return ;
	map->position_player_y--;
	map->map[map->position_player_y][map->position_player_x] = 'P';
	map->map[map->position_player_y + 1][map->position_player_x] = '0';
	
	map->step_count++;
	printf("%d\n", map->step_count);
}

void move_player_down(t_game *map)
{
	// if (map->map[map->position_player_y + 1][map->position_player_x] == '1')
	// 	return ;
	// if (map->map[map->position_player_y + 1][map->position_player_x] == 'C')
	// 	map->items--;
	// if (map->map[map->position_player_y + 1][map->position_player_x] == 'E' && map->items == 0)
	// 	exit_game(map);
	// else if (map->map[map->position_player_y + 1][map->position_player_x] == 'E')
	// 	return ;
	if (check_move_place(map->map[map->position_player_y + 1][map->position_player_x], map))
		return ;
	map->position_player_y++;
	map->map[map->position_player_y][map->position_player_x] = 'P';
	map->map[map->position_player_y - 1][map->position_player_x] = '0';

	map->step_count++;
	printf("%d\n", map->step_count);
}

void move_player_left(t_game *map)
{
	// if (map->map[map->position_player_y][map->position_player_x - 1] == '1')
	// 	return ;
	// if (map->map[map->position_player_y][map->position_player_x - 1] == 'C')
	// 	map->items--;
	// if (map->map[map->position_player_y][map->position_player_x - 1] == 'E' && map->items == 0)
	// 	exit_game(map);
	// else if (map->map[map->position_player_y][map->position_player_x - 1] == 'E')
	// 	return ;
	if (check_move_place(map->map[map->position_player_y][map->position_player_x - 1], map))
		return ;
	map->position_player_x--;
	map->map[map->position_player_y][map->position_player_x] = 'P';
	map->map[map->position_player_y][map->position_player_x + 1] = '0';


	map->step_count++;
	printf("%d\n", map->step_count);
}

void move_player_right(t_game *map)
{
	// if (map->map[map->position_player_y][map->position_player_x + 1] == '1')
	// 	return ;
	// if (map->map[map->position_player_y][map->position_player_x + 1] == 'C')
	// 	map->items--;
	// if (map->map[map->position_player_y][map->position_player_x + 1] == 'E' && map->items == 0)
	// 	exit_game(map);
	// else if (map->map[map->position_player_y][map->position_player_x + 1] == 'E')
	// 	return ;
	if (check_move_place(map->map[map->position_player_y][map->position_player_x + 1], map))
		return ;
	map->position_player_x++;
	map->map[map->position_player_y][map->position_player_x] = 'P';
	map->map[map->position_player_y][map->position_player_x - 1] = '0';

	map->step_count++;
	printf("%d\n", map->step_count);
}


