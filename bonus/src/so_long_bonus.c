/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:34:24 by vchizhov          #+#    #+#             */
/*   Updated: 2023/05/15 17:35:06 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	check_name_file(char *av)
{
	size_t	len;
	char	*tmp;

	tmp = av;
	len = ft_strlen(tmp);
	if (ft_strncmp(&tmp[len - 4], ".ber", len))
		print_error(1);
}

int	main(int ac, char **av)
{
	t_game	map;

	if (ac != 2)
		print_error(1);
	check_name_file(av[1]);
	init_map(&map);
	parsing_file(av[1], &map);
	init_window_with_map(&map);
	return (0);
}
