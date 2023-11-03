/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:31:59 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/10/30 11:36:28 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map_form(t_mlx_data *d)
{
	int	i;
	int	row_size;

	i = 1;
	row_size = ft_strlen(d->map1[0]);
	while (d->map1[i])
	{
		if (row_size != ft_strlen(d->map1[i]))
			ft_error(RED"Error\nMap is not rectangular"END, 4, d);
		i++;
	}
}

void	check_map_comps(t_mlx_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (d->map1[i])
	{
		while (d->map1[i][j])
		{
			if (!is_1(d->map1[i][j]) && !is_0(d->map1[i][j]) &&
				!is_c(d->map1[i][j]) && !is_e(d->map1[i][j]) &&
				!is_p(d->map1[i][j]))
				ft_error(RED"Error\nComponent invalid in Map"END, 5, d);
			j++;
		}
		j = 0;
		i++;
	}
}

void	check_perimeter(t_mlx_data *d)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = 0;
	while (d->map1[size])
		size++;
	while (d->map1[i])
	{
		while (d->map1[i][j])
		{
			if (!is_1(d->map1[0][j]) || !is_1(d->map1[size - 1][j]))
				ft_error(RED"Error\nMap perimeter is not valid!"END, 6, d);
			else if (!is_1(d->map1[i][0]) ||
				!is_1(d->map1[i][ft_strlen(d->map1[i]) - 1]))
				ft_error(RED"Error\nMap perimeter is not valid!"END, 6, d);
			j++;
		}
		j = 0;
		i++;
	}
}

void	check_enough_comp(t_mlx_data *d)
{
	enough_c(d);
	enough_e(d);
	enough_p(d);
}
