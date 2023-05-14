#include "so_long.h"

void check_first_string_map(t_game *map)
{
	int i;
	char *str;

	i = 0;
	str = map->map[0];
	while (str[i])
	{
		if (str[i] != '1')
		{
			print_error(1);
		}
		i++;
	}
	
}

void check_last_string_map(t_game *map)
{
	int i;
	int len;
	char *str;

	i = 0;
	len = len_pointer_arr(map->map);
	str = map->map[len - 1];
	while (str[i])
	{
		if (str[i] != '1')
			print_error(1);
		i++;
	}
}

int check_other_string_map(char *string)
{
	int i;
	int len;
	
	i = 0;
	len = ft_strlen(string);
	// printf("string = %s\n", string);
	if (string[0] != '1' || string[len - 1] != '1')
			return (1);
	return (0);
}

void check_wall_map(t_game *map)
{
	int i;
	int len;

	i = 1;
	check_first_string_map(map);
	check_last_string_map(map);
	len = len_pointer_arr(map->map);
	while(i < len - 1)
	{
		// printf("string = %s\n", map->map[i]);
		// printf("i = %d\n", i);
		if (check_other_string_map(map->map[i]))
		{
			print_error(1);
		}
		i++;
	}
	
}

void check_map(t_game *map)
{
	int i;
	int len;
	
	i = 0;
	len = len_pointer_arr(map->map);
	while(i < len - 1)
	{
		if (ft_strlen(map->map[i]) != ft_strlen(map->map[i + 1]))
		{
			print_error(1);
		}
		i++;
	}
	
	check_wall_map(map);
	map->height_map = len_pointer_arr(map->map);
	map->width_map = ft_strlen(map->map[0]);
}