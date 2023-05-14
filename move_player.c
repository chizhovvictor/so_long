#include "so_long.h"

void move_player_up(t_game *map)
{
	if (map->map[map->position_player_y - 1][map->position_player_x] == '1')
		return ;
	if (map->map[map->position_player_y - 1][map->position_player_x] == 'C')
		map->items--;
	if (map->map[map->position_player_y - 1][map->position_player_x] == 'E' && map->items == 0)
		exit_game(map);
	else if (map->map[map->position_player_y - 1][map->position_player_x] == 'E')
		return ;
	map->position_player_y--;
	map->map[map->position_player_y][map->position_player_x] = 'P';
	map->map[map->position_player_y + 1][map->position_player_x] = '0';
	
	map->step_count++;
	printf("%d\n", map->step_count);
}

void move_player_down(t_game *map)
{
	if (map->map[map->position_player_y + 1][map->position_player_x] == '1')
		return ;
	if (map->map[map->position_player_y + 1][map->position_player_x] == 'C')
		map->items--;
	if (map->map[map->position_player_y + 1][map->position_player_x] == 'E' && map->items == 0)
		exit_game(map);
	else if (map->map[map->position_player_y + 1][map->position_player_x] == 'E')
		return ;
	map->position_player_y++;
	map->map[map->position_player_y][map->position_player_x] = 'P';
	map->map[map->position_player_y - 1][map->position_player_x] = '0';

	map->step_count++;
	printf("%d\n", map->step_count);
}

void move_player_left(t_game *map)
{
	if (map->map[map->position_player_y][map->position_player_x - 1] == '1')
		return ;
	if (map->map[map->position_player_y][map->position_player_x - 1] == 'C')
		map->items--;
	if (map->map[map->position_player_y][map->position_player_x - 1] == 'E' && map->items == 0)
		exit_game(map);
	else if (map->map[map->position_player_y][map->position_player_x - 1] == 'E')
		return ;
	map->position_player_x--;
	map->map[map->position_player_y][map->position_player_x] = 'P';
	map->map[map->position_player_y][map->position_player_x + 1] = '0';


	map->step_count++;
	printf("%d\n", map->step_count);
}

void move_player_right(t_game *map)
{
	if (map->map[map->position_player_y][map->position_player_x + 1] == '1')
		return ;
	if (map->map[map->position_player_y][map->position_player_x + 1] == 'C')
		map->items--;
	if (map->map[map->position_player_y][map->position_player_x + 1] == 'E' && map->items == 0)
		exit_game(map);
	else if (map->map[map->position_player_y][map->position_player_x + 1] == 'E')
		return ;
	map->position_player_x++;
	map->map[map->position_player_y][map->position_player_x] = 'P';
	map->map[map->position_player_y][map->position_player_x - 1] = '0';

	map->step_count++;
	printf("%d\n", map->step_count);
}


