/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window_with_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:22:04 by vchizhov          #+#    #+#             */
/*   Updated: 2023/05/16 16:27:04 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	init_sprites(t_game *map)
{
	map->sprite_player1 = mlx_xpm_file_to_image(map->mlx, \
	"./sprites/player1.xpm", &map->width_sprite, &map->height_sprite);
	map->sprite_wall = mlx_xpm_file_to_image(map->mlx, \
	"./sprites/wall.xpm", &map->width_sprite, &map->height_sprite);
	map->sprite_place = mlx_xpm_file_to_image(map->mlx, \
	"./sprites/place.xpm", &map->width_sprite, &map->height_sprite);
	map->sprite_exit = mlx_xpm_file_to_image(map->mlx, \
	"./sprites/exit2.xpm", &map->width_sprite, &map->height_sprite);
	map->sprite_items = mlx_xpm_file_to_image(map->mlx, \
	"./sprites/items.xpm", &map->width_sprite, &map->height_sprite);
	map->sprite_mob = mlx_xpm_file_to_image(map->mlx, \
	"./sprites/mob.xpm", &map->width_sprite, &map->height_sprite);
}

void	print_sprites(t_game *map, char c, int y, int x)
{
	if (map->items == 0)
		init_sprite_open_exit(map);
	if (c == '0')
		mlx_put_image_to_window(map->mlx, map->mlx_win, \
		map->sprite_place, 64 * x, 64 * y);
	else if (c == '1')
		mlx_put_image_to_window(map->mlx, map->mlx_win, \
		map->sprite_wall, 64 * x, 64 * y);
	else if (c == 'C')
		mlx_put_image_to_window(map->mlx, map->mlx_win, \
		map->sprite_items, 64 * x, 64 * y);
	else if (c == 'E')
		mlx_put_image_to_window(map->mlx, map->mlx_win, \
		map->sprite_exit, 64 * x, 64 * y);
	else if (c == 'P')
		mlx_put_image_to_window(map->mlx, map->mlx_win, \
		map->sprite_player1, 64 * x, 64 * y);
	else if (c == 'M')
		mlx_put_image_to_window(map->mlx, map->mlx_win, \
		map->sprite_mob, 64 * x, 64 * y);
}

void	render_map(t_game *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			print_sprites(map, map->map[i][j], i, j);
			j++;
		}
		i++;
	}
}

void	init_window_with_map(t_game *map)
{
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, 64 * map->width_map, \
	64 * map->height_map, "so_long_bonus");
	init_sprites(map);
	init_animation_player(map);
	render_map(map);
	mlx_hook(map->mlx_win, 2, 1L << 0, my_keypress_hook, map);
	mlx_hook(map->mlx_win, 17, 1L << 17, exit_game, map);
	mlx_loop_hook(map->mlx, update_animation_player, map);
	render_map(map);
	mlx_loop(map->mlx);
}
