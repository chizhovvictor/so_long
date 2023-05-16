/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:35:12 by vchizhov          #+#    #+#             */
/*   Updated: 2023/05/16 14:41:08 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_error(int a)
{
	a = 0;
	write(2, "Error\n", 6);
	exit(1);
}

char	**create_dublicate(char **arr)
{
	char	**dublicate;
	int		i;
	int		j;

	i = 0;
	dublicate = malloc(len_pointer_arr(arr) * sizeof(char *) + 1);
	while (i < len_pointer_arr(arr))
	{
		j = 0;
		dublicate[i] = malloc(ft_strlen(arr[i]) * sizeof(char) + 1);
		while (arr[i][j])
		{
			dublicate[i][j] = arr[i][j];
			j++;
		}
		dublicate[i][j] = '\0';
		i++;
	}
	dublicate[i] = NULL;
	return (dublicate);
}

void	read_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_putstr_fd(arr[i], 1);
		write(1, "\n", 1);
		i++;
	}
}

int	len_pointer_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
