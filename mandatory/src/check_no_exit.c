/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_no_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:16:59 by vchizhov          #+#    #+#             */
/*   Updated: 2023/05/16 18:02:47 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_exit(char **map)
{
	int	i;
	int	j;
	int	exit_map;
	int	item_map;

	i = 0;
	exit_map = 0;
	item_map = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exit_map++;
			else if (map[i][j] == 'C')
				item_map++;
			j++;
		}
		i++;
	}
	if (exit_map != 0 || item_map != 0)
		print_error(1);
}

void	f_fill(char **arr_map, t_game *map, int y, int x)
{
	if (y < 0 || x < 0 || y >= map->height_map || x >= map->width_map)
		return ;
	if (arr_map[y][x] == 'F' || arr_map[y][x] == '1')
		return ;
	if (arr_map[y][x] == 'E')
	{
		arr_map[y][x] = 'F';
		return ;
	}
	arr_map[y][x] = 'F';
	f_fill(arr_map, map, y - 1, x);
	f_fill(arr_map, map, y + 1, x);
	f_fill(arr_map, map, y, x - 1);
	f_fill(arr_map, map, y, x + 1);
}

void	flood_fill(char **tmp_map, t_game *map)
{
	f_fill(tmp_map, map, map->position_player_y, map->position_player_x);
}

void	find_player(t_game *map)
{
	char	**player;
	int		i;
	int		j;

	i = 0;
	j = 0;
	player = map->map;
	while (player[i])
	{
		j = 0;
		while (player[i][j])
		{
			if (player[i][j] == 'P')
			{
				map->position_player_x = j;
				map->position_player_y = i;
			}
			j++;
		}
		i++;
	}
}

void	check_no_exit(t_game *map)
{
	char	**tmp_map;

	tmp_map = create_dublicate(map->map);
	find_player(map);
	flood_fill(tmp_map, map);
	check_exit(tmp_map);
	free_arr(tmp_map);
}
