#include "so_long.h"

void print_error(int a)
{
	a = 0;
	write(2, "Error\n", 6);
	exit(1);
}

char **create_dublicate(char **arr)
{
	char **dublicate;
	int i;

	i = 0;
	dublicate = malloc(len_pointer_arr(arr) * sizeof(char *));
	while(i < len_pointer_arr(arr))
    {
        dublicate[i] = malloc(ft_strlen(arr[i]) * sizeof(char));
        ft_memcpy(dublicate[i], arr[i], ft_strlen(arr[i]));
        i++;
    }
	dublicate[i] = NULL;
	return (dublicate); 
}

void read_arr(char **arr)
{
	int i;

	i = 0;
	while(arr[i])
	{
		ft_putstr_fd(arr[i], 1);
		write(1, "\n", 1);
		i++;
	}
}

int len_pointer_arr(char **arr)
{
	int i;

	i = 0;
	while(arr[i])
		i++;
	return (i);
}

void free_arr(char **arr)
{
	int i;

	i = 0;
	while(arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}