/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ways.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:40:14 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/10/30 12:16:06 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	fill_empty_way(t_mlx_data *d, int x, int y)
{
	if (is_c(d->map2[x][y]) || is_0(d->map2[x][y]))
		d->map2[x][y] = 'P';
}

int	player_stuck(t_mlx_data *d, int x, int y)
{
	if (is_p(d->map2[x][y]) &&
	(is_c(d->map2[x][y + 1])
	|| is_0(d->map2[x][y + 1])
	|| is_c(d->map2[x - 1][y])
	|| is_0(d->map2[x - 1][y])
	|| is_c(d->map2[x][y - 1])
	|| is_0(d->map2[x][y - 1])
	|| is_c(d->map2[x + 1][y])
	|| is_0(d->map2[x + 1][y])))
		return (TRUE);
	return (FALSE);
}

void	reach_collects(t_mlx_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->map2[i])
	{
		j = 0;
		while (d->map2[i][j])
		{
			if (is_c(d->map2[i][j]))
			{
				ft_error(RED"Error\nNot a valid way"END, 8, d);
			}
			j++;
		}
		i++;
	}
}

void	reach_exit(t_mlx_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->map2[i])
	{
		j = 0;
		while (d->map2[i][j])
		{
			if ((is_e(d->map2[i][j])
				&& is_p(d->map2[i][j + 1]))
				|| (is_e(d->map2[i][j])
				&& is_p(d->map2[i][j - 1]))
				|| (is_e(d->map2[i][j])
				&& is_p(d->map2[i + 1][j]))
				|| (is_e(d->map2[i][j])
				&& is_p(d->map2[i - 1][j])))
				return ;
			j++;
		}
		i++;
	}
	ft_error(RED"Error\nThere isn't a valid way to reach exit"END, 9, d);
}

void	ft_check_ways(t_mlx_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->map1[i])
	{
	j = -1;
		while (d->map1[i][++j])
		{
			if (player_stuck(d, i, j))
			{
				fill_empty_way(d, i + 1, j);
				fill_empty_way(d, i - 1, j);
				fill_empty_way(d, i, j + 1);
				fill_empty_way(d, i, j - 1);
				i = 0;
			}
		}
		i++;
	}
	reach_collects(d);
	reach_exit(d);
}
