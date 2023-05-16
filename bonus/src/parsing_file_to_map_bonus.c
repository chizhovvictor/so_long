/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file_to_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:31:12 by vchizhov          #+#    #+#             */
/*   Updated: 2023/05/15 17:33:12 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	init_map(t_game *map)
{
	map->map = NULL;
	map->height_map = 0;
	map->width_map = 0;
	map->players = 0;
	map->walls = 0;
	map->empty_space = 0;
	map->map_exit = 0;
	map->items = 0;
	map->position_player_x = 0;
	map->position_player_y = 0;
	map->step_count = 0;
}

void	check_open_file(char *open_file)
{
	int	i;

	i = 0;
	while (open_file[i])
	{
		if (open_file[i] != '1' && open_file[i] != '0' && open_file[i] != 'C' \
		&& open_file[i] != 'E' && open_file[i] != 'P' \
		&& open_file[i] != '\n' && open_file[i] != 'M')
		{
			print_error(1);
		}
		i++;
	}
}

void	check_count_players_and_exits(char *open_file, t_game *map)
{
	int	i;

	i = 0;
	while (open_file[i])
	{
		if (open_file[i] == 'E')
			map->map_exit++;
		else if (open_file[i] == 'C')
			map->items++;
		else if (open_file[i] == 'P')
			map->players++;
		i++;
	}
	if (map->map_exit != 1 || map->items < 1 || map->players != 1)
	{
		print_error(1);
	}
}

void	parsing_file(char *av, t_game *map)
{
	int		fd;
	char	*open_file;
	char	buf[2];

	fd = open(av, O_RDONLY);
	open_file = calloc(1, 1);
	if (fd < 0)
	{
		print_error(1);
	}
	while (read(fd, buf, 1) > 0)
	{
		buf[1] = '\0';
		open_file = ft_strjoin(open_file, buf);
	}
	close(fd);
	check_open_file(open_file);
	check_count_players_and_exits(open_file, map);
	map->map = ft_split(open_file, '\n');
	check_map(map);
	check_no_exit(map);
}
