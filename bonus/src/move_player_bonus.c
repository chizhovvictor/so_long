/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:22:18 by vchizhov          #+#    #+#             */
/*   Updated: 2023/05/16 12:08:06 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	check_move_place(char place, t_game *map)
{
	if (place == '1')
		return (1);
	if (place == 'C')
		map->items--;
	if (place == 'E' && map->items == 0)
	{
		ft_putstr_fd("YOU WIN\n", 1);
		exit_game(map);
	}
	if (place == 'M')
	{
		ft_putstr_fd("YOU DIED\n", 1);
		exit_game(map);
	}
	else if (place == 'E')
		return (1);
	map->step_count++;
	return (0);
}

void	move_player2(t_game *map, int keycode)
{
	if (keycode == 1)
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

void	move_player(char place, t_game *map, int keycode)
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
	else
		move_player2(map, keycode);
}
