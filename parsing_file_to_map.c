/*
	1 создаем функцию которая открывает файл подающийся аргументом через ав
	2 читаем его
	3 првоеряем чтоб массив состоял только из символов указанных в сабджекте
	4 проверяем наличие ексита и плэйра
	5 парсим прочитанный файл в нашу матрицу иницилизированную в структуре
	6 чекаем мапу чтоб было все окей
	7 чекаем чтоб перс доходил до выхода и не было тупиков

*/


#include "so_long.h"

void init_map(t_game *map)
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

	// printf("map->height_map %d\n", map->height_map);
	// printf("map->width_map %d\n", map->width_map);
	// printf("map->players %d\n", map->players);
	// printf("map->walls %d\n", map->walls);
	// printf("map->empty_space %d\n", map->empty_space);
	// printf("map->map_exit %d\n", map->map_exit);
	// printf("map->items %d\n", map->items);

}

void check_open_file(char *open_file)
{
	int i;
	i = 0;
	while(open_file[i])
	{
		if (open_file[i] != '1' && open_file[i] != '0' && open_file[i] != 'C'
		 && open_file[i] != 'E' && open_file[i] != 'P' && open_file[i] != '\n')
		{
			print_error(1);
		}
		i++;
	}
}

void check_count_players_and_exits(char *open_file, t_game *map)
{
	int i;
	i = 0;
	//printf("map->players = %d\nmap->map_exit = %d\nmap->items = %d\n", map->players, map->map_exit, map->items);
	while(open_file[i])
	{
		if (open_file[i] == 'E')
			map->map_exit++;
		else if (open_file[i] == 'C')
			map->items++;
		else if (open_file[i] == 'P')
			map->players++;
		i++;
	}
	//printf("map->players = %d\nmap->map_exit = %d\nmap->items = %d\n", map->players, map->map_exit, map->items);

	if (map->map_exit != 1 || map->items < 1 || map->players != 1)
		print_error(1);
}

void parsing_file(char *av, t_game *map)
{
	int fd;
	char *open_file;
	char buf[2];

	fd = open(av, O_RDONLY);
	open_file = calloc(1, 1);
	if (fd < 0)
	{
		print_error(1);
	}
	while(read(fd, buf, 1) > 0)
	{
		buf[1] = '\0';
		open_file = ft_strjoin(open_file, buf);
	}
	close(fd);
	check_open_file(open_file);
	
	//printf("%s\n", open_file);
	
	check_count_players_and_exits(open_file, map);
	map->map = ft_split(open_file, '\n');
	//read_arr(map->map);
	check_map(map);
	check_no_exit(map);


	// printf("map->height_map %d\n", map->height_map);
	// printf("map->width_map %d\n", map->width_map);
	// printf("map->players %d\n", map->players);
	// printf("map->walls %d\n", map->walls);
	// printf("map->empty_space %d\n", map->empty_space);
	// printf("map->map_exit %d\n", map->map_exit);
	// printf("map->items %d\n", map->items);
	
}