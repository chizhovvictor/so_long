/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_hook_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:24:09 by vchizhov          #+#    #+#             */
/*   Updated: 2023/05/15 17:27:06 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	deleted_sprites(t_game *map)
{
	mlx_destroy_image(map->mlx, map->sprite_player1);
	mlx_destroy_image(map->mlx, map->sprite_player2);
	mlx_destroy_image(map->mlx, map->sprite_player3);
	mlx_destroy_image(map->mlx, map->sprite_player4);
	mlx_destroy_image(map->mlx, map->sprite_exit);
	mlx_destroy_image(map->mlx, map->sprite_items);
	mlx_destroy_image(map->mlx, map->sprite_place);
	mlx_destroy_image(map->mlx, map->sprite_wall);
	mlx_destroy_image(map->mlx, map->sprite_mob);
}

int	exit_game(t_game *map)
{
	deleted_sprites(map);
	mlx_destroy_window(map->mlx, map->mlx_win);
	system("leaks so_long_bonus");
	exit(0);
}

int	my_keypress_hook(int keycode, t_game *map)
{
	if (keycode == 13 || keycode == 12)
		move_player(map->map[map->position_player_y \
		- 1][map->position_player_x], map, keycode);
	else if (keycode == 0 || keycode == 6)
		move_player(map->map[map->position_player_y \
		+ 1][map->position_player_x], map, keycode);
	else if (keycode == 1)
		move_player(map->map[map->position_player_y][map->position_player_x \
		- 1], map, keycode);
	else if (keycode == 2)
		move_player(map->map[map->position_player_y][map->position_player_x \
		+ 1], map, keycode);
	else if (keycode == 53)
		exit_game(map);
	render_map(map);
	return (keycode);
}
