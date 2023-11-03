/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_component2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:42:48 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/10/31 11:42:50 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	enough_e(t_mlx_data *d)
{
	int	i;
	int	j;
	int	e;

	i = 0;
	j = 0;
	e = 0;
	while (d->map1[i])
	{
		j = 0;
		while (d->map1[i][j])
		{
			if (is_e(d->map1[i][j]))
				e++;
			j++;
		}
		i++;
	}
	if (e != 1)
		ft_error(RED"Error\nInvalid Exit position components"END, 7, d);
}

void	enough_c(t_mlx_data *d)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (d->map1[i])
	{
		j = 0;
		while (d->map1[i][j])
		{
			if (is_c(d->map1[i][j]))
				c++;
			j++;
		}
		i++;
	}
	if (c < 1)
		ft_error(RED"Error\nNot enough collectables in Map"END, 7, d);
}

void	enough_p(t_mlx_data *d)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (d->map1[i])
	{
		j = 0;
		while (d->map1[i][j])
		{
			if (is_p(d->map1[i][j]))
				p++;
			j++;
		}
		i++;
	}
	if (p != 1)
		ft_error(RED"Invalid initial position components"END, 7, d);
}
